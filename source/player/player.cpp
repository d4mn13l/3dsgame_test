#include "player.hpp"

#include "build/knight.h"
#include <iostream>


Player::Player() {
	name = "Player";

	enable();
	monitoring = true;
	monitorable = true;

	collision_layer = PL_PLAYER;
	collision_mask = PL_WALLS | PL_PLAYER | PL_ENEMIES | PL_COINS;

	set_size(Vector2(10, 16));

	// create AnimatedSprite

	Animation idle = Animation("idle", std::vector<int> {8,9,10,11}, 0.2, true);
	Animation run = Animation("run", knight_run1_idx, knight_run16_idx, 0.2, true);
	Animation roll = Animation("roll", knight_roll1_idx, knight_roll8_idx, 0.2, true);
	SpriteFrames frames = SpriteFrames("romfs:/gfx/knight.t3x", std::vector<Animation> {idle, run, roll});

	std::cout << "run name is " << run.name << " <-" << std::endl;
	
	panimated_sprite = new AnimatedSprite(frames, "idle", 0);
	panimated_sprite->name = "AnimatedSprite";
	panimated_sprite->scale = Vector2(2,2);
	
	panimated_sprite->move(Vector2(0, -8));

	add_pchild(panimated_sprite);

	Camera* pcamera = new Camera();
	add_pchild(pcamera);

	pcamera->name = "camera";

	pcamera->margin = Vector2(30,30);
//	pcamera->set_scale(Vector2(0.5,0.5));

	pcamera->activate();

//	get_pnode_tree()->root_node.

	NodePath area_path = NodePath(std::vector<std::string> {"area"});
	Area* parea = dynamic_cast<Area*>(get_pnode_tree()->root_node.get_pnode(area_path));

	std::cout << "parea = " << parea << std::endl;

	std::function<void()> oaen = on_area_entered;
	parea->on_body_entered.connect_argless(oaen);

	std::function<void()> oaex = on_area_exited;
	parea->on_body_exited.connect_argless(oaex);
}



void Player::tick(float delta) {

//	std::cout << "tick" << std::endl;

//	std::cout << on_floor << on_wall << on_ceiling << std::endl;
//	std::cout << position.x << std::endl;

	CharacterBody::tick(delta);

	handle_movement_input();
	handle_animations();

	move_and_collide(velocity * delta);

	update_on_things();
}


void Player::handle_movement_input() {
	u32 keys_held = hidKeysHeld();
//	u32 keys_pressed = hidKeysDown();

	if (keys_held & KEY_LEFT) {
		velocity.x = -speed;
	}  
	if (keys_held & KEY_RIGHT) {
		velocity.x = speed;
	} else if (!(keys_held & KEY_LEFT)) {
		velocity.x = 0;
	}

	if ((keys_held & KEY_A) && on_floor) {
		velocity.y = -jump_velocity;
	}

	if (on_floor && velocity.y >= 0) {
		velocity.y = 0;
	} else {
		velocity.y += gravity;
	}
}


void Player::handle_animations() {
	if (velocity.x != 0 || velocity.y != 0) {
		panimated_sprite->play("run");
		if (velocity.x > 0) {
			panimated_sprite->set_flip_x(1);
		} else if (velocity.x < 0) {
			panimated_sprite->set_flip_x(-1);
		}
//		std::cout << "run" << std::endl;
	} else {
		panimated_sprite->play("idle");
//		std::cout << "idle" << std::endl;
	}
}


void Player::move(Vector2 by) {
	Node2D::move(by);

//	std::cout << "moving by " << by.x << " " << by.y << std::endl;
}


void Player::on_area_entered() {
	std::cout << "entered" << std::endl;
}

void Player::on_area_exited() {
	std::cout << "exited" << std::endl;
}