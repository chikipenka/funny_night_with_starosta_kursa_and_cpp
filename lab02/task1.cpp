#include <iostream>
#include <random>
using namespace std;

ifindef
define n 10
endif
int l, r;
int a[20];


void forward_step() {
    for(int i = l; i <= r; i++) {
        if(a[i] > a[i+1]){
            int buff = a[i];
            a[i] = a[i+1];
            a[i+1] = buff;
        }
    }
    r -= 1;
}

void backward_step() {
    for(int i = r; i >= l; --i) {
        if(a[i-1] > a[i]){
            int buff = a[i-1];
            a[i-1] = a[i];
            a[i] = buff;
        }
    }
    l += 1;
}

void shaker_sort() {
    while(l < r) {
        forward_step();
        backward_step();
    }

}


int main() {
    l = 0;
    r = n - 1;

    for(int i = 0; i < n; i++)
        a[i] = rand();

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    shaker_sort();

    cout << endl;

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
