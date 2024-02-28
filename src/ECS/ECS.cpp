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
    _entities.erase(std::remove_if(_entities.begin(), _entities.end(), [&e](Entity other){
        return e.GetId() == other.GetId();
    }), _entities.end());
}
std::vector<Entity> System::GetSystemEntities() const {
    return _entities;
}
const Signature& System::GetComponentSignature() const {
    return _componentSignature;
}


