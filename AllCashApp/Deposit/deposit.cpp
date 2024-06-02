#include "deposit.h"
#include "ui_deposit.h"
#include "Main/financemanager.h"

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
    ui->depositSumLabel->setText(QString::number(fm.getDepositSum())+ " рублей");
    ui->depositRateLabel->setText(QString::number(fm.getDepositRate())+ "%");
    ui->depositTermLabel->setText(QString::number(fm.getDepositTerm())+ " лет");
    ui->depositStartLabel->setText(fm.getDepositStartDate().toString());
    ui->depositEndLabel->setText(fm.getDepositEndDate().toString());
    ui->depositCheckLabel->setText(fm.getDepositCheck() ? "Yes" : "No");
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
