//
// Created by pierreantoine on 29/12/2019.
//

#include <iostream>
#include <filesystem>
#include <regex>
#include <vector>
#include <list>
#include <exception>

#include "application.h"
#include "config.h"
#include "../domain/parse/symbol.h"
#include "../domain/iterator/target_file_iterator.h"


using std::cout;
using std::endl;
using std::string;

namespace fs = std::filesystem;

application::application(int argc, char **argv)
        : args(argc), filters({".idea", ".git"})
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
        cout << i << "\n";
    }

    cout << endl;

}
void application::parse_options()
{

    for (auto arg_iterator = args.begin(); arg_iterator != args.end(); ++arg_iterator)
    {
        if (*arg_iterator == "--filter")
        {
            if (++arg_iterator == args.end())
            {
                throw std::runtime_error("option parse error");
            }
            filters.emplace_back(*arg_iterator);
        }
    }
}
