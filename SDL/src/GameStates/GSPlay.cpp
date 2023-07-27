#include "GSPlay.h"
#include "GameObject/TextureManager.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/MouseButton.h"
#include "GameObject/SpriteAnimation.h"
#include "GameObject/Camera.h"
#include "GameObject/MapManager.h"
#include "GameObject/Enemy.h"
#include "GameObject/Turret.h"
#include "GameObject/EnemyPool.h"
#include "GameObject/Projectile.h"
#include "iostream"


GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	// map
	p_mapManager = std::make_shared<MapManager>(21, 13, 64, nullptr, SDL_FLIP_NONE);
	p_mapManager->LoadFromFile("Data/Textures/map01.txt");

	auto texture = ResourceManagers::GetInstance()->GetTexture("h_start.png");
	p_h_start = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	p_h_start->SetSize(64, 64);
	p_h_start->Set2DPosition(64 * 2.5, 64 * 1);

	texture = ResourceManagers::GetInstance()->GetTexture("h_end.png");
	p_h_end = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	p_h_end->SetSize(64, 64);
	p_h_end->Set2DPosition(64 * 17.5, 64 * 2);

	auto texture_1 = ResourceManagers::GetInstance()->GetTexture("Turret/turret.png");
	auto texture_2 = ResourceManagers::GetInstance()->GetTexture("Turret/turret.png");
	auto texture_3 = ResourceManagers::GetInstance()->GetTexture("Turret/turret.png");
	auto texture_4 = ResourceManagers::GetInstance()->GetTexture("Turret/turret.png");
	p_turret_1 = std::make_shared<Turret>(texture_1, SDL_FLIP_NONE);
	p_turret_2 = std::make_shared<Turret>(texture_2, SDL_FLIP_NONE);
	p_turret_3 = std::make_shared<Turret>(texture_3, SDL_FLIP_NONE);
	p_turret_4 = std::make_shared<Turret>(texture_4, SDL_FLIP_NONE);


	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64, 64 * 6);
	button->SetOnLeftClick([this]() {
		p_turret_1->Set2DPosition(64, 64 * 6);
		//printf(""
		});
	button->SetOnRightClick([this]() {
		p_turret_1->Set2DPosition(64 * 22, 64 * 14);
		});
	p_listButton.push_back(button);
	p_listTurret.push_back(p_turret_1);

	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64 * 7, 64 * 10);
	button->SetOnLeftClick([this]() {
		p_turret_2->Set2DPosition(64 * 7, 64 * 10);
		});
	button->SetOnRightClick([this]() {
		p_turret_2->Set2DPosition(64 * 22, 64 * 14);
		});
	p_listButton.push_back(button);
	p_listTurret.push_back(p_turret_2);

	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64 * 8, 64 * 3);
	button->SetOnLeftClick([this]() {
		p_turret_3->Set2DPosition(64 * 8, 64 * 3);
		});
	button->SetOnRightClick([this]() {
		p_turret_3->Set2DPosition(64 * 22, 64 * 14);
		});
	p_listButton.push_back(button);
	p_listTurret.push_back(p_turret_3);

	texture = ResourceManagers::GetInstance()->GetTexture("");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->Set2DPosition(64 * 15, 64 * 9);
	button->SetOnLeftClick([this]() {
		p_turret_4->Set2DPosition(64 * 15, 64 * 9);
		});
	button->SetOnRightClick([this]() {
		p_turret_4->Set2DPosition(64 * 22, 64 * 14);
		});
	p_listButton.push_back(button);
	p_listTurret.push_back(p_turret_4);


	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("button-game/close-btn.png");
	button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->SetSize(50, 50);
	button->Set2DPosition(SCREEN_WIDTH - 60, 10);
	button->SetOnLeftClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	p_listButton.push_back(button);

	texture = ResourceManagers::GetInstance()->GetTexture("button-game/sound-btn.png");
	std::shared_ptr<MouseButton> btnMusicOn = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnMusicOn->SetSize(50, 50);
	btnMusicOn->Set2DPosition(SCREEN_WIDTH - 120, 10);
	btnMusicOn->SetOnLeftClick([]() {
		std::shared_ptr<Sound> i;
		i = std::make_shared<Sound>("Data/Sounds/play.mp3");
		i->PlaySound();
		});
	p_listButton.push_back(btnMusicOn);

	p_Sound = std::make_shared<Sound>("Data/Sounds/play.mp3");
	p_Sound->PlaySound();

	// Enemy

	p_enemyPool = std::make_shared<EnemyPool>(30, 10.0f); 

	//Camera::GetInstance()->SetTarget(obj);

	p_KeyPress = 0;

	

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

	if (e.type == SDL_MOUSEMOTION) {
		p_x = e.motion.x;
		p_y = e.motion.y;
	}

	// Mouse button click event
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        // Lấy thông tin về chuột khi click
        mouseX = e.button.x;
		mouseY = e.button.y;

        // Kiểm tra nếu click chuột trái (SDL_BUTTON_LEFT)
        if (e.button.button == SDL_BUTTON_LEFT)
        {
            // Gọi hàm shoot cho mỗi turret trong danh sách p_listTurret
            for (auto turret : p_listTurret)
            {
                turret->Shoot(mouseX, mouseY, p_listProjectiles);
            }
        }
    }
	

	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) //For e.key.repeat it's because key repeat is enabled by default and if you press and hold a key it will report multiple key presses. That means we have to check if the key press is the first one because we only care when the key was first pressed.
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			p_KeyPress |= 1 << 3;
			break;
		case SDLK_DOWN:
			p_KeyPress |= 1 << 1;
			break;
		case SDLK_LEFT:
			p_KeyPress |= 1;
			break;
		case SDLK_RIGHT:
			p_KeyPress |= 1 << 2;
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
			p_KeyPress ^= 1;
			break;
		case SDLK_DOWN:
			p_KeyPress ^= 1 << 1;
			break;
		case SDLK_RIGHT:
			p_KeyPress ^= 1 << 2;
			break;
		case SDLK_UP:
			p_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}

	}
}

void GSPlay::HandleTouchEvents(SDL_Event& e, Uint8 btn, bool bIsPressed)
{

	for (auto button : p_listButton)
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
	switch (p_KeyPress)//Handle Key event
	{
	default:
		break;
	}

	for (auto it : p_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : p_listTurret)
	{
		it->UpdateAngle(p_x, p_y);
		it->Update(deltaTime);
		
	}

	for (auto projectile : p_listProjectiles)
	{
		projectile->Update(deltaTime);

	}
	//std::cout << m_x << " " << m_y << std::endl;

	p_enemyPool->UpdateAllEnemies(0.2f);
	
	

	/*for (auto enemy : p_enemyPool->getPool()) {
		SDL_Rect e = {
			enemy->GetPosition().x,
			enemy->GetPosition().y,
			64, 64
		};
		for (auto projectile : p_listProjectiles)
		{
			SDL_Rect p = {
			projectile->GetPosition().x,
			projectile->GetPosition().y,
			15, 15
			};

			if (CheckCollision(e, p)) {
				enemy->Destroy();
			}
		}
	}*/

	//Update position of camera
	//Camera::GetInstance()->Update(deltaTime);
	//obj->Update(deltaTime);
}

void GSPlay::Draw(SDL_Renderer* renderer)
{
	
	// Vẽ Map
	p_mapManager->Draw(renderer);
	p_h_start->Draw(renderer);
	p_h_end->Draw(renderer);
	for (auto it : p_listButton)
	{
		it->Draw(renderer);
	}

	for (auto it : p_listTurret)
	{
		it->Draw(renderer);
	}

	for (auto projectile : p_listProjectiles)
	{
		projectile->Draw(renderer);
	}

	p_enemyPool->DrawAllEnemies(renderer);
}


bool GSPlay::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}