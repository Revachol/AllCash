#include "deposit.h"
#include "ui_deposit.h"
#include "financemanager.h"

Deposit::Deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deposit)
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
    // Получение данных из FinanceManager и установка в UI
    FinanceManager& fm = FinanceManager::getInstance();
    ui->depositSumLabel->setText(QString::number(fm.getDepositSum()));
    ui->depositRateLabel->setText(QString::number(fm.getDepositRate()));

}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::closeEvent(QCloseEvent *event)
{
    emit depositWindowClosed();
    QDialog::closeEvent(event);
}

void Deposit::on_backButton_clicked()
{
    emit depositWindowClosed();  // Эмитируем сигнал при нажатии кнопки "Назад"
    close();  // Закрываем окно Deposit
}
