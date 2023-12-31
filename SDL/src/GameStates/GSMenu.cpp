#include "GSMenu.h"

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU),
m_background(nullptr), m_listButton(std::list<std::shared_ptr<MouseButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	//auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("mybackground.jpg");

	// background
	//auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background->SetSize(SCREEN_WIDTH, SCREEN_HEIDHT);
	m_background->Set2DPosition(0, 0);

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("button-game/play-btn.png");
	std::shared_ptr<MouseButton> btnPlay = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnPlay->SetSize(280, 120);
	btnPlay->Set2DPosition(SCREEN_WIDTH / 3 + 100, SCREEN_HEIDHT / 2 + 10);
	btnPlay->SetOnLeftClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(btnPlay);


	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("button-game/close-btn.png");
	std::shared_ptr<MouseButton> btnClose = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	//btnClose = std::make_shared<MouseButton>(texture);
	btnClose->SetSize(50, 50);
	btnClose->Set2DPosition(SCREEN_WIDTH - 60, 10);
	btnClose->SetOnLeftClick([]() {
		exit(0);
		});
	m_listButton.push_back(btnClose);


	//Credit game
	texture = ResourceManagers::GetInstance()->GetTexture("button-game/credit-btn.png");
	btnCredit = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnCredit->Set2DPosition(SCREEN_WIDTH - 180, 10);
	btnCredit->SetSize(50, 50);
	btnCredit->SetOnLeftClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_CREDIT);
		});
	m_listButton.push_back(btnCredit);

	//Button Music
	texture = ResourceManagers::GetInstance()->GetTexture("button-game/sound-btn.png");
	std::shared_ptr<MouseButton> btnMusicOn = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnMusicOn->SetSize(50, 50);
	btnMusicOn->Set2DPosition(SCREEN_WIDTH - 120, 10);
	btnMusicOn->SetOnLeftClick([]() {
		std::shared_ptr<Sound> i;
		i = std::make_shared<Sound>("Data/Sounds/menu.mp3");
		i->PlaySound();
		});
	m_listButton.push_back(btnMusicOn);

	// game title
	///Set Font
	/*m_textColor = { 255, 255, 0 };
	m_textGameName = std::make_shared<Text>("Data/lazy.ttf", m_textColor);
	m_textGameName->SetSize(300, 50);
	m_textGameName->Set2DPosition((SCREEN_WIDTH - m_textGameName->GetWidth()) / 2, SCREEN_HEIDHT / 2 - 300);
	m_textGameName->LoadFromRenderText("");*/
	//m_Sound = std::make_shared<Sound>("Data/Sounds/TheHeroIkareruKobushiNiHiWoTsukeroTvSize-JamProject-4304931.mp3");
	m_Sound = std::make_shared<Sound>("Data/Sounds/menu.mp3");
	m_Sound->PlaySound();
}

void GSMenu::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSMenu::Pause()
{
	m_Sound->StopSound();

}

void GSMenu::Resume()
{
	m_Sound->PlaySound();
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(SDL_Event& e)
{

}

void GSMenu::HandleTouchEvents(SDL_Event& e, Uint8 btn, bool bIsPressed)
{

	for (auto button : m_listButton)
	{
		if (button->HandleMouseEvent(&e, btn))
		{
			break;
		}
	}


}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}
float time = 0.0f;
void GSMenu::Update(float deltaTime)
{
	time += deltaTime;
	//printf("DeltaTime = %f", deltaTime);
	if (time >= 1.5f)
	{
		time = 0.0f;
	}
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw(SDL_Renderer* renderer)
{
	m_background->Draw(renderer);
	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}
	//m_textGameName->Draw(renderer);
}