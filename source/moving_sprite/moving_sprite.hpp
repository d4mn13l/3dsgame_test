#ifndef MOVING_SPRITE
#define MOVING_SPRITE

#include "3dsgame/include/3dsgame.hpp"


class MovingSprite : public Sprite {
	public:
		MovingSprite(int z_index_arg, bool top_screen);
		virtual void _tick(float delta);

		float speed = 5;
};


#endif