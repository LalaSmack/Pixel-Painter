#include "C:\raylib\raylib\src\raylib.h"
#include <iostream>
#include <set>
using namespace std;

int cellSize = 10;
int cellCount = 80;
set<Vector2> painting;
Color color = BLACK;

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

void ColorChange()
{
    if (IsKeyPressed(KEY_ONE))
    {
        color = BLACK;
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        color = RED;
    }
    else if (IsKeyPressed(KEY_THREE))
    {
        color = BLUE;
    }
    else if (IsKeyPressed(KEY_FOUR))
    {
        color = GREEN;
    }
    else if (IsKeyPressed(KEY_FIVE))
    {
        color = YELLOW;
    }
    else if (IsKeyPressed(KEY_SIX))
    {
        color = ORANGE;
    }
    else if (IsKeyPressed(KEY_SEVEN))
    {
        color = PURPLE;
    }
    else if (IsKeyPressed(KEY_EIGHT))
    {
        color = PINK;
    }
    else if (IsKeyPressed(KEY_NINE))
    {
        color = BROWN;
    }
}
void DrawGrid()
{
    for (int i = 0; i < cellCount; i++)
    {
        DrawLine(i * cellSize, 0, i * cellSize, cellSize * cellCount, GRAY);
        DrawLine(0, i * cellSize, cellSize * cellCount, i * cellSize, GRAY);
    }
    for (Vector2 p : painting)
    {
        DrawRectangle(p.x * cellSize, p.y * cellSize, cellSize, cellSize, color);
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
        ColorChange();
        ClearBackground(DARKGRAY);

        EndDrawing();
    }
}
