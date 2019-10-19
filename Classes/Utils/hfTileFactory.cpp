#include "Utils/hfTileFactory.h"

#include "Core/Environment/hfTile.h"

#include "UTils/hfDebugUtils.h"

#include "cocos2d.h"

Haf::CTileFactory* Haf::CTileFactory::_instance = nullptr;

void Haf::CTileFactory::Init()
{
	_instance = new CTileFactory();
}

void Haf::CTileFactory::DeInit()
{
	delete _instance;
}

Haf::CTileFactory::CTileFactory()
{
}

Haf::CTile* Haf::CTileFactory::CreateTile(char id)
{
	switch (id)
	{
		case '*': return new CTile(LoadAsset("Ground.png"));
		case '-': return new CTile(LoadAsset("Wall.png"));
		case '|': return new CTile(LoadAsset("Wall.png"));
	}

	ASSERT(false, "Unkown tile");
}

cocos2d::Sprite* Haf::CTileFactory::LoadAsset(std::string name)
{
	cocos2d::Sprite* sprite = nullptr;

	sprite = cocos2d::Sprite::create(name);

	if (sprite == nullptr)
	{
		ASSERT(false, "Failed to load sprite :" + name);
		return nullptr;
	}
	else
	{
		return sprite;
	}
}