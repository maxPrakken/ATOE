/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myPlayer = new Player();
	myPlayer->position = Point2(SWIDTH/2, SHEIGHT/2);
	myPlayer->addSprite("assets/player.tga");

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myPlayer);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myPlayer);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myPlayer;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	playerMovement(deltaTime);
}

void MyScene::playerMovement(float deltaTime)
{
	if (input()->getKey(GLFW_KEY_W)) {
		std::cout << "pressing W" << std::endl;
		myPlayer->position.y -= moveSpeed * deltaTime;
	}
	
	if (input()->getKey(GLFW_KEY_S)) {
		myPlayer->position.y += moveSpeed * deltaTime;
	}

	if (input()->getKey(GLFW_KEY_A)) {
		myPlayer->position.x -= moveSpeed * deltaTime;
	}

	if (input()->getKey(GLFW_KEY_D)) {
		myPlayer->position.x += moveSpeed * deltaTime;
	}
}
