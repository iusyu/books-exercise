#include <iostream>
#include <sstream>
#include <thread>
#include <map>
#include <vector>
#include <string>



template<typename T>
T SupportXmlEncode(const T& container)
{
    T tmp = container;
    if( tmp.empty() ) return tmp; 
    typename T::size_type pos = 0;
    for (size_t i = 0; i < 10000; ++i)
    {
        pos = tmp.find_first_of("\"&<>", pos);
        if (pos == T::npos) break;
        T replacement;
        switch (tmp[pos])
        {
        case '\"': replacement = "&quot;"; break;   
        case '&':  replacement = "&amp;";  break;   
        case '<':  replacement = "&lt;";   break;   
        case '>':  replacement = "&gt;";   break;   
        default: ;
        }
        tmp.replace(pos, 1, replacement);
        //std::cout << tmp << std::endl;
        pos += replacement.size();
        replacement.clear();
    };
    return tmp;
}


template<>
std::string SupportXmlEncode(const std::string& container) {
    std::string tmp = container;
    if( tmp.empty() ) return tmp; 
    std::string::size_type pos = 0;
    for (size_t i = 0; i < 10000; ++i)
    {
        pos = tmp.find_first_of("\"&<>", pos);
        if (pos == std::string::npos) break;
        std::string replacement;
        switch (tmp[pos])
        {
        case '\"': replacement = "&quot;"; break;   
        case '&':  replacement = "&amp;";  break;   
        case '<':  replacement = "&lt;";   break;   
        case '>':  replacement = "&gt;";   break;   
        default: ;
        }
        tmp.replace(pos, 1, replacement);
        //std::cout << tmp << std::endl;
        pos += replacement.size();
        replacement.clear();
    };
    return tmp;
}

template<typename T>
std::vector<T> SupportXmlEncode(const std::vector<T>& container)
{
    std::vector<T> tmp = container;
    if( tmp.empty() ) return tmp;
    for(typename std::vector<T>::iterator itr = tmp.begin();
        itr != tmp.end(); ++itr )
    {
        T tmp = SupportXmlEncode(*itr);
        (*itr).clear();
        (*itr) = tmp;
    }
    return tmp;
}

template<typename T>
std::map<T,T> SupportXmlEncode(const std::map<T,T>& container)
{
    std::map<T,T> tmp = container;
    if( tmp.empty() ) return tmp;
    for(typename std::map<T,T>::iterator itr = tmp.begin();
        itr != container.end(); ++itr )
    {
        T tmp = SupportXmlEncode(itr->second);
        (*itr).second.clear();
        (*itr).second += tmp;
    }
    return tmp;
}





void TEST_F() {
    std::string xmlstr = "djslfka&js\"dklfj<dj>dfj<dkfj";
    std::cout << SupportXmlEncode(xmlstr) << std::endl;
    std::vector<std::string> vecxmlstr (10, xmlstr);
    std::vector<std::string> tmpresult = SupportXmlEncode(vecxmlstr);
    std::cout << tmpresult[0] << std::endl;
}


int main(void) {
    TEST_F();
}
