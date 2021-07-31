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
    std::string name;
    list<const char *> buffer {"APR", "DECEBER", "BUFFER", "CODING", "NVIM", "NAME", "JULY"};
    vector<string> buffer2;
    buffer2.assign(buffer.begin(), buffer.end());
    printContainer("THIS is const char* list \n", buffer2);
}