#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

// All controls are available from Geode's touch-friendly in-game Mod Settings.
class $modify(TobiPlayLayer, PlayLayer) {
    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);

        // Cocos global scheduler speed; reset on exit and keep 1x by default.
        float scale = 1.f;
        if (Mod::get()->getSettingValue<bool>("speedhack")) {
            scale = static_cast<float>(Mod::get()->getSettingValue<double>("speed-multiplier"));
        }
        CCDirector::sharedDirector()->getScheduler()->setTimeScale(scale);
    }

    void onExit() {
        CCDirector::sharedDirector()->getScheduler()->setTimeScale(1.f);
        PlayLayer::onExit();
    }
};

class $modify(TobiPlayerObject, PlayerObject) {
    bool collidedWithObject(float dt, GameObject* object) {
        if (Mod::get()->getSettingValue<bool>("noclip")) return false;
        return PlayerObject::collidedWithObject(dt, object);
    }

    bool collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) {
        if (Mod::get()->getSettingValue<bool>("noclip")) return false;
        return PlayerObject::collidedWithObject(dt, object, rect, skipCheck);
    }
};

class $modify(TobiGameManager, GameManager) {
    bool isIconUnlocked(int id, IconType type) {
        if (Mod::get()->getSettingValue<bool>("unlock-icons")) return true;
        return GameManager::isIconUnlocked(id, type);
    }
};
