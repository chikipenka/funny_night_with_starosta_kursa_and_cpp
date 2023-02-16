#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x = 1;
    cin >> x;
    while (x % 2 == 0){
        x /= 2;
    }
    if (x == 1){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
