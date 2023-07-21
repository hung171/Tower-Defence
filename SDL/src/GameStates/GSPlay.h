#pragma once
#include "GameStateBase.h"
#include "GameObject/MouseButton.h"
class Sprite2D;
class SpriteAnimation;
class MapManager;
class Enemy;
class Turret;

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
	void	HandleTouchEvents(SDL_Event& e, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw(SDL_Renderer* renderer) override;
	int m_KeyPress;

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<MapManager> m_mapManager;
	std::shared_ptr<Enemy> m_enemy;
	std::list<std::shared_ptr<Turret>>	m_listTurret;
	std::shared_ptr<Turret>		m_turret_1,
		m_turret_2,
		m_turret_3,
		m_turret_4;

	//std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<MouseButton>>	m_listButton;
	std::list<std::shared_ptr<Sprite2D>>	tileList;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::list<std::shared_ptr<Enemy>>	m_listEnemy;
	std::shared_ptr<SpriteAnimation> obj;
	std::shared_ptr<MouseButton> button;
	float time = 0.0f;
	float m_Velocity = 10.0f;

};