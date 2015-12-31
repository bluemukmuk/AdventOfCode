#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    int floor = 0;
    int count = 0;
    ifstream myfile("day1input.txt");
    if (myfile.is_open()) {
        char c;
        while (!myfile.eof()) {
            myfile.get(c);
            count++;
            if (c=='(') {
                floor++;
            } else if (c==')') {
                floor--;
            }
            if (floor == (-1)) {
                cout << "Floor is " << floor << endl;
                cout << "Count is " << count << endl;
                return 1;
            }
        }
    }
    cout << "Floor is " << floor << endl;
    return 0;
}
