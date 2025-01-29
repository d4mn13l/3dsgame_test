#ifndef PLAYER
#define PLAYER


#include "3dsgame.hpp"


class Player : public CharacterBody {
	public:
		Player();


	protected:
		virtual void tick(float delta);
};



#endif