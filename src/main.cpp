#include "C:\raylib\raylib\src\raylib.h"
#include <iostream>
#include <set>
using namespace std;

int cellSize = 10;
int cellCount = 80;
set<Vector2> painting;

bool operator<(const Vector2 v1, const Vector2 v2)
{
    if (v1.x == v2.x)
    {
        return v1.y < v2.y;
    }
    return v1.x < v2.x;
}

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

    void MarkCell()
    {
        if (IsKeyDown(KEY_SPACE))
        {
            painting.insert(dot);
        }
    }

    void UnmarkCell()
    {
        if (IsKeyDown(KEY_BACKSPACE))
        {
            painting.erase(dot);
        }
    }
};

void DrawGrid()
{
    for (int i = 0; i < cellCount; i++)
    {
        DrawLine(i * cellSize, 0, i * cellSize, cellSize * cellCount, GRAY);
        DrawLine(0, i * cellSize, cellSize * cellCount, i * cellSize, GRAY);
    }
    for (Vector2 p : painting)
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

        DrawGrid();
        dot.DrawDot();
        dot.MoveDot();
        dot.MarkCell();
        dot.UnmarkCell();
        ClearBackground(DARKGRAY);

        EndDrawing();
    }
}
