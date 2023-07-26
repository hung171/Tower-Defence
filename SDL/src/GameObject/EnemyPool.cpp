#include "EnemyPool.h"
#include <iostream>
#include <thread>
#include <chrono>

EnemyPool::EnemyPool(int poolSize, float creationDelay)
    : poolSize(poolSize), nextAvailableIndex(0), timeSinceLastCreation(0.0f), creationDelay(creationDelay)
{
    // Khởi tạo pool với các đối thủ null (nullptr)
    pool.resize(poolSize, nullptr);
}

std::shared_ptr<Enemy> EnemyPool::CreateEnemy(std::shared_ptr<TextureManager> texture, int spriteRow, int end, int frameCount, int numAction, float frameTime)
{
    // Tìm đối thủ có thể tái sử dụng hoặc tạo mới nếu pool chưa đầy
    for (size_t i = nextAvailableIndex; i < pool.size(); ++i) {
        if (pool[i] == nullptr) {
            pool[i] = std::make_shared<Enemy>(texture, spriteRow, end, frameCount, numAction, frameTime);
            nextAvailableIndex = i + 1;
            return pool[i];
        }
    }

    // Nếu pool đã đầy, không tạo thêm đối thủ mới
    return nullptr;
}

void EnemyPool::UpdateAllEnemies(float deltaTime)
{
    // Cập nhật tất cả các đối thủ trong pool
    for (const auto& enemy : pool) {
        if (enemy != nullptr) {
            enemy->Move(deltaTime); // Di chuyển tất cả các enemy trong pool

            // Kiểm tra nếu enemy đã bị hủy (đến điểm cuối) thì xóa nó khỏi danh sách
            if (enemy->IsDestroyed()) {
                DestroyEnemy(enemy);
            }
        }
    }

    // Tạo enemy mới sau mỗi (creationDelay) giây
    timeSinceLastCreation += deltaTime;
    if (timeSinceLastCreation >= creationDelay) {
        CreateNextEnemy(); // Tạo enemy mới
        timeSinceLastCreation = 0.0f; // Reset thời gian delay
    }
}

void EnemyPool::DrawAllEnemies(SDL_Renderer* renderer)
{
    // Vẽ tất cả các đối thủ trong pool
    for (const auto& enemy : pool) {
        if (enemy != nullptr) {
            enemy->Draw(renderer);
        }
    }
}

void EnemyPool::CreateNextEnemy()
{
    auto texture = ResourceManagers::GetInstance()->GetTexture("adventurer-Sheet.png");
    auto enemy1 = CreateEnemy(texture, 7, 7, 7, 11, 0.1f);
    if (enemy1 != nullptr)
    {
        enemy1->Set2DPosition(64 * 2.5, 64 * 1);
        enemy1->SetSize(64, 64);
        enemy1->SetFlip(SDL_FLIP_NONE);
        
    }
}

void EnemyPool::DestroyEnemiesAtEndPoint()
{
    // Giải phóng các enemy đã đi đến điểm cuối khỏi danh sách
    for (auto it = pool.begin(); it != pool.end();)
    {
        if ((*it) != nullptr && (*it)->IsDestroyed())
        {
            it = pool.erase(it); // Xóa đối tượng enemy khỏi danh sách
        }
        else
        {
            ++it;
        }
    }
}

void EnemyPool::DestroyEnemy(std::shared_ptr<Enemy> enemy)
{
    // Xóa đối tượng enemy khỏi danh sách
    auto it = std::find(pool.begin(), pool.end(), enemy);
    if (it != pool.end()) {
        pool.erase(it);
    }
}