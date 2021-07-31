#include <iostream>

template<class T> int compare( const T& a, const T& b) {
	std::cout<< a <<std::endl;
}


int main( int argc, char* argv[] ){ 
	//compare("HI","WORLD");
	compare("BYE", "BYE");
	return 0;
}
