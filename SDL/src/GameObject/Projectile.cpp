#include "Projectile.h"
#include <iostream>

const float Projectile::speed = 300.0f;


Projectile::Projectile(Vector3 setPos, Vector3 setDirectionNormal)

{
	m_position = setPos;
	directionNormal = setDirectionNormal;
	m_pTexture = ResourceManagers::GetInstance()->GetTexture("Turret/Projectile.png");
	m_iWidth = 15;
	m_iHeight = 15;
	m_isMarkedForDeletion = false;
	maxdistance = 200.0f;
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

	// Tính toán khoảng cách đã bay của đạn
	distanceTraveled += speed * deltatime;
	std::cout << distanceTraveled;
	// Kiểm tra xem đạn đã bay quá maxdistance chưa
	if (distanceTraveled >= maxdistance)
	{
		Destroy(); // Gọi hàm Destroy để đánh dấu đạn cần bị xóa
	}
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
	maxdistance = 0.0f; // Reset giá trị distanceTraveled khi đạn bị xoá
}


bool Projectile::IsMarkedForDeletion()
{
	return m_isMarkedForDeletion;
}

