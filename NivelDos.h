#pragma once
#include "Niveles.h"
#include "Box2Dhelper.h"
#include <box2D/box2D.h>

class NivelDos : public Niveles 
{
private:
	bool completed = false;

public:
	void load(b2World* phyWorld) override;
	void unload(b2World* phyWorld) override;
	bool isCompleted() override {
		return completed;
	}
};

