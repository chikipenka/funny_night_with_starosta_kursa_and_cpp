#include <iostream>
#include <cmath>

using namespace std;

int GCD(int x, int y){
    while(x != 0 and y != 0){
        if (x > y) {
            x = x % y;
        }
        else {
            y = y % x;
        }
    }
    return max(x, y);
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << GCD(x, y) << endl;
    return 0;
}