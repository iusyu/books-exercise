
#include <ios>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

void print(std::istream& cin);


int main(int argc, char* argv[])
{
    std::cerr <<" this is errror stream >>>>>>" << std::endl;
    int i;
    int sum = 0;
    while(std::cin >> i) {
        sum += i;
    } 

    std::cout <<std::endl << "your sum is : " << sum << std::endl;

    std::cout << "HI!" << std::endl;
    std::cout << "HI!" << std::flush;
    std::cout << "Hi!" << std::ends;
    std::cout << std::unitbuf;
    std::cout << std::nounitbuf;
    std::cout << "this is line ocde without endl ....";
    sleep(1);
    std::cout << "this is line of ";
    sleep(1);
    std::cout << "buffer line code  ";
    sleep(1);
    std::cout << std::endl;
    tieFstreamToOstream();
   //dectype(oldState);

}


void print(std::istream& cin)
{
    auto oldState = cin.rdstate();
    cin.clear();
    std::string context;
    std::string tmp;
    while( ! cin.eof() ){
        cin >> tmp;
        context += tmp;
    }
    std::cout<< context << std::endl;

    cin.setstate(oldState);
}



void tieFstreamToOstream()
{
    std::ifstream f {"./literal.txt"};
    std::ofstream o {"./literalq.txt"};
    f.tie(o);
    std::string context;
    std::string tmp;
    while( f >> tmp) {
        context += tmp;
    }

}
