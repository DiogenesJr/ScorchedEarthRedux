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

#define DEBUG_MODE true

typedef enum GameScreen {LOGO = 0, TITLE, GAMEMENU,GAMEPLAY, ENDING} GameScreen;
int screenWidth, screenHeight;
int frameCounter = 0;
bool isFullScreen;
GameScreen currentScreen;

//------------------------------------------------------------------------------------
// Debug information starting with screen dimensions and mouse cursor position
//------------------------------------------------------------------------------------
void displayDebugInformation() {
    Vector2 mousePosition = GetMousePosition();
    string mouseXPosition = to_string(mousePosition.x);
    string mouseYPosition = to_string(mousePosition.y);
    string mousePositionString = "(" + mouseXPosition + "," + mouseYPosition + ")";
    string screenDimensionStrings = "(" + to_string(screenWidth) + "," + to_string(screenHeight) + ")";
    DrawText(mousePositionString.data(), 20, 20, 40, DARKBLUE);
    DrawText(screenDimensionStrings.data(), 20, 60, 40, DARKBLUE);
}

//------------------------------------------------------------------------------------
// Set window parameters using values retrieve from the game engine object
//------------------------------------------------------------------------------------
void SetWindowSize(string* screenTitle) {
    // Initialization
    //--------------------------------------------------------------------------------------
    int display = GetCurrentMonitor();

    InitWindow(screenWidth, screenHeight, screenTitle->data());
    if (isFullScreen) {
        screenWidth = GetMonitorWidth(display);
        screenHeight = GetMonitorHeight(display);

        SetWindowSize(screenWidth, screenHeight );
        ToggleFullscreen();
    }
    else {
        SetWindowSize(screenWidth, screenHeight);
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
        
            currentScreen = GAMEMENU;
        
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
    } break;
    case TITLE:
    {
        DrawText("SCORCHED EARTH!", screenCenterWidth, screenCenterHeight, 40, BLACK);
        DrawText("PRESS ENTER to start", screenCenterWidth, screenCenterHeight + 50, 20, BLACK);

    } break;
    case GAMEMENU:
    {
        int menuWidth = 600;
        int menuHeight = 500;
        int menuXPosition = (screenWidth / 2) - (menuWidth / 2);
        int menuYPosition = (screenHeight / 2) - (menuHeight / 2);

        DrawRectangle(menuXPosition, menuYPosition, menuWidth, menuHeight, GRAY);
        DrawText("This is a game menu?", menuXPosition + 50, menuYPosition + 50, 20, BLACK);
    }break;
    case GAMEPLAY:
    {
        // TODO: Draw GAMEPLAY screen here!
        DrawRectangle(0, 0, screenWidth, screenHeight, LIGHTGRAY);
        DrawText("GAMEPLAY SCREEN", 20, 20, 40, BLACK);
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
    //These should eventually be loaded into the game engine
    //from a settings file / db
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
        if (DEBUG_MODE) {
            displayDebugInformation();
        }

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