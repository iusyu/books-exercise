#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
    unsigned long a = -1;
    std::cout<< " unsigned long type vriant : -1 =>  " << a << std::endl;
    unsigned u = 10, u2 = 42;
    std::cout<< " unsigned - unsigned : " << u - u2 <<std::endl;
    std::cout<< 12334213e4 <<std::endl;
    std::cout<< "this is line of code "
                "\tthis is second line of \"code\" " << std::endl;

    std::cout<<u"这就是一个utfi8 字符集"<< std::end;
    std::cout<<U"这就是一个utfi8 字符集"<< std::end;
    std::cout<<L"这就是一个utfi8 字符集"<< std::end;
    std::cout<<"这就是一个utfi8 字符集"<< std::end;
}
