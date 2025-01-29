#include <fstream>

#include <3ds.h>
#include <citro2d.h>

#include "include/3dsgame.hpp"

#include <3ds/console.h>

#include "moving_sprite.hpp"

int main() {
	consoleInit(GFX_BOTTOM, NULL);
	get_pobject_server()->add_pobject(get_pnode_tree()); // why do i need to do this


	for (std::string log_msg : log_queue) {
		dlog(log_msg, 4);
	}
	
	get_pobject_server()->print_pobjects();

	MainLoop main_loop;

	MovingSprite moving_sprite(3, true);
	moving_sprite.name = "moving_sprite";

	C2D_SpriteSheet sprite_sheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");


	if (!sprite_sheet) svcBreak(USERBREAK_PANIC);


	C2D_SpriteFromSheet(&moving_sprite.c2d_sprite, sprite_sheet, 10);
	moving_sprite.move(Vector2{100, 100});

	get_pnode_tree()->root_node.add_pchild(&moving_sprite);


	Sprite moving_sprite_child = Sprite(0, TOP_SCREEN);

	C2D_SpriteFromSheet(&moving_sprite_child.c2d_sprite, sprite_sheet, 42);
	moving_sprite_child.move(Vector2(20,20));

	moving_sprite.add_pchild(&moving_sprite_child);




//	Sprite bottom_sprite(1, true);

//	C2D_SpriteFromSheet(&bottom_sprite.c2d_sprite, sprite_sheet, 3);
//	bottom_sprite.move(Vector2{90,90});


	Node node_level_one;
	node_level_one.name = "Level 1one";

	Node node_level_two;
	node_level_two.name = "Level 2";

	Node another_node_level_one;
	another_node_level_one.name = "Level 1.2";

	node_level_one.add_pchild(&node_level_two);

	dlog("hi4", 4);

	get_pnode_tree()->root_node.add_pchild(&node_level_one);
	get_pnode_tree()->root_node.add_pchild(&another_node_level_one);



	std::vector<Frame> frames = {Frame{1, 1.2}, Frame{2, 1.2}, Frame{3, 1.2}, Frame{4, 1.2}};
	std::vector<Animation> animations = {Animation("default", frames, true)};
	SpriteFrames sprite_frames = SpriteFrames("romfs:/gfx/sprites.t3x", animations);

	AnimatedSprite* panimated_sprite = new AnimatedSprite(sprite_frames, "default", 0, TOP_SCREEN);
	panimated_sprite->move(Vector2{200, 200});

	get_pnode_tree()->root_node.add_pchild(panimated_sprite);


	TileMapResource tile_map_resource = TileMapResource(std::vector<std::vector<int>> {{1,2,6,5,4,3}, {4,5,2,4,6,4}, {1,2,6,5,4,3}, {4,5,2,4,6,4}, {1,2,6,5,4,3}, {4,5,2,4,6,4}}, "romfs:/gfx/tileset.t3x", 16, 0);

	TileMap* ptile_map = new TileMap(tile_map_resource);

	ptile_map->move(Vector2(100, 100));

	ptile_map->name = "TileMap";

	get_pnode_tree()->root_node.add_pchild(ptile_map);




	PhysicsBody* ppb = new PhysicsBody(true, false, true);
	ppb->move(Vector2(100, 100));
	ppb->set_size(Vector2(50, 50));
	ppb->name = "static body";
	ppb->collision_layer = 1;
	ppb->collision_mask = 1;

	get_pnode_tree()->root_node.add_pchild(ppb);


	CharacterBody* pmoving_sprite_body = new CharacterBody(true, true, true);
	pmoving_sprite_body->set_size(Vector2(24, 24));
	pmoving_sprite_body->name = "moving sprite body";
	pmoving_sprite_body->move(Vector2(69, 420));
	pmoving_sprite_body->collision_layer = 1;
	pmoving_sprite_body->collision_mask = 1;

	pmoving_sprite_body->move(moving_sprite.get_global_position() - pmoving_sprite_body->get_global_position());

	moving_sprite.add_pchild(pmoving_sprite_body);



	get_pobject_server()->print_pobjects();

	get_pnode_tree()->print_tree();


	main_loop.run();

	return 0;
}
