#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>

#include "Vector2D.h"
#include "Entity.h"

class AssetManager;
class CollisionHandler;
class TextureManager;
class SoundManager;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void selectCharacters(const char* &playerSprite, const char* &enemySprite);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() const;

	static void addTile(unsigned long id, int x, int y);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static CollisionHandler* collisionHandler;
    static AssetManager* assets;
    static TextureManager* textureManager;
    static SoundManager* soundManager;

    void refreshPlayers();
    Entity::TeamLabel getWinner() const;

private:
    void setWinner(Entity::TeamLabel winningTeam);

	int counter = 0;
	bool isRunning = false;
	SDL_Window* window;
    Entity::TeamLabel winner;
};
