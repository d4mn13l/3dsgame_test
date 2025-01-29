#ifndef PLAYER
#define PLAYER


#include "3dsgame.hpp"


class Player : public CharacterBody {
	public:
		Player();

		float gravity = 7;
		float jump_velocity = 220;
		float speed = 150;

		Vector2 velocity;

		AnimatedSprite* panimated_sprite;


		void move(Vector2 by);

	protected:
		virtual void tick(float delta);
	

	private:
		void handle_movement_input();
		void handle_animations();

};



#endif