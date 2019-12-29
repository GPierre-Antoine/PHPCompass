//
// Created by pierreantoine on 29/12/2019.
//

#ifndef PHPCOMPASS_YAML_OPTION_PARSER_H
#define PHPCOMPASS_YAML_OPTION_PARSER_H


#include "../application.h"


class yaml_option_parser
{
private:
    application & app;
    std::filesystem::path path;
    void parse_yaml_option(const std::string & a_string, const YAML::Node & node);
public:
    explicit yaml_option_parser(application & application, std::filesystem::path path);
    void import();
    void filter_nodes(const YAML::Node & node);
    static void parse_error(const std::string & string);
};

#endif //PHPCOMPASS_YAML_OPTION_PARSER_H
