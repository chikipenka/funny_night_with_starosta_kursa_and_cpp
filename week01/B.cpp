#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int D = b * b - 4 * a * c;
    if (a == 0){
        cout << -c/b << endl;
    }
    else if (D > 0){
        cout << (-b - sqrt(D))/(2 * a) << " " << (-b + sqrt(D))/(2 * a) << endl;
    }
    else if (D == 0){
        cout << (-b)/(2 * a) << endl;}
    else{
        cout << '\n' << endl;
    }
    return 0;
}