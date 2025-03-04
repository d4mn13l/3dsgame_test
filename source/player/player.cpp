#include "player.hpp"

#include "build/knight.h"
#include <iostream>


Player::Player() {

}


void Player::_ready() {
	std::cout << "readying player" << std::endl;
	name = "Player";

	enable();
	monitoring = true;
	monitorable = true;

	collision_layer = PL_PLAYER;
	collision_mask = PL_WALLS | PL_PLAYER | PL_ENEMIES | PL_COINS;

//	set_size(Vector2(10, 16));

	OUT("hi");

	// create Shape
	RectangleShape* pshape = new RectangleShape();
	pshape->size = Vector2(10, 16);
	pshape->name = "shape";
	add_pchild(pshape);


	OUT("hi");
	// create AnimatedSprite

	Animation idle = Animation("idle", std::vector<int> {8,9,10,11}, 0.2, true);
	Animation run = Animation("run", knight_run1_idx, knight_run16_idx, 0.2, true);
	Animation roll = Animation("roll", knight_roll1_idx, knight_roll8_idx, 0.2, true);
	SpriteFrames frames = SpriteFrames("romfs:/gfx/knight.t3x", std::vector<Animation> {idle, run, roll});

//	std::cout << "run name is " << run.name << " <-" << std::endl;

	OUT("hi");	
	//panimated_sprite = new AnimatedSprite(frames, "idle", 0);
	panimated_sprite = new AnimatedSprite();
	OUT("hello there");
	panimated_sprite->set_sprite_frames(frames);
	panimated_sprite->play("idle");
	panimated_sprite->name = "AnimatedSprite";
	panimated_sprite->scale = Vector2(2,2);
	
	panimated_sprite->move(Vector2(0, -8));

	add_pchild(panimated_sprite);

	OUT("hi");
	Camera* pcamera = new Camera(TOP_SCREEN);
	add_pchild(pcamera);

	pcamera->name = "camera";

	pcamera->margin = Vector2(30,30);
//	pcamera->set_scale(Vector2(0.5,0.5));


	pcamera->activate();

//	get_pnode_tree()->root_node.

/*	NodePath area_path = NodePath(std::vector<std::string> {"area"});
	Area* parea = dynamic_cast<Area*>(get_pnode_tree()->root_node.get_pnode(area_path));

	std::cout << "parea = " << parea << std::endl;

	std::function<void()> oaen = on_area_entered;
	parea->on_body_entered.connect_argless(oaen);

	std::function<void()> oaex = on_area_exited;
	parea->on_body_exited.connect_argless(oaex);
*/

	OUT("hi");
	Timer* pt = new Timer(2.5);
	pt->name = "Timer";
	pt->timeout.connect_argless(on_area_entered);
	add_pchild(pt);
	pt->start();


	OUT("hi");
	CharacterBody::_ready();


	get_pnode_tree()->print_tree();

	//NodePath np = NodePath(std::vector<std::string> {"..", "Decoration"});


}


void Player::_tick(float delta) {

//	std::cout << "_tick" << std::endl;

//	std::cout << on_floor << on_wall << on_ceiling << std::endl;

	CharacterBody::_tick(delta);

	handle_movement_input();
	handle_animations();

	move_and_collide(velocity * delta);

	update_on_things();


	auto cols = get_pphysics_server()->get_collisions(this);
//	std::cout << cols.size() << std::endl;
	for (auto col : cols) {
//	   std::cout << "po: x = " << col.overlap.x << ", y = " << col.overlap.y << std::endl;
	  
	}

}


void Player::handle_movement_input() {
	u32 keys_held = hidKeysHeld();
//	u32 keys_pressed = hidKeysDown();

//	std::cout << on_floor << on_wall << on_ceiling << std::endl;

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




void Player::on_area_entered() {
	llog("entered", 10);
}

void Player::on_area_exited() {
	llog("exited", 10);
}
