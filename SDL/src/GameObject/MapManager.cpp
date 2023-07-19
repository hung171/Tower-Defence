﻿#include "MapManager.h"
#include "ResourceManagers.h"
#include <fstream>
#include <iostream>
#include <string>

MapManager::MapManager(int width, int height, int tileSize, std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip)
    : Sprite2D(texture, flip), m_width(width), m_height(height), m_tileSize(tileSize)
{
    m_mapData.resize(height, std::vector<int>(width, 0));
    m_textureIndices.resize(256, 0); // Khởi tạo mảng chỉ số ảnh với kích thước mặc định
}

void MapManager::SetTile(int row, int col, int tileValue)
{
    if (row >= 0 && row < m_height && col >= 0 && col < m_width)
    {
        m_mapData[row][col] = tileValue;
    }
}

int MapManager::GetTile(int row, int col)
{
    if (row >= 0 && row < m_height && col >= 0 && col < m_width)
    {
        return m_mapData[row][col];
    }
    return 0; // Return a default tile value if out of range
}

void MapManager::LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        for (int row = 0; row < m_height; ++row)
        {
            for (int col = 0; col < m_width; ++col)
            {
                if (file >> m_mapData[row][col])
                {
                    // Đọc thành công giá trị từ tệp tin
                }
                else
                {
                    // Xử lý khi không thể đọc giá trị từ tệp tin
                }
            }
        }
        file.close();
    }
    else
    {
        // Xử lý khi không thể mở tệp tin
        std::cout << "Không thể mở tệp tin: " << filename << std::endl;
    }
}


void MapManager::Draw(SDL_Renderer* renderer)
{
    int tileSize = 64;

    for (int y = 0; y < m_height; ++y) 
    {
        for (int x = 0; x < m_width; ++x)
        {
            int tileValue = m_mapData[y][x];
            if (tileValue == 1)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/1.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 2)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/2.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 3)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/3.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }

            }
            else if (tileValue == 4)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/4.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 5)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/5.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 6)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/6.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 7)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/7.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 8)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/8.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 9)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/9.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 10)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/10.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
            }
            else if (tileValue == 11)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/11.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
                }
            else if (tileValue == 12)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/12.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
                }
            else if (tileValue == 13)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/13.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
                }
            else if (tileValue == 14)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/14.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
                }
            else if (tileValue == 15)
            {
                auto texture = ResourceManagers::GetInstance()->GetTexture("TileMap/15.png");
                if (texture != nullptr)
                {
                    auto tile = std::make_shared<Sprite2D>(texture, m_flip);
                    tile->SetSize(tileSize, tileSize);
                    tile->Set2DPosition(x * tileSize, y * tileSize);
                    tile->Draw(renderer);
                }
                }
        }

    }
}