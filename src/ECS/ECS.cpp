#include "./ECS.h"
//#include "../Logger/Logger.h"
#include <algorithm>

//TODO: Implement all methods from ECS.h classes 
int Entity::GetId() const{
    return _id;
}

void System::AddEntityToSystem(Entity e){
    _entities.push_back(e);
}

void System::RemoveEntityFromSystem(Entity e){
    //std::vector<Entity>::iterator findEntity = std::find(_entities.begin(), _entities.end(), e);
}
std::vector<Entity> System::GetSystemEntities() const {}
Signature& System::GetComponentSignature() const {}


