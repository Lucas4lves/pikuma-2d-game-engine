#include "./Enemy.h"

Enemy::Enemy(){

}

Enemy::Enemy(glm::vec2 initial_pos, SDL_Texture texture){
    m_initial_pos = initial_pos;
    m_texture = texture;
}

Enemy::~Enemy(){

}

void Enemy::Move(){
    Enemy e;
}