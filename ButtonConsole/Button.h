#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;

class UIElement {
public:
    static int count;
    virtual void draw() {};
    virtual void drawHor() {};
};

extern vector<class Button> listt;
extern int resultAgeConfirm;

class Button : public UIElement {
public:
    int size_x;
    int size_y;
    string text;
    int padding_horizontal;
    bool checkVal;
    bool target;

    Button();
    Button(int size_x, int size_y, string text, int padding_horizontal = 1);

    bool checktarget();
    void swapTarget();
    void draw() override;
};

class Column : public UIElement {
public:
    vector<UIElement*> components;
    Column(vector<UIElement*> components);
    void draw() override;
};

class Row : public UIElement {
public:
    vector<Button*> components;
    Row(vector<Button*> components);
    void draw() override;
    void printStr(int number);
};

class Window {
public:
    int size_x;
    int size_y;
    UIElement* component;

    Window(int size_x, int size_y, UIElement* component);
    void draw();
};

bool selectStartColor();

bool selectGameMode();

bool drawTest();

#endif