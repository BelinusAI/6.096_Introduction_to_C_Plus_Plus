#include "main.h"

using namespace std;


main(){
    int a[] = {5};
    cout << sum(a, 1);
    return 0;
}

int sum(const int x, const int y, const int z = 0, const int w = 0){
    return x + y + z + w;
}

double sum(const double x, const double y){
    return x + y;
}

int sum(const int numbers[], const int numbersLen){
    return numbersLen == 0 ? 0 : numbers[0] + sum(numbers + 1, numbersLen - 1);
}
