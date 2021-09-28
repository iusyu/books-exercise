#include <iostream>
#include <tuple>
#include <string>
#include <vector>


using namespace std;


void Test_1() {
    cout << __PRETTY_FUNCTION__ << ":" << endl;
    tuple<string, int, double> ss = {"name", 32, 193.1};
    typedef decltype(ss) ttpe;
    size_t size = tuple_size<decltype(ss)>::value;
    cout << size << endl;

    cout << get<1>(ss) << endl;

}

int main( int argc, char* argv[] ){ 
	//compare("HI","WORLD");
    Test_1();
	return 0;
}
