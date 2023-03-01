#include <iostream>

using namespace std;

#ifndef N
#define N 2
#endif

#ifndef M
#define M 2
#endif

void print_array(int A[N][M]) {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void sort2d(int (&A)[N][M]) {
    int B[N*M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            B[j+M*i] = A[i][j];
        }
    }
    for (int j = 0; j < N*M; j++) {
        int current_number = B[j];
        int k = j - 1;
        while (k >= 0 and current_number < B[k]) {
            B[k + 1] = B[k];
            k--; 
            B[k + 1] = current_number;
        }
    }
    for (int i = 0; i<N*M; i++) {
        A[i/M][i%M] = B[i];
    }
}

int main(){
    int A[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> A[i][j];
        }
    }

    sort2d(A);

    print_array(A);
    return 0;
}