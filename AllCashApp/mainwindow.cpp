#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "account.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    accountWindow(nullptr)
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

    // Создание окна Account с параметрами
    accountWindow = new Account(this,
                                "123456789",              // Номер счета
                                "Иван Иванов",            // Имя владельца
                                15000.75,                 // Баланс счета
                                "Сберегательный",         // Тип счета
                                QDate(2020, 5, 15),       // Дата открытия счета
                                1.5,                      // Процентная ставка
                                "RUB");                   // Валюта

    // Подключение сигнала закрытия окна Account к слоту для показа главного окна
    connect(accountWindow, &Account::accountWindowClosed, this, &MainWindow::showMainWindow);

    accountWindow->show();  // Используем show() для немодального окна
}

void MainWindow::showMainWindow()
{
    show();  // Показать главное окно
    if (accountWindow) {
        accountWindow->deleteLater();  // Освободить память, когда окно Account будет закрыто
        accountWindow = nullptr;
    }
}
