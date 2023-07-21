#include "SpriteAnimation.h"
#include "TextureManager.h"
#include "CMath.h"

SpriteAnimation::SpriteAnimation(std::shared_ptr<TextureManager> texture, int spriteRow,int end, int frameCount, int numAction, float frameTime) : BaseObject(texture)
{
	m_spriteRow = spriteRow;
	m_frameCount = frameCount;
	m_numAction = numAction;
	m_end = end;
	//m_animSpeed = animSpeed;
	m_frameTime = frameTime;
	//m_flip = flip;
	m_currentFrame = 0;
	m_currentTicks = 0;
	m_lastUpdate = SDL_GetTicks();
	Init();
}
SpriteAnimation::~SpriteAnimation()
{

}

void SpriteAnimation::Init()
{

}

void SpriteAnimation::Draw(SDL_Renderer* renderer)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->RenderFrame(m_position.x, m_position.y, m_iWidth, m_iHeight, m_spriteRow, m_end, m_currentFrame, m_frameCount, m_numAction, m_angle, m_flip);
	}
}

void SpriteAnimation::Update(float deltatime)
{
	m_currentTicks += deltatime;
		if (m_currentTicks  >= m_frameTime) {
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

void SpriteAnimation::Set2DPosition(float x, float y)
{
	m_position = Vector3((float)x, (float)y, 0.0f);
}

void SpriteAnimation::SetRotation(double angle)
{
	m_angle = angle;
}

void SpriteAnimation::SetFlip(SDL_RendererFlip flip)
{ 
	m_flip = flip;
}

Vector2 SpriteAnimation::Get2DPosition()
{
	return Vector2(m_position.x, m_position.y);
}

void SpriteAnimation::SetSize(int width, int height)
{
	m_iWidth = width;
	m_iHeight = height;
	m_scale = Vector3((float)m_iWidth, (float)m_iHeight, 0.0f);
}

int SpriteAnimation::GetWidth()
{
	return m_iWidth;
}

int SpriteAnimation::GetHeight()
{
	return m_iHeight;
}

bool isStop = false;

void SpriteAnimation::MoveLeft(float deltaTime)
{

		m_position.x += 20 * deltaTime;
	
}

void Normalize(Vector3& v)
{
	float lengthSquared = v.x * v.x + v.y * v.y + v.z * v.z;
	if (lengthSquared > 0)
	{
		float inverseLength = 1.0f / sqrt(lengthSquared);
		v.x *= inverseLength;
		v.y *= inverseLength;
		v.z *= inverseLength;

	}
}

int tileSize = 64;

std::vector<Vector3> pathPoints = {
	Vector3(tileSize * 2.5, tileSize * 3, 0),
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

int currentPathIndex = 0;
bool isMoving = true;

void SpriteAnimation::Move(float deltaTime)
{
	if (isMoving && currentPathIndex < pathPoints.size())
	{
		Vector3 targetPoint = pathPoints[currentPathIndex];

		Vector3 direction = targetPoint - m_position;
		float distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);

		if (distance < 5.0f)
		{
			m_position = targetPoint;
			currentPathIndex++;

			if (currentPathIndex == pathPoints.size())
			{
				isMoving = false;
			}
		}
		else
		{
			Normalize(direction);
			m_position += direction * 20 * deltaTime;
		}
	}
}


