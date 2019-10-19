#include "hfTile.h"

#include "cocos2d.h"

Haf::CTile::CTile(cocos2d::Sprite* sprite)
: _sprite(sprite)
{
}

void Haf::CTile::Render()
{
	_sprite->visit();
}