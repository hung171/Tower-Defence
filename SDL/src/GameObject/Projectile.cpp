#include "Projectile.h"
#include <iostream>

const float Projectile::speed = 10.0f, Projectile::size = 0.2f;


Projectile::Projectile(float x, float y, float mouse_x, float mouse_y)
{
	pos = Vector3(m_position.x, m_position.y, 0.0f);
	m_pTexture = ResourceManagers::GetInstance()->GetTexture("Turret/Projectile.png");
	m_position.x = x;
	m_position.y = y;
	m_iWidth = 15;
	m_iHeight = 15;
	p_x = mouse_x;
	p_y = mouse_y;
}

void Projectile::Draw(SDL_Renderer* renderer)
{
	if (!isFire) {
		return;
	}
	if (m_pTexture != nullptr)
	{
		//std::cout << 1;
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight, m_angle);
	}
}

void normalize_1(Vector3& vector)
{
	float lengthSquared = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
	if (lengthSquared > 0)
	{
		float inverseLength = 1.0f / sqrt(lengthSquared);
		vector.x *= inverseLength;
		vector.y *= inverseLength;
		vector.z *= inverseLength;

	}
}

void Projectile::Update(float deltatime)
{
	if (!isFire) {
		return;
	}
	
	Vector3 mouse_position = Vector3(p_x, p_y, 0.0f);
	Vector3 direction = mouse_position - pos;
	normalize_1(direction);
	m_position += direction * 20 * deltatime;

}




