#include "moving_sprite.hpp"


MovingSprite::MovingSprite(int z_index_arg, bool top_screen) : Sprite::Sprite(z_index_arg, top_screen) {
	return;
}

void MovingSprite::tick(float delta) {
	Sprite::tick(delta);
//	hidScanInput();

//	dlog("elo", 10);
//	std::cout << "position = " << position.x << "." << position.y << std::endl; 

	u32 keys_held = hidKeysHeld();

//	move(Vector2{10,10});

	if (keys_held & KEY_UP) {
		move(Vector2{0, -speed});
	}
	if (keys_held & KEY_RIGHT) {
		move(Vector2{speed, 0});
	}
	if (keys_held & KEY_DOWN) {
		move(Vector2{0, speed});
	}
	if (keys_held & KEY_LEFT) {
		move(Vector2{-speed, 0});
	}


	NodePath shape_path = NodePath(std::vector<std::string> {"moving sprite body"});
	NodePath static_shape_path = NodePath(std::vector<std::string> {"static body"});

	PhysicsBody* shape = dynamic_cast<PhysicsBody*>(get_pnode(shape_path));
	PhysicsBody* static_shape = dynamic_cast<PhysicsBody*>(get_pnode_tree()->get_pnode(static_shape_path));


	if (get_pphysics_server()->is_colliding(shape)) {
		Vector2 overlap = shape->get_overlap(get_pphysics_server()->get_colliders(shape).at(0));
		std::cout << overlap.x << "/ " << overlap.y << std::endl;
	} else {
		Vector2 overlap = shape->get_overlap(static_shape);
		std::cout << overlap.x << "/ " << overlap.y << std::endl;
	}

//	std::cout << get_pphysics_server()->is_colliding(shape) << std::endl;

//	std::cout << get_global_position().x << " " << shape->get_global_position().x << std::endl;

//	if (!(shape->is_overlapping(static_shape))) {
//		std::cout << "no" << std::endl;
//	}
//	if (static_shape == NULL) {
//		std::cout << "couldnt find shape" << std::endl;
//	} else {
//		std::cout << shape->is_overlapping(static_shape) << std::endl;
//	}
}