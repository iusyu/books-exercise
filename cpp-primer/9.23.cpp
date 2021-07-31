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
    int arr[] = {1,23,4,5,6,6,7,8};

    vector<int> vi (std::begin(arr), std::end(arr));
    list<int> li (std::begin(arr), std::end(arr));

    auto itr = vi.begin();
    auto itr2 = li.begin();

    for(; itr != vi.end();){
	if( *itr % 2 == 0 ){
		itr = vi.erase(itr);
		continue;
	}
	if( *itr2 % 2 ==1 ) 
	{
		itr2 = li.erase(itr2);
		continue;
	}

	itr++; itr2++;

    }

    printContainer("vi ", vi);
    printContainer("li ", li);


    

}
