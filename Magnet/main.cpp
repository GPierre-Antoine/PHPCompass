#include <iostream>
#include "src/application/application.h"


int main(int argc, char *argv[])
{
    try
    {
        map_php_application app(argc, argv);
        app.run();
    }
    catch (std::runtime_error & e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}