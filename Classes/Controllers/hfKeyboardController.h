#pragma once

#include "cocos2d.h"

namespace Haf
{
	class CKeyboardController
	{
	public:
		void Init(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* target);
		double KeyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
		bool IsKeyPressed(cocos2d::EventKeyboard::KeyCode code);

	private:
		std::map<cocos2d::EventKeyboard::KeyCode,
			std::chrono::high_resolution_clock::time_point> _keys;
		cocos2d::EventListenerKeyboard* _eventListener;
	};
}