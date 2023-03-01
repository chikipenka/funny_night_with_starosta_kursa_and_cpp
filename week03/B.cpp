#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

void swap(int& lha, int& rha){
    int changer = lha;
    lha = rha;
    rha = changer;
}

void print_array(int arr[N]) {
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int A[N] = {0}; // array initialization
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = N-1; i > 0; i--){
        swap(A[i], A[(i - 1 + N) % N]);
    }
    print_array(A);
    return 0;
}


