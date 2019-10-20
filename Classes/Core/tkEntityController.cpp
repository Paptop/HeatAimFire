#include "Core/tkEntityController.h"

#include "Core/tkEntity.h"
#include "Core/Environment/hfMap.h"
#include "Utils/hfTileFactory.h"
#include "Utils/hfDebugUtils.h"

cocos2d::Vec2 mousePos;

Haf::CEntityController::CEntityController(CEntity* entity, CMap* env, cocos2d::Scene* scene)
: _pcEntity(entity)
, _pcMap(env)
, _rootScene(scene)
{
	_keyController = new CKeyboardController();
	//ASSERT(_pcMap->GetScene() != nullptr, "Scene not set");
	_keyController->Init(_rootScene->getEventDispatcher(), _rootScene);

	_pcSprite = CTileFactory::LoadAsset("Crosshair.png");
	_rootScene->addChild(_pcEntity->GetSprite());
	_rootScene->addChild(_pcSprite);
	_pcMap->setPositionNormalized(cocos2d::Vec2(0.5f, 0.5f));

	SetUpMouse();
}

void Haf::CEntityController::CheckInput(float fDelta)
{
	const int Speed = 4;
	auto* camera = _rootScene->getDefaultCamera();
	cocos2d::Vec2 loc = _pcMap->getPosition();

	cocos2d::Sprite* sprite = _pcEntity->GetSprite();
	cocos2d::Vec2 playerPos = sprite->getPosition();
	

	if (_keyController->IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_W))
	{
		//camera->setPosition(loc.x, loc.y + Speed);
		_pcMap->setPosition(loc.x, loc.y - Speed);
		sprite->setPosition(playerPos.x, playerPos.y + Speed);
	}
	else if (_keyController->IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_A))
	{
		//camera->setPosition(loc.x - Speed, loc.y);
		_pcMap->setPosition(loc.x + Speed, loc.y);
		sprite->setPosition(playerPos.x - Speed, playerPos.y);
	}
	else if (_keyController->IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_S))
	{
		//camera->setPosition(loc.x, loc.y - Speed);
		_pcMap->setPosition(loc.x, loc.y + Speed);
		sprite->setPosition(playerPos.x, playerPos.y - Speed);
	}
	else if (_keyController->IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_D))
	{
		//camera->setPosition(loc.x + Speed, loc.y);
		_pcMap->setPosition(loc.x - Speed, loc.y);
		sprite->setPosition(playerPos.x + Speed, playerPos.y);
	}

	cocos2d::Vec2 newMousePos = cocos2d::CCDirector::sharedDirector()->convertToGL(mousePos);
	_pcSprite->setPosition(newMousePos);

	float angle = -CC_RADIANS_TO_DEGREES((newMousePos - sprite->getPosition()).getAngle());
	cocos2d::log("Player pos X %f, pos Y %f, Mouse pos X %f, pos Y %f, angle %f \n", loc.x, loc.y, mousePos.x, mousePos.y, angle);
	_pcEntity->GetSprite()->setRotation(angle);
}

void Haf::CEntityController::Update(float fDelta)
{
}

void Haf::CEntityController::SetUpMouse()
{
	auto listener = cocos2d::EventListenerMouse::create();
	listener->onMouseDown = [=](cocos2d::Event* event) {
		cocos2d::EventMouse* mouseEvent = static_cast<cocos2d::EventMouse*>(event);
	};

	listener->onMouseMove = [=](cocos2d::Event* event) {
		// Cast Event to EventMouse for position details like above
		cocos2d::EventMouse* mouseEvent = static_cast<cocos2d::EventMouse*>(event);
		mousePos = mouseEvent->getLocation();
	};

	listener->onMouseScroll = [](cocos2d::Event* event) {
		cocos2d::log("Mouse wheel scrolled");
	};

	listener->onMouseUp = [](cocos2d::Event* event) {
		cocos2d::log("Mouse button released");
	};

	_rootScene->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
}