#include "account.h"
#include "ui_account.h"

Account::Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account),
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

    connect(&manager, &FinanceManager::dataChanged, this, &Account::updateView);
    updateView();
}

Account::~Account()
{
    delete ui;
}

void Account::updateView() {
    ui->accountNumberLabel->setText(manager.getAccountNumber());
    ui->accountHolderNameLabel->setText(manager.getAccountHolderName());
    ui->accountBalanceLabel->setText(QString::number(manager.getAccountBalance()));
    ui->accountTypeLabel->setText(manager.getAccountType());
    ui->openingDateLabel->setText(manager.getOpeningDate().toString());
    ui->currencyLabel->setText(manager.getCurrency());
    ui->creditLabel->setText(manager.isCreditOpened() ? "Yes" : "No");
    ui->depositLabel->setText(manager.isDepositOpened() ? "Yes" : "No");
}

void Account::closeEvent(QCloseEvent *event)
{
    emit accountWindowClosed();
    QDialog::closeEvent(event);
}

void Account::on_backButton_clicked()
{
    emit accountWindowClosed();
    close();
}
