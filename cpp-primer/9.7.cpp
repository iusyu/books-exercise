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
    std::for_each(container.begin(), container.end(), [](auto& p) { std::cout << p << " "; } );
    std::cout << std::endl;
}

int main()
{
    using namespace std;
    vector<int> vii {1,2,3,4,5,6,7,89,0};
    vector<int>::value_type iii = vii[2];
    vector<int>::reference riii = vii[2];
    riii = 1000;
    cout << "vector<int>::value_type iii = " << iii << endl;
    cout << "vector<int>::reference riii = " << riii << endl;
    cout << "vector<int> vii[2] = " << vii[2] << endl;
    
}