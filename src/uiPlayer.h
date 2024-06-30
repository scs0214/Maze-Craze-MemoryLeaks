#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class PlayerUI {
public:
    PlayerUI();
    ~PlayerUI();
    void renderPlayer(SDL_Renderer* renderer, int row, int col, int num);
    bool processInputP1(char& direction);
    bool processInputP2(char& direction);
    int setPosition(int rowBackend, int colBackend, int cellSize);

private:
    SDL_Texture* texture;
    int positionX;
    int positionY;
    int jumpWallAmount;
};

#endif