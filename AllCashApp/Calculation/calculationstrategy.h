#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

class CalculationStrategy {
public:
  virtual double calculate(double principal, double annualRate,
                           int termMonths) = 0;
  virtual ~CalculationStrategy() = default;
};

#endif // CALCULATIONSTRATEGY_H
