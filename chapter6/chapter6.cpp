#include <iostream>
#include <cmath> //for exponentiation
void commaOperator();
bool conditionalOperator(int x, int y);

int main() {
  double x{ std::pow(3.0, 4.0) }; // 3^4
  std::cout << x << '\n';

  commaOperator();
  std::cout << conditionalOperator(3,4) << '\n';
  std::cout << conditionalOperator(4,3) << '\n';
  return 0;
}


void commaOperator() {
  //, allows yout o evaluate multiple expressions wherever a single expression is allowed. It evalutes the left operand
  // then the right operand, and then returns the result of the right operand
  int x{ 1 };
  int y{ 2 };
  int z{(++x, ++y)};
  

  std::cout << x << " " << y << " " << z << '\n';
}

bool conditionalOperator(int x, int y) {
  return (x > y) ? true : false;
}