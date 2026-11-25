#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

namespace {
    bool noclipEnabled() {
        return Mod::get()->getSettingValue<bool>("noclip");
    }
}

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
    // Cover both public collision entry points and their internal dispatch. In
    // 2.2091 some object collision paths reach the internal/rotated handlers
    // directly, so hooking only collidedWithObject is not sufficient.
    bool collidedWithObject(float dt, GameObject* object) {
        if (noclipEnabled()) return false;
        return PlayerObject::collidedWithObject(dt, object);
    }

    bool collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) {
        if (noclipEnabled()) return false;
        return PlayerObject::collidedWithObject(dt, object, rect, skipCheck);
    }

    bool collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) {
        if (noclipEnabled()) return false;
        return PlayerObject::collidedWithObjectInternal(dt, object, rect, skipCheck);
    }

    bool handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope) {
        if (noclipEnabled()) return false;
        return PlayerObject::handleRotatedCollisionInternal(dt, object, rect, skipCheck, skipPre, slope);
    }

    bool handleRotatedObjectCollision(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) {
        if (noclipEnabled()) return false;
        return PlayerObject::handleRotatedObjectCollision(dt, object, rect, skipCheck);
    }

    void collidedWithSlope(float dt, GameObject* object, bool skipPre) {
        if (noclipEnabled()) return;
        PlayerObject::collidedWithSlope(dt, object, skipPre);
    }

    void collidedWithSlopeInternal(float dt, GameObject* object, bool forced) {
        if (noclipEnabled()) return;
        PlayerObject::collidedWithSlopeInternal(dt, object, forced);
    }

    void handleRotatedSlopeCollision(float dt, GameObject* object, bool skipPre) {
        if (noclipEnabled()) return;
        PlayerObject::handleRotatedSlopeCollision(dt, object, skipPre);
    }
};

class $modify(TobiGameManager, GameManager) {
    // The icon check is typed by IconType; color checks use UnlockType.
    bool isIconUnlocked(int id, IconType type) {
        if (Mod::get()->getSettingValue<bool>("unlock-icons")) return true;
        return GameManager::isIconUnlocked(id, type);
    }

    bool isColorUnlocked(int id, UnlockType type) {
        if (Mod::get()->getSettingValue<bool>("unlock-icons")) return true;
        return GameManager::isColorUnlocked(id, type);
    }
};
