#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif

int trace(int (&A)[N][N]){
    int counter = 0;
    for(int i = 0; i < N; i++){
        counter += A[i][i];
    }
    return counter;
}

int main(){
    int A[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }     
    }
    cout << trace(A) << endl;
    return 0;
}