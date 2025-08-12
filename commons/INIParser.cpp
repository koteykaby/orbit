#include "INIParser.hpp"
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <stdexcept>
#include <windows.h>

bool INIParser::Load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        return false;

    std::string line;
    std::string current_section;

    while (std::getline(file, line)) {
        trim(line);

        if (line.empty() || line[0] == ';' || line[0] == '#')
            continue;

        if (line.front() == '[' && line.back() == ']') {
            current_section = line.substr(1, line.size() - 2);
            trim(current_section);
            continue;
        }

        size_t delimiter_pos = line.find('=');
        if (delimiter_pos != std::string::npos) {
            std::string key = line.substr(0, delimiter_pos);
            std::string value = line.substr(delimiter_pos + 1);

            trim(key);
            trim(value);

            data[current_section][key] = value;
        }
    }
    return true;
}

std::string INIParser::GetString(const std::string& section,
    const std::string& key,
    const std::string& default_value) const {
    auto sec_it = data.find(section);
    if (sec_it == data.end()) return default_value;

    auto key_it = sec_it->second.find(key);
    if (key_it == sec_it->second.end()) return default_value;

    return key_it->second;
}

std::wstring INIParser::GetWString(const std::string& section,
    const std::string& key,
    const std::wstring& default_value) const {
    std::string utf8_str = GetString(section, key, "");
    if (utf8_str.empty()) {
        return default_value;
    }

    int size_needed = MultiByteToWideChar(
        CP_UTF8,
        0,
        utf8_str.c_str(),
        (int)utf8_str.size(),
        NULL,
        0
    );

    if (size_needed <= 0) {
        throw std::runtime_error("UTF-8 to UTF-16 conversion failed");
    }

    std::vector<wchar_t> buffer(size_needed);
    int result = MultiByteToWideChar(
        CP_UTF8,
        0,
        utf8_str.c_str(),
        (int)utf8_str.size(),
        buffer.data(),
        size_needed
    );

    if (result <= 0) {
        throw std::runtime_error("UTF-8 to UTF-16 conversion failed");
    }

    return std::wstring(buffer.data(), buffer.size());
}

int INIParser::GetInt(const std::string& section,
    const std::string& key,
    int default_value) const {
    std::string value = GetString(section, key, "");
    if (value.empty()) return default_value;

    try {
        return std::stoi(value);
    }
    catch (...) {
        return default_value;
    }
}

double INIParser::GetDouble(const std::string& section,
    const std::string& key,
    double default_value) const {
    std::string value = GetString(section, key, "");
    if (value.empty()) return default_value;

    try {
        return std::stod(value);
    }
    catch (...) {
        return default_value;
    }
}

bool INIParser::GetBool(const std::string& section,
    const std::string& key,
    bool default_value) const {
    std::string value = GetString(section, key, "");
    if (value.empty()) return default_value;

    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char c) { return std::tolower(c); });

    if (value == "true" || value == "yes" || value == "on" || value == "1")
        return true;
    if (value == "false" || value == "no" || value == "off" || value == "0")
        return false;

    return default_value;
}

void INIParser::trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
        }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
        }).base(), str.end());
}