//#include "physics_server.hpp"
//#include "physics_body.hpp"

#include <cmath>
#include <iostream>
#include <algorithm>

/*
g++ non_citra_test.cpp 3dsgame/source/objects/servers/object_server.cpp 3dsgame/source/objects/servers/physics_server.cpp 3dsgame/source/objects/object.cpp 3dsgame/source/math/vector2.cpp 3dsgame/source/nodes/node.cpp 3dsgame/source/nodes/node2d.cpp 3dsgame/source/nodes/physics/physics_body.cpp 3dsgame/source/nodes/shapes/rectangle_shape.cpp 3dsgame/source/resources/collision_data.cpp 3dsgame/source/core/node_path.cpp 3dsgame/source/debugging/logging.cpp -I 3dsgame/include/things -I 3dsgame -I 3dsgame/include
*/

template <typename T> int sign(T of) {
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
};


int main() {
	Shape s1;
	s1.global_position = Vector2(2, 1);
	s1.size = Vector2(20, 4);

	Shape s2;
	s2.global_position = Vector2(-20, 11);
	s2.size = Vector2(20, 10);

	
	Vector2 overlap = s1.get_overlap(&s2);
	std::cout << "overlap = " << overlap.x << ", " << overlap.y << std::endl;

	

	return 0;
}