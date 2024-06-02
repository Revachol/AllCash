#include "deposit.h"
#include "ui_deposit.h"
#include "Main/financemanager.h"

Deposit::Deposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deposit),
    manager(FinanceManager::getInstance())
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

    connect(&manager, &FinanceManager::dataChanged, this, &Deposit::updateView);
    updateView();
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::updateView() {
    ui->depositSumLabel->setText(QString::number(manager.getDepositSum())+ " рублей");
    ui->depositRateLabel->setText(QString::number(manager.getDepositRate())+ "%");
    ui->depositTermLabel->setText(QString::number(manager.getDepositTerm())+ " лет");
    ui->depositStartLabel->setText(manager.getDepositStartDate().toString());
    ui->depositEndLabel->setText(manager.getDepositEndDate().toString());
    ui->depositCheckLabel->setText(manager.getDepositCheck() ? "Yes" : "No");
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
