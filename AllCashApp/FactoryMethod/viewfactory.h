#ifndef VIEWFACTORY_H
#define VIEWFACTORY_H

#include <QWidget>

class ViewFactory {
public:
  virtual Account *createAccount(QWidget *parent) = 0;
  virtual Credits *createCredits(QWidget *parent) = 0;
  virtual OpenCredit *createOpenCredit(QWidget *parent) = 0;
  virtual Deposit *createDeposit(QWidget *parent) = 0;
  virtual OpenDeposit *createOpenDeposit(QWidget *parent) = 0;
  virtual ~ViewFactory() = default;
};

#endif // VIEWFACTORY_H
