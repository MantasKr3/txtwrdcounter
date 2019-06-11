#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <locale>
#include <regex>
#include <streambuf>
#include <vector>
#include <sstream>
#include <algorithm>

int main()
{
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
  // std::set<std::string> my_set(listas.begin(), listas.end());
  //   std::vector<std::string> my_vec(my_set.begin(), my_set.end());
  //   std::sort(my_vec.begin(), my_vec.end());
  //   listas= std::multiset<std::string>(my_vec.begin(),my_vec.end());
for(auto zodis = listas.begin(); zodis != listas.end(); zodis=listas.upper_bound(*zodis)) 
{
  std::ifstream in("Text.txt");

if(listas.count(*zodis)>=2){
std::string eilute;
std::string word;
std::vector<int> line;
int eile = 1;
int kartai=eile;
in.clear();  
 while (std::getline(in, eilute))
    {
        kartai=eile;
        std::stringstream abc(eilute);
        while (!abc.eof())
        {
          abc>>word;
          
         if(kartai>eile)
          {
              break;
          }
           if (word==*zodis)
          {
             kartai++;
             line.push_back(eile);
          }
        
         
        }
        eile++;

    }

outputas<<std::endl;
outputas << *zodis << "  pasikartoja (kartai) : " << listas.count(*zodis) << "  ir jis pasikartoja yra siose teksto eilutese: ";
outputas<<std::endl;


auto mid =line.size() / 2; 
if(mid>=3)
{
    mid++;
}
for(size_t i=0;i<=mid;i++)
{  
outputas<<line[i]<<"  "<<line[i+1]<<std::endl;
i++;
}
  outputas<<std::endl;
  }
  in.clear();
}
outputas.close();

    return 0;
}
