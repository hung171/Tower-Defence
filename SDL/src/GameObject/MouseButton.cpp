#include "MouseButton.h"
#include "TextureManager.h"
MouseButton::MouseButton() : Sprite2D(), m_pBtLeftClick(nullptr), m_pBtRightClick(nullptr)
{
	m_position.x= 0;
	m_position.y = 0;
}

MouseButton::MouseButton(std::shared_ptr<TextureManager> texture, SDL_RendererFlip flip)
	: Sprite2D(texture,flip), m_pBtLeftClick(nullptr), m_pBtRightClick(nullptr)
{
}



bool MouseButton::HandleMouseEvent(SDL_Event* e, Uint8 button)
{
    //If mouse button clicked
    if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == button)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        // Check if mouse is in button
        bool inside = true;
        //Mouse is left/right above/below of the button
        if (x < m_position.x || x > m_position.x + m_iWidth || y < m_position.y || y > m_position.y + m_iHeight)
        {
            inside = false;
        }
        // Mouse is outside button
        if (inside)
        {
            // Perform click action
            if (button == SDL_BUTTON_LEFT) {
                m_pBtLeftClick();
            }
            else if (button == SDL_BUTTON_RIGHT) {
                m_pBtRightClick();
            }
        }
        return inside;
    }
    return false;
}

void MouseButton::Draw(SDL_Renderer * renderer)
{
	if (m_pTexture != nullptr)
	{
		m_pTexture->Render(m_position.x, m_position.y, m_iWidth, m_iHeight);
	}
}

void MouseButton::SetOnLeftClick(std::function<void(void)> pBtLeftClick)
{
	m_pBtLeftClick = pBtLeftClick;
}

void MouseButton::SetOnRightClick(std::function<void(void)> pBtRightClick)
{
    m_pBtRightClick = pBtRightClick;
}





