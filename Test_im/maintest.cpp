#include "maintest.h"


Maintest::Maintest(int i, int j) : QWidget(),
m_image(new QImage(i,j,QImage::Format_RGB32 )), m_h(i),m_l(j), m_label(new QLabel(this))
{
    for (int i=90; i<590; i++)
    {
        for(int j=0;j<500;j++)
        {
            m_image->setPixel(i,j,qRgb(255,255,255));
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
