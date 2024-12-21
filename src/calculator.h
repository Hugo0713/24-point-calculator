#include <vector>
#include <string>

class Calculator
{
public:
    Calculator(const std::vector<int> &numbers);
    bool canCalculate24();
    std::vector<std::string> calculate();
    std::string getExpression();

private:
    std::vector<int> numbers;
    bool tryAllOperations(std::vector<double> &nums, std::string &expression);
    double applyOperation(double a, double b, char op);
    bool evaluate(double result);
    std::string expression;
};