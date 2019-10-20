#pragma once

#include "Core/Environment/hfTilePos.h"

namespace cocos2d
{
	class Sprite;
}

namespace Haf
{
	class CEntity
	{
	public:
		cocos2d::Sprite* GetSprite() const { return _sprite; }
		const STilePos& GetPos() const { return _pos; }

		void SetSprite(cocos2d::Sprite* sprite);
		void SetPos(const STilePos& tilePos);

	private:
		cocos2d::Sprite* _sprite;
		STilePos		 _pos;
	};
}