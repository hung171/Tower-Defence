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
	void Draw(SDL_Renderer* renderer);
	void Update(float deltatime) override;
	float UpdateAngle(float x, float y);
	bool inRange(float x, float y);
	void Shoot(float x, float y, std::vector<std::shared_ptr<Projectile>>& projectiles);
private:
	
	std::shared_ptr<Projectile> m_ProjectTile;

	float angle;
	static const float speedAngular, weaponRange;
	std::weak_ptr<Enemy> enemyTarget;
	Vector3 pos;
	std::vector<Projectile> m_pro;
	float t_x, t_y;
};

