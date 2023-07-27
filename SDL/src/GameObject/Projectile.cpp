#include "Projectile.h"

const float Projectile::speed = 100.0f, Projectile::size = 0.2f,
Projectile::distanceTraveledMax = 20.0f;


Projectile::Projectile(Vector3 setPos, Vector3 setDirectionNormal)

{
	m_position = setPos;
	directionNormal = setDirectionNormal;
	m_pTexture = ResourceManagers::GetInstance()->GetTexture("Turret/Projectile.png");
	m_iWidth = 15;
	m_iHeight =15;
}

void Projectile::Draw(SDL_Renderer* renderer)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight, m_angle);
	}
}

void Projectile::Update(float deltatime)
{
	float distanceMove = speed * deltatime;
	m_position += directionNormal * distanceMove;

	distanceTraveled += distanceMove;
	if (distanceTraveled >= distanceTraveledMax)
		collisionOccurred = true;;
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

void Projectile::SetDirection(float x, float y)
{
	Vector3 newDirection(x - m_position.x, y - m_position.y, 0.0f);
	normalize_1(newDirection);
	directionNormal = Vector3(newDirection.x, newDirection.y, 0.0f);
}


