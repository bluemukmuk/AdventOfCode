#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
bool matchesVowels(string line);
bool matchesDoubles(string line);
bool hasNoStrings(string line);
bool hasPairs(string line);
bool hasARepeat(string line);

int main() {
    int count = 0;
    ifstream myfile("day5input.txt");
    if (myfile.is_open()) {
        string line;
        while (!myfile.eof()){
            getline(myfile,line);
            if (line.empty()) {
                continue;
            }

           // Part 1
           // if (matchesVowels(line) && matchesDoubles(line) && hasNoStrings(line)) {
           //     count++;
           // }

            // Part 2
            if (hasPairs(line) && hasARepeat(line)) {
                count++;
            }

        }

    }
    cout << "Nice strings " << count << endl;
    return 0;
}


bool matchesVowels(string line){
    int vowels = 0;
    for(int i=0;line[i]!='\0';i++)
    {
        if(line[i]=='a'
                || line[i]=='e'
                || line[i]=='i'
                || line[i]=='o'
                || line[i]=='u'
                || line[i]=='A'
                || line[i]=='E'
                || line[i]=='I'
                || line[i]=='O'
                || line[i]=='U')
            vowels++;
    }
    if (vowels >= 3)
        return true;
    else
        return false;
}


bool matchesDoubles(string line) {
    for(int k=0;line[k+1]!='\0';k++) {
        if(line[k] == line[k+1]) {
                return true;
        }
    }
    return false;
}

bool hasNoStrings(string line) {
    for(int k=0;line[k+1]!='\0';k++) {
        if(line[k] == 'a') {
            if(line[k+1] == 'b') {
                return false;
            }
        } else if(line[k] == 'c') {
            if(line[k+1] == 'd') {
                return false;
            }
        } else if(line[k] == 'p') {
            if(line[k+1] == 'q') {
                return false;
            }
        } else if(line[k] == 'x') {
            if(line[k+1] == 'y') {
                return false;
            }
        }
    }
    return true;
}

bool hasPairs(string line) {
    for(int k=0;line[k+1]!='\0';k++) {
        for (int j=k+2; line[j+1] != '\0'; j++) {
            if (line[j] == line [k]) {
                if (line[j+1] == line[k+1]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool hasARepeat(string line) {
    for(int k=0;line[k+1]!='\0';k++) {
        if(line[k] == line[k+2]) {
                return true;
        }
    }
    return false;
}
