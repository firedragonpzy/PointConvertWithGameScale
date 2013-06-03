//
//  GameLayer.h
//  PointConvertWithGameScale
//
//  Created by firedragonpzy on 13-6-3.
//
//

#ifndef __PointConvertWithGameScale__GameLayer__
#define __PointConvertWithGameScale__GameLayer__

#include "cocos2d.h"
#include "Ground.h"
USING_NS_CC;

class GameLayer : public CCLayer {
    
public:
    virtual bool init();
    void onEnter();
    CREATE_FUNC(GameLayer);
    void test(){CCLog("dadsfasdfasdfasdf");}
private:
    CCSize winSize;
    CCPoint originPoint;
    void initParams();
    // init ground
    void addGround();

};


#endif /* defined(__PointConvertWithGameScale__GameLayer__) */
