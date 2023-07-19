#pragma once
#include <queue>
#include <vector>
#include <string>
#include "SDL.h"
#include "CMath.h"
#include "TextureManager.h"
#include "ResourceManagers.h"



class Level
{
private:
	static const unsigned char flowDistanceMax = 255;

	struct Tile {
		bool isWall = false;
		int flowDirectionX = 0;
		int flowDirectionY = 0;
		unsigned char flowDistance = flowDistanceMax;
	};


public:

	Level(int setTileCountX, int setTileCountY);
	~Level();
	void draw(SDL_Renderer* renderer, int tileSize);

	bool isTileWall(int x, int y);
	void setTileWall(int x, int y, bool setWall);
	Vector2 getTargetPos();
	Vector2 getFlowNormal(int x, int y);



private:
	void drawTile(SDL_Renderer* renderer, int x, int y, int tileSize);
	void calculateFlowField();
	void calculateDistances();
	void calculateFlowDirections();


	std::vector<Tile> listTiles;
	const int tileCountX, tileCountY;

	const int targetX = 0, targetY = 0;

	SDL_Texture* textureTileWall = nullptr,
		* textureTileTarget = nullptr,
		* textureTileEmpty = nullptr,
		* textureTileArrowUp = nullptr,
		* textureTileArrowUpRight = nullptr,
		* textureTileArrowRight = nullptr,
		* textureTileArrowDownRight = nullptr,
		* textureTileArrowDown = nullptr,
		* textureTileArrowDownLeft = nullptr,
		* textureTileArrowLeft = nullptr,
		* textureTileArrowUpLeft = nullptr;
};