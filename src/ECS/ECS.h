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

struct IComponent{
    protected:
        static int nextId;
};

//Assigning a unique ID to a component type
template <typename T>
class Component : public IComponent {
    public:
        static int GetId(){
            static auto id = nextId++;
            return id;
        }
};

class Entity{
    //TODO
    private:
        int _id;
    public:
        Entity();
        Entity(int _id) : _id(_id){}; //Initializing list
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
        const Signature& GetComponentSignature() const;
        // Defines required component type entities to a system
        template <typename T> void RequireComponent();
};

class Registry{
    //TODO
};

template <typename T>
void System::RequireComponent(){
    const auto componentId = Component<T>::GetId();
    _componentSignature.set(componentId);
}
#endif
