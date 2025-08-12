#pragma once
#ifndef INI_PARSER_H
#define INI_PARSER_H

#include <string>
#include <map>
#include <windows.h>

class INIParser {
public:
    bool Load(const std::string& filename);

    std::string GetString(const std::string& section,
        const std::string& key,
        const std::string& default_value = "") const;

    std::wstring GetWString(const std::string& section,
        const std::string& key,
        const std::wstring& default_value = L"") const;

    int GetInt(const std::string& section,
        const std::string& key,
        int default_value = 0) const;

    double GetDouble(const std::string& section,
        const std::string& key,
        double default_value = 0.0) const;

    bool GetBool(const std::string& section,
        const std::string& key,
        bool default_value = false) const;

private:
    static void trim(std::string& str);
    std::map<std::string, std::map<std::string, std::string>> data;
};

#endif // INI_PARSER_H