#include <iostream>
void chap1_5();
void chap1_6();
void chap1_11();
void hiWorld();

int main() {
  int x{ 1 };
  double y{ 0.3 };
  [[maybe_unused]] double z{ 0.590213 };


  std::cout << x << y << std::endl;
  hiWorld();
  chap1_5();
  chap1_6();
  chap1_11();
  return 0;
}

void chap1_5() {
  int x{};

  std::cin >> x;

  std::cout << "You entered: " << x << "\n";
}

void chap1_6() {
  int x{};

  std::cout << x << "\n" << "------------" << "\n";

}



void chap1_11() {
  int x{ };

  std::cout << "Entern an integer: ";
  std::cin >> x;
  std::cout << "Double that number is: " << 2*x << "\n";
  
}