#pragma once
#include<raylib.h>
#include<ctime>
class analoge{
    private:
        int radius;
        Vector2 position;
        int hour;
        int minutes;
        int second;
        void drawFace() const;
        void drawhours()const;
        void drawMin(int minutes) const;
        void drawHor(int hour , int minutes) const;
        void drawSec(int second) const;
        
    public:
        analoge(int radius , Vector2 position) : radius(radius) , position(position),hour(0),minutes(0),second(0){};
        void draw() const;
        void update();
};