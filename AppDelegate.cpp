#include "AppDelegate.h"
#include "AppScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    Director::getInstance()->setOpenGLView(EGLView::getInstance());
    Director::getInstance()->setAnimationInterval(1.0 / 60);
    Director::getInstance()->setDisplayStats(true);
    CAppScene::show(SCENE_LOGO);
    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}
