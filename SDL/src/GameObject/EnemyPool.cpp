#include "EnemyPool.h"
#include "Dot.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib> 
#include <ctime>

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
            enemy->Update(deltaTime);
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

        // Tạo thời gian delay ngẫu nhiên từ 1s đến 4s cho lần tạo enemy tiếp theo
        float randomDelay = 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 20.0f));
        timeSinceLastCreation = -randomDelay; // Đặt thời gian delay ngẫu nhiên
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
    // Sinh số ngẫu nhiên từ 0 đến 1
    int randomEnemy = rand() % 2; // randomEnemy sẽ là 0 hoặc 1

    // Tạo ngẫu nhiên enemy1 hoặc enemy2
    auto texture = ResourceManagers::GetInstance()->GetTexture(randomEnemy == 0 ? "enemy1.png" : "enemy2.png");
    auto enemy = CreateEnemy(texture, 1, 6, 7, 1, 1.0f);

    if (enemy != nullptr)
    {
        enemy->Set2DPosition(64 * 2.5, 64 * 1);
        enemy->SetSize(64, 64);
        enemy->SetFlip(SDL_FLIP_NONE);
        
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

std::vector<std::shared_ptr<Enemy>> EnemyPool::getPool()
{
    return pool;
}

void EnemyPool::DestroyEnemy(std::shared_ptr<Enemy> enemy)
{
    // Xóa đối tượng enemy khỏi danh sách
    auto it = std::find(pool.begin(), pool.end(), enemy);
    if (it != pool.end()) {
        pool.erase(it);
    }
}






