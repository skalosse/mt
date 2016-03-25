#include "maintest.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Maintest win, win2;
    srand(time(NULL));
    int y,z;
    for(int i=0; i<365;i++)
    {
        y=rand()%1023;
        z=rand()%768;
        win.refresh_random(y,z);
        win2.refresh_random(y,z);
    }
    y=600;

    for(int i=0; i<365;i++)
    {
        z=rand()%400;
        win.refresh_random(y,z);
        win2.refresh_random(y,z+200);
    }

    if(win.get_image()->save("/home/ioann/testim2.bmp","BMP") && win2.get_image()->save("/home/ioann/testim2.bmp","BMP"));
    {
        std::cout<<"ok"<<std::endl;
    }
    win.show();
    win2.show();

    return a.exec();
}
