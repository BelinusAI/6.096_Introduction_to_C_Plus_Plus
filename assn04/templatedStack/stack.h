#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <vector>

using namespace std;

/* templated classes and functions are generally just implemented in the header file */

// A templated forward declaration of the class
template <class T> class Stack ;

// A templated function prototype for the friend function.
template<class T>
Stack<T> operator+(const Stack<T> &s1 , const Stack<T> &s2);

// The full templated class definition, including the friend statement
template <class T>
class Stack{
    friend Stack<T> operator+<>(const Stack<T> &s1 , const Stack<T> &s2);
    vector<T> items;

public:
    bool empty () const{return items.empty () ;}
    void push(const T & item){items.push_back(item);}
    T pop(){
        T last = items.back ();
        items.pop_back();
        return last ;
    }
};

//The operator function definition, if you didn’t include it above
template <class T>
Stack<T> operator +(const Stack<T> &s1 , const Stack<T> &s2){
    Stack<T> result = s1;
    for(unsigned i = 0; i <s1.items.size(); ++i) {
            result.items.push_back(s2.items[i]);
    }
    return result;
}

#endif // STACK_H_INCLUDED
