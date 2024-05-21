#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <QObject>
#include <QString>
#include <QDate>

class FinanceManager : public QObject
{
    Q_OBJECT

public:
    static FinanceManager& getInstance();

    // Методы для управления счетами
    void setAccountDetails(const QString &accountNumber,
                           const QString &accountHolderName,
                           double accountBalance,
                           const QString &accountType,
                           const QDate &openingDate,
                           const QString &currency,
                           bool credit,
                           bool deposit);

    QString getAccountNumber() const;
    QString getAccountHolderName() const;
    double getAccountBalance() const;
    QString getAccountType() const;
    QDate getOpeningDate() const;
    QString getCurrency() const;
    bool isCredit() const;
    bool isDeposit() const;

    // Методы для управления кредитами
    void setCreditDetails(double creditAmount,
                          double interestRate,
                          int term,
                          const QDate &startDate,
                          const QDate &endDate);

    double getCreditAmount() const;
    double getInterestRate() const;
    int getTerm() const;
    QDate getCreditStartDate() const;
    QDate getCreditEndDate() const;

    void setDepositDetails(double depositSum,
                           double depositRate);
    double getDepositSum() const;
    double getDepositRate() const;

private:
    FinanceManager();  // Закрытый конструктор для реализации Singleton
    FinanceManager(const FinanceManager&) = delete;
    FinanceManager& operator=(const FinanceManager&) = delete;

    // Данные счета
    QString accountNumber;
    QString accountHolderName;
    double accountBalance;
    QString accountType;
    QDate openingDate;
    QString currency;
    bool credit;
    bool deposit;

    // Данные кредита
    double creditAmount;
    double interestRate;
    int term;
    QDate startDate;
    QDate endDate;

    double depositSum;
    double depositRate;
};

#endif // FINANCEMANAGER_H
