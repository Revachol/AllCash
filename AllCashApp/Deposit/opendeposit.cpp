#include "opendeposit.h"
#include "ui_opendeposit.h"


OpenDeposit::OpenDeposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDeposit),
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
}

OpenDeposit::~OpenDeposit()
{
    delete ui;
}

void OpenDeposit::closeEvent(QCloseEvent *event)
{
    emit openDepositWindowClosed();
    QDialog::closeEvent(event);
}

void OpenDeposit::on_backButton_clicked()
{
    emit openDepositWindowClosed();
    close();
}

void OpenDeposit::on_depositOpenButton_clicked()
{
    long long int depositAmount = ui->depositAmountInput->text().toLongLong();
    int depositTerm = ui->depositTermInput->text().toInt();
    bool depositCheck = ui->depositCheck->isChecked();

    manager.setDepositSum(depositAmount);
    manager.setDepositTerm(depositTerm);
    manager.setDepositRate(12);
    manager.setDepositStartDate(QDate(2022,6,1));
    manager.setDepositEndDate(QDate(2022 + depositTerm, 6, 1));
    manager.setDepositCheck(depositCheck);

    close();
}

