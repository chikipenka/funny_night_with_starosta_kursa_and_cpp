#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

const int mnoga = 1000000;

int simple_search(int* arr, int size, int value) {

    for (int i = 0; i <= size - 1; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;

}

int binary_search(int* arr, int size, int value) {

    int right = size;
    int left = 0;
    int temp = size / 2;

    while (temp != left) {

        if (value >= arr[temp]) {
            left = temp;
            temp = (left + right) / 2;
        }
        else {
            right = temp;
            temp = (left + right) / 2;
        }

        if (value == arr[temp]) {
            return temp;
        }

        if (value == arr[temp + 1]) {
            return temp + 1;
        }

    }

    return -1;

}


void fill_array(int* arr, int n) {

    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }

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


void random_experiment(int* array, int number) {

    for (int array_size = 500; array_size <= mnoga; array_size = array_size + 500) {
        int dot1 = 0;
        int dot2 = 0;
        int temp;
        cout << array_size << "RE" << endl;
        for (int i = 0; i < number; i++) {
            int value = array_size * i / number;

            auto begin = chrono::steady_clock::now();
            //cout << simple_search(array, array_size, value) << ", ";
            temp = simple_search(array, array_size, value);
            auto end = chrono::steady_clock::now();
            auto time_span1 = chrono::duration_cast<chrono::nanoseconds>(end - begin);
            //cout << time_span1.count() << ", ";
            dot1 = dot1 + time_span1.count();

            begin = chrono::steady_clock::now();
            //cout << binary_search(array, array_size, value) << ", ";
            temp = binary_search(array, array_size, value);
            end = chrono::steady_clock::now();
            auto time_span2 = chrono::duration_cast<chrono::nanoseconds>(end - begin);
            //cout << time_span2.count() << endl;
            dot2 = dot2 + time_span2.count();
        }

        dot1 = dot1 / number;
        dot2 = dot2 / number;

        ofstream out("C:\\MIPT_proga\\testing_directory\\points.txt", ios::app);
        if (out.is_open())
        {
            out << array_size << ", " << dot1 << ", " << dot2 << endl;
        }
        out.close();
    }

}


void worst_experiment(int* array, int number) {

    for (int array_size = 500; array_size <= mnoga; array_size = array_size + 500) {
        int dot1 = 0;
        int dot2 = 0;
        int temp;
        cout << array_size << "WE" << endl;
        for (int i = 0; i < number; i++) {
            int value = -1;

            auto begin = chrono::steady_clock::now();
            //cout << simple_search(array, array_size, value) << ", ";
            temp = simple_search(array, array_size, value);
            auto end = chrono::steady_clock::now();
            auto time_span1 = chrono::duration_cast<chrono::nanoseconds>(end - begin);
            //cout << time_span1.count() << ", ";
            dot1 = dot1 + time_span1.count();

            begin = chrono::steady_clock::now();
            //cout << binary_search(array, array_size, value) << ", ";
            temp = binary_search(array, array_size, value);
            end = chrono::steady_clock::now();
            auto time_span2 = chrono::duration_cast<chrono::nanoseconds>(end - begin);
            //cout << time_span2.count() << endl;
            dot2 = dot2 + time_span2.count();
        }

        dot1 = dot1 / number;
        dot2 = dot2 / number;

        ofstream out("C:\\MIPT_proga\\testing_directory\\points.txt", ios::app);
        if (out.is_open())
        {
            out << array_size << ", " << dot1 << ", " << dot2 << endl;
        }
        out.close();
    }

}

static int arr[mnoga];

int main()
{
    fill_array(arr, mnoga);
    const int number_of_repeats = 100;


    random_experiment(arr, number_of_repeats);
    worst_experiment(arr, number_of_repeats);

    return 0;
}
