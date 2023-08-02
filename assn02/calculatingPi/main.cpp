#include <iostream>
#include <cmath>
#include <ctime>
#include "main.h"

using namespace std;

int main(){
    cout << "Pi = " << computePi(5000000);
    return 0;
}

bool isInside(const double x, const double y){
    return sqrt(x*x + y*y < 1);
}

double computePi(int n){
    srand(time(0));

    int dartsInCircle = 0;
    for(int i = 0; i < n; i++){
        double x = rand() / (double)RAND_MAX, y = rand() / (double)RAND_MAX;
        if(isInside(x, y))
            dartsInCircle++;
    }

    return (4 * dartsInCircle) / (double)n;
}

