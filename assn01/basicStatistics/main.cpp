# include <iostream >

using namespace std;

int main(){
    int N, maxVal, minVal, range, input;
    float mean = 0;

    cout << "Enter N : ";
    cin >> N;

    cin >> input;
    mean += input;
    maxVal = input;
    minVal = input;

    for(int i = 1; i < N; i++){
        cin >> input;
        mean += input;

        if(input >= maxVal)
            maxVal = input;
        else if(input <= minVal)
            minVal = input;
    }

    mean = mean / N;
    range = maxVal - minVal;

    cout << "Mean: " << mean << "\n";
    cout << "Max: " << maxVal << "\n";
    cout << "Min: " << minVal << "\n";
    cout << "Range: " << range << "\n";



    return 0;
}
