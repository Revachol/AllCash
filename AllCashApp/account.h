#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr,
                     const QString &accountNumber = "",
                     const QString &accountHolderName = "",
                     double accountBalance = 0.0,
                     const QString &accountType = "",
                     const QDate &openingDate = QDate::currentDate(),
                     double interestRate = 0.0,
                     const QString &currency = "USD");
    ~Account();

signals:
    void accountWindowClosed();  // Сигнал для уведомления о закрытии окна

private slots:
    void on_backButton_clicked();  // Слот для обработки нажатия кнопки "Назад"

private:
    Ui::Account *ui;
    QString accountNumber;
    QString accountHolderName;
    double accountBalance;
    QString accountType;
    QDate openingDate;
    double interestRate;
    QString currency;

protected:
    void closeEvent(QCloseEvent *event) override;  // Переопределение обработчика закрытия окна
};

#endif // ACCOUNT_H
