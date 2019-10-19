#pragma once

#include "Core/Environment/hfTilePos.h"

namespace cocos2d
{
	class Sprite;
}

namespace Haf
{
	class CTile
	{
	public:
		CTile(cocos2d::Sprite* sprite);
		inline void SetMapPos(const STilePos& pos) { _gridPos = pos; }

		const STilePos& GetMapPos()  const { return _gridPos; }
		cocos2d::Sprite* GetSprite() const { return _sprite; }

		void Render();

	private:
		cocos2d::Sprite* _sprite;
		STilePos		 _gridPos;
	};
}