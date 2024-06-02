#include "financemanager.h"

FinanceManager &FinanceManager::getInstance() {
  static FinanceManager instance;
  return instance;
}

FinanceManager::FinanceManager()
    : accountBalance(0.0),
      creditOpened(false),
      depositOpened(false),
      creditAmount(0.0),
      interestRate(0.0),
      term(0) {}

// Методы для управления счетами
QString FinanceManager::getAccountNumber() const { return accountNumber; }
void FinanceManager::setAccountNumber(const QString &value) {
  accountNumber = value;
  emit dataChanged();
}

QString FinanceManager::getAccountHolderName() const {
  return accountHolderName;
}
void FinanceManager::setAccountHolderName(const QString &value) {
  accountHolderName = value;
  emit dataChanged();
}

double FinanceManager::getAccountBalance() const { return accountBalance; }
void FinanceManager::setAccountBalance(double value) {
  accountBalance = value;
  emit dataChanged();
}

QString FinanceManager::getAccountType() const { return accountType; }
void FinanceManager::setAccountType(const QString &value) {
  accountType = value;
  emit dataChanged();
}

QDate FinanceManager::getOpeningDate() const { return openingDate; }
void FinanceManager::setOpeningDate(const QDate &value) {
  openingDate = value;
  emit dataChanged();
}

QString FinanceManager::getCurrency() const { return currency; }
void FinanceManager::setCurrency(const QString &value) {
  currency = value;
  emit dataChanged();
}

//Кредит
bool FinanceManager::isCreditOpened() const { return creditOpened; }
void FinanceManager::setCreditOpened(bool value) {
  creditOpened = value;
  emit dataChanged();
}

long long int FinanceManager::getCreditAmount() const { return creditAmount; }
void FinanceManager::setCreditAmount(long long int value) {
  creditAmount = value;
  emit dataChanged();
}

double FinanceManager::getInterestRate() const { return interestRate; }
void FinanceManager::setInterestRate(double value) {
  interestRate = value;
  emit dataChanged();
}

int FinanceManager::getCreditTerm() const { return term; }
void FinanceManager::setCreditTerm(int value) {
  term = value;
  emit dataChanged();
}

QDate FinanceManager::getCreditStartDate() const { return startDate; }
void FinanceManager::setCreditStartDate(const QDate &value) {
  startDate = value;
  emit dataChanged();
}

QDate FinanceManager::getCreditEndDate() const { return endDate; }
void FinanceManager::setCreditEndDate(const QDate &value) {
  endDate = value;
  emit dataChanged();
}

double FinanceManager::getMonthlyPayment() const { return MonthPayment; }
void FinanceManager::setMonthlyPayment(double value) {
  MonthPayment = value;
  emit dataChanged();
}

//Депозит
bool FinanceManager::isDepositOpened() const { return depositOpened; }
void FinanceManager::setDepositOpened(bool value) {
  depositOpened = value;
  emit dataChanged();
}

long long int FinanceManager::getDepositSum() const { return depositSum; }
void FinanceManager::setDepositSum(long long int value) {
  depositSum = value;
  emit dataChanged();
}

double FinanceManager::getDepositRate() const { return depositRate; }
void FinanceManager::setDepositRate(double value) {
  depositRate = value;
  emit dataChanged();
}

int FinanceManager::getDepositTerm() const { return depositTerm; }
void FinanceManager::setDepositTerm(int value) {
  depositTerm = value;
  emit dataChanged();
}

bool FinanceManager::getDepositCheck() const { return non_refillable; }
void FinanceManager::setDepositCheck(bool value) {
  non_refillable = value;
  emit dataChanged();
}

QDate FinanceManager::getDepositStartDate() const { return depositStartDate; }
void FinanceManager::setDepositStartDate(const QDate &value) {
  depositStartDate = value;
  emit dataChanged();
}

QDate FinanceManager::getDepositEndDate() const { return depositEndDate; }
void FinanceManager::setDepositEndDate(const QDate &value) {
  depositEndDate = value;
  emit dataChanged();
}

double FinanceManager::getTotalSum() const { return depositTotal; }
void FinanceManager::setTotalSum(double value) {
  depositTotal = value;
  emit dataChanged();
}
