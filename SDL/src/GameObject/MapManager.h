#pragma once
#include "Sprite2D.h"
#include <vector>
#include <string>
#include <memory>

class MapManager : public Sprite2D
{
private:
    int m_width;
    int m_height;
    int m_tileSize;
    std::vector<std::vector<int>> m_mapData;
    std::vector<int> m_textureIndices; // Lưu trữ chỉ số ảnh tương ứng với từng giá trị tile

public:
    MapManager(int width, int height, int tileSize, std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip);
    void SetTile(int row, int col, int tileValue);
    int GetTile(int row, int col);
    void LoadFromFile(const std::string& filename);
    void Draw(SDL_Renderer* renderer) override;
<<<<<<< HEAD
};
=======
};


>>>>>>> b82266d5f9b525c3e903efa92bf737af9639c22c
