#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

bool doAction(string action, bool status);

int main() {
    int count = 0;
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
            while (x1 < (x2+1)) {
                while (y1 < (y2+1)) {
                    bool status = false;
                    status = light[x1][y1];
                    light[x1][y1] = doAction(action,status);
                    y1++;
                }
                x1++;
            }
        }
    }
    for (int i=0;i<1000; i++) {
        for (int j=0; j<1000; j++) {
            if (light[i][j] == true) {
                count++;
            }
        }
    }
    cout << "Lights on " << count << endl;
    return 0;
}


bool doAction(string action, bool status) {
    if (action == "turnon") {
        return true;
    } else if ( action == "turnoff") {
        return false;
    } else if ( action == "toggle") {
        if (status == false ) {
            return true;
        } else {
            return false;
        }
    }
    return status;
}
