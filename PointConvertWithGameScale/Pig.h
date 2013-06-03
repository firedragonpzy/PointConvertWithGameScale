//
//  Pig.h
//  PointConvertWithGameScale
//
//  Created by firedragonpzy on 13-6-3.
//
//

#ifndef __PointConvertWithGameScale__Pig__
#define __PointConvertWithGameScale__Pig__

#include "cocos2d.h"
#include "Ground.h"

USING_NS_CC;


class Pig : public CCSprite, public CCTargetedTouchDelegate{
    
public:
    
    static Pig* getInstance();
    
    
    void onEnter();
    
    CCRect atlasRect();
    
    bool isContainTouchLocation(CCTouch *pTouch);
    
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    
    void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    CC_SYNTHESIZE(float, _m_pScale, GlobalScale);
    
private:
    static Pig *m_pInstance;
    Pig();
    void initParams();
    
    
    
    
};


#endif /* defined(__PointConvertWithGameScale__Pig__) */
