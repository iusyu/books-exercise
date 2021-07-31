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
    vector<string> buffer {"APR", "DECEBER", "BUFFER", "CODING", "NVIM", "NAME", "JULY"};
    vector<string> buffer2 {"APR", "DECEBER", "BUFFER", "CODING", "NVIM"};
    printContainer("vector<string> type : buffer\n", buffer);
    printContainer("vector<string> type : buffer2\n", buffer2);

    std::swap(buffer, buffer2);
    std::cout << "after swaping...\n" << std::endl;
    printContainer("vector<string> type : buffer\n", buffer);
    printContainer("vector<string> type : buffer2\n", buffer2);

    list<string> ls1;
    ls1.assign(buffer.begin(), buffer.begin()+3);
    printContainer("list<string> type: ", ls1);
    ls1.assign(5,"FUNC YOU");
    printContainer("list<string> type: ", ls1);
}