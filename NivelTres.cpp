#include "NivelTres.h"
#include "Box2Dhelper.h"


void NivelTres::load(b2World* phyWorld) {


    firstObstacleBody = Box2Dhelper::CreateRectangularStaticBody(phyWorld, 1, 45);
    firstObstacleBody->SetTransform(b2Vec2(50.0f, 80.0f), 23.0f);
    secondObstacleBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 2, 45, 1.0f, 0.5f, 0.3f);
    secondObstacleBody->SetTransform(b2Vec2(20.0f, 90.0f),4.0f);
    thirdObstacleBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 3, 5, 1.0f, 0.5f, 0.3f);
    thirdObstacleBody->SetTransform(b2Vec2(60.0f, 5.0f), 56.0f);
    fourthObstacleBody = Box2Dhelper::CreateCircularKinematicBody(phyWorld, 5.0);
    fourthObstacleBody->SetTransform(b2Vec2(15.0f, 25.0f),7.0f);
    fifthObstacleBody = Box2Dhelper::CreateTriangularStaticBody(phyWorld, b2Vec2(4.0, 4.0), 4.0f);
    fifthObstacleBody->SetTransform(b2Vec2(60.0f, 7.0f), 56.9f);


    naveBody = Box2Dhelper::CreateCircularDynamicBody(phyWorld, 4.0, 0.5, 0.5, 0.5);
    naveBody->SetTransform(b2Vec2(50.0, 50.0), 0.0f);

    rocaBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 2.0f, 2.0f, 3.0f, 1.0f, 0.2f); //<<<<<<<<<<<<<<<<<<<<<<<<<<ROCA
    rocaBody->SetTransform(b2Vec2(50.0f, 40.0f), 0.0f);

    firstBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 2, 2, 1.0f, 0.5, 0.3f);//torso
    firstBody->SetTransform(b2Vec2(10.0f, 75.0f), 0.0f);

    secondBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 1, 1, 1.0f, 0.5, 0.3f);//cabeza
    secondBody->SetTransform(b2Vec2(10.0f, 73.25f), 0.0f);

    thirdBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 2.5, 0.5, 1.0f, 0.5f, 0.3f);
    thirdBody->SetTransform(b2Vec2(7.25f, 74.0f), 0.0f);

    fourthBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 2.5, 0.5, 1.0f, 0.5f, 0.3f);
    fourthBody->SetTransform(b2Vec2(12.75f, 74.0f), 0.0f);

    fifthBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 0.5, 3, 5.0f, 0.5f, 0.3f);
    fifthBody->SetTransform(b2Vec2(9.25f, 77.5f), 0.0f);

    sixthBody = Box2Dhelper::CreateRectangularDynamicBody(phyWorld, 0.5, 3, 5.0f, 0.5f, 0.3f);
    sixthBody->SetTransform(b2Vec2(10.75f, 77.5f), 0.0f);

    groundBody = Box2Dhelper::CreateRectangularStaticBody(phyWorld, 100, 10);
    groundBody->SetTransform(b2Vec2(50.0f, 100.0f), 0.0f);

    upBody = Box2Dhelper::CreateRectangularStaticBody(phyWorld, 100, 10);
    upBody->SetTransform(b2Vec2(50.0f, 0.0f), 0.0f);

    leftWallBody = Box2Dhelper::CreateRectangularStaticBody(phyWorld, 10, 100);
    leftWallBody->SetTransform(b2Vec2(0.0f, 50.0f), 0.0f);

    rightWallBody = Box2Dhelper::CreateRectangularStaticBody(phyWorld, 10, 100);
    rightWallBody->SetTransform(b2Vec2(100.0f, 50.0f), 0.0f);

    revolute_head.Initialize(firstBody, secondBody, b2Vec2(10.0f, 74.0f));
    revolute_head.upperAngle = (0.4);
    revolute_head.lowerAngle = (0.1);
    revolute_head.collideConnected = true;
    b2RevoluteJoint* revoluteHead = (b2RevoluteJoint*)phyWorld->CreateJoint(&revolute_head);

    revolute_armR.Initialize(firstBody, thirdBody, b2Vec2(9.0f, 74.0f));
    revolute_armR.upperAngle = (0.1);
    revolute_armR.lowerAngle = (0.3);
    revolute_armR.collideConnected = true;
    b2RevoluteJoint* revoluteArmR = (b2RevoluteJoint*)phyWorld->CreateJoint(&revolute_armR);

    revolute_armL.Initialize(firstBody, fourthBody, b2Vec2(11.0f, 74.0f));
    revolute_armL.upperAngle = (0.1);
    revolute_armL.lowerAngle = (0.3);
    revolute_armL.collideConnected = true;
    b2RevoluteJoint* revoluteArmL = (b2RevoluteJoint*)phyWorld->CreateJoint(&revolute_armL);

    revolute_legR.Initialize(firstBody, fifthBody, b2Vec2(9.25f, 76.0f));
    revolute_legR.upperAngle = (0.1);
    revolute_legR.lowerAngle = (0.15);
    revolute_legR.collideConnected = true;
    b2RevoluteJoint* revoluteLegR = (b2RevoluteJoint*)phyWorld->CreateJoint(&revolute_legR);

    revolute_legL.Initialize(firstBody, sixthBody, b2Vec2(10.75f, 76.0f));
    revolute_legL.upperAngle = (0.1);
    revolute_legL.lowerAngle = (0.15);
    revolute_legL.collideConnected = true;
    b2RevoluteJoint* revoluteLegL = (b2RevoluteJoint*)phyWorld->CreateJoint(&revolute_legL);



}
void NivelTres::unload(b2World* phyWorld) {//DESTRUYE CADA ELEMENTO DEL NIVEL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    if (firstObstacleBody) {
        phyWorld->DestroyBody(firstObstacleBody);
        firstObstacleBody = nullptr;//para evitar borrar demas
    }
    if (secondObstacleBody) {
        phyWorld->DestroyBody(secondObstacleBody);
        secondObstacleBody = nullptr;//para evitar borrar demas
    }
    if (thirdObstacleBody) {
        phyWorld->DestroyBody(thirdObstacleBody);
        thirdObstacleBody = nullptr;//para evitar borrar demas
    }
    if (fourthObstacleBody) {
        phyWorld->DestroyBody(fourthObstacleBody);
        fourthObstacleBody = nullptr;//para evitar borrar demas
    }
    if (fifthObstacleBody) {
        phyWorld->DestroyBody(fifthObstacleBody);
        fifthObstacleBody = nullptr;//para evitar borrar demas
    }
    if (naveBody) {
        phyWorld->DestroyBody(naveBody);
        naveBody = nullptr;
    }
    if (rocaBody) {
        phyWorld->DestroyBody(rocaBody);
        rocaBody = nullptr;
    }
    if (firstBody) {
        phyWorld->DestroyBody(firstBody);
        firstBody = nullptr;
    }
    if (secondBody) {
        phyWorld->DestroyBody(secondBody);
        secondBody = nullptr;
    }
    if (thirdBody) {
        phyWorld->DestroyBody(thirdBody);
        thirdBody = nullptr;
    }
    if (fourthBody) {
        phyWorld->DestroyBody(fourthBody);
        fourthBody = nullptr;
    }
    if (fifthBody) {
        phyWorld->DestroyBody(fifthBody);
        fifthBody = nullptr;
    }
    if (sixthBody) {
        phyWorld->DestroyBody(sixthBody);
        sixthBody = nullptr;
    }
    if (firstObstacleBody) {
        phyWorld->DestroyBody(firstObstacleBody);
        firstObstacleBody = nullptr;
    }
    if (secondObstacleBody) {
        phyWorld->DestroyBody(secondObstacleBody);
        secondObstacleBody = nullptr;
    }
    if (thirdObstacleBody) {
        phyWorld->DestroyBody(thirdObstacleBody);
        thirdObstacleBody = nullptr;
    }
    if (fourthObstacleBody) {
        phyWorld->DestroyBody(fourthObstacleBody);
        fourthObstacleBody = nullptr;
    }
    if (fifthObstacleBody) {
        phyWorld->DestroyBody(fifthObstacleBody);
        fifthObstacleBody = nullptr;
    }
}
