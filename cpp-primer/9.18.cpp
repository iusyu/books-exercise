#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <deque>
#include <algorithm>

template <typename T>
void printContainer(const std::string desc, const T& container)
{
    std::cout <<desc << " Container Have: " << std::endl;
    std::for_each(container.begin(), container.end(), [](auto& p) { std::cout << "line: "<<p << " "; } );
    std::cout << std::endl;
}

int main()
{
    using namespace std;
    vector<int> a {1,23,4,5,6,7,8};
    vector<int> b {1,23,4,5,6,7,8};
    list<int> l {1,23,4,5,6,6,7,8};

    list<string> wde;
    string tmp;
    char tmpc;
    while( cin.get(tmpc)) {
        
        if( tmpc == ' ') {
            wde.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.push_back(tmpc);

        if( tmpc == '\n'){
            wde.push_back(tmp)
        }
    }

    printContainer("Cin Get Word:", wde);


}