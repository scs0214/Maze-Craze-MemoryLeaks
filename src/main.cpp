#include <iostream>
#include "UI_TitleScreen.h"
#include "UI_Treasure.h"
#include "UI_Main.h"

int main(int argc, char* argv[]) {
    UI_TitleScreen UI_TitleScreen;
    UI_MAIN UI_Main;
    UI_Treasure UI_Treasure;

    enum GameState {
        TITLE_SCREEN, MAIN_PROGRAM, WIN_SCREEN
    };

    if (!UI_Main.initialize()) {
    if (!UI_Main.initialize()) {
        return 1;
    }

    GameState gameState = TITLE_SCREEN;

    SDL_Renderer* renderer = UI_Main.getRenderer();
    SDL_Event event;
    GameState gameState = TITLE_SCREEN;

    SDL_Renderer* renderer = UI_Main.getRenderer();
    SDL_Event event;
    bool running = true;
    char direction = 'x';
    char direction = 'x';

    while (running) {
        if (gameState == TITLE_SCREEN) {
            UI_TitleScreen.runTitleScreen(renderer);
        } else if (gameState == MAIN_PROGRAM) {
            // UI_Main.renderMainProgram(matrix, playerNumber); // AQUI SE UTILIZAN LOS VALORES DEL BACKEND PARA RENDERIZAR
        }
        else if (gameState == WIN_SCREEN) {
            UI_Treasure.runWinScreen(renderer, 1);
        }

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (gameState == TITLE_SCREEN) {
                if (UI_TitleScreen.handleEvents(event)) {
                    gameState = MAIN_PROGRAM;
                }
            } else if (gameState == MAIN_PROGRAM) {
                // UI_Main.handleEvents(event, gameState);
            }
        }
        if (gameState == TITLE_SCREEN) {
            UI_TitleScreen.runTitleScreen(renderer);
        } else if (gameState == MAIN_PROGRAM) {
            // UI_Main.runMainProgram(matrix, playerNumber); // AQUI SE UTILIZAN LOS VALORES DEL BACKEND PARA RENDERIZAR
        }

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (gameState == TITLE_SCREEN) {
                if (UI_TitleScreen.handleEvents(event)) {
                    gameState = MAIN_PROGRAM;
                }
            } else if (gameState == MAIN_PROGRAM) {
                // UI_Main.handleEvents(event, gameState);
            }
        }
    }

    return 0;
}
