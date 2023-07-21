#include "GSPlay.h"
#include "GameObject/TextureManager.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/MouseButton.h"
#include "GameObject/SpriteAnimation.h"
#include "GameObject/Camera.h"
#include "GameObject/MapManager.h"
#include "GameObject/Enemy.h"
#include "GameObject/Turret.h"


GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	// map
	m_mapManager = std::make_shared<MapManager>(21, 13, 64, nullptr, SDL_FLIP_NONE);
	m_mapManager->LoadFromFile("Data/Textures/map01.txt");

	auto texture_1 = ResourceManagers::GetInstance()->GetTexture("Turret/RedTurret.png");
	auto texture_2 = ResourceManagers::GetInstance()->GetTexture("Turret/RedTurret.png");
	auto texture_3 = ResourceManagers::GetInstance()->GetTexture("Turret/RedTurret.png");
	auto texture_4 = ResourceManagers::GetInstance()->GetTexture("Turret/RedTurret.png");
	m_turret_1 = std::make_shared<Turret>(texture_1, SDL_FLIP_NONE);
	m_turret_2 = std::make_shared<Turret>(texture_2, SDL_FLIP_NONE);
	m_turret_3 = std::make_shared<Turret>(texture_3, SDL_FLIP_NONE);
	m_turret_4 = std::make_shared<Turret>(texture_4, SDL_FLIP_NONE);


	auto texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64, 64 * 6);
	button->SetOnLeftClick([this]() {
		m_turret_1->Set2DPosition(64, 64 * 6);
		});
	button->SetOnRightClick([this]() {
		m_turret_1->Set2DPosition(64 * 22, 64 * 14);
		});
	m_listButton.push_back(button);

	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64 * 7, 64 * 10);
	button->SetOnLeftClick([this]() {
		m_turret_2->Set2DPosition(64 * 7, 64 * 10);
		});
	button->SetOnRightClick([this]() {
		m_turret_2->Set2DPosition(64 * 22, 64 * 14);
		});
	m_listButton.push_back(button);

	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64 * 8, 64 * 3);
	button->SetOnLeftClick([this]() {
		m_turret_3->Set2DPosition(64 * 8, 64 * 3);
		});
	button->SetOnRightClick([this]() {
		m_turret_3->Set2DPosition(64 * 22, 64 * 14);
		});
	m_listButton.push_back(button);

	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64 * 15, 64 * 9);
	button->SetOnLeftClick([this]() {
		m_turret_4->Set2DPosition(64 * 15, 64 * 9);
		});
	button->SetOnRightClick([this]() {
		m_turret_4->Set2DPosition(64 * 22, 64 * 14);
		});
	m_listButton.push_back(button);


	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->SetSize(50, 50);
	button->Set2DPosition(SCREEN_WIDTH - 60, 10);
	button->SetOnLeftClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// settings close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->SetSize(50, 50);
	button->Set2DPosition(SCREEN_WIDTH - 120, 10);
	button->SetOnLeftClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPTION);
		});
	m_listButton.push_back(button);

	// Animation 
	texture = ResourceManagers::GetInstance()->GetTexture("adventurer-Sheet.png");
	obj = std::make_shared<SpriteAnimation>(texture, 7, 7, 7, 11, 0.1f);
	obj->SetFlip(SDL_FLIP_NONE);
	obj->SetSize(64, 64);
	obj->Set2DPosition(64 * 2.5, 64 * 3);
	m_listAnimation.push_back(obj);

	//Camera::GetInstance()->SetTarget(obj);

	// enemy


	m_KeyPress = 0;
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{
}





void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) //For e.key.repeat it's because key repeat is enabled by default and if you press and hold a key it will report multiple key presses. That means we have to check if the key press is the first one because we only care when the key was first pressed.
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			m_KeyPress |= 1 << 3;
			break;
		case SDLK_DOWN:
			m_KeyPress |= 1 << 1;
			break;
		case SDLK_LEFT:
			m_KeyPress |= 1;
			break;
		case SDLK_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		default:
			break;
		}

	}
	////Key Up
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_KeyPress ^= 1;
			break;
		case SDLK_DOWN:
			m_KeyPress ^= 1 << 1;
			break;
		case SDLK_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case SDLK_UP:
			m_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}

	}
}

void GSPlay::HandleTouchEvents(SDL_Event& e, Uint8 btn, bool bIsPressed)
{

	for (auto button : m_listButton)
	{
		if (button->HandleMouseEvent(&e, btn))
		{
			break;
		}
	}

	
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	switch (m_KeyPress)//Handle Key event
	{
	default:
		break;
	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listAnimation)
	{
		if (m_KeyPress == 1)
		{

			//it->MoveLeft(deltaTime);
		}
		it->Update(deltaTime);
		it->Move(0.1f);
	}


	//Update position of camera
	//Camera::GetInstance()->Update(deltaTime);
	//obj->Update(deltaTime);
}

void GSPlay::Draw(SDL_Renderer* renderer)
{
	
	// Vẽ Map
	m_mapManager->Draw(renderer);

	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}

	m_turret_1->Draw(renderer);
	m_turret_2->Draw(renderer);
	m_turret_3->Draw(renderer);
	m_turret_4->Draw(renderer);
	
	for (auto it : m_listAnimation)
	{
		it->Draw(renderer);
	}
}