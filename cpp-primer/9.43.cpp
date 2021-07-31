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


void insertForwardList( std::forward_list<int>& list, int a, int b)
{
	auto itrPre = list.before_begin();
	auto itr = list.begin();
	std::for_each(list.begin(), list.end(), [&](auto& p){ if( p == a ) { list.insert_after(itrPre, b); } itrPre++; });
}

template<typename T>
void insertDiap( T& container)
{
	auto begin = container.begin();
	while( begin != container.end() )
	{
		++begin;
		container.insert(begin, 42);
		++begin;
	}
}



void changeSubstr(std::string& s, const std::string& oldVal, const std::string& newVal)
{
	std::string::size_type pos;
	while((pos = s.find(oldVal) ) != std::string::npos){
		s.replace(pos,oldVal.size(), newVal);
	}
}

std::string addPrefixAndPostfix(const std::string& name, const std::string& prefix, const std::string& postfix)
{

	std::string prefixtmp;
	prefixtmp.reserve(name.size() + prefix.size() + postfix.size());
	std::cout << "string capacity => " << prefixtmp.capacity() << std::endl;
	prefixtmp.insert(0, prefix);
	prefixtmp.insert(prefix.size(), name);
	prefixtmp.insert(prefix.size() + name.size(), postfix);
	return prefixtmp;
}


int main()
{
    using namespace std;
    string str = "May be in thoes day will snow in sky May";
    std::cout << str << std::endl;
    changeSubstr(str, "in", "SY");
    std::cout << str << std::endl;

    changeSubstr(str, "May", "DECKK");
    std::cout << str << std::endl;

    std::cout << addPrefixAndPostfix(std::string("July Mars"), "Mr.", "III") << std::endl;

}
