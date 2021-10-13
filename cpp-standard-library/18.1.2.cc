#include <iostream>
#include <sstream>
#include <thread>
#include <map>
#include <vector>
#include <string>




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
        std::cout << tmp << std::endl;
        pos += replacement.size();
        replacement.clear();
    };
    return tmp;
}

std::vector<std::string> SupportXmlEncode(const std::vector<std::string>& container)
{
    std::vector<std::string> tmp = container;
    if( tmp.empty() ) return tmp;
    for(std::vector<std::string>::iterator itr = tmp.begin();
        itr != tmp.end(); ++itr )
    {
        std::string tmp = SupportXmlEncode(*itr);
        (*itr).clear();
        (*itr) = tmp;
    }
    return tmp;
}

std::map<std::string,std::string> SupportXmlEncode(const std::map<std::string,std::string>& container)
{
    std::map<std::string,std::string> tmp = container;
    if( tmp.empty() ) return tmp;
    for(std::map<std::string,std::string>::iterator itr = tmp.begin();
        itr != container.end(); ++itr )
    {
        std::string tmp = SupportXmlEncode(itr->second);
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
