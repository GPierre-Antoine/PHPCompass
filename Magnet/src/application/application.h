//
// Created by pierreantoine on 29/12/2019.
//

#pragma once


#include <vector>
#include <string>
#include <filesystem>


class application
{
private:
    std::vector<std::string> args;
    std::vector<std::string> filters;
    std::vector<std::string>::iterator arg_iterator;
    void parse_options();
    [[nodiscard]] bool iterator_is_invalid() const;
    void ensure_has_next_arg();
public:
    application(int argc, char **argv);
    void run();
    void configure_from_yaml(const std::filesystem::path & path);
    void filter_folder(const std::string & filename);
};
