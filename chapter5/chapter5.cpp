#include <iostream>
#include <format>
#include <bitset>
// #include <print>
#include <string>

void numeralSystems();
void constVsConstExpr();
constexpr int cmax(int x, int y);
void strings();
void quiz5_7_1();
void string_view();

int main() {
  // x is a non-constant variable
  int x { 4 };

  x = 3;

  // constant variable, type of gravity is const double
  const double gravity { 9.8 };

  // const variables can be intialized from other variables
  // even non-const ones
  const int const_x { x };

  x = 5;

  // general convention:
  // const variables in C: uppercase, underscored, e.g.
  const double EARTH_GRAVITY { 9.8 };

  //convention in c: camelCase, "k" prefixx
  const double kEarthGravity { 9.8 };

  std::cout << gravity << " " << const_x << " " << EARTH_GRAVITY << " " << kEarthGravity << '\n';

  //best practice: don't use const for value parameters



  std::cout << 5.0 << '\n'; // no suffix is type double (by default)
  std::cout << 5.0f << '\n'; // 5.0f is type float

  double avogardo { 6.02e23 }; // 6.02 x 10^23 is a double

  std::cout << avogardo << '\n';

  numeralSystems();
  std::cout << '\n' << '\n';
  constVsConstExpr();
  std::cout << '\n' << '\n';
  strings();
  quiz5_7_1();
  string_view();
  return 0;
}

// a function's return value may also be made const
// best practice: don't use const when returning by value
// prefer constant variables over object-like macros with substitution text
#if 0
const int getValue() {
  const int x { 5 };
  return x;
}
#endif


void numeralSystems() {
  int o{ 012 }; // 0 before the number means this is octal
  std::cout << "Octal: " << o << '\n';

  int h{ 0xF}; // 0x before the number means this is hexadecimal
  std::cout << "Hexadecimal: " << h << '\n';

  int b{ 0b1010 }; // assign binary 0000 0000 0000 1010 to the variable
  std::cout << "Binary: " << b << '\n';

  // for ease of reading, we are allowed to use ' as digit seperator
  // it's not allowed to place the seperator before the 1st digit
  // e.g. 0b'1000 is not allowed
  long value{ 2'132'673'462 };
  std::cout << "Seperated: " << value << '\n' << '\n';

  // Outputting values in decimal, octal, hexadecimal
  int x{ 12 };
  std::cout << "Decimal (default): " << x << '\n';
  std::cout << std::hex << "Hexadecimal: " << x << '\n';
  std::cout << std::oct << "Octal: " << x << '\n';
  std::cout << std::dec << "Switch back to decimal: " << x << '\n';


  // Printing binaries is more difficult, C++ provides std::bitset
  // We have to define a std::bitset variable and tell bitset how many bits we want to store
  // can be initialized with an integral value in any format
  std::bitset<8> bin1{ 0b1100'0101 }; // binary literal
  std::cout << "With bitset: " << bin1 << '\n';
  
  std::cout << std::format("{:b}\n", x); // C++20, prints number as binary digit
  std::cout << std::format("{:#b}\n", x); //prefixes 0b

  // std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, 


}

void constVsConstExpr() {
  // constexpr are always compile-time constants
  constexpr double gravity{ 9.8 }; // ok, 9.8 is a constant expression

  const int x{ 3 };
  constexpr int expr_x{ x };

  #if 0
  int y{ 4 };
  constexpr int expr_y{ y }; // gives a compile-time error
  #endif
  /*
   * const means the value of an object cannot be changed after initialization.
   * The value of the initializer may be known at compile-time or runtime.
   * The const object cant be evaluated at runtime
   * 
   * constexpr means that the object can be used in a constant expression.
   * The value of the initializer must be known at compile-time.
   * The constexpr object can be evaluated at runtime or compile-time
   * 
   * !!! const function parameters are treated as *runtime* constants,
   * even when the supplied argument is a compile-time constant
   * 
   * !!! Function cannot be declared as constexpr, since their
   * initialization value isn't determined until runtime
  */

  std::cout << gravity << " " << expr_x << " " << '\n';


  const int f1{ cmax(3,2) };
  const int f2{ cmax(3,2) };

  #if 0
  constexpr int f3{ cmax(3, x) }; // not a constant expression
  int y {2};
  constexpr int f4 { cmax(y, 10) };
  #endif

  std::cout << f1 << " " << f2 << '\n';
}

// Constant expression functions

/* A constexpr function is a function that can be called in a constant expression.
 * A constexpr function must evaluate at compile-time when the constant expression
 * it is part of must evaluate at compile time.
*/
constexpr int cmax(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}




void strings() {
  std::string empty {}; // empty string
  std::cout << "Empty: \"" << empty << "\"\n";

  std::string name { "Alex" }; // initialize with alex
  std::cout << "Name: \"" << name << "\"\n";
  // std string can handle strings of different lengths!
  name = "Jonathan";
  std::cout << "Name: \"" << name << "\"\n";




  // std::cin breaks on whitspace =>
  // use std::getline to input text
  // std::ws ignores leading whitespace
  std::cout << "Enter your full name: ";
  std::string name_in {};
  std::getline(std::cin >> std::ws, name_in);

  std::cout << "Enter your favorite color: ";
  std::string color_in {};
  std::getline(std::cin >> std::ws, color_in);
  std::cout << "Your name is " << name_in << " and your favorite color is " << color_in << '\n';

  // length of a string:

  std::cout << name << " has length: " << name.length() << '\n';
  // returns unsigned integral type, usually size_t, need to cast to int to prevent warning
  int length_name { static_cast<int>(name.length()) };
  std::cout << "name length variable: " << length_name << '\n';

  // DO NOT pass std::string by value, as it makes an expensive copy
  // in most cases, use a std::string_view parameter instead

  using namespace std::string_literals;
  std::cout << "foo\n"; //no suffix is a C-style string literal
  std::cout << "goo\n"s; //s suffix is a std::string literal
}

void quiz5_7_1() {
  std::cout << "Enter your full name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);

  std::cout << "Enter your age: ";
  int age{};
  std::cin >> age;

  std::cout << "Your age + length of name is: " << age + static_cast<int>(name.length()) << '\n';
}





void printSV(std::string_view str) {
  std::cout << str << '\n';
}

std::string getName() {
  using namespace std::string_literals;
  return "Alex"s;
}

void string_view() {
  std::string s {"Hello, World!"}; // s makes a copy of its initializer, SLOW!!
  std::cout << s << '\n'; // copy created => printed => destroyed
  /*
   * std::string_view provides read-only access to an existing string,
   * (a C-style string, a std::string, or another std::string_view) without
   * making a copy.
  */

 std::string_view sv{ "Hello, world!" };
 std::cout << sv << '\n'; // no copy created

printSV("Hello C-style"); // implicitly converted
std::string s1 {"Hello String"};
printSV(s1); // implicitly converted
std::string_view s3 {"Hello String View"};
printSV(s3);

// other direction doesn't work, i.e. string_view is
// not automatically converted to string
using namespace std::string_literals;
using namespace std::string_view_literals;

std::cout << "foo\n"; // no suffix => C-style string literal
std::cout << "goo\n"s; // s suffix => std::string literal
std::cout << "moo\n"sv; // sv suffix => std::string_view literal

std::string_view x1 {s1};
std::cout << "String: \"" << s1 << "\" View: \"" << x1 << "\"\n";
s1 = "Edited";
std::cout << "String: \"" << s1 << "\" View: \"" << x1 << "\"\n"; // undefined

std::string_view return_name { getName() }; //name initialized with return of fucn
std::cout << return_name << '\n'; //undefined behavior, since return values are temporary object

// !!! DO NOT INITIALIZE A STRING_VIEW WITH A STRING LITERAL
// !!! ONLY USE C-STRING LITERALS, STRING_VIEW LITERAL,
// !!! OR A STRING/STRING_VIEW/C-STYLE STRING OBJECT

std::string_view str{ "Peach" };
std::cout << str << '\n';

//Remove 1 char from left side of view
str.remove_prefix(1);
std::cout << str << '\n';

//Remove 2 chars from the right side of view
str.remove_suffix(2);
std::cout << str << '\n';

str = "Peach"; // reset the view
std::cout << str << '\n';

// !!! string_view can view a substring
// !!! string_view may or may not be null-terminated
}


