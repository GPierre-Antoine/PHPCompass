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

application::application(int argc, char **argv)
        : args(argc), filters()
{
    for (auto i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }
}

void application::run()
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
void application::parse_options()
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
bool application::iterator_is_invalid() const
{
    return this->arg_iterator == this->args.end();
}

void application::ensure_has_next_arg()
{
    ++this->arg_iterator;
    if (iterator_is_invalid())
    {
        throw std::runtime_error("option parse error");
    }
}
void application::configure_from_yaml(const std::filesystem::path & path)
{
    yaml_option_parser parser(*this, path);
    parser.import();
}
void application::filter_folder(const std::string & filename)
{
    filters.push_back(filename);
}