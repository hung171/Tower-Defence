#pragma once

#include <vector>
#include <memory>
#include <chrono> 
#include "Enemy.h"

class EnemyPool {
private:
	int poolSize;
	int nextAvailableIndex;
	std::vector<std::shared_ptr<Enemy>> pool;
	float timeSinceLastCreation; 
	float creationDelay;

public:
	EnemyPool(int poolSize, float creationDelay);

	std::shared_ptr<Enemy> CreateEnemy(std::shared_ptr<TextureManager> texture, int spriteRow, int end, int frameCount, int numAction, float frameTime);
	void UpdateAllEnemies(float deltaTime);
	void DrawAllEnemies(SDL_Renderer* renderer);
	void CreateNextEnemy();
	void DestroyEnemy(std::shared_ptr<Enemy> enemy);

	// Hàm giải phóng tất cả các enemy đã đi đến điểm cuối
	void DestroyEnemiesAtEndPoint();

};
