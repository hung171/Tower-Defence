#pragma once
#include "GameStateBase.h"
#include "GameObject/MouseButton.h"
#include "Sound.h"
#include "Timer.h"
#include "GSWin.h"

class Sprite2D;
class SpriteAnimation;
class MapManager;
class Enemy;
class Turret;
class EnemyPool;
class Projectile;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(SDL_Event& e) override;
	void	HandleTouchEvents(SDL_Event& e, Uint8 btn, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw(SDL_Renderer* renderer) override;

	bool CheckWinCondition() const;
	bool CheckLoseCondition() const;
	//void	HandleMouseEvent(SDL_MouseMotionEvent event);
	int p_KeyPress;

private:
	bool CheckCollision(SDL_Rect a, SDL_Rect b);

	std::shared_ptr<Sprite2D>	p_background;
	std::shared_ptr<Sprite2D>	p_h_start;
	std::shared_ptr<Sprite2D>	p_h_end;

	std::shared_ptr<MapManager> p_mapManager;
	std::list<std::shared_ptr<Turret>>	p_listTurret;
	std::shared_ptr<Turret>		p_turret_1,
		p_turret_2,
		p_turret_3,
		p_turret_4;

	Timer m_countdown;

	//std::shared_ptr<Text>		m_score;
	std::shared_ptr<Sound>					p_Sound;
	std::list<std::shared_ptr<MouseButton>>	p_listButton;
	std::list<std::shared_ptr<Sprite2D>>	tileList;
	std::list<std::shared_ptr<SpriteAnimation>>	p_listAnimation;
	std::list<std::shared_ptr<Enemy>>	p_listEnemy;

	std::shared_ptr<EnemyPool> p_enemyPool;
	std::shared_ptr<MouseButton> button;
	std::vector<Vector3> pathPoints;
	std::vector<std::shared_ptr<Projectile>> p_listProjectiles;

	float m_Velocity = 10.0f;
	float p_x, p_y;
	float mouseX, mouseY;
	//float time;

	// check status
	bool m_isWin;
	bool m_isLose;
	float shootCooldown;
	int count = 0;
};