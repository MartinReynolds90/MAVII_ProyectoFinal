
#pragma once
#include <box2D/box2D.h>


class Box2Dhelper
{
public:
	static b2Body* CreateDynamicBody(b2World* phyWorld);
	static b2Body* CreateStaticBody(b2World* phyWorld);
	static b2Body* CreateKinematicBody(b2World* phyWorld);
	static b2FixtureDef CreateRectangularFixtureDef(float sizeX, float sizeY, float density, float friction, float restitution);
	static b2FixtureDef CreateCircularFixtureDef(float radius, float density, float friction, float restitution);
	static b2FixtureDef CreatePolyFixtureDef(b2Vec2* v, int n, float density, float friction, float restitution);
	static b2FixtureDef CreateTriangularFixtureDef(b2Vec2 c, float h, float density, float friction, float restitution);
	static b2Body* CreateRectangularDynamicBody(b2World* phyWorld, float sizeX, float sizeY, float density, float friction, float restitution);
	static b2Body* CreateRectangularStaticBody(b2World* phyWorld, float sizeX, float sizeY);
	static b2Body* CreateRectangularKinematicBody(b2World* phyWorld, float sizeX, float sizeY);
	static b2Body* CreateCircularDynamicBody(b2World* phyWorld, float radius, float density, float friction, float restitution);
	static b2Body* CreateCircularKinematicBody(b2World* phyWorld, float radius);
	static b2Body* CreateCircularStaticBody(b2World* phyWorld, float radius);
	static b2Body* CreateTriangularDynamicBody(b2World* phyWorld, b2Vec2 center, float h, float density, float friction, float restitution);
	static b2Body* CreateTriangularKinematicBody(b2World* phyWorld, b2Vec2 center, float h);
	static b2Body* CreateTriangularStaticBody(b2World* phyWorld, b2Vec2 center, float h);
	static b2Body* CreatePolyDynamicBody(b2World* phyWorld, b2Vec2* v, int n, float density, float friction, float restitution);
	static b2Body* CreatePolyKinematicBody(b2World* phyWorld, b2Vec2* v, int n);
	static b2Body* CreatePolyStaticBody(b2World* phyWorld, b2Vec2* v, int n);
	static b2DistanceJoint* CreateDistanceJoint(b2World* phyWorld, b2Body* first, b2Vec2 anchorFirst, b2Body* second, b2Vec2 anchorSecond,
		float distance, float frec, float dampRatio);
	static b2RevoluteJoint* CreateRevoluteJoint(b2World* phyWorld, b2Body* base, b2Vec2 anchorBase, b2Body* second,
		float angMin, float angMax, float motorSpeed, float maxTorque,
		bool enableMotor, bool enableLimits);
	static b2PrismaticJoint* CreatePrismaticJoint(b2World* phyWorld, b2Body* base, b2Vec2 anchorBase, b2Body* second,
		b2Vec2 axis, float distMin, float distMax, float motorSpeed, float maxForce,
		bool enableMotor, bool enableLimits);
	static b2PulleyJoint* CreatePulleyJoint(b2World* phyWorld, b2Body* first, b2Vec2 anchorFirst, b2Vec2 worldAnchor1,
		b2Body* second, b2Vec2 anchorSecond, b2Vec2 worldAnchor2, float ratio);
	static b2GearJoint* CreateGearJoint(b2World* phyWorld, b2Body* first, b2Body* second,
		b2Joint* Joint1, b2Joint* Joint2, float ratio);
	static b2MouseJoint* CreateMouseJoint(b2World* phyWorld, b2Body* second, float maxForce);
};
