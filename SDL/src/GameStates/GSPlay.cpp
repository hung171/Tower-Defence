#include "GSPlay.h"
#include "GameObject/TextureManager.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/MouseButton.h"
#include "GameObject/SpriteAnimation.h"
#include "GameObject/Camera.h"
#include "GameObject/MapManager.h"


GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{

	m_mapManager = std::make_shared<MapManager>(21, 13, 64, nullptr, SDL_FLIP_NONE);
	m_mapManager->LoadFromFile("C:/Users/han.glschool/source/repos/Thuan-Hung-Dung/SDL/Data/Textures/map01.txt");	

	// button close
	auto texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->SetSize(50, 50);
	button->Set2DPosition(SCREEN_WIDTH - 60, 10);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// settings close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->SetSize(50, 50);
	button->Set2DPosition(SCREEN_WIDTH - 120, 10);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPTION);
		});
	m_listButton.push_back(button);

	// Animation 
	texture = ResourceManagers::GetInstance()->GetTexture("adventurer-Sheet.png");
	obj = std::make_shared<SpriteAnimation>(texture, 8, 4, 7, 11, 0.1f);
	obj->SetFlip(SDL_FLIP_HORIZONTAL);
	obj->SetSize(64, 64);
	obj->Set2DPosition(64 * 5, 64 * 7);
	m_listAnimation.push_back(obj);

	//Camera::GetInstance()->SetTarget(obj);

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

void GSPlay::HandleTouchEvents(SDL_Event& e, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvent(&e))
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
	}

	//Update position of camera
	//Camera::GetInstance()->Update(deltaTime);
	//obj->Update(deltaTime);
}

void GSPlay::Draw(SDL_Renderer* renderer)
{
	//m_score->Draw();

	/*for (auto it : tileList)
	{
		it->Draw(renderer);
	}*/
	
	
	// Vẽ Map
	m_mapManager->Draw(renderer);

	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}
	/*for (auto it : m_listButton_2)
	{
		it->Draw(renderer);
	}*/
	//	obj->Draw(renderer);
		//	obj->Draw(renderer);
	for (auto it : m_listAnimation)
	{
		it->Draw(renderer);
	}
}