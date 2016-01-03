#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

int main() {
    //wire : {name, value}
    ifstream myfile("day7input.txt");
    if (myfile.is_open()) {
        string line;
        while (!myfile.eof()){
            string source1;
            string source2;
            string action;
            string destination;
            string arrow;
            getline(myfile,line);
            if (line.empty()) {
                continue;
            }
            stringstream ss(line);
            ss >> source1;
            if (source1 == "NOT") {
                action = "NOT";
                ss >> source2 >> arrow >> destination;
            } else {
                ss >> action >> source2 >> arrow >> destination;
            }
            cout << source1 << "," << action << "," << source2 << "," << arrow << "," << destination << endl;
            //return 1;
            //cout << action << endl;
            //if (action == "NOT") {
            //use source2
            //} else if (action == "RSHIFT") {
            //} else if (action == "LSHIFT") {
            //} else if (action == "AND") {
            //} else if (action == "OR") {
            //}
        }
    }
    cout << "a is " << endl;
    return 0;
}


