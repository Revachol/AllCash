#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "financemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    accountWindow(nullptr),
    creditsWindow(nullptr)
{
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

    // Установка данных счета в FinanceManager
    FinanceManager& fm = FinanceManager::getInstance();
    fm.setAccountDetails("123456789", "Иван Иванов", 15000.75, "Сберегательный",
                         QDate(2020, 5, 15), "RUB", true, true);

    // Создание окна Account
    accountWindow = new Account(this);

    // Подключение сигнала закрытия окна Account к слоту для показа главного окна
    connect(accountWindow, &Account::accountWindowClosed, this, &MainWindow::showMainWindow);

    accountWindow->show();
}

void MainWindow::on_pushButtonCredits_clicked()
{
    hide();

    // Установка данных кредита в FinanceManager
    FinanceManager& fm = FinanceManager::getInstance();
    fm.setCreditDetails(20000.0, 3.5, 12, QDate(2021, 6, 1), QDate(2022, 6, 1));

    // Создание окна Credits
    creditsWindow = new Credits(this);

    // Подключение сигнала закрытия окна Credits к слоту для показа главного окна
    connect(creditsWindow, &Credits::creditsWindowClosed, this, &MainWindow::showMainWindow);

    creditsWindow->show();
}

void MainWindow::showMainWindow()
{
    show();  // Показать главное окно
    if (accountWindow) {
        accountWindow->deleteLater();  // Освободить память, когда окно Account будет закрыто
        accountWindow = nullptr;
    }
    if (creditsWindow) {
        creditsWindow->deleteLater();  // Освободить память, когда окно Credits будет закрыто
        creditsWindow = nullptr;
    }
}
