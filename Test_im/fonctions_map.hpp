#ifndef FONCTIONS_MAP_HPP
#define FONCTIONS_MAP_HPP

#include <fstream>
#include <string>
#include <map>

typedef std::map<std::string, bool> StringMap;

std::ofstream &operator<<(std::ofstream &stream, const StringMap &map);

std::ifstream &operator>>(std::ifstream &stream, StringMap &map);

#endif