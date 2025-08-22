//
// Created by admin on 22.08.2025.
//

#include "utils.h"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool Utils::getModSettingsBoolValue(std::string path) {
    return Mod::get()->getSettingValue<bool>(path);
}