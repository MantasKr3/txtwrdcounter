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

std::ofstream outputas("rezultatai.txt",std::ios::app);
std::ifstream t("Text.txt");

std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>()); // teksta imam kaip viena string'a
str.resize(remove_if(str.begin(), str.end(),[](char x){return !isalnum(x) && !isspace(x);})-str.begin()); // removinam simbolius
t.close();
std::ofstream output("Text.txt");// isvedam teksta be simboliu
output<<str;
output.close();
 std::ifstream input("Text.txt");






    std::multiset<std::string> listas = 
        std::multiset<std::string>( std::istream_iterator<std::string>(input),
                                    std::istream_iterator<std::string>());
input.close();
outputas<<"Pasikartojantys zodziai:"<<std::endl;


 for(auto zodis = listas.begin(); zodis != listas.end(); zodis=listas.upper_bound(*zodis)) 
{
  std::ifstream in("Text.txt");

if(listas.count(*zodis)>=2){
std::string eilute;
std::string word;
std::vector<int> line;
int eile = 1;
in.clear();  
 while (std::getline(in, eilute))
    {
        std::stringstream abc(eilute);
        while (!abc.eof())
        {
          abc>>word;
          if(word==*zodis)
          {
            line.push_back(eile);
          }

        }
        eile++;

    }


  outputas << *zodis << "  pasikartoja (kartai) : " << listas.count(*zodis) << "  ir jis pasikartoja yra siose teksto eilutese: ";
      for(size_t i=0;i<line.size();i++)
{
  outputas<<line[i]<<" ";
}
  outputas<<std::endl;
  }
  in.clear();
}
outputas.close();

    return 0;
}
