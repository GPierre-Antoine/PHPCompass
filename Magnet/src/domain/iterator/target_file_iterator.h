//
// Created by pierreantoine on 29/12/2019.
//

#pragma once


#include <filesystem>
#include <vector>


class target_file_iterator
{
private:
    std::filesystem::recursive_directory_iterator iterator;
    const std::string look_for;
    std::vector<std::string> ignore_list;
public:
    explicit target_file_iterator(const std::filesystem::path & path, std::string extension);
    target_file_iterator(
            const std::filesystem::path & path, std::string extension, std::vector<std::string> ignore_list
    );
    std::optional<std::filesystem::path> reach_next();
};
