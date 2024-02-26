# ECS

## Entities 
	* Simple an ID;
	* represent objects into a game scene;
	
## Components:

	* PURE DATA;
	* Structs;
	* Contiguous list of data in memory (making its access easier);
	
## Systems:
	
	* THE LOGIC;
	* Tasks;
	* They transform components from a state to another; 
	* e.g: MovementSystem might update the positions of all moving entities who know how to move by their velocities each frame;
