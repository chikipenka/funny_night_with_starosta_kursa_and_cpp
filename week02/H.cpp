#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x;
    cin >> x;
    bool trigger;
    trigger = true;
    for (int i = 2; i <= sqrt(x); i ++){
        if (x % i == 0){
            trigger = false;
            break;
        }
    }
    if (trigger){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}