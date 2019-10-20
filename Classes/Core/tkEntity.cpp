#include "Core/tkEntity.h"


void Haf::CEntity::SetSprite(cocos2d::Sprite* sprite)
{
	_sprite = sprite;
}

void Haf::CEntity::SetPos(const STilePos& tilePos)
{
	_pos = tilePos;
}