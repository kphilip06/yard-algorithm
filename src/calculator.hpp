#pragma once

#include <iostream>
#include <stack>


class Calculator {
private:
public:
    std::string inToPost(std::stack<char>& ops, const std::string& input);
    double postToDouble(const std::string& output);
    void evaluate(const std::string& input);
};
