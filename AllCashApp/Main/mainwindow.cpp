#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "financemanager.h"
#include "../FactoryMethod/factorymethod.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    accountWindow(nullptr),
    creditsWindow(nullptr),
    depositWindow(nullptr),
    openCreditWindow(nullptr),
    openDepositWindow(nullptr),
    factory(new FactoryMethod)
{
    FinanceManager& fm = FinanceManager::getInstance();
    fm.setAccountNumber("123456789");
    fm.setAccountHolderName("Иван Иванов");
    fm.setAccountBalance(15000.75);
    fm.setAccountType("Сберегательный");
    fm.setOpeningDate(QDate(2020, 5, 15));
    fm.setCurrency("RUB");
    fm.setCreditOpened(false);
    fm.setDepositOpened(false);

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
    delete factory;
}

void MainWindow::on_pushButton_clicked()
{
    hide();

    accountWindow = factory->createAccount(this);

    connect(accountWindow, &Account::accountWindowClosed, this, &MainWindow::showMainWindow);

    accountWindow->show();
}

void MainWindow::on_pushButtonCredits_clicked()
{
    hide();
    creditsWindow = new Credits(this);
    FinanceManager& fm = FinanceManager::getInstance();
    if (fm.isCreditOpened()) {
        creditsWindow = factory->createCredits(this);

        connect(creditsWindow, &Credits::creditsWindowClosed, this, &MainWindow::showMainWindow);

        creditsWindow->show();
    } else {
        openCreditWindow = factory->createOpenCredit(this);

        connect(openCreditWindow, &OpenCredit::openCreditsWindowClosed, this, &MainWindow::showCreditsWindow);

        openCreditWindow->setCalculationStrategy(new AnnuityInterestStrategy());

        openCreditWindow->show();
    }
}

void MainWindow::showCreditsWindow()
{
    if (openCreditWindow) {
        openCreditWindow->deleteLater();
        openCreditWindow = nullptr;
    }

    creditsWindow = factory->createCredits(this);;

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
    if (openDepositWindow) {
        openDepositWindow->deleteLater();
        openDepositWindow = nullptr;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    FinanceManager& fm = FinanceManager::getInstance();
    if (fm.isDepositOpened()) {
        depositWindow = factory->createDeposit(this);

        connect(depositWindow, &Deposit::depositWindowClosed, this, &MainWindow::showMainWindow);

        depositWindow->show();
    } else {
        openDepositWindow = factory->createOpenDeposit(this);

        connect(openDepositWindow, &OpenDeposit::openDepositWindowClosed, this, &MainWindow::showDepositWindow);

        openDepositWindow->setCalculationStrategy(new DepositCalculationStrategy());

        openDepositWindow->show();
    }
}

void MainWindow::showDepositWindow()
{
    if (openDepositWindow) {
        openDepositWindow->deleteLater();
        openDepositWindow = nullptr;
    }

    depositWindow = factory->createDeposit(this);

    connect(depositWindow, &Deposit::depositWindowClosed, this, &MainWindow::showMainWindow);

    depositWindow->show();
}
