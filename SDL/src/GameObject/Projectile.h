#include <memory>
#include "SDL.h"
#include "CMath.h"
#include "TextureManager.h"
#include "Timer.h"
#include "ResourceManagers.h"


class Projectile : public Sprite2D
{
public:
	Projectile(float x, float y, float mouse_x, float mouse_y);
	//void Draw(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer) override;
	void Update(float deltatime) override;

	//float UpdateAngle(int x, int y);
	//bool inRange(int x, int y);

	bool isFire = false;

private:
	static const float speed, size;
	static const int distanceTraveledMax = 64 * 3;
	Vector3 pos;
	Vector2 directionNormal;
	int distanceTraveled;
	bool collisionOccurred = false;
	float p_x, p_y;
};
