//
// Created by pierreantoine on 26/10/2019.
//

#include "file_info.h"


file_info::file_info(std::string filename) noexcept
        : filename(std::move(filename)), current_line(1)
{

}
const std::string & file_info::get_filename() const
{
    return filename;
}
size_t file_info::get_current_line() const
{
    return current_line;
}
void file_info::increase_line_count() noexcept
{
    current_line += 1;
}

std::size_t std::hash<file_info>::operator()(const file_info & k) const
{
    using std::hash;
    return hash<std::string>()(k.get_filename());
}

bool operator==(const file_info & first, const file_info & second) noexcept
{
    return first.get_filename()==second.get_filename();
}