#include <iostream>
#include <raylib.h>
#include"analoge.hpp"

using namespace std;

int main () {
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 600;


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "analoge clock");
    SetTargetFPS(15);
    analoge an{250,{300,300}};

    while (WindowShouldClose() == false){
        //updating
        an.update();

        BeginDrawing();
        ClearBackground(BLACK);
        an.draw();
         
        EndDrawing();
    }

    CloseWindow();
}