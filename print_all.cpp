#include<iostream>

/***
 * Excercise done for the Abstract Programming course
  * Implementation of print_all(...) function with variadic templates
 ***/
 

void print_all(std::ostream& os) {
}

template<typename T, typename... Args>
void print_all(std::ostream& os, T a, Args... args) {
    os << a << " ";
    print_all(os, args...);
    // ((os << args), ...);
}

int main() {
    print_all(std::cout, 4, 5.8f, "str", 1.8, 3, 1.1, 9);
    return 0;
}