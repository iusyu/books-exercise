#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <deque>
#include <algorithm>
#include <stack>
#include <sstream>


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


int countVectorString(const std::vector<std::string>& s)
{
	int sum =0;

	std::for_each(s.begin(), s.end(), [&](auto& p){ sum += std::stoi(p); } );
	return sum;
}


int calculating(const std::string& s)
{
	std::stack<char> oprand;
	std::stack<char> oprator;
	std::istringstream inc (s);

	char tmp;
	while( inc.get(tmp) ){
		switch(tmp){
			case '(':
				oprand.push(tmp);
				break;
		}
	}
}


int main()
{
    using namespace std;
    vector<string>  co {"1", "2", "3", "4", "5"};

    printContainer("vector<string> ", co);
    std::cout << " Sum of it => " << countVectorString(co) << std::endl;

}
