#include "mainwindow.h"
#include "settings.h"
#include "glwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QSettings>
#include <QLabel>
#include <QGroupBox>
#include <iostream>

void MainWindow::initialize() {
//    realtime = new Realtime;

    glWidget = new GLWidget;

    QHBoxLayout *hLayout = new QHBoxLayout; // horizontal alignment
    QVBoxLayout *vLayout = new QVBoxLayout(); // vertical alignment
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addLayout(vLayout);
    hLayout->addWidget(glWidget, 1);
    this->setLayout(hLayout);

    // Create labels in sidebox
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    QLabel *toon_labels = new QLabel(); // Parameters label
    toon_labels->setText("Toon Shader");
    toon_labels->setFont(font);


    QLabel *rim_thic_label = new QLabel(); // Extra Credit label
    rim_thic_label->setText("Rim Thickness");

    QLabel *layers_label = new QLabel(); // Extra Credit label
    layers_label->setText("Layers");

    uploadFile = new QPushButton();
    uploadFile->setText(QStringLiteral("Upload Scene File"));

    // Create slider controls to control parameters
    QGroupBox *toon1Layout = new QGroupBox(); // horizonal slider 1 alignment
    QHBoxLayout *layout1 = new QHBoxLayout();

    toonLevelSlider = new QSlider(Qt::Orientation::Horizontal);
    toonLevelSlider->setTickInterval(1);
    toonLevelSlider->setMinimum(1);
    toonLevelSlider->setMaximum(5);
    toonLevelSlider->setValue(1);

    toonLevelBox = new QSpinBox();
    toonLevelBox->setMinimum(1);
    toonLevelBox->setMaximum(5);
    toonLevelBox->setSingleStep(1);
    toonLevelBox->setValue(1);

    layout1->addWidget(toonLevelSlider);
    layout1->addWidget(toonLevelBox);
    toon1Layout->setLayout(layout1);

    QGroupBox *toon2Layout = new QGroupBox(); // horizonal slider 1 alignment
    QHBoxLayout *layout2 = new QHBoxLayout();

    toon2Slider = new QSlider(Qt::Orientation::Horizontal);
    toon2Slider->setTickInterval(1);
    toon2Slider->setMinimum(0);
    toon2Slider->setMaximum(15);
    toon2Slider->setValue(0);

    toon2Box = new QSpinBox();
    toon2Box->setMinimum(0);
    toon2Box->setMaximum(15);
    toon2Box->setSingleStep(1);
    toon2Box->setValue(0);

    layout2->addWidget(toon2Slider);
    layout2->addWidget(toon2Box);
    toon2Layout->setLayout(layout2);


    // Extra Credit:
    ec1 = new QCheckBox();
    ec1->setText(QStringLiteral("Extra Credit 1"));
    ec1->setChecked(false);

    specular_on = new QCheckBox();
    specular_on->setText(QStringLiteral("Specular"));
    specular_on->setChecked(false);

//    vLayout->addWidget(uploadFile);
    vLayout->addWidget(toon_labels);
    vLayout->addWidget(ec1);
    vLayout->addWidget(specular_on);

    vLayout->addWidget(layers_label);
    vLayout->addWidget(toon1Layout);
    vLayout->addWidget(rim_thic_label);
    vLayout->addWidget(toon2Layout);

    connectUIElements();

    //set defualt values here
}

void MainWindow::finish() {
//    realtime->finish();
//    delete(realtime);
}

void MainWindow::connectUIElements() {
    connectToonLevels();
    connectToon2();
    connectExtraCredit();
//    connectUploadFile();
}

void MainWindow::connectToonLevels() {
    connect(toonLevelSlider, &QSlider::valueChanged, this, &MainWindow::onValChangeToonLevels);
    connect(toonLevelBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::onValChangeToonLevels);
}

void MainWindow::connectToon2() {
    connect(toon2Slider, &QSlider::valueChanged, this, &MainWindow::onValChangeToon2);
    connect(toon2Box, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &MainWindow::onValChangeToon2);
}



//void MainWindow::connectNear() {
//    connect(nearSlider, &QSlider::valueChanged, this, &MainWindow::onValChangeNearSlider);
//    connect(nearBox, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
//            this, &MainWindow::onValChangeNearBox);
//}

void MainWindow::connectExtraCredit() {
    connect(ec1, &QCheckBox::clicked, this, &MainWindow::onExtraCredit1);
    connect(specular_on, &QCheckBox::clicked, this, &MainWindow::onSpecularOn);
}

//void MainWindow::connectUploadFile() {
//    connect(uploadFile, &QPushButton::clicked, this, &MainWindow::onUploadFile);
//}



void MainWindow::onValChangeToonLevels(int newValue) {
    toonLevelSlider->setValue(newValue);
    toonLevelBox->setValue(newValue);
    settings.toon_levels = toonLevelSlider->value();
//    realtime->settingsChanged();
}

void MainWindow::onValChangeToon2(int newValue) {
    toon2Slider->setValue(newValue);
    toon2Box->setValue(newValue);
    settings.toon2 = toon2Slider->value();
//    realtime->settingsChanged();
}

//void MainWindow::onValChangeFarSlider(int newValue) {
//    //farSlider->setValue(newValue);
//    farBox->setValue(newValue/100.f);
//    settings.farPlane = farBox->value();
////    realtime->settingsChanged();
//}


//void MainWindow::onValChangeFarBox(double newValue) {
//    farSlider->setValue(int(newValue*100.f));
//    //farBox->setValue(newValue);
//    settings.farPlane = farBox->value();
////    realtime->settingsChanged();
//}

// Extra Credit:

void MainWindow::onExtraCredit1() {
    settings.extraCredit1 = !settings.extraCredit1;
//    realtime->settingsChanged();
}

void MainWindow::onSpecularOn() {
    settings.specular_on = !settings.specular_on;
//    realtime->settingsChanged();
}

//void MainWindow::onUploadFile() {
//    // Get abs path of scene file
//    QString configFilePath = QFileDialog::getOpenFileName(this, tr("Upload File"), QDir::homePath(), tr("Scene Files (*.obj)"));
//    if (configFilePath.isNull()) {
//        std::cout << "Failed to load null scenefile." << std::endl;
//        return;
//    }

//    settings.sceneFilePath = configFilePath.toStdString();

//    std::cout << "Loaded scenefile: \"" << configFilePath.toStdString() << "\"." << std::endl;

//    glWidget->updateObjFile();
////    realtime->sceneChanged();
//}
