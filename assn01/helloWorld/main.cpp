# include <iostream >

using namespace std;


int main (){

    // Hello World I
    const char* var = "Hello world!";
    cout << var << "\n";

    // Hello World II
    int n;

    cin >> n;
    for(; n-- > 0;)
        cout << var << "\n";

    cin >> n;
    while(n-- > 0){
        cout << var << "\n";
    }

    cin >> n;
    do{
        cout << var << "\n";
    } while(--n > 0);

    return 0;
}
