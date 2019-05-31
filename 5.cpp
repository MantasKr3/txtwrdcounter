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
std::ifstream t("Text.txt");

std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>()); // teksta imam kaip viena string'a
str.resize(remove_if(str.begin(), str.end(),[](char x){return !isalnum(x) && !isspace(x);})-str.begin()); // removinam simbolius
t.close();
std::ofstream output("Text.txt");// isvedam teksta be simboliu
output<<str;
output.close();
 std::ifstream input("Text.txt");



    std::multiset<std::string> list = 
        std::multiset<std::string>( std::istream_iterator<std::string>(input),
                                    std::istream_iterator<std::string>()); // iteruojam teksta po zodi multiset konteineryje
input.close();
std::ofstream outputas("rezultatai.txt");

 for(auto zodis = list.begin(); zodis != list.end(); zodis=list.upper_bound(*zodis)) //panaudojam multiset funkcijas
{
  outputas << *zodis << " : " << list.count(*zodis) << std::endl; //naujdoam multiset integruota count()
}    
       outputas.close();

    return 0;
}
