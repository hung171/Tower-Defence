#include "Turret.h"

//const float Turret::speedAngular = MathAddon::angleDegToRad(180.0f), Turret::weaponRange = 3.0f;

Turret::Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip)
	: Sprite2D(texture, flip)
{
	m_angle = 0.0f;
	m_position.x = 64 ;
	m_position.y = 64 *6 ;
	m_iWidth = 64;
	m_iHeight = 64;
	t_x = 0;
	t_y = 0;
	//m_ProjectTile = std::make_shared<Projectile>(Get2DPosition(), Vector3(t_x, t_y, 0.0f));
}

void Turret::Draw(SDL_Renderer* renderer)
{
	//m_ProjectTile->Draw(renderer);
	if (m_pTexture != nullptr)
	{
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight, m_angle);
	}
}

void Turret::Update(float deltatime)
{
	//m_angle += deltatime * 20;

	//Uint32 mouseState = SDL_GetMouseState(&x, &y);
	SetRotation(UpdateAngle(t_x, t_y));

}
	

float Turret::UpdateAngle(float x, float y)
{
	t_x = x;
	t_y = y;
	if (inRange(x, y)) {
		return atan2(y - (m_position.y + 32), x - (m_position.x + 32)) * 180.0 / M_PI;
	}
	return 0;
}

bool Turret::inRange(float x, float y)
{
	int distance = sqrt((x - (m_position.x + 32)) * (x - (m_position.x + 32)) + (y - (m_position.y + 32)) * (y - (m_position.y + 32)));
	if (distance > 64 * 4) {
		return false;
	}
	return true;
}

void Turret::Shoot(float x, float y, std::vector<std::shared_ptr<Projectile>>& projectiles)
{
	if (inRange(x, y))
	{
		pos = Vector3(m_position.x + 32 - 7.5, m_position.y + 32 - 7.5, 0.0f);
		std::shared_ptr<Projectile> projectile = std::make_shared<Projectile>(pos, Vector3(x, y, 0.0f));
		projectile->SetDirection(x, y);
		projectiles.push_back(projectile);
	}

}






  