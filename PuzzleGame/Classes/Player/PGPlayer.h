//
//  PGPlayer.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-30.
//
//

#ifndef __PuzzleGame__PGPlayer__
#define __PuzzleGame__PGPlayer__

#include "cocos2d.h"
#include "PlistLoader.h"
#include "BasicPhysics.h"
#include "PhysicsSprite.h"

using namespace cocos2d;

class PGPlayer : CCObject{
public:
    PGPlayer();
    virtual ~PGPlayer();
    
    /*产生玩家单例*/
    static PGPlayer* sharedPlayer();
    /*产生玩家对象*/
    void createPlayer(CCLayer* layer);
    /*删除游戏玩家*/
    void deletePlayer(CCLayer* layer);
    /*播放玩家动画*/
    void playMoveAnim(CCSprite* sprite);
    void playJumpAnim(CCSprite* sprite);
    void playPushAnim(CCSprite* sprite);
private:
    PlistLoader *plist;
    
    CCAnimate *moveAnim;
    CCAnimate *jumpAnim;
    CCAnimate *pushAnim;
    
    void initWithMoveAnimation(CCTexture2D *playerTex);
    void initWithJumpAnimation(CCTexture2D *playerTex);
    void initWithPushAnimation(CCTexture2D *playerTex);
    
    void addPlayerBodyToScreen(CCLayer* layer,CCTexture2D *playerTex);
};

#endif /* defined(__PuzzleGame__PGPlayer__) */
