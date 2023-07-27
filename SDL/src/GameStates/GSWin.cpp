#include "GSWin.h"

GSWin::GSWin() : GameStateBase(StateType::STATE_WIN),
m_background(nullptr), m_textGameName(nullptr)
{
}


GSWin::~GSWin()
{
}



void GSWin::Init()
{

	//auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("mybackground.jpg");

	//auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background->SetSize(SCREEN_WIDTH, SCREEN_HEIDHT);
	m_background->Set2DPosition(0, 0);

	// m_background2
	texture = ResourceManagers::GetInstance()->GetTexture("win.jpg");
	m_background2 = std::make_shared<Sprite2D>(texture, SDL_FLIP_NONE);
	m_background2->SetSize(SCREEN_WIDTH / 1.25, SCREEN_HEIDHT / 1.25);
	m_background2->Set2DPosition(SCREEN_WIDTH / 2 - SCREEN_WIDTH / 2.5, SCREEN_HEIDHT / 2 - SCREEN_HEIDHT / 2.5);


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

void GSWin::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSWin::Pause()
{
	m_Sound->StopSound();

}

void GSWin::Resume()
{
	m_Sound->PlaySound();
}


void GSWin::HandleEvents()
{
}

void GSWin::HandleKeyEvents(SDL_Event& e)
{
}

void GSWin::HandleTouchEvents(SDL_Event& e, Uint8 btn, bool bIsPressed)
{

	for (auto button : m_listButton)
	{
		if (button->HandleMouseEvent(&e, btn))
		{
			break;
		}
	}


}


void GSWin::HandleMouseMoveEvents(int x, int y)
{
}


void GSWin::Update(float deltaTime)
{

	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSWin::Draw(SDL_Renderer* renderer)
{
	m_background->Draw(renderer);
	m_background2->Draw(renderer);
	for (auto it : m_listButton)
	{
		it->Draw(renderer);
	}
	//m_textGameName->Draw(renderer);
}