#pragma once
#ifndef __Target__
#define __Target__

#include "DisplayObject.h"
#include "TextureManager.h"
#include "Scene.h"

class Target : public DisplayObject {
public:
	Target();
	~Target();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void reset();
	
private:
	void m_move();

	void m_checkBounds();
};


#endif /* defined (__Target__) */