#include "GSLose.h"
#include "iostream"

GSLose::GSLose() : GameStateBase(StateType::STATE_LOSE),
m_background(nullptr), m_textGameName(nullptr)
{
}


GSLose::~GSLose()
{
}



void GSLose::Init()
{
	//std::cout << "lose";
	//auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("mybackground.jpg");

	//auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background->SetSize(SCREEN_WIDTH, SCREEN_HEIDHT);
	m_background->Set2DPosition(0, 0);

	// m_background2
	texture = ResourceManagers::GetInstance()->GetTexture("youLose.png");
	m_background2 = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background2->SetSize(SCREEN_WIDTH / 2, SCREEN_HEIDHT / 3);
	m_background2->Set2DPosition(SCREEN_WIDTH / 4, SCREEN_HEIDHT / 4);


	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("button-game/close-btn.png");
	auto button = std::make_shared<MouseButton>(texture, SDL_FLIP_NONE);
	button->SetSize(50, 50);
	button->Set2DPosition(SCREEN_WIDTH - 60, 10);
	button->SetOnLeftClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButton.push_back(button);


}

void GSLose::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSLose::Pause()
{
	m_Sound->StopSound();

}

void GSLose::Resume()
{
	m_Sound->PlaySound();
}


void GSLose::HandleEvents()
{
}

void GSLose::HandleKeyEvents(SDL_Event& e)
{
}

void GSLose::HandleTouchEvents(SDL_Event& e, Uint8 btn, bool bIsPressed)
{

	for (auto button : m_listButton)
	{
		if (button->HandleMouseEvent(&e, btn))
		{
			break;
		}
	}


}


void GSLose::HandleMouseMoveEvents(int x, int y)
{
}


void GSLose::Update(float deltaTime)
{

	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSLose::Draw(SDL_Renderer* renderer)
{
	m_background->Draw(renderer);
	m_background2->Draw(renderer);
	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}
	//m_textGameName->Draw(renderer);
}