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
    Vector2     GetPosition();
    Vector2     GetSize();
    void Destroy();
    bool IsMarkedForDeletion();

private:
    static const float speed, size, distanceTraveledMax;
    float distanceTraveled = 0.0f;
    Vector3 pos, directionNormal;
    float maxdistance;
    bool m_isMarkedForDeletion;
};
