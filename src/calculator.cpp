#include <iostream>
#include <stack>
#include <cctype>

#include "calculator.hpp"

std::string Calculator::inToPost(std::stack<char>& ops, const std::string& input) {
    std::string output;

    for ( char c : input) {
        bool order = true;
        if (std::isdigit(c)) {
            output += c;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output += ops.top();
                ops.pop();
            }
            if (!ops.empty()) {
                ops.pop();
            }
        }
        else {
            while (order) {
                if (ops.empty() || ops.top() == '(') {
                    ops.push(c);
                    order = false;
                }
                else if ((c == 42 || c == 47) && (ops.top() == 43 || ops.top() == 45)) {
                    ops.push(c);
                    order = false;
                } else if ((( c == 42 || c == 47) && (ops.top() == 43 || ops.top() == 45)) || (c == 43 || c == 45) && (ops.top() == 42 || ops.top() == 47)) {
                    output += ops.top();
                    ops.pop();
                } else {
                    ops.push(c);
                    order = false;
                }
            }
        }
    }

    while (!ops.empty()) {
        output += ops.top();
        ops.pop();
    }

    return output;
}

double Calculator::postToDouble(const std::string& output) {
    std::stack<double> values;

    for (char c : output) {
        if (std::isdigit(c)) {
            values.push(c - '0');
        } else {
            double operand2 = values.top(); values.pop();
            double operand1 = values.top(); values.pop();

            switch (c) {
                case '+': values.push(operand1 + operand2); break;
                case '-': values.push(operand1 - operand2); break;
                case '*': values.push(operand1 * operand2); break;
                case '/': values.push(operand1 / operand2); break;
            }
        }
    }

    return values.top();
}

void Calculator::evaluate(const std::string& input) {
    std::stack<char> ops;

    std::string postfix = inToPost(ops, input);

    std::cout << postToDouble(postfix) << std::endl;
}
