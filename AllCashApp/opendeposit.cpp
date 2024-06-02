#include "opendeposit.h"
#include "ui_opendeposit.h"
#include "financemanager.h"


OpenDeposit::OpenDeposit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDeposit)
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

    FinanceManager& fm = FinanceManager::getInstance();
    fm.setDepositDetails(depositAmount, 3.5, depositTerm, false, QDate(2021, 6, 1), QDate(2021 + depositTerm, 6, 1));
    fm.setAccountDetails(fm.getAccountNumber(), fm.getAccountHolderName(), fm.getAccountBalance(),
                         fm.getAccountType(), fm.getOpeningDate(), fm.getCurrency(), fm.isCredit(), true);

    close();
}
