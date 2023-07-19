#include "GSCredit.h"

GSCredit::GSCredit() : GameStateBase(StateType::STATE_CREDIT),
m_background(nullptr), m_listButton(std::list<std::shared_ptr<MouseButton>>{}), m_textGameName(nullptr)
{
}


GSCredit::~GSCredit()
{
}



void GSCredit::Init()
{	

	//auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background3.png");

	// background
	//auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background->SetSize(SCREEN_WIDTH, SCREEN_HEIDHT);
	m_background->Set2DPosition(0, 0);

	// background2
	texture = ResourceManagers::GetInstance()->GetTexture("background2.png");
	std::shared_ptr<MouseButton> backgound_2 = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	backgound_2->SetSize(SCREEN_WIDTH / 2, SCREEN_HEIDHT / 2);
	backgound_2->Set2DPosition(SCREEN_WIDTH / 4, SCREEN_HEIDHT / 4);
	backgound_2->SetOnClick([]() { 

		});
	m_listButton.push_back(backgound_2);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("button_close.png");
	std::shared_ptr<MouseButton> btnClose = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnClose = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	btnClose->SetSize(70, 60);
	btnClose->Set2DPosition(SCREEN_WIDTH - btnClose->GetWidth() - 10, 10);
	btnClose->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(btnClose);

	// game title
	///Set Font
	
	m_textColor = { 255, 255, 0 };
	m_textGameName = std::make_shared<Text>("Data/lazy.ttf", m_textColor);
	m_textGameName->SetSize(300, 50);
	m_textGameName->Set2DPosition((SCREEN_WIDTH - m_textGameName->GetWidth()) / 2, SCREEN_HEIDHT / 2 - 300);
	m_textGameName->LoadFromRenderText("");
	m_Sound = std::make_shared<Sound>("Data/Sounds/TheHeroIkareruKobushiNiHiWoTsukeroTvSize-JamProject-4304931.mp3");
	m_Sound->PlaySound();
	
}

void GSCredit::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSCredit::Pause()
{
	m_Sound->StopSound();

}

void GSCredit::Resume()
{
	m_Sound->PlaySound();
}


void GSCredit::HandleEvents()
{
}

void GSCredit::HandleKeyEvents(SDL_Event& e)
{
}

void GSCredit::HandleTouchEvents(SDL_Event& e, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvent(&e))
		{
			break;
		}
	}
}

void GSCredit::HandleMouseMoveEvents(int x, int y)
{
}

float extern time1 = 0.0f;

void GSCredit::Update(float deltaTime)
{
	time1 += deltaTime;
	//printf("DeltaTime = %f", deltaTime);
	if (time1 >= 1.5f)
	{
		time1 = 0.0f;
	}
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSCredit::Draw(SDL_Renderer* renderer)
{
	m_background->Draw(renderer);
	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}
	m_textGameName->Draw(renderer);
}
