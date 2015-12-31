#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;
    int turn = 0;
    int count=0;
    string coords[8200];
    coords[count++]="0,0";
    ifstream myfile("day3input.txt");
    if (myfile.is_open()) {
        char d;
        string nexthouse;
        while (!myfile.eof()){
            myfile.get(d);
            //get new position
            if ( d == '^') {
                if (turn % 2){
                    y++;
                } else {
                    b++;
                }
            } else if ( d == 'v') {
                if (turn % 2){
                    y--;
                } else {
                    b--;
                }
            } else if ( d == '>') {
                if (turn % 2){
                    x++;
                } else {
                    a++;
                }
            } else if ( d == '<') {
                if (turn % 2){
                    x--;
                } else {
                    a--;
                }
            }

            //check if exists in structure
            if (turn % 2) {
                nexthouse = to_string(x) + "," + to_string(y);
            } else {
                nexthouse = to_string(a) + "," + to_string(b);
            }

            bool found = false;
            for (int i=0; i<count; i++) {
                //if not inside, add it in
                if ( nexthouse.compare(coords[i]) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                coords[count]=nexthouse;
                count++;
            }
            turn++;
        }
    }
    cout << "Count " << count << endl;
    return 0;
}

