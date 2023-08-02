#include <iostream>
#include "main.h"

using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};

    reverseArray(a, 5);
    printArray(a, 5);

    return 0;
}

void printArray(const int integerArray[], const int len){
    cout << integerArray[0];
    for(int i = 1; i < len; i++){
        cout << ", " << integerArray[i];
    }
}

void reverseArray(int integerArray[], const int len){
    for(int i = 0; i <= len / 2; i++){
        int aux = *(integerArray + i);
        *(integerArray + i) = *(integerArray + len - 1 - i);
        *(integerArray + len - 1 - i) = aux;
    }
}

void transpose (const int input [][LENGTH], int output [][WIDTH]){
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < LENGTH; j++){
            output[j][i] = input[i][j];
        }
    }
}

