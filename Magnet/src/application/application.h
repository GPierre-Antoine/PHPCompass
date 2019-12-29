//
// Created by pierreantoine on 29/12/2019.
//

#pragma once


#include <vector>
#include <string>


class application
{
private:
    std::vector<std::string> args;
    std::vector<std::string> filters;
    void parse_options();
public:
    application(int argc, char **argv);
    void run();
};
