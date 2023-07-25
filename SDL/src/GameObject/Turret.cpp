#include "Turret.h"


const float Turret::speedAngular = MathAddon::angleDegToRad(180.0f), Turret::weaponRange = 3.0f;

Turret::Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip)
	: Sprite2D(texture, flip)
{
	m_angle = 0.0f;
	m_position.x = 22 * 64;
	m_position.y = 9 * 64;
	m_iWidth = 64;
	m_iHeight = 64;
	pos = Vector2(m_position.x, m_position.y);
}

void Turret::Draw(SDL_Renderer* renderer)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight, m_angle);
	}
}

void Turret::Update(float deltatime)
{
	m_angle += deltatime * 20;
	SetRotation(m_angle);

	Sprite2D::Update(deltatime);
}

