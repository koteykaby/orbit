#pragma once

#include <vector>
#include <filesystem>
#include <string>
#include <memory>

#include "logger.hpp"
#include "dependencies/ini.h"

namespace fs = std::filesystem;

struct Save {
    unsigned int id;
    std::string name;
    uint64_t size;
};

struct SaveInformation {
    unsigned int id;
    const char* name;
    uint64_t size;
};

std::vector<Save> get_saves() {
    std::vector<Save> saves;

    mINI::INIFile file("orbit/saves/manifest.ini");
    mINI::INIStructure ini;
    if (!file.read(ini)) {
        LOG_WARN("manifest.ini is empty");
        return saves;
    }

    fs::path saves_path = "orbit/saves";

    for (const auto& it : ini) {
        const std::string& section = it.first;
        if (section.rfind("save_", 0) == 0) {
            Save s{};
            const auto& fields = it.second;

            if (fields.has("id")) {
                s.id = std::stoul(fields.get("id"));
            }
            if (fields.has("name")) {
                s.name = fields.get("name");
            }

            fs::path file_path = saves_path / (std::to_string(s.id) + ".sav");
            if (fs::exists(file_path)) {
                s.size = fs::file_size(file_path);
                saves.push_back(s);
            }
        }
    }

    return saves;
}
