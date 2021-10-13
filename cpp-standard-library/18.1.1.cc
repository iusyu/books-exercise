#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <thread>
#include <map>
#include <set>
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

template<typename T>
std::ostream& operator<<(std::ostream& sout, const std::vector<T>& container)
{
    typename std::vector<T>::const_iterator itr = container.cbegin();
    sout << "[ ";
    for( ; itr != container.cend(); ++itr )
    {
        sout << *itr <<", ";
    }
    return sout << " ]";
}

template<typename KT, typename VT>
std::ostream& operator<<(std::ostream& sout, const std::map<KT,VT>& container)
{
    typename std::map<KT,VT>::const_iterator itr = container.cbegin();
    sout << '{';
    for ( ; itr != container.cend(); ++itr) {
        sout << "\"" << itr->first << "\":\"" << itr->second << "\""; 
    }
    return sout << '}';
}

template<typename T>
std::ostream& operator<<(std::ostream& sout, const std::set<T>& container)
{
    typename std::set<T>::const_iterator itr = container.cbegin();
    sout << "( ";
    for ( ; itr != container.cend(); ++itr) {
        sout << *itr << ", "; 
    }
    sout << " )";
    return sout;
}


void TEST_F() {
    std::string xmlstr = "djslfka&js\"dklfj<dj>dfj<dkfj";
    std::cout << SupportXmlEncode(xmlstr) << std::endl;
    std::vector<std::string> vecxmlstr (10, xmlstr);
    std::vector<std::vector<std::string> > vec2dxmlstr (10, vecxmlstr);
    std::vector<std::string> tmpresult = SupportXmlEncode(vecxmlstr);
    std::vector<std::vector<std::string> > tmp2dresult = SupportXmlEncode(vec2dxmlstr);
    std::cout << tmpresult << std::endl;
}


int main(void) {
    TEST_F();
}
