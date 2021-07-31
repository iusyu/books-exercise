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


int main(int argc, char* argv[])
{
	std::thread my_thread (do_some_work);
	std::thread my_thread1 (do_some_work);
	ThreadGuard th1(my_thread);
	ThreadGuard th2(my_thread1);
	//my_thread.join();
}
