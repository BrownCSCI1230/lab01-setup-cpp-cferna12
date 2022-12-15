#pragma once

#include <QMainWindow>
#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
//#include "realtime.h"
#include "glwidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    void initialize();
    void finish();

private:
    void connectUIElements();
//    void connectParam2();
//    void connectNear();
//    void connectFar();
    void connectToonLevels();
    void connectToon2();
    void connectExtraCredit();
//    void connectUploadFile();
//    void onUploadFile();

    GLWidget *glWidget;

//    Realtime *realtime;
//    QSlider *nearSlider;
//    QSlider *farSlider;
//    QDoubleSpinBox *nearBox;
//    QDoubleSpinBox *farBox;

    QSlider *toonLevelSlider;
    QSpinBox *toonLevelBox;
    QSlider *toon2Slider;
    QSpinBox *toon2Box;
    // Extra Credit:
    QCheckBox *ec1;
    QCheckBox *specular_on;
    QPushButton *uploadFile;
private slots:

    void onValChangeToonLevels(int newValue);
    void onValChangeToon2(int newValue);
    // Extra Credit:
    void onExtraCredit1();
    void onSpecularOn();

};
