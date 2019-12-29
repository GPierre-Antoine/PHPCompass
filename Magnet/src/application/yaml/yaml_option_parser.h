//
// Created by pierreantoine on 29/12/2019.
//

#ifndef PHPCOMPASS_YAML_OPTION_PARSER_H
#define PHPCOMPASS_YAML_OPTION_PARSER_H


#include "../application.h"


class yaml_option_parser
{
private:
    optionnable & carrier;
    std::vector<YAML::Node> config;
    void parse_yaml_option(const std::string & a_string, const YAML::Node & node);
    void filter_nodes(const YAML::Node & node);
    static void parse_error(const std::string & string);
public:
    explicit yaml_option_parser(optionnable & optionnable, std::vector<YAML::Node> config);
    static yaml_option_parser from_file(optionnable & optionnable, const std::filesystem::path & path);
    void import();
};

#endif //PHPCOMPASS_YAML_OPTION_PARSER_H
