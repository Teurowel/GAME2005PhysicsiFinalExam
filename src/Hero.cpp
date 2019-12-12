#include "Hero.h"
#include "Game.h"

Hero::Hero()
{
	TheTextureManager::Instance()->load("../Assets/textures/hero/heroIdleSheet.png",
		"hero", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/hero/heroWalkSheet.png",
		"heroWalk", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/hero/heroJumpSheet.png",
		"heroJump", TheGame::Instance()->getRenderer());

	m_iCurrentFrame = 0;
	m_iMaxFrame = 4;

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("hero");
	setWidth(size.x / m_iMaxFrame);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.f, 0.f));
	setType(GameObjectType::HERO);

	m_bOnGround = false;
	m_fSpeed = 20.f;

	m_fCurrentAnimationTick = 0.f;
	m_fMaxAnimationTick = 0.3f;

	m_fJumpForce = 50.f;
	m_bJump = true;
	
	m_bGoingRight = true;
	flip = SDL_FLIP_NONE;
	m_moveState = MOVE_IDLE;

}

Hero::~Hero()
{

}

void Hero::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	int width = getWidth();
	int height = getHeight();

	//TheTextureManager::Instance()->draw("hero", xComponent, yComponent,
	//	TheGame::Instance()->getRenderer(), 0, 255, true);
	
	if (m_moveState == MOVE_IDLE || m_moveState == MOVE_UP)
	{
		TheTextureManager::Instance()->drawFrame("hero", xComponent, yComponent, width, height, 0, m_iCurrentFrame, TheGame::Instance()->getRenderer(),
			0, 255, true, flip);
	}
	else if (m_moveState == MOVE_LEFT || m_moveState == MOVE_RIGHT)
	{
		TheTextureManager::Instance()->drawFrame("heroWalk", xComponent, yComponent, width, height, 0, m_iCurrentFrame, TheGame::Instance()->getRenderer(),
			0, 255, true, flip);
	}

}

void Hero::update()
{
	m_fCurrentAnimationTick += (1.f / 60.f);

	if (m_fCurrentAnimationTick >= m_fMaxAnimationTick)
	{
		m_iCurrentFrame += 1;
		if (m_iCurrentFrame == m_iMaxFrame)
			m_iCurrentFrame = 0;

		m_fCurrentAnimationTick = 0.f;
	}




	if (m_bGoingRight)
		flip = SDL_FLIP_NONE;
	else
		flip = SDL_FLIP_HORIZONTAL;



}

void Hero::clean()
{
}

void Hero::SetMoveState(MoveState moveState)
{
	if (m_moveState != moveState)
	{
		if (moveState == MOVE_IDLE || moveState == MOVE_UP)
		{
			m_iMaxFrame = 4;
			m_iCurrentFrame = 0;
			m_fCurrentAnimationTick = 0.f;
			m_fMaxAnimationTick = 0.3f;
		}
		else if (moveState == MOVE_LEFT || moveState == MOVE_RIGHT)
		{
			m_iMaxFrame = 6;
			m_iCurrentFrame = 0;
			m_fCurrentAnimationTick = 0.f;
			m_fMaxAnimationTick = 0.1f;
		}

		m_moveState = moveState;
	}
	
}