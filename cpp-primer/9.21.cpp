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
    std::for_each(container.begin(), container.end(), [](auto& p) { std::cout << " "<<p << " "; } );
    std::cout << std::endl;
}

int main()
{
    using namespace std;
    vector<int> a {1,23,4,5,6,7,8};
    vector<int> b {1,23,4,5,6,7,8};
    list<int> l {1,23,4,5,6,6,7,8};

    deque<int> di1;
    deque<int> di2;

    for( auto& itr: l){
        if( itr % 2 == 0) di1.push_front(itr);
        else di2.push_front(itr);
    }

    printContainer("deque 1 :" , di1);
    printContainer("deque 2 :" , di2);


}