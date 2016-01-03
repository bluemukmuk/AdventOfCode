#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
int main() {
    int total = 0;
    ifstream myfile("day8input.txt");
    if (myfile.is_open()) {
        string line;
        while (!myfile.eof()){
            getline(myfile,line);
            if (line.empty()) {
                continue;
            }
            //PART ONE
            //i=1 because first char is always "
            //for (int i=1; i<line.length(); i++) {
            //    if (line[i] == '\\') {
            //        if (line[i+1] == '\\') {
            //            total++;
            //            i++;
            //        } else if (line[i+1] == '\"') {
            //            total++;
            //        } else if (line[i+1] == 'x') {
            //            total += 3;
            //        }
            //    }
            //}
            //total += 2;
            //PART TWO
            for (int i=0; i<line.length(); i++) {
                if (line[i] == '\"' || line[i] =='\\') {
                    total++;
                }
            }
            total +=2;
        }
    }
    cout << "Final Answer " << total << endl;
    return 0;
}

