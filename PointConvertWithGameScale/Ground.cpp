//
//  Ground.cpp
//  PointConvertWithGameScale
//
//  Created by firedragonpzy on 13-6-3.
//
//

#include "Ground.h"
#include "Pig.h"
#include "GameLayer.h"

Ground::Ground() {
    scheduleUpdate();
}

Ground* Ground::create(const char *pszFilename)
{
    Ground *ground = new Ground();
    if (ground && ground->initWithFile(pszFilename)) {
        ground->autorelease();
        return ground;
    }
    CC_SAFE_DELETE(ground);
    ground = NULL;
    return NULL;
}


void Ground::update(float dt)
{
    if (isContaintRect(getPigRect())) {   
        CCLog("crash----------------------crash");
        
    }else
    {
        
    }
    
}


CCRect Ground::atlasRect()
{
    CCSize cSize = getContentSize();
    CCPoint pos = this->getPosition();
    return CCRectMake(pos.x - cSize.width/2, pos.y - cSize.height/2, cSize.width, cSize.height);
}


bool Ground::isContaintRect(CCRect rect)
{
    return atlasRect().intersectsRect(rect);
}


CCRect Ground::getPigRect()
{
    Pig *pigTemp = Pig::getInstance();
    
    CCPoint pos = pigTemp->getPosition();
    pos = ccp(pos.x*pigTemp->getGlobalScale(),pos.y*pigTemp->getGlobalScale());
    pos = _m_pGameLayer->convertToNodeSpace(pos);
    
    CCSize cSize = pigTemp->getContentSize();
    float width = cSize.width;
    float height = cSize.height;
    
    return CCRectMake(pos.x - width/2, pos.y - height/2, width, height);
}

