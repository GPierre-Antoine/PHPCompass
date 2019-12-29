//
// Created by pierreantoine on 29/12/2019.
//

#include <optional>
#include <utility>
#include "target_file_iterator.h"


target_file_iterator::target_file_iterator(const std::filesystem::path & path, std::string extension)
        : iterator(path), look_for(std::move(extension)), ignore_list()
{
}

target_file_iterator::target_file_iterator(
        const std::filesystem::path & path, std::string extension, std::vector<std::string> ignore_list
)
        : iterator(path), look_for(std::move(extension)), ignore_list(std::move(ignore_list))
{

}

std::optional<std::filesystem::path> target_file_iterator::reach_next()
{
    for (; iterator != std::filesystem::recursive_directory_iterator(); ++iterator)
    {
        if (iterator->is_directory())
        {
            if (std::find(ignore_list.begin(), ignore_list.end(), iterator->path().filename()) != ignore_list.end())
            {
                iterator.disable_recursion_pending();
            }
            continue;
        }
        if (iterator->path().extension() != look_for)
        {
            continue;
        }
        return std::optional<std::filesystem::path>(*(iterator++));
    }
    return std::optional<std::filesystem::path>();
}


