#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int count = 0;
    int countt = 0;
    bool light[1000][1000]={false};
    ifstream myfile("day6input.txt");
    if (myfile.is_open()) {
        string line;
        while (!myfile.eof()){
            string action, action2;
            int x1, x2, y1, y2=0;
            char comma;
            string through;
            getline(myfile,line);
            if (line.empty()) {
                continue;
            }
            stringstream ss(line);
            ss >> action;
            if (action == "toggle") {
                ss >> x1 >> comma >> y1 >> through >> x2 >> comma >> y2;
            } else {
                ss >> action2 >> x1 >> comma >> y1 >> through >> x2 >> comma >> y2;
                action = action + action2;
            }
            cout << x1 << "," << x2 << "," << through << "," << x2 << "," << y2 << endl;
            bool status = false;
            while (x1 <= x2) {
                while (y1 <= y2) {
                    status = light[x1][y1];
                    if (action == "turnon") {
                        status = true;
                        count++;
                    } else if ( action == "turnoff") {
                        status = false;
                        count--;
                    } else if ( action == "toggle") {
                        if (status == false ) {
                            status = true;
                            count++;
                        } else if (status == true) {
                            status = false;
                            count--;
                        }
                    }
                    cout << action << endl << count << endl;
                    light[x1][y1] = status;
                    y1++;
                }
                x1++;
            }
        }
    }
    for (int i=0;i<1000; i++) {
        for (int j=0; j<1000; j++) {
            if (light[i][j] == true) {
                countt++;
            }
        }
    }
    cout << "Lights on " << count << endl;
    cout << "Countt " << countt << endl;
    return 0;
}


