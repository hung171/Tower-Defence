#include "GameStateBase.h"
#include "GameStates/GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSCredit.h"
#include "GSWin.h"
#include "GSLose.h"

GameStateBase::GameStateBase(StateType stateType) : m_stateType(stateType)
{}

std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateType stt)
{
	std::shared_ptr<GameStateBase> gs = nullptr;
	switch (stt)
	{
	case StateType::STATE_INVALID:
		break;
	case StateType::STATE_INTRO:
		gs = std::make_shared<GSIntro>();
		//GSINTRO;
		break;
	case StateType::STATE_MENU:
		gs = std::make_shared<GSMenu>();
		//GSMENU
		break;
	case StateType::STATE_PLAY:
		gs = std::make_shared<GSPlay>();
		//GSPLAY
		break;
	case StateType::STATE_CREDIT:
		gs = std::make_shared<GSCredit>();
		//GSPLAY
		break;
	case StateType::STATE_WIN:
		gs = std::make_shared<GSWin>();
		//GSWIN
		break;
	case StateType::STATE_LOSE:
		gs = std::make_shared<GSLose>();
		//GSPLOSE
		break;
	default:
		break;
	}
	return gs;
}

StateType GameStateBase::GetGameStateType()
{
	return m_stateType;
}
