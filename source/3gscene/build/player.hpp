#pragma once



#include "3dsgame.hpp" 
#include "build/knight.h" 
#include "bases/damageable.hpp" 

class Player : public virtual CharacterBody, public virtual Damageable {
	public:
	virtual void take_damage(float amout) ;
	class PlayerSprite : public virtual AnimatedSprite {
		public:
		PlayerSprite() ;
		void _ready() ;
		virtual void _tick(float delta) ;
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
