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
    vector<int> a {1,23,4,5,6,7,8};
    vector<int> b {1,23,4,5,6,7,8};
    if( a == b ) std::cout << "those elemt is same \n" << std::flush;
    else std::cout << "Tthos is same elemt \n" << std::flush;

}