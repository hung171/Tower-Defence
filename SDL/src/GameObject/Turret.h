#pragma once
#include <memory>
#include "SDL.h"
#include "CMath.h"
#include "TextureManager.h"
#include "Timer.h"
#include "Enemy.h"
#include "Projectile.h"

class Projectile;

class Turret : public Sprite2D
{
public:
	Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip);
	void	Init() override;
	void Draw(SDL_Renderer* renderer);
	void Update(float deltatime) override;
	//void shootProjectile(std::vector<Projectile> listProjectiles, float angle);

	float UpdateAngle(float x, float y);
	bool inRange(float x, float y);

private:
	std::vector<std::shared_ptr<Projectile>>		t_listPro;

	float angle;
	static const float speedAngular, weaponRange;
	std::weak_ptr<Enemy> enemyTarget;
	Timer timerWeapon;
	std::vector<std::shared_ptr<Projectile>> listProjectile;
	Vector2 pos;
	float t_x, t_y;
};

