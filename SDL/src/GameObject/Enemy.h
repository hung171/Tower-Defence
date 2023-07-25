	#pragma once
	#include <memory>
	#include "SDL.h"
	#include <SDL_render.h>
	#include "SpriteAnimation.h"
	#include "CMath.h"
	#include "TextureManager.h"
	#include "Timer.h"
	#include "ResourceManagers.h"

	class TextureManager;
	class Enemy : public SpriteAnimation {
		
	public:
		Enemy(std::shared_ptr<TextureManager> texture, int spriteRow, int end, int frameCount, int numAction, float  frameTime);
		~Enemy();

		void		Init() override;

		void		Move(float deltaTime);
		void Destroy();
		bool IsDestroyed() const;
	private:
		int currentPathIndex;
		bool isMoving;
		bool isDestroyed;

	};