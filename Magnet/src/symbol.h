//
// Created by pierreantoine on 29/12/2019.
//

#pragma once


#include <string>
#include <vector>
#include <filesystem>
#include <mutex>


class symbol
{
public:
    explicit symbol(std::string name);
    void add_definition(std::filesystem::path path);
    [[nodiscard]] const std::vector<std::filesystem::path> & get_definitions();
private:
    std::string name;
    std::vector<std::filesystem::path> definitions;
    std::mutex mutex;
};
