#include "Turret.h"


//const float Turret::speedAngular = MathAddon::angleDegToRad(180.0f), Turret::weaponRange = 3.0f;

Turret::Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip)
	: Sprite2D(texture, flip), timerWeapon(1.0f)
{
	m_angle = 0.0f;
	m_position.x = 22 * 64;
	m_position.y = 9 * 64;
	m_iWidth = 64;
	m_iHeight = 64;
	pos = Vector2(m_position.x, m_position.y);
	t_x = 0;
	t_y = 0;
	Init();
}

void Turret::Init()
{
	auto m_Pro = std::make_shared<Projectile>(m_position.x, m_position.y, t_x, t_y);
	t_listPro.push_back(m_Pro);
}

void Turret::Draw(SDL_Renderer* renderer)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight, m_angle);
	}
	for (auto it : t_listPro) {
		it->Draw(renderer);
	}
}

void Turret::Update(float deltatime)
{
	//m_angle += deltatime * 20;

	//Uint32 mouseState = SDL_GetMouseState(&x, &y);
	SetRotation(UpdateAngle(t_x, t_y));

	for (auto it : t_listPro) {
		it->Update(deltatime);
	}
	
}


float Turret::UpdateAngle(float x, float y)
{
	t_x = x;
	t_y = y;
	float angel;
	if (inRange(x, y)) {
		return angle = -10 + atan2(y - (m_position.y + 32), x - (m_position.x + 32)) * 180.0 / M_PI;
	}
	return 0;
}

bool Turret::inRange(float x, float y)
{
	int distance = sqrt((x - (m_position.x + 32)) * (x - (m_position.x + 32)) + (y - (m_position.y + 32)) * (y - (m_position.y + 32)));
	if (distance > 64 * 3) {
		return false;
	}
	for (auto it : t_listPro) {
		it->isFire=true;
	}
	return true;
}

//void Turret::shootProjectile(std::vector<Projectile> listProjectiles, float angle) {
//	//Shoot a projectile towards the target unit if the weapon timer is ready.
//	if (timerWeapon.timeSIsZero()) {
//		listProjectiles.push_back(Projectile(Vector2(angle)));
//
//		timerWeapon.resetToMax();
//	}
//}
//
//


  