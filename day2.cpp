#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    ifstream myfile("day2input.txt");
    int totalpaper = 0;
    int totalribbon = 0;
    char x;
    if (myfile.is_open()) {
        string line;
        while (!myfile.eof()){
            int paper = 0;
            int ribbon = 0;
            int a, b, c = 0;
            getline(myfile,line);
            if (line.empty()) {
                continue;
            }
            stringstream ss(line);
            ss >> a >> x >> b >> x >> c;
            if (a>b) {
                swap(a,b);
            }
            if (a>c) {
                swap(a,c);
            }
            if (b>c) {
                swap(b,c);
            }
            ribbon = 2*a + 2*b +a*b*c;
            paper = 3*a*b + 2*a*c + 2*b*c;
            totalpaper += paper;
            totalribbon += ribbon;
        }
    }
    cout << "Total wrapping paper needed: " << totalpaper << endl;
    cout << "Total wrapping ribbon needed: " << totalribbon << endl;
    return 0;
}

