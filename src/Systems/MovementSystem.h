#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

class MovementSystem : public System {
   public:
        MovementSystem();
        //What entities are into this system?  
        //RequireComponent<TransformComponent>();

        void Update();
        //TODO: Update entities positions each frame based on its velocity
        //Loop all entities the system is interested in
};

#endif