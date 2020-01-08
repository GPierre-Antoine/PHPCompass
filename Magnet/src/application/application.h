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
    ~application() = default;
};

class optionnable
{
public:
    virtual void parse_options() = 0;
    ~optionnable() = default;
    virtual void add_filter(const std::string & a_string) = 0;

};

class map_php_application : public application, public optionnable
{
private:
    std::vector<std::string> args;
    std::vector<std::string> filters;
    std::vector<std::string>::iterator arg_iterator;
    [[nodiscard]] bool iterator_is_invalid() const;
    void ensure_has_next_arg();
    void configure_from_yaml(const std::filesystem::path & path);
public:
    map_php_application(int argc, char **argv);
    void parse_options() override;
    void run() override;
    ~map_php_application() = default;
    void add_filter(const std::string & a_string) override;
};
