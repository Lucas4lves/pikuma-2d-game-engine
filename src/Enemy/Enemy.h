#ifndef ENEMY_H
#define ENEMY_H

#include <glm/glm.hpp>
#include <SDL2/SDL_image.h>

class Enemy{
    private:
        glm::vec2 m_initial_pos;
        SDL_Texture m_texture;
    public:
        Enemy();
        Enemy(glm::vec2 initial_pos, SDL_Texture texture);
        ~Enemy();

    void Move();


};

#endif