#include "account.h"
#include "ui_account.h"
#include "financemanager.h"

Account::Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account)
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
    ui->accountNumberLabel->setText(fm.getAccountNumber());
    ui->accountHolderNameLabel->setText(fm.getAccountHolderName());
    ui->accountBalanceLabel->setText(QString::number(fm.getAccountBalance()));
    ui->accountTypeLabel->setText(fm.getAccountType());
    ui->openingDateLabel->setText(fm.getOpeningDate().toString());
    ui->currencyLabel->setText(fm.getCurrency());
    ui->creditLabel->setText(fm.isCredit() ? "Yes" : "No");
    ui->depositLabel->setText(fm.isDeposit() ? "Yes" : "No");
}

Account::~Account()
{
    delete ui;
}

void Account::closeEvent(QCloseEvent *event)
{
    emit accountWindowClosed();
    QDialog::closeEvent(event);
}

void Account::on_backButton_clicked()
{
    emit accountWindowClosed();  // Эмитируем сигнал при нажатии кнопки "Назад"
    close();  // Закрываем окно Account
}
