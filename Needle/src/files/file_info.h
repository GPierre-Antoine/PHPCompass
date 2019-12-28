//
// Created by pierreantoine on 26/10/2019.
//

#ifndef PHPCOMPASS_FILE_INFO_H
#define PHPCOMPASS_FILE_INFO_H


#include <string>
#include <stdexcept>


class file_info
{
private:
    const std::string filename;
    std::size_t current_line;
public:
    explicit file_info(std::string) noexcept;
    [[nodiscard]] const std::string & get_filename() const;
    [[nodiscard]] std::size_t get_current_line() const;
    void increase_line_count() noexcept;
};

bool operator==(const file_info & first, const file_info & second) noexcept;

namespace std
{
    template <>
    struct hash<file_info>
    {
        std::size_t operator()(const file_info & k) const;
    };
}

#endif //PHPCOMPASS_FILE_INFO_H
