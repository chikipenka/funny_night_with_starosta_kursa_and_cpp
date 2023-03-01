#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int binsearch(int (&A)[N]) {
    int i = 0, l = 0, r = N - 1;
    while (l < r) {
        i = (l + r)/2;
        if (A[i] == 1) {
            r = i;
        }
        else {
            l = i;
        }
        if (l == r - 1) {
            return l;
        }
    }
}

int main(){
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    if (A[N-1] == 0) {
        cout << N - 1 << endl;
    }
    else {
        cout << binsearch(A) << endl;
    }
    return 0;
}