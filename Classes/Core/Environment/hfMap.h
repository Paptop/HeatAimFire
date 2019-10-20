#pragma once

#include <vector>
#include <string>

#include "Core/Environment/hfTile.h"

#include "cocos2d.h"

namespace cocos2d
{
	class Scene;
}

namespace Haf
{
	class CMap : public cocos2d::Layer
	{
	public:
		CMap();
		void CreateMap(std::string strData, cocos2d::Scene* scene);
		inline cocos2d::Scene* GetScene() const { return _rootScene; }

	private:
		std::vector<std::vector<CTile*>> _mapData;
		cocos2d::Scene*					_rootScene;
	};
}