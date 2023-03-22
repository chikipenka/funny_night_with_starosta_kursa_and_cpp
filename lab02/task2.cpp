#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;

int comb_sort(int a[], int n) {
    int step = n - 1;
    int cnt_swap = 0;

    while(step >= 1) {
        for(int i = 0; i + step < n; i++) {
            if (a[i] > a[i + step]){
                cnt_swap += 1;
                int buff = a[i];
                a[i] = a[i + step];
                a[i + step] = buff;
			}
        }
        step /= 2;
    }

    return cnt_swap;
}

void bubble_sort(int* arr, int size) {
    int up = 1;
    while (up > 0) {
        up = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                ++up;
            }
        }
    }
}


int main() {
    ofstream out;
    out.open("results_laba2_task2.txt");

    int N = 1000;

    cout << endl;


    for(int n = 3; n < N; n++) {
        int *a = new int[n];

        for(int i = 0; i < n; i++){
            a[i] = rand();
	}
        int cnt_swap = 0;
        auto begin = std::chrono::steady_clock::now();
        for(unsigned cnt = 100000; cnt != 0; --cnt){
            cnt_swap += comb_sort(a, n);
	    bubble_sort(a, n);
	}
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds > (end - begin);
        if (out.is_open())
            out << n << " " << time_span.count() << " " << cnt_swap << std::endl;
        cout << n << endl;

        delete [] a;
    }
    return 0;
}
