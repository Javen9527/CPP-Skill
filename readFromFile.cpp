#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

//核心：
/*
1.三个都使用到了：stringstream ifstream iostream; 
2.对ifstream抛出异常设置
3.读入顺序是：ifstream 通过iostream 读入至 stringstream
*/

string myReadFromFile(const char *path)
{
  std::string str;
  
  std::ifstream ifile;
  ifile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  
  try
  {
    ifile.open(path);
    std::stringstream strstream;
    strstream << ifile.rdbuf();
 
    str = strstream.str();
    ifile.close();
  }
  catch(std::ifstream::failure &e)
  {
    std::cout << "Read failed..." << std::endl;
  }
  return str;
}
