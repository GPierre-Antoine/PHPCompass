#include <iostream>
#include <filesystem>
#include <regex>
#include <vector>
#include <list>
#include "config.h"
#include "src/symbol.h"


using std::cout;
using std::endl;
using std::string;

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    cout << "Version " << PHPCOMPASS_VERSION_MAJOR << "." << PHPCOMPASS_VERSION_MINOR << endl;
    cout << "Current path is: " << fs::current_path() << endl;

    std::vector<std::string> ignore_list{".idea", ".git", "_vendors", "PHPMailer", "html2pdf", "tests"};
    std::vector<fs::path> pathList;

    for (auto i = fs::recursive_directory_iterator(fs::current_path()); i != fs::recursive_directory_iterator(); ++i)
    {
        if (i->is_directory())
        {
            if (std::find(ignore_list.begin(), ignore_list.end(), i->path().filename()) != ignore_list.end())
            {
                i.disable_recursion_pending();
            }
            continue;
        }
        if (i->path().extension() != ".php")
        {
            continue;
        }
        pathList.push_back(*i);
    }

    std::vector<symbol> class_list;
    std::string currentNamespace;

    for (const auto & i : pathList)
    {
        cout << i << "\n";
    }

    cout << endl;

    return 0;
}