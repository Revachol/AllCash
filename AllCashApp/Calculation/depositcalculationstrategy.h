#ifndef DEPOSITCALCULATIONSTRATEGY_H
#define DEPOSITCALCULATIONSTRATEGY_H

#include "calculationstrategy.h"
#include <cmath>

class DepositCalculationStrategy : public CalculationStrategy {
public:
    double calculate(double initialAmount, double annualRate, int termMonths) override {
        double monthlyRate = annualRate / 12 / 100;
        return initialAmount * pow(1 + monthlyRate, termMonths);
    }
};

#endif // DEPOSITCALCULATIONSTRATEGY_H
