#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

struct Settings {
    std::string sceneFilePath;
    float ambientParam = 1;
    float rimThickParam = 1;
    float nearPlane = 0.01;
    float farPlane = 100.f;
    bool perPixelFilter = false;
    bool kernelBasedFilter = false;
    bool extraCredit1 = false;
    bool extraCredit2 = false;
    bool extraCredit3 = false;
    bool extraCredit4 = false;
    bool specular_on = false;

    int toon_levels = 1;
    int toon2 = 1;
};


// The global Settings object, will be initialized by MainWindow
extern Settings settings;

#endif // SETTINGS_H
