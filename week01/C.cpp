#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x;
    cin >> x;
    int result = 1;
    for (int i = 1; i < x + 1; i++) {
        result *= i;
    }
    cout << result << endl;
    return 0;
}