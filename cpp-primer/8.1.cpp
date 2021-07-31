
#include <iostream>
#include <string>
#include <fstream>


void print(std::istream& cin);


int main(int argc, char* argv[])
{
    std::cerr <<" this is errror stream >>>>>>" << std::endl;

    char buffer[1024] = {0};
    
    std::ifstream f{"./literal.txt"};
    print(f);
    std::string context {f.fail()};
    std::cout<< context << std::endl;
    print(std::cin);
    
    auto oldState = std::cout.rdstate();
    std::cout.clear();
    std::cout.setstate(oldState);
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
