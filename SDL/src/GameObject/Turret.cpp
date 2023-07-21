#include "Turret.h"

Turret::Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip)
	: Sprite2D(texture, flip)
{
	m_position.x = 22 * 64;
	m_position.y = 9 * 64;
	m_iWidth = 70;
	m_iHeight = 70;
}

void Turret::Draw(SDL_Renderer* renderer)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight);
	}
}
