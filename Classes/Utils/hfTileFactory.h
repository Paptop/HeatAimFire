#pragma once

#include <string>

namespace cocos2d
{
	class Sprite;
}

namespace Haf
{
	class CTile;

	class CTileFactory
	{
	public:
		static inline CTileFactory* GetInstance() { return _instance; }
		static void Init();
		static void DeInit();
		static CTile* CreateTile(char id);

		//TODO: Move to separate class
		static cocos2d::Sprite* LoadAsset(std::string name);
		CTileFactory();
	private:
		static CTileFactory* _instance;
	};
}
