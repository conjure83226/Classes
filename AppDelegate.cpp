#include "SimpleAudioEngine.h"
#include "CCLuaEngine.h"
#include "AppDelegate.h"
#include "AppLua.h"

using namespace CocosDenshion;
USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    Director::getInstance()->setOpenGLView(EGLView::getInstance());
    Director::getInstance()->setAnimationInterval(1.0 / 60);
    Director::getInstance()->setDisplayStats(true);
    auto pLuaEngine = LuaEngine::getInstance();
    AppLua::registerExtend(pLuaEngine->getLuaStack()->getLuaState());
    ScriptEngineManager::getInstance()->setScriptEngine(pLuaEngine);
    return pLuaEngine->executeScriptFile("run.lua") == 0;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}
