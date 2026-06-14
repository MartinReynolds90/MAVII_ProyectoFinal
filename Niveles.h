#pragma once
#include <Box2D/Box2D.h>


class Niveles
{
public:
	b2Body* firstObstacleBody;
	b2Body* secondObstacleBody;
	b2Body* thirdObstacleBody;
	b2Body* fourthObstacleBody;
	b2Body* fifthObstacleBody;

	b2Body* naveBody;
	b2Body* rocaBody;
	b2Body* firstBody;
	b2Body* secondBody;
	b2Body* thirdBody;
	b2Body* fourthBody;
	b2Body* fifthBody;
	b2Body* sixthBody;

	b2Body* groundBody;
	b2Body* upBody;
	b2Body* leftWallBody;
	b2Body* rightWallBody;

	b2RevoluteJointDef revolute_head;
	b2RevoluteJointDef revolute_armL;
	b2RevoluteJointDef revolute_armR;
	b2RevoluteJointDef revolute_legL;
	b2RevoluteJointDef revolute_legR;


	//b2RevoluteJointDef resorte;

	virtual void load(b2World* world) = 0;
	virtual void unload(b2World* world) = 0;
	virtual bool isCompleted() = 0;
	virtual ~Niveles() {}

};

