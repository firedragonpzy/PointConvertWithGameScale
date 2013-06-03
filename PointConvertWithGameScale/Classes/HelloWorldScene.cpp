#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    // deal with helloworld
    setAnchorPoint(CCPointZero);
    this->ignoreAnchorPointForPosition(false);
    // init gamelayer
    m_pGameLayer = GameLayer::create();
    m_pGameLayer->setPosition(ccp(500,0));
    addChild(m_pGameLayer);
    
    // about scale
    this->setScale(1.3);
    Pig::getInstance()->setGlobalScale(this->getScale());
    // init pig
    addPig();
    

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::addPig()
{
    Pig *pig = Pig::getInstance();
    pig->setPosition(ccp(300,200));
    this->addChild(pig);
    
}


