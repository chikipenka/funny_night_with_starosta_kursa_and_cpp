#include <iostream>

using namespace std;

int fibonacci(int i){
    if (i > 1){
        return fibonacci(i - 1) + fibonacci(i-2);
    }
    else {
        return 1;
    }
}

int main(){
    int i;
    cin >> i;
    cout << fibonacci(i) << endl;
    return 0;
}