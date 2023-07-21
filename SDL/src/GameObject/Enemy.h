#pragma once
#include "BaseObject.h"

class Enemy : public BaseObject {
protected:
	// Khai báo biến và phương thức riêng cho Enemy

public:
	Enemy() : BaseObject() {}
	Enemy(std::shared_ptr<TextureManager> texture) : BaseObject(texture) {}

	virtual void Init() override;
	virtual void Draw(SDL_Renderer* renderer) override;
	virtual void Update(float deltaTime) override;

};
