#include "AppScene.h"

USING_NS_CC;

// 获得过渡场景(设置进入过渡场景时的效果)
Scene* CAppSceneDefine::getTransition(Scene *pScene, SceneName nextScene, SceneName lastScene)
{
	if (SCENE_LOGO == nextScene)
	{
		return TransitionCrossFade::create(0.3f, pScene);
	}
	return pScene;
}

// 绘制过渡场景(设置过渡场景的显示)
bool CAppSceneDefine::drawTransition(LayerColor *pRoot, SceneName nextScene)
{
	bool bRet = false;
	do
	{
		if (SCENE_LOGO == nextScene)
		{
            pRoot->setOpacity(255);
            pRoot->setColor(Color3B::BLACK);
			LayerColor *pLayer = LayerColor::create(Color4B(255, 0, 0, 255));
            pLayer->setContentSize(CAppScene::getLogicSize());
            CAppScene::setup(pLayer, LOGIC_CENTER);
			CC_BREAK_IF(! pLayer);
			pRoot->addChild(pLayer);
		}
		bRet = true;
	} while (0);
	return bRet;
}

// 更新场景
void CAppSceneDefine::update(SceneName updateScene, bool isShow)
{
	if (SCENE_LOGO == updateScene)
	{
        if (isShow)
        {
            const std::string filename = "logo_show.lua";
            std::string path = FileUtils::getInstance()->fullPathForFilename(filename);
            if (path == filename)
            {
                log("文件不存在");
                return;
            }
            LuaEngine::getInstance()->executeScriptFile(path.c_str());
        }
        else
        {
            LuaEngine::getInstance()->executeScriptFile(FileUtils::getInstance()->fullPathForFilename("logo_hide.lua").c_str());
        }
	}
}
