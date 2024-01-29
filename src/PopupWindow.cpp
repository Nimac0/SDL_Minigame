#include <iostream>
#include "PopupWindow.h"
#include "TextureManager.h"
#include "SDL_image.h"
#include "Game.h"

PopupWindow::PopupWindow(const char* title, const std::string &message) :
continueGame(false), interacted(false) {
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 250, 0);
    //font = TTF_OpenFont("assets/Trajan.ttf", 24); // Change the path and size as needed

    this->renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

    //SDL_Surface* surface = TTF_RenderText_Blended(font, message.c_str(), {255, 255, 255});
    //texture = SDL_CreateTextureFromSurface(renderer, surface);

    //SDL_FreeSurface(surface);
}

PopupWindow::~PopupWindow() {
    SDL_DestroyTexture(this->texture);
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

void PopupWindow::handleWinnerEvents() {

    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            continueGame = false;
            interacted = true;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_c)
            {
                continueGame = true;
                interacted = true;
            }
            else if (e.key.keysym.sym == SDLK_q)
            {
                continueGame = false;
                interacted = true;
            }
        }
    }
}

bool PopupWindow::shouldContinue() const {
    return continueGame;
}

void PopupWindow::renderWinnerPopup(bool winner) {

    SDL_RenderClear(this->renderer);

    this->texture = winner ? IMG_LoadTexture(this->renderer, "assets/Player1Victory.png")
            : IMG_LoadTexture(this->renderer, "assets/Player2Victory.png");

    SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);

    SDL_RenderPresent(this->renderer);

    //Error handling for debugging
    const char* sdlError = SDL_GetError();
    if (*sdlError != '\0') {
        std::cerr << "SDL Error: " << sdlError << std::endl;
        SDL_ClearError();
    }

}
