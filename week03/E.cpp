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

void print_array(int arr[N * 2]) {
    for (int i = 0; i < N * 2; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int A[N], B[N], C[N * 2]; // array initialization
    int i = 0, j = 0, k = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    while (k < N * 2){
        if (j < N and i < N){
            if (A[i] < B[j]){
                C[k] = A[i];
                i ++;
            }
        else {
            C[k] = B[j];
            j ++;
        }
        }
        else if(i == N) {
            C[k] = B[j];
            j ++;
        }
        else if(j == N) {
            C[k] = A[i];
            i ++;
        }
        k ++;
    }
    print_array(C);
    return 0;
}


