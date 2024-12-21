#include "calculator.h"
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

Calculator::Calculator(const vector<int> &numbers) : numbers(numbers) {}

bool Calculator::canCalculate24()
{
    if (numbers.size() != 4)
        return false;

    // 将 int 类型的 vector 转换为 double 类型的 vector
    vector<double> nums(numbers.begin(), numbers.end());
    sort(nums.begin(), nums.end());
    do
    {
        // 尝试所有运算符组合
        if (tryAllOperations(nums, expression))
        {
            return true;
        }
    } while (next_permutation(nums.begin(), nums.end()));

    return false;
}

bool Calculator::tryAllOperations(vector<double> &nums, string &expression)
{
    const vector<char> ops = {'+', '-', '*', '/'};

    for (char op1 : ops)
    {
        for (char op2 : ops)
        {
            for (char op3 : ops)
            {
                // 尝试所有运算符的排列组合和括号组合
                if (evaluate(applyOperation(applyOperation(applyOperation(nums[0], nums[1], op1), nums[2], op2), nums[3], op3)))
                {
                    stringstream ss;
                    ss << "(" << "(" << nums[0] << " " << op1 << " " << nums[1] << ")" << " " << op2 << " " << nums[2] << ")" << " " << op3 << " " << nums[3];
                    expression = ss.str();
                    return true;
                }
                if (evaluate(applyOperation(applyOperation(nums[0], applyOperation(nums[1], nums[2], op2), op1), nums[3], op3)))
                {
                    stringstream ss;
                    ss << "(" << nums[0] << " " << op1 << " " << "(" << nums[1] << " " << op2 << " " << nums[2] << ")" << ")" << " " << op3 << " " << nums[3];
                    expression = ss.str();
                    return true;
                }
                if (evaluate(applyOperation(nums[0], applyOperation(applyOperation(nums[1], nums[2], op2), nums[3], op3), op1)))
                {
                    stringstream ss;
                    ss << nums[0] << " " << op1 << " " << "(" << "(" << nums[1] << " " << op2 << " " << nums[2] << ")" << " " << op3 << " " << nums[3] << ")";
                    expression = ss.str();
                    return true;
                }
                if (evaluate(applyOperation(nums[0], applyOperation(nums[1], applyOperation(nums[2], nums[3], op3), op2), op1)))
                {
                    stringstream ss;
                    ss << nums[0] << " " << op1 << " " << "(" << nums[1] << " " << op2 << " " << "(" << nums[2] << " " << op3 << " " << nums[3] << ")" << ")";
                    expression = ss.str();
                    return true;
                }
                if (evaluate(applyOperation(applyOperation(nums[0], nums[1], op1), applyOperation(nums[2], nums[3], op3), op2)))
                {
                    stringstream ss;
                    ss << "(" << nums[0] << " " << op1 << " " << nums[1] << ")" << " " << op2 << " " << "(" << nums[2] << " " << op3 << " " << nums[3] << ")";
                    expression = ss.str();
                    return true;
                }
            }
        }
    }

    return false;
}

bool Calculator::evaluate(double result)
{
    return abs(result - 24.0) < 1e-6;
}

double Calculator::applyOperation(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return (b != 0) ? a / b : NAN; // 避免除以零
    default:
        return NAN;
    }
}

vector<string> Calculator::calculate()
{
    vector<string> result;
    if (canCalculate24())
    {
        result.push_back("+");
    }
    else
    {
        result.push_back("-");
    }
    for (int num : numbers)
    {
        result.push_back(to_string(num));
    }
    return result;
}

string Calculator::getExpression()
{
    return expression;
}