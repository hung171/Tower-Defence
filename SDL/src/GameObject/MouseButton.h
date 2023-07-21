#pragma once
#include <SDL.h>
#include "Sprite2D.h"
#include <functional>

class MouseButton : public Sprite2D
{
public:
	
	//Initializes internal variable
	MouseButton();
	MouseButton(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip);

	//Handles mouse event
	bool HandleMouseEvent(SDL_Event* e, Uint8 button);
	//Show button sprite
	void Draw(SDL_Renderer * renderer) override;
	//SDL_Point* GetButtonPosition();
	
	void	SetOnLeftClick(std::function<void(void)>pBtLeftClick);
	void	SetOnRightClick(std::function<void(void)>pBtRightClick);
private:
	std::function<void(void)>m_pBtLeftClick;
	std::function<void(void)>m_pBtRightClick;
	//Top left position
	//SDL_Point* mPosition;
	//Currently used global sprite
	
};

