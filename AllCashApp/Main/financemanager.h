#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <QDate>
#include <QObject>
#include <QString>

class FinanceManager : public QObject {
  Q_OBJECT

 public:
  static FinanceManager &getInstance();

  QString getAccountNumber() const;
  void setAccountNumber(const QString &value);

  QString getAccountHolderName() const;
  void setAccountHolderName(const QString &value);

  double getAccountBalance() const;
  void setAccountBalance(double value);

  QString getAccountType() const;
  void setAccountType(const QString &value);

  QDate getOpeningDate() const;
  void setOpeningDate(const QDate &value);

  QString getCurrency() const;
  void setCurrency(const QString &value);

  //Кредит
  bool isCreditOpened() const;
  void setCreditOpened(bool value);

  long long int getCreditAmount() const;
  void setCreditAmount(long long int value);

  double getInterestRate() const;
  void setInterestRate(double value);

  int getCreditTerm() const;
  void setCreditTerm(int value);

  QDate getCreditStartDate() const;
  void setCreditStartDate(const QDate &value);

  QDate getCreditEndDate() const;
  void setCreditEndDate(const QDate &value);

  double getMonthlyPayment() const;
  void setMonthlyPayment(double value);

  //Депозит
  bool isDepositOpened() const;
  void setDepositOpened(bool value);

  long long int getDepositSum() const;
  void setDepositSum(long long int value);

  double getDepositRate() const;
  void setDepositRate(double value);

  int getDepositTerm() const;
  void setDepositTerm(int value);

  bool getDepositCheck() const;
  void setDepositCheck(bool value);

  QDate getDepositStartDate() const;
  void setDepositStartDate(const QDate &value);

  QDate getDepositEndDate() const;
  void setDepositEndDate(const QDate &value);

  double getTotalSum() const;
  void setTotalSum(double value);

 signals:
  void dataChanged();

 private:
  FinanceManager();
  FinanceManager(const FinanceManager &) = delete;
  FinanceManager &operator=(const FinanceManager &) = delete;

  // Данные счета
  QString accountNumber;
  QString accountHolderName;
  double accountBalance;
  QString accountType;
  QDate openingDate;
  QString currency;
  bool creditOpened;
  bool depositOpened;

  // Данные кредита
  long long int creditAmount;
  double interestRate;
  int term;
  QDate startDate;
  QDate endDate;
  double MonthPayment;

  //Данные вклада
  long long int depositSum;
  double depositRate;
  int depositTerm;
  bool non_refillable;
  QDate depositStartDate;
  QDate depositEndDate;
  double depositTotal;
};

#endif  // FINANCEMANAGER_H
