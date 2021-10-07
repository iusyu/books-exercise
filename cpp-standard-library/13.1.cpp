#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void test_1() {

}


int main(int argc, char* args[]) {
    if(argc < 4) {
        cerr << "Argument isn't enough..." << endl;
        cout << string::npos << endl;
    }

    string line;
    while ( getline(cin, line) ) {
        string::size_type pos = line.find_first_not_of("ABCDEFGHJKM");
        line.find_last_not_of("GETLINE");
        cout << "line max size : " << line.max_size() << endl;
        cout << "line capacity size : " << line.capacity() << endl;
        cout << "line  size : " << line.size() << endl;
        cout << "line  length : " << line.length() << endl;
        string tmp;
        vector<string> tmpvec;
        stringstream sin (line);
        while (getline(sin, tmp, ',')) {
            tmpvec.push_back(tmp);
            tmp.clear();
        }
        
    }
}
