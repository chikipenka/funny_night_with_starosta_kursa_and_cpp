#include <iostream>

using namespace std;

long long int recursive_power(int base, int power){
    if (power == 0){
        return 1;
    }
    else if (power == 1){
        return base;
    }
    else{
        return base * recursive_power(base, power - 1);
    }
}

long long int reversed_number(long long int number){
    int counter;
    counter = 0;
    long long int old_number, new_number; 
    old_number = number;
    new_number = 0;
    int current_n;
    while (old_number > 0){
        old_number /= 10;
        counter += 1;
    }
    old_number = number;
    int new_counter;
    new_counter = 1;
    while (new_counter <= counter){
        current_n = old_number % recursive_power(10, new_counter) / recursive_power(10, new_counter - 1);
        new_number += current_n * recursive_power(10, counter - new_counter);
        old_number -= current_n * recursive_power(10, new_counter - 1);
        new_counter ++;
    }
    return new_number;
}

int main(){
    long long int x;
    cin >> x;
    if (x == reversed_number(x)){
        cout << "YES" << endl;
    }
    else {
       cout << "NO" << endl;
    }
    return 0;
}
