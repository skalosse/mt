#include "maintest.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <QApplication>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include "fonctions_map.hpp"
#include "Package.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Maintest win, win2;
    srand(time(NULL));
    int y,z;

    unsigned char buf[50] = "";

    StringMap hash_points;
    int fd; /* File descriptor for the port */
    int i = 0;
    unsigned char c;

    // connection au Raspberry
    fd = open("/dev/ttyS0", O_RDONLY);
    if (fd == -1) {
      perror("open_port: Unable to open /dev/ttyS0 - ");
      exit(1);
    }
    else {
      // attendre le début d'une trame
      while(c != 0xFA)
        read(fd, &c, sizeof(unsigned char));

      // lecture des trames
      while(1) {
        read(fd, &c, sizeof(unsigned char));

        // start
        if (c == 0xFA) {
          buf[i] = '\0';

          Package pck(buf);
          pck.store(hash_points);

          i = 0;
        }
        else {
          buf[i] = c;
          i++;
        }
      }
    }
    for (StringMap::const_iterator it = hash_points.begin(), end = hash_points.end(); it != end; it++)
    {
        std::size_t pos = it->first.find(":");

         y = atoi(it->first.substr(0, pos).c_str());
         z = atoi(it->first.substr(pos+1).c_str());
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

    if(win.get_image()->save("/home/ioann/testim2.bmp","BMP") && win2.get_image()->save("/home/ioann/testim2.bmp","BMP"))
    {
        std::cout<<"ok"<<std::endl;
    }
    win.show();
    win2.show();

    return a.exec();
}
