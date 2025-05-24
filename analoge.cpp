#include "analoge.hpp"

void analoge::draw() const
{
    drawFace();
    drawhours();
    drawMin(minutes);
    drawHor(hour,minutes);
    drawSec(second);
    DrawCircleV(position , 15 , DARKGRAY);
}
void analoge::update()
{
    //look
    std::time_t t = std::time(0);
    //converting this time to local time
    std::tm* now = std::localtime(&t);//now is the pointer to a tm structure that holds the current local time including fields like the current year , month,day,hour,minutes , second and more all adjusted to the local time zone
     hour = now->tm_hour % 12;
     minutes = now->tm_min;
     second = now->tm_sec;

}
void analoge::drawFace() const
{
    DrawCircleV(position , radius , BLACK);//vector2 center , float radius and color
    DrawCircleV(position , radius-30 , LIGHTGRAY);
    DrawCircleV(position , radius-40 , RAYWHITE);
}
void analoge::drawhours() const{
    float rectW = 10;
    float rectH = radius;
    float rectX =  rectW / 2;
    Rectangle rect = {position.x , position.y , rectW , rectH};
    for(int i = 0 ; i< 12 ; i++){
        DrawRectanglePro(rect, {rectX, rectH}, i*30, BLACK);
    }
    DrawCircleV(position , radius-50 , RAYWHITE);
}

void analoge::drawMin(int minutes) const{
    float handlerectW = 10;
    float handlerectH = radius*0.7;//making slightly shorter
    float handlerectX =  handlerectW / 2;
    Rectangle handlerect = {position.x , position.y , handlerectW , handlerectH};
    int angle = minutes*6;//look
    DrawRectanglePro(handlerect, {handlerectX, handlerectH}, angle, DARKGRAY);

}

void analoge::drawHor(int hour , int minutes) const
{
    float HourhandlerectW = 10;
    float HourhandlerectH = radius*0.5;//making slightly shorter
    float HourhandlerectX =  HourhandlerectW / 2;
    Rectangle Hourhandlerect = {position.x , position.y , HourhandlerectW , HourhandlerectH};
    int Rotationangle = 30 * hour + (minutes/60.0)*30;//look
    DrawRectanglePro(Hourhandlerect, {HourhandlerectX, HourhandlerectH}, Rotationangle, DARKGRAY);
}

void analoge::drawSec(int second) const
{
    float SecHandlerectW = 5;
    float SecHandlerectH = radius*1.05;
    float SecHandlerectX =  SecHandlerectW / 2;
    Rectangle sechandlerect = {position.x , position.y , SecHandlerectW , SecHandlerectH};
    int secangle = second*6;//look
    DrawRectanglePro(sechandlerect, {SecHandlerectX, SecHandlerectH - 45}, secangle, RED);

}