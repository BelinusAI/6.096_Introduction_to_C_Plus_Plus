#include <iostream>
#include "main.h"

using namespace std;

int main(){
    char *a = "Hola mundo!";
    cout << lenString(a) << '\n';

    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    swaps(&ptr1, &ptr2);
    cout << *ptr1 << " " << *ptr2 << '\n';

    /* 7.5 */
    char *oddOrEven = "Never odd or even";
    //Create a pointer to a char value named nthCharPtr pointing to the 6th character of oddOrEven
    char *nthCharPtr = oddOrEven + 6;
    //Using pointer arithmetic, update nthCharPtr to point to the 4th character in oddOrEven
    nthCharPtr-=2;
    //Print the value currently pointed to by nthCharPtr
    cout << *nthCharPtr << '\n';
    //Create a new pointer to a pointer (a char **) named pointerPtr that points to nthCharPtr.
    char **pointerPtr = &nthCharPtr;
    //Print the value stored in pointerPtr
    cout << pointerPtr;
    //Using pointerPtr, print the value pointed to by nthCharPtr
    cout << **pointerPtr << '\n';
    // Update nthCharPtr to point to the next character in oddOrEven
    nthCharPtr++;
    cout << nthCharPtr - oddOrEven;

    return 0;
}

int lenString(char *str){
    int len = 0;
    while(*(str) != '\0'){
        len++;
        str++;
    }
    return len;
}

void swaps(int **x, int **y){
    int *aux = *x;
    *x = *y;
    *y = aux;
}
