#include "financemanager.h"

FinanceManager& FinanceManager::getInstance()
{
    static FinanceManager instance;
    return instance;
}

FinanceManager::FinanceManager()
    : accountBalance(0.0), credit(false), deposit(false), creditAmount(0.0), interestRate(0.0), term(0) {}

// Методы для управления счетами
void FinanceManager::setAccountDetails(const QString &accountNumber,
                                       const QString &accountHolderName,
                                       double accountBalance,
                                       const QString &accountType,
                                       const QDate &openingDate,
                                       const QString &currency,
                                       bool credit,
                                       bool deposit)
{
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->accountBalance = accountBalance;
    this->accountType = accountType;
    this->openingDate = openingDate;
    this->currency = currency;
    this->credit = credit;
    this->deposit = deposit;
}

QString FinanceManager::getAccountNumber() const { return accountNumber; }
QString FinanceManager::getAccountHolderName() const { return accountHolderName; }
double FinanceManager::getAccountBalance() const { return accountBalance; }
QString FinanceManager::getAccountType() const { return accountType; }
QDate FinanceManager::getOpeningDate() const { return openingDate; }
QString FinanceManager::getCurrency() const { return currency; }
bool FinanceManager::isCredit() const { return credit; }
bool FinanceManager::isDeposit() const { return deposit; }

// Методы для управления кредитами
void FinanceManager::setCreditDetails(double creditAmount,
                                      double interestRate,
                                      int term,
                                      const QDate &startDate,
                                      const QDate &endDate)
{
    this->creditAmount = creditAmount;
    this->interestRate = interestRate;
    this->term = term;
    this->startDate = startDate;
    this->endDate = endDate;
}

double FinanceManager::getCreditAmount() const { return creditAmount; }
double FinanceManager::getInterestRate() const { return interestRate; }
int FinanceManager::getTerm() const { return term; }
QDate FinanceManager::getCreditStartDate() const { return startDate; }
QDate FinanceManager::getCreditEndDate() const { return endDate; }

// Методы для управления депозитом
void FinanceManager::setDepositDetails(long long int depositSum,
                       double depositRate,
                       int depositTerm,
                       bool non_refillable,
                       QDate depositStartDate,
                       QDate depositEndDate){
    this->depositSum = depositSum;
    this->depositRate = depositRate;
    this->depositTerm = depositTerm;
    this->non_refillable = non_refillable;
    this->depositStartDate = depositStartDate;
    this->depositEndDate = depositEndDate;
}

long long int FinanceManager::getDepositSum() const { return depositSum; }
double FinanceManager::getDepositRate() const { return depositRate; }
int FinanceManager::getDepositTerm() const { return depositTerm; }
bool FinanceManager::getDepositCheck() const{ return non_refillable ;}
QDate FinanceManager::getDepositStartDate() const { return depositStartDate; }
QDate FinanceManager::getDepositEndDate() const{ return depositEndDate; }
