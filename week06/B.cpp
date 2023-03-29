#include <iostream>
#include <string>

using namespace std;

struct Time{
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time current_time, difference, ending_time;
    cin >> current_time.hours >> current_time.minutes >> current_time.seconds
    >> difference.hours >> difference.minutes >> difference.seconds;
    
    ending_time.hours = (current_time.hours + difference.hours + (current_time.minutes + difference.minutes
    + (current_time.seconds + difference.seconds) / 60) / 60) % 24;
    
    ending_time.minutes = (current_time.minutes + difference.minutes + (current_time.seconds + difference.seconds) / 60) % 60;
    
    ending_time.seconds = (current_time.seconds + difference.seconds) % 60;

    cout << ending_time.hours << ':' << ending_time.minutes << ':' << ending_time.seconds << endl;
    return 0;
}
