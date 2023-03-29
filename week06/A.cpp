#include <iostream>
#include <string>

using namespace std;

struct Students{
    string name;
    int score;
};

int main() {
    Students A[10];
    int M;
    for (int i = 0; i < 10; i++) {
        cin >> (A[i]).name >> (A[i]).score;
    }
    cin >> M;
    for (int i = 0; i < 10; i++) {
        if (M < (A[i]).score){
            cout << (A[i]).name << ' ';
        }   
    }
    cout << endl;
    return 0;
}
