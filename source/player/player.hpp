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


	protected:
		virtual void _tick(float delta);

		virtual void _ready();
	

	private:
		void handle_movement_input();
		void handle_animations();


		static void on_area_entered();
		static void on_area_exited();

};



#endif