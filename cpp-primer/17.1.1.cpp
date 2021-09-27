#include <iostream>
#include <tuple>
#include <string>
#include <vector>


using namespace std;

template<class T> int compare( const T& a, const T& b) {
	std::cout<< a <<std::endl;
}

void Test_1() {
    cout << __PRETTY_FUNCTION__ << ":" << endl;
    tuple<string, int, double> ss = {"name", 32, 193.1};

}

int main( int argc, char* argv[] ){ 
	//compare("HI","WORLD");
	compare("BYE", "BYE");
    Test_1();
	return 0;
}
