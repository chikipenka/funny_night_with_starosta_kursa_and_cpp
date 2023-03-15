#include <iostream>

#ifndef N
#define N 10  
#endif

using namespace std;

void swap(int* a, int* b) {
    int c = *b;
    *b = *a;
    *a = c;
}

int partition(int A[], int left, int right){
    int pivot = A[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[right]);
    return (i + 1);
}

void quick_sort(int arr[], int l, int r){
    if (l < r){
        int pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot - 1);
        quick_sort(arr, pivot + 1, r);
    }
}

int main(){
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    quick_sort(A, 0, N-1);

    for(int i = 0; i < N; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
