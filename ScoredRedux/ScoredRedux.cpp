/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "GameEngine.h"

typedef enum GameScreen {LOGO = 0, TITLE, GAMEPLAY, ENDING} GameScreen;
int screenWidth, screenHeight;
int frameCounter = 0;
bool isFullScreen;
GameScreen currentScreen;

//------------------------------------------------------------------------------------
// Set window parameters using values retrieve from the game engine object
//------------------------------------------------------------------------------------
void SetWindowSize(string* screenTitle) {
    // Initialization
    //--------------------------------------------------------------------------------------
    int display = GetCurrentMonitor();

    InitWindow(screenWidth, screenHeight, screenTitle->data());
    if (isFullScreen) {
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        ToggleFullscreen();
    }
    else {
        SetWindowSize(screenWidth, screenHeight);
    }   
}

void DrawCurrentScreen(GameScreen currentGameScreen) {
    switch (currentGameScreen)
    {
    case LOGO:
    {
        // TODO: Draw LOGO screen here!
        DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
        DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

    } break;
    case TITLE:
    {
        // TODO: Draw TITLE screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
        DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
        DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

    } break;
    case GAMEPLAY:
    {
        // TODO: Draw GAMEPLAY screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
        DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
        DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

    } break;
    case ENDING:
    {
        // TODO: Draw ENDING screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
        DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
        DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

    } break;
    default: break;
    }
}

void DetermineGameScreen() {
    switch (currentScreen) {
    case LOGO:
    {
        frameCounter++;
        if (frameCounter > 120) {
            currentScreen = TITLE;
            frameCounter = 0;
        }
    }break;
    case TITLE:
    {
        if (IsKeyPressed(KEY_ENTER)) {
            currentScreen = GAMEPLAY;
        }
    }break;
    default:break;
    }
}

void DrawCurrentScreen() {
    int screenCenterWidth = screenWidth / 2;
    int screenCenterHeight = screenHeight / 2;

    switch (currentScreen)
    {
    case LOGO:
    {
        // TODO: Draw LOGO screen here!
        DrawText("Scorched Earth: Redux!", screenCenterWidth, screenCenterHeight, 40, BLACK);
        DrawText("WAIT for 2 SECONDS...", screenCenterWidth, screenCenterHeight + 50, 20, GRAY);

    } break;
    case TITLE:
    {
        DrawText("SCORCHED EARTH!", screenCenterWidth, screenCenterHeight, 40, BLACK);
        DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", screenCenterWidth, screenCenterHeight + 50, 20, BLACK);

    } break;
    case GAMEPLAY:
    {
        // TODO: Draw GAMEPLAY screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
        DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
        DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

    } break;
    case ENDING:
    {
        // TODO: Draw ENDING screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
        DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
        DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

    } break;
    default: break;
    }
}

void WriteMessageToScreen(const char* messageText, int xPosition, int yPosition) {
    DrawText(messageText, xPosition, yPosition, 45, BLACK);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    //Initialize game engine with default values
    GameEngine engine = GameEngine::GameEngine();
    screenWidth = engine.defaultScreenWidth;
    screenHeight = engine.defaultScreenWidth;
    isFullScreen = engine.isFullScreen;
    currentScreen = LOGO;

    //Initializing window.  Going full screen for now.
    //TODO: Make this a setting / configurable
    SetWindowSize(&engine.gameTitle);
    SetTargetFPS(engine.targetFPS);               // Set our game to run at 60 frames-per-second

    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);
        DetermineGameScreen();
        DrawCurrentScreen();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}