#include <jni.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Grid.h"
#include "Grid.cpp"
#include <string>

Grid g;
extern "C"
JNIEXPORT jstring
JNICALL
Java_com_gregmaxin_colourmesilly_MainActivity_stringFromJNI(JNIEnv *env, jobject, int cmd, int x, int y, int z) {
    if (cmd == 1) {
        g.init(5);
    }
    if (cmd == 2){
        g.use(x,y,z);
    }
    std::string display = g.Display();
    return env->NewStringUTF(display.c_str());
}
