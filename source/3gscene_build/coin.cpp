#include "coin.hpp"


Coin::Coin() : Area() {
	monitoring = true ; 
	collision_mask = PL_PLAYER ; 
	name = "Coin" ; 
	enable ( ) ; 
	std::function<void ( PhysicsBody* ) > oc = std::bind ( &Coin::on_collect , this , std::placeholders::_1 ) ; 
	connect ( &on_body_entered , oc ) ; 
	CollectShape* collectshape_inst = new CollectShape ( ) ; 
	add_pchild ( collectshape_inst ) ; 
	CoinSprite* coinsprite_inst = new CoinSprite ( ) ; 
	add_pchild ( coinsprite_inst ) ; 
}


void Coin::on_collect(PhysicsBody* pbody) {
	OUT ( "collected" ) ; 
	queue_free ( ) ; 
}


Coin::CollectShape::CollectShape() : RectangleShape() {
	show_this_shape = true ; 
	set_size ( Vector2 ( 6 , 6 ) ) ; 
}



Coin::CoinSprite::CoinSprite() : AnimatedSprite() {
	name = "CoinSprite" ; 
	set_sprite_frames ( frames ) ; 
	play ( "spin" ) ; 
}



