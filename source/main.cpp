#include "3dsgame.hpp"

#include <bitset>

//#include "moving_sprite/moving_sprite.hpp"
//#include "player/player.hpp"
#include "player.hpp"
#include "slime.hpp"
#include "coin.hpp"
#include "source/pr/performance_reporter.hpp"



int main() {

	MainLoop main_loop = MainLoop();



//	std::cout << "size of vector = " << sizeof(Vector2) << std::endl;

	


/*	
	MovingSprite moving_sprite(3, true);
	moving_sprite.name = "moving_sprite";

	C2D_SpriteSheet sprite_sheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");


	if (!sprite_sheet) svcBreak(USERBREAK_PANIC);


//	C2D_SpriteFromSheet(&moving_sprite.c2d_sprite, sprite_sheet, 10);
	moving_sprite.move(Vector2{100, 100});

	get_pnode_tree()->root_node.add_pchild(&moving_sprite);


	Sprite moving_sprite_child = Sprite(0, TOP_SCREEN);

//	C2D_SpriteFromSheet(&moving_sprite_child.c2d_sprite, sprite_sheet, 42);
	moving_sprite.set_c2d_image_from_psheet(&sprite_sheet, 42);
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

	llog("hi4", 4);

	get_pnode_tree()->root_node.add_pchild(&node_level_one);
	get_pnode_tree()->root_node.add_pchild(&another_node_level_one);



	std::vector<Frame> frames = {Frame{1, 1.2}, Frame{2, 1.2}, Frame{3, 1.2}, Frame{4, 1.2}};
	std::vector<Animation> animations = {Animation("default", frames, true)};
	SpriteFrames sprite_frames = SpriteFrames("romfs:/gfx/sprites.t3x", animations);

	AnimatedSprite* panimated_sprite = new AnimatedSprite(sprite_frames, "default", 0, TOP_SCREEN);
	panimated_sprite->move(Vector2{200, 200});

	get_pnode_tree()->root_node.add_pchild(panimated_sprite);
*/


/*	TileMapResource tile_map_resource = TileMapResource(std::vector<std::vector<int>> {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,1,0,0,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,23,24,0,0},
			{0,0,0,0,0,0,0,2,0,0,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,2,0,0,45,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,2,0,0,66,0,0,1,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
		}, 
		"romfs:/gfx/tileset.t3x", 16, 0);
	tile_map_resource.collision = true;
	tile_map_resource.collision_layer = PL_WALLS;


	TileMap* ptile_map = new TileMap(tile_map_resource);

	ptile_map->name = "TileMap";
	get_pnode_tree()->root_node.add_pchild(ptile_map);

	get_pnode_tree()->print_tree();*/

/*

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

	*/


	TileMapResource tmr = TileMapResource("romfs:/resources/tilemap.3gres");
	TileMap* ptile_map = new TileMap(tmr);
	ptile_map->name = "TileMap";

	get_pnode_tree()->root_node.add_pchild(ptile_map);

	TileMapResource decoration_res = TileMapResource("romfs:/resources/decoration.3gres");
	TileMap* pdecoration_map = new TileMap(decoration_res);
	pdecoration_map->name = "Decoration";
	get_pnode_tree()->root_node.add_pchild(pdecoration_map);



	PhysicsBody* pfloor = new PhysicsBody(false, true);
	pfloor->name = "pfloor";
	pfloor->collision_layer = PL_WALLS;
	pfloor->enable();

	RectangleShape* pfloor_pshape = new RectangleShape();
	pfloor_pshape->set_size(Vector2(200, 20));
	pfloor->add_pchild(pfloor_pshape);

	pfloor->move(Vector2(100, 100));

//	get_pnode_tree()->root_node.add_pchild(pfloor);


	PhysicsBody* pwall = new PhysicsBody(false, true);
	pwall->name = "pwall";
	pwall->collision_layer = PL_WALLS;
	pwall->enable();

	RectangleShape* pwall_shape = new RectangleShape();
	pwall_shape->set_size(Vector2(20, 32));
	pwall->add_pchild(pwall_shape);

	pwall->move(Vector2(140, 74));

//	get_pnode_tree()->root_node.add_pchild(pwall);


	PhysicsBody* pceil = new PhysicsBody(false, true);
	pceil->name = "pceil";
	pceil->collision_layer = PL_WALLS;
	pceil->enable();

	RectangleShape* pceil_shape = new RectangleShape();
	pceil_shape->set_size(Vector2(100, 10));
	pceil->add_pchild(pceil_shape);
	pceil->move(Vector2(50, 50));

//	get_pnode_tree()->root_node.add_pchild(pceil);



	Area* parea = new Area();
	parea->name = "area";
	parea->collision_mask = PL_PLAYER;
	parea->enable();
	parea->monitoring = true;

	RectangleShape* parea_pshape = new RectangleShape();
	parea_pshape->set_size(Vector2(20, 20));
	parea->add_pchild(parea_pshape);

	parea->move(Vector2(250, 50));
//	get_pnode_tree()->root_node.add_pchild(parea);


	Sprite* pbottom_sprite = new Sprite("romfs:/gfx/sprites.t3x", 10, 0, BOTTOM_SCREEN);
	pbottom_sprite->name = "BottomScreenSprite";
//	get_pnode_tree()->root_node.add_pchild(pbottom_sprite);

	OUT(std::to_string(pbottom_sprite->get_global_position().x) + "/" + std::to_string(pbottom_sprite->get_global_position().y));



	Sprite* psprite = new Sprite("romfs:/gfx/tileset.t3x", 1, 0, TOP_SCREEN);
	psprite->name = "Sprite";
//	get_pnode_tree()->root_node.add_pchild(psprite);


	Point* porigin = new Point();
	porigin->name = "OriginPoint";
	get_pnode_tree()->root_node.add_pchild(porigin);



	TouchButton* ptouch_button = new TouchButton();
	ptouch_button->name = "TouchButton";
	ptouch_button->set_size(Vector2(100, 100));
//	get_pnode_tree()->root_node.add_pchild(ptouch_button);



	TextureButton* ptexture_button = new TextureButton();
	ptexture_button->set_screen(BOTTOM_SCREEN);
	ptexture_button->name = "TextureButton";
	ptexture_button->set_normal_image(load_c2d_image("romfs:/gfx/sprites.t3x", 5));
	ptexture_button->set_pressed_image(load_c2d_image("romfs:/gfx/sprites.t3x", 6));
	get_pnode_tree()->root_node.add_pchild(ptexture_button);


	Player* pplayer = new Player();

	pplayer->move(Vector2(100, 0));

	get_pnode_tree()->root_node.add_pchild(pplayer);



	Node2D* penemies = new Node2D();
	penemies->name = "Enemies";
	get_pnode_tree()->root_node.add_pchild(penemies);

	Slime* pslime = new Slime();
	pslime->name = "Slime";
	pslime->move(Vector2(120, 0));
//	penemies->add_pchild(pslime);



//	std::cout << std::bitset<8>(pplayer->collision_mask) << std::endl;
//	std::cout << std::bitset<8>(pslime->collision_layer) << std::endl;


//	get_pobject_server()->print_pobjects();

	/*Node2D* pcoins = new Node2D();
	pcoins->name = "Coins";

	for (int i = 0; i < 10; i++) {
		Coin* pcoin = new Coin();
		pcoin->move(Vector2(32*i, 50));
		pcoins->add_pchild(pcoin);
	}

	get_pnode_tree()->root_node.add_pchild(pcoins);*/

//	consoleInit(GFX_BOTTOM, NULL);
//	PerformanceReporter* pr = new PerformanceReporter();
//	pr->name = "PerformanceReporter";
//	get_pnode_tree()->root_node.add_pchild(pr);


	get_pnode_tree()->print_tree();

	main_loop.start();

	return 0;
}
