//
// Created by pierreantoine on 26/10/2019.
//

#include "file_info_manager.h"


void file_info_manager::process(std::string filename) noexcept
{
    file_info file(std::move(filename));
    if (knows_file(file))
    {
        return;
    }
    file_set.insert(file);
    file_stack.push(file);
}

void file_info_manager::increase_line_count() noexcept(false)
{
    get_top_file().increase_line_count();
}

file_info & file_info_manager::get_top_file() noexcept(false)
{
    if (file_stack.empty())
    {
        throw std::runtime_error("No file in stack");
    }
    return file_stack.top();
}

const file_info & file_info_manager::get_current_file() noexcept(false)
{
    return get_top_file();
}
bool file_info_manager::knows_file(const file_info & file) const noexcept
{
    return this->file_set.count(file) > 0;
}
