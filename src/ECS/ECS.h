#ifndef ECS_H
#define ECS_H
#include <bitset>
#include <vector>

const unsigned int MAX_COMPONENTS = 32;
/////////////////////////////////////////////////////////////
// Signature
/////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////
typedef std::bitset<MAX_COMPONENTS> Signature;

class Components{
    //TODO
};

class Entity{
    //TODO
    private:
        int id;
    public:
        Entity();
        Entity(int _id) : _id(id){}; //Initializing list
        int GetId() const; //Methods that does not modify the state of an entity
};

//////////////////////////////
//////// SYSTEMS /////////////
/////Processes entities that contain specific signatures////////
//////////////////////////////

class System{
    //TODO
   private:
        Signature _componentSignature; 
        std::vector<Entity> _entities;
    public:
        System() = default;
        virtual ~System() = default;

        void AddEntityToSystem(Entity e);
        void RemoveEntityFromSystem(Entity e);
        std::vector<Entity> GetSystemEntities() const;
        Signature& GetComponentSignature() const;

};

class Registry{
    //TODO
};
#endif