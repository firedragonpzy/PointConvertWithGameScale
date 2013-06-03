//
//  GameLayer.cpp
//  PointConvertWithGameScale
//
//  Created by firedragonpzy on 13-6-3.
//
//

#include "GameLayer.h"

bool GameLayer::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        initParams();
        bRet = true;
    } while (0);
    
    return bRet;
}


void GameLayer::onEnter()
{
    CCLayer::onEnter();
}


void GameLayer::initParams()
{
    winSize = CCDirector::sharedDirector()->getWinSize();
    originPoint = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // init ground
    addGround();
}


void GameLayer::addGround()
{
    Ground *ground = Ground::create("Icon-72.png");
    ground->setPosition(ccp(200,200));
    ground->setGameLayer(this);
    this->addChild(ground);
}