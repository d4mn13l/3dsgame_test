#ifndef SLIME
#define SLIME
#include "3dsgame.hpp" 
#include "build/slime.h" 
#include "bases/damageable.hpp" 
#include <iostream> 

class Slime : public virtual CharacterBody, public virtual Damageable {
	public:
	virtual void take_damage(float delta) ;
	void on_animated_sprite_animation_finished(std::string anim_name) ;
	void flip() ;
	void set_flip_x(int to) ;
	class SlimeSprite : public virtual AnimatedSprite {
		public:
		SlimeSprite() ;
		void _ready() ;
		Animation anim_move = Animation("move",slime_move1_idx,slime_move4_idx,0.2,true);
		
		Animation anim_take_damage = Animation("take_damage",slime_take_damage1_idx,slime_take_damage3_idx,0.2,true);
		
		SpriteFrames sprite_frames = SpriteFrames("romfs:/gfx/slime.t3x",std::vector<Animation>{anim_move,anim_take_damage});
		
	};
	
	class SlimeShape : public virtual RectangleShape {
		public:
		SlimeShape() ;
	};
	
	class HittableArea : public virtual Area {
		public:
		HittableArea() ;
		class HittableShape : public virtual RectangleShape {
			public:
			HittableShape() ;
		};
		
	};
	
	class Hitbox : public virtual Area {
		public:
		Hitbox() ;
		class HitboxShape : public virtual RectangleShape {
			public:
			HitboxShape() ;
		};
		
	};
	
	Slime() ;
	float speed = 10.0;
	
	float gravity = 6.0;
	
	AnimatedSprite* psprite;
	
	Area* phittable_area;
	
	Vector2 velocity;
	
	int flip_x = 1;
	
	protected:
	void _ready() ;
	void _tick(float delta) ;
};
#endif