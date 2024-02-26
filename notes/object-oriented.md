# Object Inheritance approach [ WRONG ] 

 -> 'Thing' 
 -> Player, Enemy, Obstacle etc (all of them inherit from THING)
 
 ## C++ allows multiple inheritance, but...
  -> Diamond Inheritance (troublesome)
  -> It is a concept to AVOID!
  
 # Component Based Design [ BETTER ]
 
  -> Transform, Collision Shape, Mesh Renderer as if they were plugged to Game Objects;
  -> Entities === Game Objects;
   
  e.g: Sprite Component (Texture/.png),
       Transform(Scale, Rotation),
       Collider 
  
  -> A vector of components "attached" to an Entity;
 
class Entity{
    private:
    
      std::vector<Component*> _components;
      
    public:
    
      AddComponent<T>(Component component);
      void Update(delta_time);
      void Render();
      
      ...
}

class Component{
   Entity *owner;
   virtual Update(); -> 
   virtal Render();  -> can be override
}

class Registry{ //Entity management
   vector<Entity *> entities;
   
   void AddEntity(entity);
   void RemoveEntity(entity);
   void Update(delta_time);
   void Render();
   
   ...
}
