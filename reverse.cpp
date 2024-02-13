#include <iostream>
#include <vector>
#include <list>
#include <iterator>

/**
 * Excercise done for the Abstract Programming course
 * 
 * Reverse function for various collections
 */


template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2)
    {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    my_reverse(v.begin(), v.end());
    for (int n : v) std::cout << n << ' ';
    std::cout << '\n';

    std::list<int> l{1, 2, 3, 4, 5};
    my_reverse(l.begin(), l.end());
    for (auto n : l) std::cout << n << ' ';
    std::cout << '\n';

    int a[] = {1, 2, 3, 4, 5};
    my_reverse(a, a+5);
    for (int i : a) std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}