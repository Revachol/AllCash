#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "financemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    accountWindow(nullptr),
    creditsWindow(nullptr),
    depositWindow(nullptr),
    openCreditWindow(nullptr)
{
    FinanceManager& fm = FinanceManager::getInstance();
    fm.setAccountDetails("123456789", "Иван Иванов", 15000.75, "Сберегательный",
                         QDate(2020, 5, 15), "RUB", false, false);

    ui->setupUi(this);
    QPixmap pix(":/resources/img/logo.png");
    int w = ui->logo->width();
    int h = ui->logo->height();

    ui->logo->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    QPixmap bkgnd(":/resources/img/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();

    // Создание окна Account
    accountWindow = new Account(this);

    // Подключение сигнала закрытия окна Account к слоту для показа главного окна
    connect(accountWindow, &Account::accountWindowClosed, this, &MainWindow::showMainWindow);

    accountWindow->show();
}

void MainWindow::on_pushButtonCredits_clicked()
{
    hide();
    creditsWindow = new Credits(this);
    FinanceManager& fm = FinanceManager::getInstance();
    if (fm.isCredit()) {

        // Создание окна Credits
        creditsWindow = new Credits(this);

        // Подключение сигнала закрытия окна Credits к слоту для показа главного окна
        connect(creditsWindow, &Credits::creditsWindowClosed, this, &MainWindow::showMainWindow);

        creditsWindow->show();
    } else {
        // Создание окна для открытия кредита
        openCreditWindow = new OpenCredit(this);

        // Подключение сигнала открытия кредита к слоту для показа окна Credits
        connect(openCreditWindow, &OpenCredit::openCreditsWindowClosed, this, &MainWindow::showCreditsWindow);

        openCreditWindow->show();
    }
}

void MainWindow::showCreditsWindow()
{
    if (openCreditWindow) {
        openCreditWindow->deleteLater();
        openCreditWindow = nullptr;
    }

    creditsWindow = new Credits(this);

    connect(creditsWindow, &Credits::creditsWindowClosed, this, &MainWindow::showMainWindow);

    creditsWindow->show();
}

void MainWindow::on_pushButton_2_clicked(){
    on_pushButtonCredits_clicked();
}

void MainWindow::showMainWindow()
{
    show();
    if (accountWindow) {
        accountWindow->deleteLater();
        accountWindow = nullptr;
    }
    if (creditsWindow) {
        creditsWindow->deleteLater();
        creditsWindow = nullptr;
    }
    if (openCreditWindow) {
        openCreditWindow->deleteLater();
        openCreditWindow = nullptr;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    depositWindow = new Deposit(this);
    FinanceManager& fm = FinanceManager::getInstance();
    if (fm.isDeposit()) {

        // Создание окна Credits
        depositWindow = new Deposit(this);

        // Подключение сигнала закрытия окна Credits к слоту для показа главного окна
        connect(depositWindow, &Deposit::depositWindowClosed, this, &MainWindow::showMainWindow);

        depositWindow->show();
    } else {
        // Создание окна для открытия кредита
        openDepositWindow = new OpenDeposit(this);

        // Подключение сигнала открытия кредита к слоту для показа окна Credits
        connect(openDepositWindow, &OpenDeposit::openDepositWindowClosed, this, &MainWindow::showDepositWindow);

        openDepositWindow->show();
    }
}

void MainWindow::showDepositWindow()
{
    if (openDepositWindow) {
        openDepositWindow->deleteLater();
        openDepositWindow = nullptr;
    }

    depositWindow = new Deposit(this);

    connect(depositWindow, &Deposit::depositWindowClosed, this, &MainWindow::showMainWindow);

    depositWindow->show();
}
