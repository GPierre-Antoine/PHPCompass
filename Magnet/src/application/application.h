//
// Created by pierreantoine on 29/12/2019.
//

#pragma once


#include <vector>
#include <string>
#include <filesystem>


class application
{
public:

    virtual void run() = 0;
    virtual void add_configuration(const std::pair<std::string, std::string> & configuration) = 0;
    ~application() = default;
};

class map_php_application : public application
{
private:
    std::vector<std::string> args;
    std::vector<std::string> filters;
    std::vector<std::string>::iterator arg_iterator;
    void parse_options();
    [[nodiscard]] bool iterator_is_invalid() const;
    void ensure_has_next_arg();
    void configure_from_yaml(const std::filesystem::path & path);
public:
    map_php_application(int argc, char **argv);
    void run() override;
    void add_configuration(const std::pair<std::string, std::string> & configuration) override;
    ~map_php_application() = default;
};
