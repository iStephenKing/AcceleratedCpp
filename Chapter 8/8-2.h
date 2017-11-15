#ifndef GUARD_8_2_H
#define GUARD_8_2_H
/*
    8-2.h

    Implement custom (and likely more basic) version STL functions

    Stephen King
    11/13/17
*/


template<class InputIterator1, class InputIterator2>
bool c_equal(InputIterator1 b, InputIterator1 e, InputIterator2 d)
{
    while (!(b == e))
        if (!(*b++ == *d++))
            return false;
    return true;
}

template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 b, ForwardIterator1 e, ForwardIterator2 b2, ForwardIterator2 e2)
{
    
    while (++b != e) {
        ForwardIterator1 check1 = b;
        ForwardIterator2 check2 = b2;
        while (*(++check1) == *(++check2))
        {
            if (check2 == e2)
                return b;
            if (check1 == e)
                return e;
        }
    }
    return e;
}

template <class T>
void c_swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template <class Bi>
void c_reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
    
            c_swap(*begin++, *end);
        
    }
}



#endif