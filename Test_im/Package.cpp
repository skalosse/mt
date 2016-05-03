#include "Package.hpp"


Package::Package(unsigned char * buffer)
{
    setIndex((int)buffer[0]);
    setChecksum_l((int)buffer[19]);
    setChecksum_h((int)buffer[20]);

    // get distance for each data
    unsigned char data[] = { buffer[3], buffer[7], buffer[11], buffer[15] };

    setData(data);
}

Package::Package(int index, int checksum_l, int checksum_h, unsigned char* data)
{
    setIndex(index);
    setChecksum_l(checksum_l);
    setChecksum_h(checksum_h);
    setData(data);
}

Package::~Package()
{

}

int Package::getIndex()
{
    return m_index;
}

void Package::setIndex(int index)
{
    m_index = index - 0xA0;
}

int Package::getChecksum_l()
{
    return m_checksum_l;
}

void Package::setChecksum_l(int checksum_l)
{
    m_checksum_l = checksum_l;
}

int Package::getChecksum_h()
{
    return m_checksum_h;
}

void Package::setChecksum_h(int checksum_h)
{
    m_checksum_h = checksum_h;
}

unsigned char* Package::getData()
{
    return m_data;
}

void Package::setData(unsigned char * data)
{
    m_data[0] = data[0];
    m_data[1] = data[1];
    m_data[2] = data[2];
    m_data[3] = data[3];
}

int* Package::convert_plan(int indice)
{
    int radian = (m_index*90+indice)/PI;
    int* coordonee = new int[2];

    coordonee[0] = (int)(cos(radian) * (int)m_data[indice]);
    coordonee[1] = (int)(sin(radian) * (int)m_data[indice]);

    return coordonee;
}

bool Package::store(StringMap map)
{
    int* coordonee;
    std::string buf;

    for(int i=0; i<4; i++)
    {
        coordonee=convert_plan(i);
        buf = coordonee[0];
        buf += ":";
        buf += coordonee[1];
        map[buf] = true;
    }
    return true;
}
