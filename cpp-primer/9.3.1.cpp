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
    list<int> l {1,23,4,5,6,6,7,8};

    std::cout << "l size() " << l.size() << std::endl;
    auto itrl = l.begin();
    for( auto& itr : b){
        if( itr == *itrl) std::cout << itr <<" " << *itrl << std::endl;

        l.insert(itrl,6);
        itrl++;
    }

    std::cout << std::endl;
    std::cout << " after compared l size() " << l.size() << std::endl;

    std::string name {"JULY BUILL"};
    vector<char> cvec {'a','b','c','d'};
    auto itr = name.begin();
    itr += 5;

    std::cout << name  << std::endl;
    name.insert(itr,'A');
    std::cout << name <<std::endl;

    name.insert(itr,5,'A');
    std::cout << name <<std::endl;

    name.insert(itr, cvec.begin(), cvec.end());
    std::cout << name <<std::endl;

}