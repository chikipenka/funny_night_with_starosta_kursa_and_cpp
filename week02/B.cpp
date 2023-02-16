#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x = 1;
    int counter = -1;
    while (x != 0){
        cin >> x;
        if (x % 2 == 0){
            counter ++;
        }
    }
    cout << counter << endl;
    return 0;
}
