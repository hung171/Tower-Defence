#pragma once
#include <memory>
#include "SDL.h"
#include "CMath.h"
#include "TextureManager.h"
#include "Timer.h"



class Turret : public Sprite2D
{
public:
	Turret(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip);
	void Draw(SDL_Renderer* renderer);


private:


};

