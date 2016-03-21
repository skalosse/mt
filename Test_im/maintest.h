#ifndef MAINTEST_H
#define MAINTEST_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QWidget>
//#include <QVBoxLayout>
#include <QLabel>
class Maintest : public QWidget
{
Q_OBJECT
public:
     Maintest( int i=1024, int j=768);
    ~Maintest();
    QImage* get_image();

private:
    QImage* m_image;
    QLabel*  m_label;
    int m_h, m_l;
};

#endif // MAINTEST_H
