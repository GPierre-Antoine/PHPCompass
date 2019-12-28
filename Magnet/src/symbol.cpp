//
// Created by pierreantoine on 29/12/2019.
//

#include <utility>
#include "symbol.h"


using std::mutex;
using mutex_lock = std::lock_guard<std::mutex>;

symbol::symbol(std::string name)
        : name(std::move(name))
{

}
void symbol::add_definition(std::filesystem::path path)
{
    mutex_lock lock(mutex);
    definitions.push_back(std::move(path));
}
const std::vector<std::filesystem::path> & symbol::get_definitions()
{
    mutex_lock lock(mutex);
    return definitions;
}
