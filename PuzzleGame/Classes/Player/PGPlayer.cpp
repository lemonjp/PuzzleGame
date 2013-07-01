//
//  PGPlayer.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-30.
//
//

#include "PGPlayer.h"

using namespace cocos2d;

static PGPlayer* player;

PGPlayer* PGPlayer::sharedPlayer(){
    if (!player) {
        player=new PGPlayer();
    }
    return player;
}

PGPlayer::PGPlayer(){
    plist=PlistLoader::initWithPlistFile("PlayerConfig.plist");

    moveAnim=CCArray::create();
    jumpAnim=CCArray::create();
}

PGPlayer::~PGPlayer(){
    CC_SAFE_DELETE(plist);
}

void PGPlayer::createPlayer(CCLayer* layer){
    CCString *file=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerFileName"));
    //用纹理缓存（资源池）加载纹理
    CCTexture2D *playerTex=CCTextureCache::sharedTextureCache()->addImage(file->getCString());
    //创建动画
    CCArray *animFrames=CCArray::create();
    for (int i=0; i<4; i++) {
        CCSpriteFrame *frame=CCSpriteFrame::createWithTexture(playerTex, CCRectMake(128*i, 140, 128, 140));
        animFrames->addObject(frame);
    }
    //用侦序列创建动画
    CCAnimation *animation=CCAnimation::createWithSpriteFrames(animFrames);
    //创建Animate播放动画
    animation->setDelayPerUnit(0.3f);
    CCAnimate *animate=CCAnimate::create(animation);
    moveAnim->addObject(CCRepeatForever::create(animate));
    
    CCSpriteFrame *frame1=CCSpriteFrame::createWithTexture(playerTex, CCRectMake(0, 0, 128, 140));
    CCSprite *sprite=CCSprite::createWithSpriteFrame(frame1);
    sprite->setPosition(ccp(100,100));
    sprite->setScale(0.5f);
    layer->addChild(sprite);
    sprite->runAction(CCRepeatForever::create(animate));
}

void PGPlayer::deletePlayer(CCLayer* layer){
    CCString *file=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerFileName"));
    //删除纹理
    CCTextureCache::sharedTextureCache()->removeTextureForKey(file->getCString());
    if (moveAnim->count()!=0) {
        moveAnim->removeAllObjects();
    }
    if (jumpAnim->count()!=0) {
        jumpAnim->removeAllObjects();
    }
}

void PGPlayer::initWithMoveAnimation(){
    
}
