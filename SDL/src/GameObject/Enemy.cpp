﻿#include "Enemy.h"
#include "CMath.h"
#include "EnemyPool.h"
#include <iostream>
#include "Projectile.h"

int tileSize = 64;


Enemy::Enemy(std::shared_ptr<TextureManager> texture, int spriteRow, int end, int frameCount, int numAction, float frameTime)
	: SpriteAnimation(texture, spriteRow, end, frameCount, numAction, frameTime)
{
    isMoving = true;
    currentPathIndex = 0;
    isDestroyed = false;
}
Enemy::~Enemy()
{

}

void Enemy::Init()
{

}

void Enemy::Update(float deltaTime)
{
    // Cập nhật hành động của enemy tại đây
    m_currentTicks += deltaTime;
    if (m_currentTicks >= m_frameTime) {
        m_currentFrame++;
        if (m_currentFrame >= m_end) {
            m_currentFrame = 0;
        }
        if (m_currentFrame >= m_frameCount) {
            m_currentFrame = 0;
        }
        m_currentTicks -= m_frameTime;
    }
}




void normalize(Vector3& vector)
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

std::vector<Vector3> pathPoints = {
	Vector3(tileSize * 2.5, tileSize * 7, 0),
	Vector3(tileSize * 1.5, tileSize * 7, 0),
	Vector3(tileSize * 1.5, tileSize * 10, 0),
	Vector3(tileSize * 5.5, tileSize * 10, 0),
	Vector3(tileSize * 5.5, tileSize * 8, 0),
	Vector3(tileSize * 9.5, tileSize * 8, 0),
	Vector3(tileSize * 9.5, tileSize * 4, 0),
	Vector3(tileSize * 6.5, tileSize * 4, 0),
	Vector3(tileSize * 6.5, tileSize * 1, 0),
	Vector3(tileSize * 13.5, tileSize * 1, 0),
	Vector3(tileSize * 13.5, tileSize * 10, 0),
	Vector3(tileSize * 17.5, tileSize * 10, 0),
	Vector3(tileSize * 17.5, tileSize * 2, 0),
};

void Enemy::Move(float deltaTime)
{
    if (!isDestroyed && isMoving && currentPathIndex < pathPoints.size())
    {
        Vector3 targetPoint = pathPoints[currentPathIndex];

        Vector3 direction = targetPoint - m_position;
        float distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);

        if (distance < 10.0f)
        {
            m_position = targetPoint;
            currentPathIndex++;

            if (currentPathIndex < pathPoints.size())
            {
                targetPoint = pathPoints[currentPathIndex];
                direction = targetPoint - m_position;
                distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
            }
            else
            {
                // Gọi hàm hủy khi enemy đi đến điểm tọa độ cuối
                Destroy();
                return;
            }
        }

        if (distance >= 10.0f)
        {
            normalize(direction);
            m_position += direction * 20 * deltaTime;
        }
    }
}


void Enemy::Destroy()
{

    // Đánh dấu là Enemy đã bị hủy
    isDestroyed = true;
}


bool Enemy::IsDestroyed() const
{
    return isDestroyed;
}

bool Enemy::getIsAlive()
{
    return isAlive;
}

Vector2 Enemy::GetPosition() 
{
    return Vector2(m_position.x, m_position.y);
}

Vector2 Enemy::GetSize() 
{
    return Vector2(m_iWidth, m_iHeight);
}











