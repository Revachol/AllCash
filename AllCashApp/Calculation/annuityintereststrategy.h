#ifndef ANNUITYINTERESTSTRATEGY_H
#define ANNUITYINTERESTSTRATEGY_H

#include <cmath>

#include "calculationstrategy.h"

class AnnuityInterestStrategy : public CalculationStrategy {
 public:
  double calculate(double loanAmount, double annualRate,
                   int termMonths) override {
    double monthlyRate = annualRate / 12 / 100;
    return (loanAmount * monthlyRate) / (1 - pow(1 + monthlyRate, -termMonths));
  }
};

#endif  // ANNUITYINTERESTSTRATEGY_H
