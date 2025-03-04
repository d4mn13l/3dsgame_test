#ifndef DAMAGEABLE
#define DAMAGEABLE


class Damageable {
	public:
		virtual void take_damage(float amount) = 0;
};


#endif