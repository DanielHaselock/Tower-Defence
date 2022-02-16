#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <cstdint>
#include <list>
#include <map>
#include <vector>
#include "Window.h"
#include "Sprite.h"

namespace TD
{


    class Renderer
    {
    public:
        typedef std::uint8_t Layer;
        Sprite& CreateSprite(const sf::Texture& my_Texture, sf::Vector2i position, Layer zLayer);
        void RemoveSprite(Sprite& my_Sprite);
        void RemoveAll();
        const sf::Texture* LoadTextureFile(const std::string& name);
        const sf::Texture* GetTexture(const std::string& name);
        void DrawSprites();
        void setWindow(Window* my_window);
        Window* get_window();

    private:
        std::map<std::string, sf::Texture*> textures;
        // std::vector<Layer, std::initializer_list<Sprite>> sprites;
         //std::vector<std::list<Sprite*>> sprites;
        std::vector<std::list<Sprite*>> sprites;
        Window* window;

    };
}