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
	// Cập nhật vị trí của đạn
	m_position += directionNormal * speed * deltatime;


}


void Projectile::SetDirection(float x, float y)
{
	Vector3 newDirection(x - m_position.x, y - m_position.y, 0.0f);
	normalize_1(newDirection);
	directionNormal = Vector3(newDirection.x, newDirection.y, 0.0f);
}

Vector2 Projectile::GetPosition() 
{
	return Vector2(m_position.x, m_position.y);
}

Vector2 Projectile::GetSize() 
{
	return Vector2(m_iWidth, m_iHeight);
}

void Projectile::Destroy()
{
	m_isMarkedForDeletion = true;
}

bool Projectile::IsMarkedForDeletion() 
{
	return m_isMarkedForDeletion;
}