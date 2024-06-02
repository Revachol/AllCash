#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include "../Account/account.h"
#include "../Credit/credits.h"
#include "../Credit/opencredit.h"
#include "../Deposit/deposit.h"
#include "../Deposit/opendeposit.h"
#include "viewfactory.h"

class FactoryMethod : public ViewFactory {
 public:
  Account *createAccount(QWidget *parent) override {
    return new Account(parent);
  }

  Credits *createCredits(QWidget *parent) override {
    return new Credits(parent);
  }

  OpenCredit *createOpenCredit(QWidget *parent) override {
    return new OpenCredit(parent);
  }

  Deposit *createDeposit(QWidget *parent) override {
    return new Deposit(parent);
  }

  OpenDeposit *createOpenDeposit(QWidget *parent) override {
    return new OpenDeposit(parent);
  }
};

#endif  // FACTORYMETHOD_H
