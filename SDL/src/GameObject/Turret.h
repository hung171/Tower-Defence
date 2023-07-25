#pragma once
#include <memory>
#include "SDL.h"
#include "CMath.h"
#include "TextureManager.h"
#include "Timer.h"
#include "Enemy.h"



class Turret : public Sprite2D
{
public:
	Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip);
	void Draw(SDL_Renderer* renderer);
	void Update(float deltatime) override;
	float UpdateAngle(int x, int y);

	bool inRange(int x, int y);

private:
	float angle;
	static const float speedAngular, weaponRange;
	std::weak_ptr<Enemy> enemyTarget;

	Vector2 pos;
	int t_x, t_y;
};

