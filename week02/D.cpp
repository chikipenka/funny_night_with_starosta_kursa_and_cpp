#include <iostream>

using namespace std;

int recursive_power(int base, int power){
    if (power == 0){
        return 1;
    }
    else if (power == 1){
        return base;
    }
    else{
        return base * recursive_power(base, power - 1);
    }
}

int main() {
    int base, power;
    cin >> base >> power;
    cout << recursive_power(base, power) << endl;
    return 0;
}
    