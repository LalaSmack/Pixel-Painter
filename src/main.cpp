#include "C:\raylib\raylib\src\raylib.h"
#include <iostream>
#include <list>
using namespace std;

int cellSize = 10;
int cellCount = 80;
list<Vector2> painting;

class Dot
{
public:
    Vector2 dot = {40, 40};
    void DrawDot()
    {
        DrawRectangle(dot.x * cellSize, dot.y * cellSize, cellSize, cellSize, WHITE);
    }

    void MoveDot()
    {
        if (IsKeyPressed(KEY_UP))
        {
            dot.y--;
        }
        if (IsKeyPressed(KEY_DOWN))
        {
            dot.y++;
        }
        if (IsKeyPressed(KEY_LEFT))
        {
            dot.x--;
        }
        if (IsKeyPressed(KEY_RIGHT))
        {
            dot.x++;
        }
    }

    void MarkDot()
    {
        if (IsKeyDown(KEY_SPACE))
        {
            painting.push_back(dot);
        }
    }
};

void drawGrid()
{
    for (int i = 0; i < cellCount; i++)
    {
        DrawLine(i * cellSize, 0, i * cellSize, cellSize * cellCount, GRAY);
        DrawLine(0, i * cellSize, cellSize * cellCount, i * cellSize, GRAY);
    }
    for (auto p : painting)
    {
        DrawRectangle(p.x * cellSize, p.y * cellSize, cellSize, cellSize, BLACK);
    }
}

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Pixel Painter");
    SetTargetFPS(60);
    Dot dot;
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        drawGrid();
        dot.DrawDot();
        dot.MoveDot();
        dot.MarkDot();
        ClearBackground(DARKGRAY);

        EndDrawing();
    }
}
