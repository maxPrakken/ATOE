#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include <rt2d/input.h>

class Player : public Entity {
public:
	Player();
	virtual ~Player();

	virtual void update(float deltaTime);

private:
	

};

#endif // !PLAYER_H
