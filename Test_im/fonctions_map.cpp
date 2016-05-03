#include "fonctions_map.hpp"


std::ofstream &operator<<(std::ofstream &stream, const StringMap &map)
{
  for (StringMap::const_iterator it = map.begin(), end = map.end(); it != end; it++)
    stream << it->first << std::endl;

  return stream;
}

std::ifstream &operator>>(std::ifstream &stream, StringMap &map)
{
  std::string str;

  while(!stream.eof()) {
    getline(stream, str);
    map[str] = 1;
  }

  return stream;
}
