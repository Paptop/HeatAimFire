#pragma once

#include <vector>
#include <string>

#include "Core/Environment/hfTile.h"

namespace cocos2d
{
	class Scene;
}

namespace Haf
{
	class CMap
	{
	public:
		CMap();
		void CreateMap(std::string strData, cocos2d::Scene* scene);

	private:
		std::vector<std::vector<CTile*>> _mapData;
		cocos2d::Scene*					_rootScene;
	};
}