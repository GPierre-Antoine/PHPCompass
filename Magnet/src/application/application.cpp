//
// Created by pierreantoine on 29/12/2019.
//

#include <iostream>
#include <filesystem>
#include <vector>
#include <list>
#include <algorithm>

#include "yaml-cpp/yaml.h"

#include "application.h"
#include "config.h"
#include "../domain/parse/symbol.h"
#include "../domain/iterator/target_file_iterator.h"
#include "yaml/yaml_option_parser.h"


namespace fs = std::filesystem;

map_php_application::map_php_application(int argc, char **argv)
        : args(argc), filters()
{
    for (auto i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }
}

void map_php_application::run()
{
    parse_options();
    std::vector<fs::path> pathList;
    auto iterator = target_file_iterator(
            fs::current_path(), ".php", filters
    );

    while (auto i = iterator.next())
    {
        pathList.push_back(*i);
    }

    std::vector<symbol> class_list;
    std::string currentNamespace;
    for (const auto & i : pathList)
    {
        std::cout << i << "\n";
    }

    std::cout << std::endl;

}
void map_php_application::parse_options()
{
    for (arg_iterator = args.begin(); arg_iterator != args.end(); ++arg_iterator)
    {
        if (*arg_iterator == "--filter")
        {
            this->ensure_has_next_arg();
            filters.emplace_back(*arg_iterator);
            continue;
        }
        if (*arg_iterator == "--yaml")
        {
            this->ensure_has_next_arg();
            this->configure_from_yaml(std::filesystem::path(*arg_iterator));
            continue;
        }
    }
}
bool map_php_application::iterator_is_invalid() const
{
    return this->arg_iterator == this->args.end();
}

void map_php_application::ensure_has_next_arg()
{
    ++this->arg_iterator;
    if (iterator_is_invalid())
    {
        throw std::runtime_error("option parse error");
    }
}
void map_php_application::configure_from_yaml(const std::filesystem::path & path)
{
    auto parser = yaml_option_parser::from_file(*this, path);
    parser.import();
}

void map_php_application::add_configuration(const std::pair<std::string, std::string> & configuration)
{
    if (configuration.first == "filters")
    {
        filters.push_back(configuration.second);
    }
    else
    {
        throw std::runtime_error("unknown configuration " + configuration.first);
    }
}