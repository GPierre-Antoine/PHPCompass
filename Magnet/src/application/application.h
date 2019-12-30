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
    virtual void add_configuration(const std::string & key, const std::vector<std::string> & values) = 0;
    [[nodiscard]] virtual std::size_t expect_configuration(const std::string & a_string) const = 0;
    virtual void parse_options() = 0;
    ~optionnable() = default;
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
    void assert_size(const std::string & key, const std::vector<std::string> & values) const;
public:
    map_php_application(int argc, char **argv);
    void parse_options() override;
    void run() override;
    void add_configuration(const std::string & key, const std::vector<std::string> & values) override;
    [[nodiscard]] std::size_t expect_configuration(const std::string & a_string) const override;
    ~map_php_application() = default;
};
