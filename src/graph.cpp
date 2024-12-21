#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <vector>
#include <string>
#include "calculator.h"

using namespace std;

class CalculatorGUI
{
public:
    CalculatorGUI()
    {
        window = new Fl_Window(400, 300, "24 Point Calculator");

        input1 = new Fl_Input(50, 50, 50, 30, "Card 1:");
        input2 = new Fl_Input(150, 50, 50, 30, "Card 2:");
        input3 = new Fl_Input(250, 50, 50, 30, "Card 3:");
        input4 = new Fl_Input(350, 50, 50, 30, "Card 4:");

        calculateButton = new Fl_Button(150, 100, 100, 30, "Calculate");
        calculateButton->callback(CalculateCallback, this);

        resultOutput = new Fl_Output(150, 150, 200, 30, "Result:");

        window->end();
        window->show();
    }

    static void CalculateCallback(Fl_Widget *widget, void *data)
    {
        CalculatorGUI *gui = (CalculatorGUI *)data;
        gui->Calculate();
    }

    void Calculate()
    {
        vector<int> numbers;
        numbers.push_back(cardToValue(input1->value()));
        numbers.push_back(cardToValue(input2->value()));
        numbers.push_back(cardToValue(input3->value()));
        numbers.push_back(cardToValue(input4->value()));

        Calculator calculator(numbers);
        if (calculator.canCalculate24())
        {
            resultOutput->value(calculator.getExpression().c_str());
        }
        else
        {
            resultOutput->value("Fail");
        }
    }

    int cardToValue(const string &card)
    {
        if (card == "J")
            return 11;
        if (card == "Q")
            return 12;
        if (card == "K")
            return 13;
        if (card == "A")
            return 1;
        return stoi(card);
    }

private:
    Fl_Window *window;
    Fl_Input *input1;
    Fl_Input *input2;
    Fl_Input *input3;
    Fl_Input *input4;
    Fl_Button *calculateButton;
    Fl_Output *resultOutput;
};

int main(int argc, char **argv)
{
    CalculatorGUI gui;
    return Fl::run();
}