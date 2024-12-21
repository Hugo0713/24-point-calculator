#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "calculator.h"

void processInput(const std::vector<int> &numbers)
{
    Calculator calculator(numbers);
    if (calculator.canCalculate24())
    {
        std::vector<std::string> result = calculator.calculate();
        for (const std::string &res : result)
        {
            std::cout << res << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}

int cardToValue(const std::string &card)
{
    if (card == "J")
    {
        return 11;
    }
    else if (card == "Q")
    {
        return 12;
    }
    else if (card == "K")
    {
        return 13;
    }
    else if (card == "A")
    {
        return 1;
    }
    else
    {
        return std::stoi(card);
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        // 命令行输入
        std::vector<int> numbers;
        for (int i = 1; i < argc; ++i)
        {
            numbers.push_back(cardToValue(argv[i]));
        }
        if (numbers.size() == 4)
        {
            processInput(numbers);
        }
        else
        {
            std::cerr << "请提供四个数字。" << std::endl;
        }
    }
    else
    {
        // 文件输入
        std::ifstream inputFile("../input.txt"); // 使用相对路径
        if (!inputFile)
        {
            std::cerr << "无法打开文件。" << std::endl;
            return 1;
        }

        std::ofstream outputFile("../output.txt");
        if (!outputFile)
        {
            std::cerr << "无法创建输出文件。" << std::endl;
            return 1;
        }

        std::string line;
        int total = 0;
        int success = 0;
        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            std::vector<std::string> cards(4);
            for (int i = 0; i < 4; ++i)
            {
                iss >> cards[i];
            }

            std::vector<int> numbers;
            for (const std::string &card : cards)
            {
                numbers.push_back(cardToValue(card));
            }

            Calculator calculator(numbers);
            if (calculator.canCalculate24())
            {
                outputFile << "+\t";
                ++success;
            }
            else
            {
                outputFile << "-\t";
            }
            ++total;

            for (const std::string &card : cards)
            {
                outputFile << card << "\t";
            }
            outputFile << std::endl;
        }

        outputFile << success << "/" << total << std::endl;
    }

    return 0;
}