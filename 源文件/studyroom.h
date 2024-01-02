#ifndef STUDYROOM_H
#define STUDYROOM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <map>
using namespace std;

class Time
{
public:
    double hour;
    double minute;
    double second;
    Time();
    void Menu();
    void KeyInput();
    void settime();
    void display();
    void Reset();
};

#endif
