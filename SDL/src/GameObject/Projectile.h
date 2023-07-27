#pragma once
#include <memory>
#include "SDL.h"
#include "CMath.h"
#include "TextureManager.h"
#include "Timer.h"
#include "Enemy.h"
#include "ResourceManagers.h"



class Projectile : public Sprite2D
{
public:
	Projectile(Vector3 setPos, Vector3 setDirectionNormal);
	void Draw(SDL_Renderer* renderer);
	void Update(float deltatime) override;
	void SetDirection(float x, float y);
private:
	//Vector2D pos, directionNormal;
	static const float speed, size, distanceTraveledMax;
	float distanceTraveled = 0.0f;
	Vector3 pos, directionNormal;

	bool collisionOccurred = false;
};

