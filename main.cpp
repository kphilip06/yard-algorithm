#include <iostream>

#include "src/calculator.hpp"

int main() {
  Calculator calc;
  calc.evaluate("2+5");
  calc.evaluate("3+6*5");
  calc.evaluate("4*(2+3)");
  calc.evaluate("(7+9)/8");

}
