#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "utils.h"

#include <Geode/modify/MenuLayer.hpp>
CCDirector* director = CCDirector::sharedDirector();
class $modify(CustomMenuLayer, MenuLayer) {

    bool init() {
        if(!MenuLayer::init()) {
            return false;
        }
        CCMenu* menu = CCMenu::create();
        this->addChild(menu);
        menu->setLayout(RowLayout::create());
        menu->setID("quick-access-menu");
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        menu->setPosition((size.width / 2) - 100, 90.f);
        menu->setContentSize({350.f, 50.f});
        menu->setAnchorPoint({0.213, 0.500});
        menu->ignoreAnchorPointForPosition(false);
        CCSprite* spr = CCSprite::createWithSpriteFrameName("GJ_myServerBtn_001.png");
        auto levels = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(CustomMenuLayer::onLevels)
                );
        auto awarded = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_starBtn_001.png"),
                this,
                menu_selector(CustomMenuLayer::onAwarded)
        );
        auto hall_of_fame = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_viewListsBtn_001.png"),
                this,
                menu_selector(CustomMenuLayer::onHallOfFame)
        );
        auto favouriteLevels = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("gj_heartOn_001.png"),
                this,
                menu_selector(CustomMenuLayer::onFavouriteLevels)
        );
        auto savedButton = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("gj_folderBtn_001.png"),
                this,
                menu_selector(CustomMenuLayer::onSaved)
        );
        auto profileButton = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png"),
                this,
                menu_selector(CustomMenuLayer::onMyProfile)
        );
        auto sentButton = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("modBadge_01_001.png"),
                this,
                menu_selector(CustomMenuLayer::onSent)
        );
        auto featuredButton = CCMenuItemSpriteExtra::create(
                CircleButtonSprite::createWithSpriteFrameName("diffIcon_05_btn_001.png"),
                this,
                menu_selector(CustomMenuLayer::onFeatured)
        );
        if(Utils::getModSettingsBoolValue("profile-move")) {
            auto profileMenu = this->getChildByID("profile-menu");
            profileMenu->getChildByID("profile-button")->removeFromParent();
            this->getChildByID("player-username")->removeFromParent();
            this->getChildByID("profile-menu")->removeFromParent();
            menu->addChild(profileButton);
        }
        if(Utils::getModSettingsBoolValue("my-levels")) {
            menu->addChild(levels);
        }
        if(Utils::getModSettingsBoolValue("awarded")) {
            menu->addChild(awarded);
        }
        if(Utils::getModSettingsBoolValue("hall_of_fame")){
            menu->addChild(hall_of_fame);
        }
        if(Utils::getModSettingsBoolValue("favourite-levels")){
            menu->addChild(favouriteLevels);
        }
        if(Utils::getModSettingsBoolValue("saved-button")){
            menu->addChild(savedButton);
        }
        if(Utils::getModSettingsBoolValue("sent-button")){
            menu->addChild(sentButton);
        }
        if(Utils::getModSettingsBoolValue("featured-button")){
            menu->addChild(featuredButton);
        }
        awarded->setID("awarded-button"_spr);
        levels->setID("my-levels-button"_spr);
        hall_of_fame->setID("hall_of_fame_button"_spr);
        favouriteLevels->setID("favourite-levels-button"_spr);
        savedButton->setID("search-button"_spr);
        profileButton->setID("profile-button"_spr);
        sentButton->setID("sent-button"_spr);
        featuredButton->setID("featured-button"_spr);
        menu->updateLayout();
        return true;
    }

    void onLevels(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::MyLevels);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }
    void onAwarded(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::Awarded);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }

    void onHallOfFame(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::HallOfFame);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);

        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }

    void onFavouriteLevels(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::FavouriteLevels);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);
        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }

    void onSaved(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::SavedLevels);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);
        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }

    void onSent(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::Sent);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);
        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }

    void onFeatured(CCObject*) {
        auto searchObject = GJSearchObject::create(SearchType::Featured);
        auto browserLayer = LevelBrowserLayer::scene(searchObject);
        auto transitionFade = CCTransitionFade::create(0.5, browserLayer);

        director->pushScene(transitionFade);
    }
};