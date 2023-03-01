// идея подсказанна умным другом
#include <iostream>

using namespace std;

#ifndef N
#define N 5
#endif 

int main(){
    int A[N] = {0}; // array initialization
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    if (N == 1){
        cout << A[0] << endl;
    }
    else{
        int answer = A[0];
        for(int i = 1; i < N; i++){
        answer = answer ^ A[i];
    }
    cout << answer << endl;
    }
    return 0;
}