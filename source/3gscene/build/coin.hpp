#pragma once


#include "3dsgame.hpp" 
#include "build/coin.h" 


class Coin : public virtual Area {
	public:
	Coin() ;
	void on_collect(PhysicsBody* pbody) ;
	void _tick(float delta) ;
	class CollectShape : public virtual RectangleShape {
		public:
		CollectShape() ;
	};
	
	class CoinSprite : public virtual AnimatedSprite {
		public:
		CoinSprite() ;
		Animation spin_anim = Animation("spin",coin_spin_1_idx,coin_spin_12_idx,0.2,true);
		
		SpriteFrames frames = SpriteFrames("romfs:/gfx/coin.t3x",std::vector<Animation>{spin_anim});
		
	};
	
};
