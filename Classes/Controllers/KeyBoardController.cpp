#include "Controllers/hfKeyboardController.h"


void Haf::CKeyboardController::Init(cocos2d::EventDispatcher* dispatcher, cocos2d::Node* target)
{
	_eventListener = cocos2d::EventListenerKeyboard::create();

	_eventListener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
		if (_keys.find(keyCode) == _keys.end()) {
			_keys[keyCode] = std::chrono::high_resolution_clock::now();
		}
	};
	_eventListener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
		_keys.erase(keyCode);
	};

	dispatcher->addEventListenerWithSceneGraphPriority(_eventListener, target);
}

double Haf::CKeyboardController::KeyPressedDuration(cocos2d::EventKeyboard::KeyCode code)
{
	if (!IsKeyPressed(code))
	{
		return 0.0;
	}

	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _keys[code]).count();
}

bool Haf::CKeyboardController::IsKeyPressed(cocos2d::EventKeyboard::KeyCode code)
{
	if (_keys.find(code) != _keys.end())
	{
		return true;
	}

	return false;
}