#ifndef SHOWPROJECTIONS_H
#define SHOWPROJECTIONS_H
#include <string>
#include <QMainWindow>

#include "include/TwoDObj.h"
namespace Ui {
class ShowProjections;
}

class ShowProjections : public QMainWindow
{
    Q_OBJECT

public:

    explicit ShowProjections(QWidget *parent = 0);
    float angleX, angleY, angleZ;
    std::string objfileName;
    ~ShowProjections();
    void generateView() ;
    TwoDObj *twoDObjAttr ;
    void draw() ;


private slots:
    void on_xSlider_valueChanged(int value);

    void on_ySlider_valueChanged(int value);

    void on_zSlider_valueChanged(int value);


    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::ShowProjections *ui;
};

#endif // SHOWPROJECTIONS_H
