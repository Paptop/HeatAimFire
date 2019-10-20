#include "Core/Environment/hfMap.h"

#include "Utils/hfDebugUtils.h"
#include "Utils/hfTileFactory.h"

#include "cocos2d.h"

Haf::CMap::CMap()
: _mapData()
, _rootScene(nullptr)
{
}

void Haf::CMap::CreateMap(std::string strData, cocos2d::Scene* scene)
{
	scene->addChild(this);

	std::vector<CTile*> rowTiles;

	int row = 0;

	for (int i = 0; i < strData.size(); ++i)
	{
		const char c = strData.at(i);

		if (c == '\r')
		{
			continue;
		}

		if (c == '\n')
		{
			_mapData.push_back(rowTiles);
			rowTiles.clear();
			row++;
			continue;
		}
		int col = rowTiles.size();

		CTile* newTile = CTileFactory::CreateTile(c);
		newTile->SetMapPos(STilePos(row, col));

		cocos2d::Sprite* sprite = newTile->GetSprite();
		sprite->setPosition(col * sprite->getBoundingBox().size.width, row * sprite->getBoundingBox().size.height);
		this->addChild(sprite);
		rowTiles.push_back(newTile);
	}
}