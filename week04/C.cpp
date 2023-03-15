#include <iostream>

using namespace std;

#ifndef N
#define N 10
#endif

void swap(int* a, int* b) {
    int c = *b;
    *b = *a;
    *a = c;
}

void sort_for_heaps(int (&A)[N], int i, int lenght){
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if ((left < lenght) and (A[max] < A[left])){
        max = left;
    }
    if ((right < lenght) and (A[max] < A[right])){
        max = right;
    }
    if (max != i){
        swap(A[max], A[i]);
        sort_for_heaps(A, max, lenght);
    }
    
}

void cheops_sort(int (&A)[N]){
    for (int i = N/2; i>=0; i--){
        sort_for_heaps(A, i, N);
    }
    for (int i = N-1; i>=0; i--){
        swap(A[0], A[i]);
        sort_for_heaps(A, 0, i);
    }
}

int main(){
    int A[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    cheops_sort(A);
    for (int i = 0; i < N; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
