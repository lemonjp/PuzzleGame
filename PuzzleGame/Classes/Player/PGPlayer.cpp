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
    //是否有碰撞到其它刚体
    isContinueCollde=true;
    plist=PlistLoader::initWithPlistFile("PlayerConfig.plist");
    //获取玩家的速度
    CCString *speedStr=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerMoveSpeed"));
    speed=speedStr->floatValue();
}

PGPlayer::~PGPlayer(){
    CC_SAFE_DELETE(plist);
}

void PGPlayer::createPlayer(CCLayer* layer){
    CCString *file=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerFileName"));
    CCString *file2=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerFileName2"));
    //用纹理缓存（资源池）加载纹理
    CCTexture2D *playerTex=CCTextureCache::sharedTextureCache()->addImage(file->getCString());
    CCTexture2D *playerTex2=CCTextureCache::sharedTextureCache()->addImage(file2->getCString());
    
    //初始化动画
    this->initWithMoveAnimation(playerTex);
    this->initWithJumpAnimation(playerTex);
    this->initWithPushAnimation(playerTex);
    
    //添加玩家刚体
    this->addPlayerBodyToScreen(layer, playerTex);
}

void PGPlayer::deletePlayer(CCLayer* layer){
    CCString *file=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerFileName"));
    CCString *file2=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerFileName2"));
    //删除纹理
    CCTextureCache::sharedTextureCache()->removeTextureForKey(file->getCString());
    CCTextureCache::sharedTextureCache()->removeTextureForKey(file2->getCString());
}

void PGPlayer::addPlayerBodyToScreen(CCLayer* layer,CCTexture2D *playerTex){
    //添加玩家精灵
    CCString *imageSizeStr=dynamic_cast<CCString*>(plist->getObjectFromFileKey("ImagePreSize"));
    CCSize imageSize=CCSizeFromString(imageSizeStr->getCString());
    CCString *positionStr=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerPosition"));
    CCPoint position=CCPointFromString(positionStr->getCString());
    
    CCSpriteFrame *frame1=CCSpriteFrame::createWithTexture(playerTex, CCRectMake(0, 0, imageSize.width, imageSize.height));
    sprite=new SpriteBody();
    
    sprite->initWithSpriteFrame(frame1);
    sprite->setPosition(position);
    sprite->autorelease();
    
    CCString *playerTag=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerTag"));
    CCString *playerZOrder=dynamic_cast<CCString*>(plist->getObjectFromFileKey("PlayerZOrder"));

    layer->addChild(sprite,playerZOrder->intValue(),playerTag->intValue());
    //运行player动画
    this->playMoveAnim(sprite);
    //生成刚体
    BasicPhysics::sharedPhysics()->createBody(sprite,
                                              sprite->getPosition() ,
                                              b2_dynamicBody,
                                              0.8f,0.5f,0.0f,
                                              CCSizeMake(35, 50));
    //设置固定旋转
    sprite->setFixedRotation(true);
}

void PGPlayer::playerMoveingInBox2d(PlayerDirection dir){
    float posX=sprite->getPosition().x;
    //CCLOG("%f",sprite->getLinearImpulse().y);

    int PTM_RATIO=BasicPhysics::sharedPhysics()->getRATIO();
    
    sprite->setTransform(b2Vec2((posX+dir*speed)/PTM_RATIO,
                                sprite->getPosition().y/PTM_RATIO), 0);
}

void PGPlayer::playerJumpingInBox2d(){
    if (!(sprite->getLinearImpulse().y>=-2.0f&&this->getIsContinueCollde())){
        return;
    }
    int PTM_RATIO=BasicPhysics::sharedPhysics()->getRATIO();
    sprite->applyLinearImpulse(b2Vec2(0,8.0f),
                               b2Vec2(sprite->getPosition().x/PTM_RATIO,
                                      sprite->getPosition().y/PTM_RATIO));
}

void PGPlayer::playMoveAnim(CCSprite* sprite){
    sprite->stopAllActions();
    sprite->runAction(CCRepeatForever::create(moveAnim));
}

void PGPlayer::playJumpAnim(CCSprite* sprite){
    sprite->stopAllActions();
    sprite->runAction(CCRepeatForever::create(jumpAnim));
}

void PGPlayer::playPushAnim(CCSprite* sprite){
    sprite->stopAllActions();
    sprite->runAction(CCRepeatForever::create(pushAnim));
}

void PGPlayer::initWithMoveAnimation(CCTexture2D *playerTex){
    CCString *imageSizeStr=dynamic_cast<CCString*>(plist->getObjectFromFileKey("ImagePreSize"));
    CCSize imageSize=CCSizeFromString(imageSizeStr->getCString());
    //创建行走动画
    CCArray *animFrames=CCArray::create();
    for (int i=0; i<4; i++) {
        CCSpriteFrame *frame=CCSpriteFrame::createWithTexture(playerTex, CCRectMake(imageSize.width*i, imageSize.height, imageSize.width, imageSize.height));
        animFrames->addObject(frame);
    }
    //用侦序列创建动画
    CCAnimation *animation=CCAnimation::createWithSpriteFrames(animFrames);
    //创建Animate播放动画
    animation->setDelayPerUnit(0.3f);
    moveAnim=CCAnimate::create(animation);
}

void PGPlayer::initWithJumpAnimation(CCTexture2D *playerTex){
    CCString *imageSizeStr=dynamic_cast<CCString*>(plist->getObjectFromFileKey("ImagePreSize"));
    CCSize imageSize=CCSizeFromString(imageSizeStr->getCString());
    //创建跳跃动画
    CCArray *animFrames=CCArray::create();
    for (int i=0; i<4; i++) {
        CCSpriteFrame *frame=CCSpriteFrame::createWithTexture(playerTex,CCRectMake(imageSize.width*i, imageSize.height*2,imageSize.width, imageSize.height));
        animFrames->addObject(frame);
    }
    //用侦序列创建动画
    CCAnimation *animation=CCAnimation::createWithSpriteFrames(animFrames);
    //创建Animate播放动画
    animation->setDelayPerUnit(0.3f);
    jumpAnim=CCAnimate::create(animation);
}

void PGPlayer::initWithPushAnimation(CCTexture2D *playerTex){
    //创建推东西的动画
    CCString *imageSizeStr=dynamic_cast<CCString*>(plist->getObjectFromFileKey("ImagePreSize"));
    CCSize imageSize=CCSizeFromString(imageSizeStr->getCString());
    //创建行走动画
    CCArray *animFrames=CCArray::create();
    for (int i=0; i<4; i++) {
        CCSpriteFrame *frame=CCSpriteFrame::createWithTexture(playerTex, CCRectMake(imageSize.width*i, imageSize.height*3, imageSize.width, imageSize.height));
        animFrames->addObject(frame);
    }
    //用侦序列创建动画
    CCAnimation *animation=CCAnimation::createWithSpriteFrames(animFrames);
    //创建Animate播放动画
    animation->setDelayPerUnit(0.3f);
    pushAnim=CCAnimate::create(animation);
}

void PGPlayer::awakePlayer(){
    sprite->awakeBody();
}