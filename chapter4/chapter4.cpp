#include <iostream>
#include <cstdint> // for fixed-width integers
#include <cstddef> // for std::size_t
#include <iomanip> // for output manipulator std::setprecision()
void print(double x);
void print_int(int x);


int main() {
  char c = 1;
  int x = 4;
  double y = 129.0123;

  std::cout << "Size char: " << sizeof(c) << "\nSize int: " << sizeof(x) << "\nSize double: " << sizeof(y) << "\n\n";
  

  std::int32_t z { 32767 };
  z += 1;
  std::cout << z << "\n";

  std::int8_t q { 64 }; // behaves like a char


  std::int_fast32_t r{ 156 }; // fastest signed integer type thats at least 32-bits

  std::uint_least32_t s{ 12 }; //smallest unsigned integer type thats at least 32-bits

  std::cout << q << " " << r << " " << s << "\n";

  // truncating to 6 digits
  std::cout << 9.87654321f << '\n';
  std::cout << 987.654321f << '\n';
  std::cout << 987654.321f << '\n';
  std::cout << 9876543.21f << '\n';
  std::cout << 0.0000987654321f << '\n';

  std::cout << std::setprecision(17); // show 17 digits of precision
  std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
  std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

  double zero { 0.0 };
  double posinf { 5.0 / zero }; // positive infinity
  std::cout << posinf << '\n';
  double neginf { -5.0 / zero }; // negative infinity
  std::cout << neginf << '\n';
  double z1 { 0.0 / posinf }; // positive zero
  std::cout << z1 << '\n';
  double z2 { -0.0 / posinf }; // negative zero
  std::cout << z2 << '\n';
  double nan { zero / zero }; // not a number (mathematically invalid)
  std::cout << nan << '\n';

  //booleans 
  std::cout << true << '\n'; // true evaluates to 1
  std::cout << !true << '\n'; // !true evaluates to 0
  bool b {false};
  std::cout << b << '\n'; // b is false, which evaluates to 0
  std::cout << !b << '\n'; // !b is true, which evaluates to 1


  std::cout << std::boolalpha; // print bools as true or false
  std::cout << true << '\n';
  std::cout << false << '\n';

  print(5); //implicit type cnversion
  int test_x { 5 };
  print(test_x);

  print_int(5.5);


  // explicit type conversion: static_cast
  // static_cast<new_type>(expression)
  double test_double{ 5.5 };
  print(test_double);
  print(static_cast<int>(test_double));

  char ch{ 97 };

  std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

  int signed_x = -1;

  std::cout << signed_x << " in unsigned is: " << static_cast<std::uint32_t>(signed_x) << '\n';

  return 0;
}




void print(double x) {
  std::cout << x << '\n';
}

void print_int(int x) {
  std::cout << x << '\n';
}