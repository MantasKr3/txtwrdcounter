#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <locale>
#include <regex>
#include <streambuf>


int main()
{
std::ifstream inputas("Text.txt");
std::ofstream out("url.txt");

    std::multiset<std::string> list = 
        std::multiset<std::string>( std::istream_iterator<std::string>(inputas),
                                    std::istream_iterator<std::string>()); // iteruojam teksta po zodi multiset konteineryje

inputas.close();
out<<"URL ADRESAI:"<<std::endl;
 for(auto zodis = list.begin(); zodis != list.end(); zodis=list.upper_bound(*zodis)) //panaudojam multiset funkcijas
{
    std::string word=*zodis;
 if(word.rfind("www.",0)==0||word.rfind("http://",0)==0||word.rfind("https://",0)==0||word.rfind("ftp://",0)==0||word.rfind("localhost:",0)==0)
    {
     out << *zodis << " : " << list.count(*zodis) << std::endl; //naujdoam multiset integruota count()
    }
}    
out.close();



    return 0;
}