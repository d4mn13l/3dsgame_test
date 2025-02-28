#include "player.hpp"


Player::PlayerSprite::PlayerSprite() : AnimatedSprite() {
	OLOG ( "initing PlayerSprite" ) ; 
	Animation idle = Animation ( "idle" , std::vector<int> { 8 , 9 , 10 , 11 } , 0.2 , true ) ; 
	Animation run = Animation ( "run" , knight_run1_idx , knight_run16_idx , 0.2 , true ) ; 
	Animation roll = Animation ( "roll" , knight_roll1_idx , knight_roll8_idx , 0.2 , true ) ; 
	SpriteFrames frames = SpriteFrames ( "romfs:/gfx/knight.t3x" , std::vector<Animation> { idle , run , roll } ) ; 
	set_sprite_frames ( frames ) ; 
	play ( "idle" ) ; 
	name = "AnimatedSprite" ; 
	scale = Vector2 ( 2 , 2 ) ; 
}


void Player::PlayerSprite::_ready() {
	AnimatedSprite::_ready ( ) ; 
	move ( Vector2 ( 0 , -8 ) ) ; 
}



Player::PlayerShape::PlayerShape() : RectangleShape() {
	size = Vector2 ( 10 , 16 ) ; 
	name = "Shape" ; 
}


void Player::PlayerShape::_ready() {
	RectangleShape::_ready ( ) ; 
}



Player::PlayerCamera::PlayerCamera() : Camera() {
	set_screen ( TOP_SCREEN ) ; 
	activate ( ) ; 
}


void Player::PlayerCamera::move_globally(Vector2 by) {
	Camera::move_globally ( by ) ; 
}


void Player::PlayerCamera::_ready() {
	Camera::_ready ( ) ; 
}



Player::Player() : CharacterBody() {
	monitoring = true ; 
	monitorable = true ; 
	collision_layer = PL_PLAYER ; 
	collision_mask = PL_WALLS|PL_PLAYER|PL_ENEMIES|PL_COINS ; 
	PlayerSprite* playersprite_inst = new PlayerSprite ( ) ; 
	add_pchild ( playersprite_inst ) ; 
	PlayerShape* playershape_inst = new PlayerShape ( ) ; 
	add_pchild ( playershape_inst ) ; 
	PlayerCamera* playercamera_inst = new PlayerCamera ( ) ; 
	add_pchild ( playercamera_inst ) ; 
}


void Player::_ready() {
	enable ( ) ; 
	NodePath as_path = NodePath ( "AnimatedSprite" ) ; 
	panimated_sprite = dynamic_cast<AnimatedSprite*> ( get_pnode ( as_path ) ) ; 
	CharacterBody::_ready ( ) ; 
}


void Player::_tick(float delta) {
	CharacterBody::_tick ( delta ) ; 
	handle_movement_input ( ) ; 
	handle_animations ( ) ; 
	move_and_collide ( velocity * delta ) ; 
	update_on_things ( ) ; 
	OLOG ( std::to_string ( on_floor ) + std::to_string ( on_wall ) + std::to_string ( on_ceiling ) ) ; 
}


void Player::handle_movement_input() {
	u32 keys_held = hidKeysHeld ( ) ; 
	if ( keys_held & KEY_LEFT ) { 
		velocity.x = -speed ; 
	} 
	if ( keys_held & KEY_RIGHT ) { 
		velocity.x = speed ; 
	} 
	else if ( ! ( keys_held & KEY_LEFT ) ) { 
		velocity.x = 0 ; 
	} 
	if ( ( keys_held & KEY_A ) && on_floor ) { 
		velocity.y = -jump_velocity ; 
	} 
	if ( on_floor && velocity.y >= 0 ) { 
		velocity.y = 0 ; 
	} 
	else { 
		velocity.y += gravity ; 
	} 
}


void Player::handle_animations() {
	if ( velocity.x != 0 || velocity.y != 0 ) { 
		panimated_sprite->play ( "run" ) ; 
		if ( velocity.x > 0 ) { 
			panimated_sprite->set_flip_x ( 1 ) ; 
		} 
		else if ( velocity.x < 0 ) { 
			panimated_sprite->set_flip_x ( -1 ) ; 
		} 
	} 
	else { 
		panimated_sprite->play ( "idle" ) ; 
	} 
}


