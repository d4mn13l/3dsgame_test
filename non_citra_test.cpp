/*#include "3dsgame/include/things/resources/resource.hpp"

#include <iostream>

class RealResource : public Resource {
	public:
		virtual void load(std::string path) {};
};

int main() {



	RealResource r = RealResource();

	auto vars = r.get_var_strings_from_file("romfs/resources/tilemap.3gres");

	std::cout << sizeof(r) << std::endl;

	for (auto var : vars) {
//		std::cout << var.first << " = " << var.second << std::endl << std::endl;
	}
}
*/









/*#include <iostream>
#include <fstream>

#include <string>

int main() {
	std::ifstream file("romfs/resources/tilemap.3gres");

	std::string line;

	getline(file, line);

	if (line == "TileMapResource") {
		std::cout << "resource has correct type, continuing" << std::endl;
	}

	bool inside_var = false;
	std::string var_name = "";
	std::string var_value_string = "";


	while (getline(file, line)) {
		if (line.length() == 0) {
			continue;
		}

		// remove all spaces and tabs
		for (int i = 0; i < line.length(); i++) {
			if (line.at(i) == ' ' || line.at(i) == '\t') {
				line.erase(line.begin() + i);
				i -= 1;
			}
		}

		if (line[0] == '[') {
			
			inside_var = true;

			for (int i = 1; i < line.length(); i++) {
				if (line[i] == '=') {
					break;
				}
				var_name += line[i];
			}

			std::cout << "start of var " << var_name << std::endl;

			var_value_string += line.substr(var_name.length() + 2, line.length() - 3 - var_name.length());
		} else if (inside_var) {
			var_value_string += line;
		}

		if (!inside_var) {
			continue;
		}


		if (var_value_string != "") {
			var_value_string += "\n";
		}

		;
		

		if (line[line.length() - 1] == ']') {
			std::cout << "end of var " << var_name << std::endl;
			std::cout << var_name << " is " << var_value_string << std::endl;
			inside_var = false;
			var_name = "";
			var_value_string = "";
		} 
	}
}*/
























//#include "physics_server.hpp"
//#include "physics_body.hpp"

/*#include <cmath>
#include <iostream>
#include <algorithm>

#include "3dsgame/source/nodes/shapes/rectangle_shape.hpp"
#include "3dsgame/source/nodes/physics/character_body.hpp"
#include "3dsgame/source/objects/servers/physics_server.hpp"*/

/*
g++ non_citra_test.cpp 3dsgame/source/objects/servers/object_server.cpp 3dsgame/source/objects/servers/physics_server.cpp 3dsgame/source/objects/object.cpp 3dsgame/source/math/vector2.cpp 3dsgame/source/nodes/node.cpp 3dsgame/source/nodes/node2d.cpp 3dsgame/source/nodes/physics/physics_body.cpp 3dsgame/source/nodes/shapes/rectangle_shape.cpp 3dsgame/source/resources/collision_data.cpp 3dsgame/source/core/node_path.cpp 3dsgame/source/debugging/logging.cpp -I 3dsgame/include/things -I 3dsgame -I 3dsgame/include

g++ non_citra_test.cpp 3dsgame/source/nodes/shapes/rectangle_shape.cpp 3dsgame/source/math/vector2.cpp 3dsgame/source/math/math_stuff.cpp 3dsgame/source/nodes/shapes/shape.cpp 3dsgame/source/nodes/node2d.cpp 3dsgame/source/nodes/node.cpp 3dsgame/source/debugging/logging.cpp 3dsgame/source/core/node_path.cpp -I 3dsgame -I 3dsgame/include -I 3dsgame/include/things

g++ non_citra_test.cpp 3dsgame/source/nodes/shapes/rectangle_shape.cpp 3dsgame/source/math/vector2.cpp 3dsgame/source/math/math_stuff.cpp 3dsgame/source/nodes/shapes/shape.cpp 3dsgame/source/nodes/node2d.cpp 3dsgame/source/nodes/node.cpp 3dsgame/source/debugging/logging.cpp 3dsgame/source/core/node_path.cpp 3dsgame/source/objects/object.cpp 3dsgame/source/objects/servers/object_server.cpp 3dsgame/source/objects/servers/physics_server.cpp 3dsgame/source/resources/collision_data.cpp 3dsgame/source/nodes/physics/character_body.cpp 3dsgame/source/nodes/physics/physics_body.cpp -I 3dsgame -I 3dsgame/include -I 3dsgame/include/things -I 3dsgame/source/nodes
*/



/*int main() {
	RectangleShape* s1 = new RectangleShape();
	s1->size = Vector2(20, 20);

	RectangleShape* s2 = new RectangleShape();
	s2->size = Vector2(20, 20);
	
	
	CharacterBody* c1 = new CharacterBody();

	c1->add_pchild(s1);
	c1->add_pshape(s1);
	
	c1->collision_layer = 1;
	c1->collision_mask = 1;
	c1->monitoring = true;
	c1->enable();

	CharacterBody* c2 = new CharacterBody();

	c2->add_pchild(s2);
	c2->add_pshape(s2);

	c2->collision_layer = 1;
	c2->collision_mask = 1;
	c2->monitorable = true;
	c2->enable();

	c2->move(Vector2(30, 0));

	Vector2 overlap = s1->get_raw_overlap(s2);
	
	std::cout << overlap.x << ", " << overlap.y << std::endl;

	std::vector<CollisionData> cols = get_pphysics_server()->get_collisions(c1, true);

	std::cout << "number of collisions: " << cols.size() << std::endl;

	for (auto col : cols) {
		std::cout << col.overlap.x << ", " << col.overlap.y << std::endl;
	}


	c1->unclip();

	std::cout << "c1 pos = " << c1->get_global_position().x << ", " << c1->get_global_position().y << std::endl;

//	std::cout << s1->get_global_position().x << ", " << s1->get_global_position().y << std::endl;
//	std::cout << s2->get_global_position().x << ", " << s2->get_global_position().y << std::endl;

	return 0;
}*/


















/*template <typename T> int sign(T of) {
	return (of / std::abs(of));
}

class Vector2 {
	public:
		float x,y;

		Vector2() {};
		Vector2(float nx, float ny) {
			x = nx;
			y = ny;
		}
};


class Shape {
	public:
		Vector2 get_overlap(Shape* prect) {
			Vector2 gp = global_position;
			Vector2 prect_gp = prect->global_position;
			Vector2 overlap;

			
			overlap.y = (prect_gp.y + (prect->size.y * sign(prect->size.y) * -1) - (-gp.y + (size.y * sign(size.y)) * -1));
		

			if ((gp.x + size.x < prect_gp.x - prect->size.x) || (gp.x - size.x > prect_gp.x + prect->size.x)) {
				// right side of this is to the left of prect or vice versa -> no overlap can exist
				overlap.x = 0;
			} else {
//				overlap.x = std::clamp((prect_gp.x - prect->size.x * sign(prect->size.x) + gp.x + size.x * sign(size.x)), 2 * -size.x, 2 * size.x);
				overlap.x = prect_gp.x - prect->size.x * sign(prect->size.x) + gp.x + size.x * sign(size.x);

				std::cout << "lambda = " << ((prect_gp.x + prect->size.x - gp.x) / size.x) << " or " << (prect_gp.x - prect->size.x - gp.x) / size.x << std::endl;
}

			if ((gp.y + size.y < prect_gp.y - prect->size.y) || (gp.y - size.y > prect_gp.y + prect->size.y)) {
				// bottom side of this is to the top of prect or vice versa -> no overlap can exist
				overlap.y = 0;
			} else {
				overlap.y = std::clamp((prect_gp.y + (prect->size.y * sign(prect->size.y) * -1) - (-gp.y + (size.y * sign(size.y)) * -1)), 2 * -size.y, 2 * size.y);
			}

			return overlap;
		}
	
		Vector2 size;
		Vector2 global_position;
};*/
