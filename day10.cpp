#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string number = "3113322113";
    string newString;
    for (int r=0; r<50; r++) {
        stringstream ss;
        for (int i=0; i<number.length(); i++) {
            int count = 1;
            if (number[i] == number [i+1]) {
                int k=i+1;
                while(number[k] == number[i]) {
                    count++;
                    k++;
                }
                i = k-1;
            }
            ss << count << number[i];
            newString = ss.str();
        }
        number = newString;
    }
    cout << newString.length() << endl;
    return 0;
}
