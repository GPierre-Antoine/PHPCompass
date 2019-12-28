#include <iostream>
#include "config.h"


using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{

    string title = "Super jeu";
    cout << "Version " << PHPCOMPASS_VERSION_MAJOR << "." << PHPCOMPASS_VERSION_MINOR << endl;

    return 0;
}