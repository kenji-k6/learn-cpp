#include <iostream>
void chap1_5();

int main() {
  int x{ 1 };
  double y{ 0.3 };
  [[maybe_unused]] double z{ 0.590213 };


  std::cout << x << y << std::endl;

  chap1_5();

  return 0;
}

void chap1_5() {
  int x{};

  std::cin >> x;

  std::cout << "You entered: " << x << "\n";
}