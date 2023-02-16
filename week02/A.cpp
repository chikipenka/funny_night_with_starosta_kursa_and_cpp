#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x;
    cin >> x;
    if (x % 400 == 0) {
        cout << "YES" << endl;
    }
    else if (x % 100 == 0)
    {
        cout << "NO" << endl;
    }
    else if (x % 4 == 0)
    {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
