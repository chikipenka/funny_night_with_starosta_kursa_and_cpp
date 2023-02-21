#include <iostream>

using namespace std;

int recursive_factorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * recursive_factorial(n - 1);
    }
}

int main(){
    int n;
    cin >> n;
    cout << recursive_factorial(n) << endl;
    return 0;
}