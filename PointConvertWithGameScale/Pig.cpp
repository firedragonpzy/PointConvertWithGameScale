//
//  Pig.cpp
//  PointConvertWithGameScale
//
//  Created by firedragonpzy on 13-6-3.
//
//

#include "Pig.h"

//
//  Pig.cpp
//  Runner
//
//  Created by firedragonpzy on 13-5-21.
//
//

#include "Pig.h"

Pig* Pig::m_pInstance = NULL;

Pig::Pig()
{
}


Pig* Pig::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new Pig();
        m_pInstance->initWithFile("blocks.png");
        //        m_pInstance->initParams();
    }
    return m_pInstance;
}


void Pig::initParams()
{
}



void Pig::onEnter()
{
    CCSprite::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -1, true);
}

bool Pig::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    if (this->isContainTouchLocation(pTouch) ) {
        return true;
    }
    return false;
    
}

void Pig::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{    
    CCPoint pos = this->getPosition();    
    CCPoint sub = pTouch->getDelta();    
    this->setPosition(ccpAdd(pos, ccp(sub.x/_m_pScale,sub.y/_m_pScale)));
}

void Pig::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCLog("firedragonpzy:ccTouchEnded");    
}

CCRect Pig::atlasRect()
{    
    CCSize cSize = this->boundingBox().size;
    return CCRectMake(-cSize.width/2, -cSize.height/2, cSize.width, cSize.height);    
}

bool Pig::isContainTouchLocation(cocos2d::CCTouch *pTouch)
{    
    return this->atlasRect().containsPoint(convertTouchToNodeSpaceAR(pTouch));    
}

