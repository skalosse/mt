#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <cmath>
#include <cstring>
#include "fonctions_map.hpp"

#define PI 3.141592653589793238463


// <start> <index> <speed_L> <speed_H> [Data 0] [Data 1] [Data 2] [Data 3] <checksum_L> <checksum_H>

class Package
{
    private:

    // attributs
	int m_index;
    int m_checksum_l;
    int m_checksum_h;
    unsigned char m_data[4];

    public:

    // constructeur
    Package(unsigned char * buffer);
    Package(int index, int checksum_l, int checksum_h, unsigned char* data);
    ~Package();

    // getters et setters
    int getIndex();
    void setIndex(int index);
    int getChecksum_l();
    void setChecksum_l(int checksum_l);
    int getChecksum_h();
    void setChecksum_h(int checksum_h);
    unsigned char* getData();
    void setData(unsigned char* data);

    bool store(StringMap map);

    private:

    int* convert_plan(int indice);

    // x=cos(theta)*dist
    // y=sin(theta)*dist
};

#endif