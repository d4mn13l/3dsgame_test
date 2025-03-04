#include "player.hpp"


void Player::take_damage(float amout) {
	OUT ( "ouch" ) ; 
}


Player::PlayerSprite::PlayerSprite() : AnimatedSprite() {
	scale = Vector2 ( 2 , 2 ) ; 
	name = "AnimatedSprite" ; 
	OUT ( "initing PlayerSprite" ) ; 
	Animation idle = Animation ( "idle" , std::vector<int> { 8 , 9 , 10 , 11 } , 0.2 , true ) ; 
	Animation run = Animation ( "run" , knight_run1_idx , knight_run16_idx , 0.2 , true ) ; 
	Animation roll = Animation ( "roll" , knight_roll1_idx , knight_roll8_idx , 0.2 , true ) ; 
	SpriteFrames frames = SpriteFrames ( "romfs:/gfx/knight.t3x" , std::vector<Animation> { idle , run , roll } ) ; 
	set_sprite_frames ( frames ) ; 
	play ( "idle" ) ; 
}


void Player::PlayerSprite::_ready() {
	AnimatedSprite::_ready ( ) ; 
	move ( Vector2 ( 0 , -8 ) ) ; 
}



Player::PlayerShape::PlayerShape() : RectangleShape() {
	set_size ( Vector2 ( 20 , 32 ) ) ; 
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



Player::Player() : CharacterBody(), Damageable() {
	collision_mask = PL_WALLS|PL_PLAYER|PL_COINS ; 
	collision_layer = PL_PLAYER ; 
	monitorable = true ; 
	monitoring = true ; 
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
	panimated_sprite = get_pnode<AnimatedSprite> ( as_path ) ; 
	CharacterBody::_ready ( ) ; 
}


void Player::_tick(float delta) {
	CharacterBody::_tick ( delta ) ; 
	handle_movement_input ( ) ; 
	handle_animations ( ) ; 
	move_and_collide ( velocity * delta ) ; 
	update_on_things ( ) ; 
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
	if ( get_pinput_server ( ) ->is_action_just_released ( KEY_A ) && velocity.y < 0 ) { 
		velocity.y = 0 ; 
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


