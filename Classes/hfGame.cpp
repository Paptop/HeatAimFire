/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "hfGame.h"
#include "SimpleAudioEngine.h"

#include "Core/Environment/hfMap.h"
#include "Utils/hfGlobalUtils.h"
#include "Utils/hfDebugUtils.h"

USING_NS_CC;

Scene* Haf::Game::createScene()
{
    return Haf::Game::create();
}

Haf::Game::Game()
: _worldMap(nullptr)
{
}

Haf::Game::~Game()
{
	CGlobalUtils::Deinit();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Haf::Game::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	CGlobalUtils::Init();
	_worldMap = new CMap();
	std::string mapData = FileUtils::getInstance()->getStringFromFile("Test.txt");
	_worldMap->CreateMap(mapData, this);
	scheduleUpdate();

	auto eventListener = EventListenerKeyboard::create();


	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

		int speed = 10;
		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->setPosition(loc.x - speed, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->setPosition(loc.x + speed, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->setPosition(loc.x, loc.y + speed);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			event->getCurrentTarget()->setPosition(loc.x, loc.y - speed);
			break;
		}
	};

	//auto size = Director::getInstance()->getWinSize();
	//float zeye = Director::getInstance()->getZEye();
	//this->getDefaultCamera()->initPerspective(45.0f, (GLfloat)size.width / size.height, 0, zeye + size.height / 2.0f);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this->getDefaultCamera());

    return true;
}


void Haf::Game::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void Haf::Game::update(float fDelta)
{
	cocos2d::Scene::update(fDelta);
}
