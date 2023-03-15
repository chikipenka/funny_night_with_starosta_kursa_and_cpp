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


void gnome_sort(int (&array)[N]){
    for(int i = 1; i < N; i++){
        for(int j = i; j > 0 ; j--){
            if (array[j - 1] > array[j]){
                swap(array[j], array[j-1]);
            }
        }
    }
}

int main(){
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    gnome_sort(A);

    for(int i = 0; i < N; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
