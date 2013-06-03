//
//  Ground.h
//  PointConvertWithGameScale
//
//  Created by firedragonpzy on 13-6-3.
//
//

#ifndef __PointConvertWithGameScale__Ground__
#define __PointConvertWithGameScale__Ground__

#include "cocos2d.h"

USING_NS_CC;

class GameLayer;

class Pig;


class Ground : public CCSprite{
    
public:
    Ground();
    
    static Ground* create(const char *pszFilename);    
    void update(float dt);
    CC_SYNTHESIZE(GameLayer*, _m_pGameLayer, GameLayer);

    
private:
    CCRect atlasRect();
    bool isContaintRect(CCRect rect);    
    CCRect getPigRect();
    
};


#endif /* defined(__PointConvertWithGameScale__Ground__) */
