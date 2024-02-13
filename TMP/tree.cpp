#include <iostream>

/* 
Excercise done for the Abstract Programming course

Program draws christmas tree using Template Meta Programming
*/

template<int I, char c>
class print_n_char {
private:
    enum { go = (I - 1) != 0 };

public:
    static inline void f()
    {
        std::cout << c;
        print_n_char<go ? (I-1) : 0, c>::f();
    }
};

// Specialization provides base case for
// recursion
template<char c>
class print_n_char<0, c> {
public:
    static inline void f()
    { }
};

template<bool C, int N, int S>
class if_ { };

template<int N, int S>
class if_<true, N, S> {
public:
    static inline void f()
    { std::cout << std::endl << std::endl; }         // true case
};

template<int N, int S>
class if_<false, N, S> {
public:
    static inline void f()
    { 
        print_n_char<S, ' '>::f();
        print_n_char<N, '*'>::f();
        print_n_char<S, ' '>::f();
    }         // false case
};

template<int N, int I>
class ChristmasTreeDraw {
public:
    static inline void f()
    {
        if_<I % 2 == 0, I, (N - I) / 2>::f();
        ChristmasTreeDraw<N, I + 1>::f();
    }
};

// Specialization provides base case for
// recursion
template<int N>
class ChristmasTreeDraw<N, N> {
public:
    static inline void f()
    { print_n_char<N, '*'>::f(); }
};

template<int I>
class ChristmasTree {
public:
    static inline void print()
    {
        ChristmasTreeDraw<I, 0>::f();
    }
};

int main()
{
    const int lowestLevelWidth = 9;
    ChristmasTree<lowestLevelWidth>::print();
    return 0;
}

/* Expected output:
    *
    
   ***
   
  *****
  
 *******
 
*********

*/