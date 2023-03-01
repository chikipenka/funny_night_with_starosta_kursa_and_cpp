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
    int A[N] = {1, 2, 3, 4, 5}; // array initialization
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N/2; i++){
        swap(A[i], A[N - i - 1]);
    }
    print_array(A);
    return 0;
}


