#include <iostream>
#include <filesystem>
#include <regex>
#include <vector>
#include <list>
#include "config.h"
#include "src/symbol.h"
#include "src/iterator/target_file_iterator.h"


using std::cout;
using std::endl;
using std::string;

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    cout << "Version " << PHPCOMPASS_VERSION_MAJOR << "." << PHPCOMPASS_VERSION_MINOR << endl;
    cout << "Current path is: " << fs::current_path() << endl;

    std::vector<fs::path> pathList;
    auto iterator = target_file_iterator(
            fs::current_path(), {".idea", ".git", "_vendors", "PHPMailer", "html2pdf", "tests"}
    );

    while (auto i = iterator.reach_next())
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

    return 0;
}