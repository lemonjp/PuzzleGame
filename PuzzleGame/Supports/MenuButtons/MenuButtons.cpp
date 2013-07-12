//
//  MeneButtons.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-7.
//
//

#include "MenuButtons.h"

using namespace cocos2d;

MenuButtonPlugin::MenuButtonPlugin(){
    //初始化plist文件
    plist=PlistLoader::initWithPlistFile("MenuButtonConfig.plist");
    //初始化纹理
    CCString* buttonImage=dynamic_cast<CCString*>(plist->getObjectFromFileKey("ButtonImage"));
    texture=CCTextureCache::sharedTextureCache()->addImage(buttonImage->getCString());
}

MenuButtonPlugin::~MenuButtonPlugin(){
    CC_SAFE_DELETE(plist);
}

void MenuButtonPlugin::addPluginButtonToScreen(ButtonType type,
                                               cocos2d::CCPoint position,
                                               cocos2d::CCLayer *layer,
                                               int tag){
    this->initWithTexture(texture,CCRectMake(0, 0, 70, 72));
    this->setPosition(ccp(100,100));
    layer->addChild(this);
}

void MenuButtonPlugin::onEnter(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0 ,true);
    CCSprite::onEnter();
}

void MenuButtonPlugin::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}

bool MenuButtonPlugin::ccTouchBegan(CCTouch *touch, CCEvent *event){
    
    return true;
}

void MenuButtonPlugin::ccTouchEnded(CCTouch *touch, CCEvent *event){
    
}
