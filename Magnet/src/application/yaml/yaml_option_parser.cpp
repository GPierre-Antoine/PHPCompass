//
// Created by pierreantoine on 29/12/2019.
//

#include <yaml-cpp/yaml.h>
#include <iostream>
#include "yaml_option_parser.h"


yaml_option_parser::yaml_option_parser(optionnable & optionnable, std::vector<YAML::Node> config)
        : carrier(optionnable), config(std::move(config))
{

}
void yaml_option_parser::import()
{

    for (auto & option : config)
    {
        if (!option.IsMap())
        {
            throw std::runtime_error("yaml is not a map");
        }
        for (const auto & set : option)
        {
            this->parse_yaml_option(set.first.as<std::string>(), set.second);
        }
    }
}

void yaml_option_parser::parse_yaml_option(const std::string & a_string, const YAML::Node & node)
{
    if (a_string == "filters")
    {
        this->filter_nodes(node);
    }
    else
    {
        parse_error("node isnt unknown key " + a_string);
    }
}

void yaml_option_parser::filter_nodes(const YAML::Node & node)
{
    if (!node.IsSequence())
    {
        parse_error("filters node isnt a sequence");
    }

    for (const auto & string_node : node)
    {
        if (!string_node.IsScalar())
        {
            parse_error("filtered item must be a string");
        }
        carrier.add_filter({string_node.as<std::string>()});
    }
}

void yaml_option_parser::parse_error(const std::string & string)
{
    throw std::runtime_error(std::string("parse error: ") + string);
}
yaml_option_parser yaml_option_parser::from_file(optionnable & optionnable, const std::filesystem::path & path)
{
    if (!std::filesystem::exists(path))
    {
        throw std::runtime_error("yaml file does not exist");
    }
    return yaml_option_parser(optionnable, YAML::LoadAllFromFile(path));
}
