#include "account.h"
#include "ui_account.h"

Account::Account(QWidget *parent,
                 const QString &accountNumber,
                 const QString &accountHolderName,
                 double accountBalance,
                 const QString &accountType,
                 const QDate &openingDate,
                 double interestRate,
                 const QString &currency) :
    QDialog(parent),
    ui(new Ui::Account),
    accountNumber(accountNumber),
    accountHolderName(accountHolderName),
    accountBalance(accountBalance),
    accountType(accountType),
    openingDate(openingDate),
    interestRate(interestRate),
    currency(currency)
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
    ui->labelAccountNumber->setText(accountNumber);
    ui->labelAccountHolderName->setText(accountHolderName);
    ui->labelAccountBalance->setText(QString::number(accountBalance, 'f', 2));
    ui->labelAccountType->setText(accountType);
    ui->labelOpeningDate->setText(openingDate.toString("dd.MM.yyyy"));
    ui->labelInterestRate->setText(QString::number(interestRate, 'f', 2) + "%");
    ui->labelCurrency->setText(currency);
}

Account::~Account()
{
    delete ui;
}

void Account::closeEvent(QCloseEvent *event)
{
    emit accountWindowClosed();  // Эмитируем сигнал при закрытии окна
    QDialog::closeEvent(event);
}

void Account::on_backButton_clicked()
{
    emit accountWindowClosed();  // Эмитируем сигнал при нажатии кнопки "Назад"
    close();  // Закрываем окно Account
}
