#include "slime.hpp"


Slime::~Slime() {
	OUT ( "slime is dead" ) ; 
}


void Slime::take_damage(float amount) {
	OUT ( "ouch oof my bones" ) ; 
	psprite->play ( "take_damage" ) ; 
}


void Slime::on_animated_sprite_animation_finished(std::string anim_name) {
	OUT ( "finished anim " + anim_name ) ; 
	if ( anim_name == "take_damage" ) { 
		OUT ( "killing myself" ) ; 
		pparent->kill_pchild ( this ) ; 
		OUT ( "im ded" ) ; 
	} 
}


void Slime::flip() {
	set_flip_x ( -1 * flip_x ) ; 
}


void Slime::set_flip_x(int to) {
	flip_x = to ; 
	psprite->set_flip_x ( to ) ; 
}


Slime::SlimeSprite::SlimeSprite() : AnimatedSprite() {
	scale = Vector2 ( 2 , 2 ) ; 
	name = "SlimeSprite" ; 
	set_sprite_frames ( sprite_frames ) ; 
	play ( "move" ) ; 
	move ( Vector2 ( 0 , -10 ) ) ; 
}


void Slime::SlimeSprite::_ready() {
	AnimatedSprite::_ready ( ) ; 
}



Slime::SlimeShape::SlimeShape() : RectangleShape() {
	name = "SlimeShape" ; 
	set_size ( Vector2 ( 20 , 24 ) ) ; 
}



Slime::HittableArea::HittableArea() : Area() {
	monitoring = true ; 
	collision_mask = PL_PLAYER ; 
	name = "HittableArea" ; 
	enable ( ) ; 
	HittableShape* hittableshape_inst = new HittableShape ( ) ; 
	add_pchild ( hittableshape_inst ) ; 
}


Slime::HittableArea::HittableShape::HittableShape() : RectangleShape() {
	show_this_shape = true ; 
	name = "HittableShape" ; 
	set_size ( Vector2 ( 20 , 4 ) ) ; 
	move ( Vector2 ( 0 , -10 ) ) ; 
}




Slime::Hitbox::Hitbox() : Area() {
	name = "Hitbox" ; 
	HitboxShape* hitboxshape_inst = new HitboxShape ( ) ; 
	add_pchild ( hitboxshape_inst ) ; 
}


Slime::Hitbox::HitboxShape::HitboxShape() : RectangleShape() {
	show_this_shape = true ; 
	name = "HitboxShape" ; 
	set_size ( Vector2 ( 20 , 10 ) ) ; 
	move ( Vector2 ( 0 , 4 ) ) ; 
}




Slime::Slime() : CharacterBody(), Damageable() {
	monitorable = true ; 
	monitoring = true ; 
	collision_mask = PL_WALLS ; 
	collision_layer = PL_ENEMIES ; 
	name = "slime" ; 
	SlimeSprite* slimesprite_inst = new SlimeSprite ( ) ; 
	add_pchild ( slimesprite_inst ) ; 
	SlimeShape* slimeshape_inst = new SlimeShape ( ) ; 
	add_pchild ( slimeshape_inst ) ; 
	HittableArea* hittablearea_inst = new HittableArea ( ) ; 
	add_pchild ( hittablearea_inst ) ; 
	Hitbox* hitbox_inst = new Hitbox ( ) ; 
	add_pchild ( hitbox_inst ) ; 
}


void Slime::_ready() {
	OUT ( "readying slime" ) ; 
	enable ( ) ; 
	CharacterBody::_ready ( ) ; 
	OUT ( "1" ) ; 
	psprite = get_pnode<AnimatedSprite> ( NodePath ( "SlimeSprite" ) ) ; 
	OUT ( "1" ) ; 
	std::function<void ( std::string ) > thing = std::bind ( &Slime::on_animated_sprite_animation_finished , this , std::placeholders::_1 ) ; 
	OUT ( "connecting" ) ; 
	connect ( &psprite->on_animation_finished , thing ) ; 
	OUT ( "connected" ) ; 
	phittable_area = get_pnode<Area> ( NodePath ( "HittableArea" ) ) ; 
	std::function<void ( ) > paobe = std::bind ( &Slime::take_damage , this , 1.0 ) ; 
	connect_argless ( &phittable_area->on_body_entered , paobe ) ; 
}


void Slime::_tick(float delta) {
	CharacterBody::_tick ( delta ) ; 
	update_on_things ( ) ; 
	if ( on_wall ) { 
		flip ( ) ; 
	} 
	velocity.x = speed * flip_x ; 
	if ( !on_floor ) { 
		velocity.y += gravity ; 
	} 
	else { 
		velocity.y = 0 ; 
	} 
	move_and_collide ( velocity * delta ) ; 
	unclip ( ) ; 
}


