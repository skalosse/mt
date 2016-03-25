#include "maintest.h"


Maintest::Maintest(int i, int j) : QWidget(),
m_image(new QImage(i,j,QImage::Format_Mono)), m_h(i),m_l(j), m_label(new QLabel(this))
{
    for (int i=0; i<m_h; i++)
    {
        for(int j=0;j<m_l;j++)
        {
            m_image->setPixel(i,j,false);
        }
    }
    m_label->setPixmap(QPixmap::fromImage(*m_image));
}

Maintest::~Maintest()
{

}

QImage* Maintest::get_image()
{
    return m_image;
}

void Maintest::refresh_random(int i,int j)
{
    m_image->setPixel(i,j,1);
    m_label->setPixmap(QPixmap::fromImage(*m_image));
}
