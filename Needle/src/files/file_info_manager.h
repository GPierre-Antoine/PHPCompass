//
// Created by pierreantoine on 26/10/2019.
//

#ifndef PHPCOMPASS_FILE_INFO_MANAGER_H
#define PHPCOMPASS_FILE_INFO_MANAGER_H


#include <stack>
#include <unordered_set>
#include "file_info.h"


class file_info_manager
{
private:
    std::stack<file_info> file_stack;
    std::unordered_set<file_info> file_set;
    file_info& get_top_file() noexcept(false);
public:
    void process(std::string filename) noexcept;
    void increase_line_count() noexcept(false);
    const file_info& get_current_file() noexcept(false);
    bool knows_file(const file_info & file) const noexcept;
};

#endif //PHPCOMPASS_FILE_INFO_MANAGER_H
