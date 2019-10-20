#pragma once

#include "Controllers/hfKeyboardController.h"

namespace cocos2d
{
	class Scene;
}

namespace Haf
{
	class CEntity;
	class CMap;

	class CEntityController
	{
	public:
		CEntityController(CEntity* entity, CMap* env, cocos2d::Scene* scene);
		void CheckInput(float fDelta);
		void Update(float fDelta);

	private:
		void SetUpMouse();
	private:
		CEntity*			 _pcEntity;
		CMap*				 _pcMap;
		CKeyboardController* _keyController;
		cocos2d::Scene*		 _rootScene;
		cocos2d::Sprite*     _pcSprite;
	};
}