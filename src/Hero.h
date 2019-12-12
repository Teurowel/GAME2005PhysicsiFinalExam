#pragma once
#ifndef __Hero__
#define __Hero__

#include "DisplayObject.h"
#include "MoveState.h"
// SDL Libraries
#include<SDL.h>
#include<SDL_image.h>

class Hero : public DisplayObject
{
public:
	Hero();
	~Hero();
	
	// Inherited via GameObject
	virtual void draw() override;

	virtual void update() override;

	virtual void clean() override;

	bool GetOnGround() const { return m_bOnGround; }
	void SetOnGround(bool bOnGround) { m_bOnGround = bOnGround; }
	float GetSpeed() const { return m_fSpeed; }
	float GetJumpForce() const { return m_fJumpForce; }
	bool GetJump() const { return m_bJump; }
	void SetJump(bool bJump) { m_bJump = bJump; }
	void SetGoingRight(bool bGoingRight) { m_bGoingRight = bGoingRight; }
	void SetMoveState(MoveState moveState);
	MoveState GetMoveState() const { return m_moveState; }
private:
	bool m_bOnGround;
	float m_fSpeed;

	int m_iCurrentFrame;
	int m_iMaxFrame;

	float m_fCurrentAnimationTick;
	float m_fMaxAnimationTick;

	float m_fJumpForce;
	bool m_bJump;
	
	bool m_bGoingRight;
	SDL_RendererFlip flip;

	MoveState m_moveState;

};

#endif /* defined (__Hero__) */