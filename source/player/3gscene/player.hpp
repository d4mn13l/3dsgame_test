#ifndef PLAYER
#define PLAYER

#include "3dsgame.hpp" 
#include "build/knight.h" 

class Player : public CharacterBody {
	public:
	class PlayerSprite : public AnimatedSprite {
		public:
		PlayerSprite() ;
		void _ready() ;
	};
	
	class PlayerShape : public RectangleShape {
		public:
		PlayerShape() ;
		virtual void _ready() ;
	};
	
	class PlayerCamera : public Camera {
		public:
		PlayerCamera() ;
		virtual void move_globally(Vector2 by) ;
		virtual void _ready() ;
	};
	
	Player() ;
	float gravity = 7.0;
	
	float jump_velocity = 220.0;
	
	float speed = 150.0;
	
	Vector2 velocity;
	
	AnimatedSprite* panimated_sprite;
	
	protected:
	void _ready() ;
	void _tick(float delta) ;
	private:
	void handle_movement_input() ;
	void handle_animations() ;
};
#endif