#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "MoveState.h"
#include "CollisionManager.h"
#include "SoundManager.h"

#include "Platform.h"
#include "Hero.h"

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	// Hero Stuff
	Hero* m_pHero;
	//MoveState m_moveState;

	// Platform Stuff
	Platform* m_pPlatform;

	glm::vec2 m_mousePosition;

	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;
	bool m_isGravityEnabled = false;

	// Physics Variables
	float m_gravity = 9.8f;
	int m_PPM = 10; // pixels per meter
	glm::vec2 m_position = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_velocity = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_acceleration = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_speedFactor = glm::vec2(0.0f, 0.0f);

	// Physics functions
	void m_move();
};

#endif /* defined (__START_SCENE__) */