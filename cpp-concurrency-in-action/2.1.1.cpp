#include <thread>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>


void do_some_work(){
	static int counting =0;
	counting ++;
	std::cout << "this is my thread => " << counting << std::endl;
}


int main(int argc, char* argv[])
{
	std::thread my_thread (do_some_work);
	std::thread my_thread1 (do_some_work);
	my_thread.join();
	my_thread1.join();
	//my_thread.join();
}
