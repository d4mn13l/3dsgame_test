#ifndef PLAYER
#define PLAYER

#include "3dsgame.hpp" 
#include "build/knight.h" 

class Player : public virtual CharacterBody {
	public:
	class PlayerSprite : public virtual AnimatedSprite {
		public:
		PlayerSprite() ;
		void _ready() ;
	};
	
	class PlayerShape : public virtual RectangleShape {
		public:
		PlayerShape() ;
		virtual void _ready() ;
	};
	
	class PlayerCamera : public virtual Camera {
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