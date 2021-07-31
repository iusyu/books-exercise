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


class ThreadGuard{
public:
	explicit ThreadGuard(std::thread& tt):tthread(tt){}
	~ThreadGuard(){
		if(tthread.joinable() ){
			tthread.join();
		}
	}

	ThreadGuard(const ThreadGuard&) =delete;
	ThreadGuard& operator=(const ThreadGuard&) = delete;
private:
	std::thread& tthread;
};

class Windows{
public:
	void openFileWithWindow(std::string name){

	}

	void startThread(std::string name){
		std::thread other{ Windows()};
		other.detach();
	}

};


class Extarctor{
public:
	Extarctor():counting(0){}
	Extarctor(const Extarctor& src) {
		counting = src.counting;
		counting++;
	}
	Extarctor& operator=(const Extarctor& src) {
		counting = src.counting;
		counting++;
		return *this;
	}

	void operator()(std::string& op) {
		std::cout << "there will be some operation of " << op << std::endl; 
		std::cout << "how much my copyed => " << counting << std::endl;
	}

private:
	std::string statues;
	std::size_t counting;
};


void my_thread_work(std::string& src){
	std::cout << "WORKING ON" << src << std::endl;
	src.append("this is MY LODE MOUNTAIN");
	std::cout << "WORKING ON" << src << std::endl;
}


int main(int argc, char* argv[])
{
	using namespace std;
	Extarctor ext;
	string data ("WO CAO NI DAYE");
	thread my_thread { my_thread_work, data};
	ThreadGuard tguard_1(my_thread);
	//my_thread.join();
}
