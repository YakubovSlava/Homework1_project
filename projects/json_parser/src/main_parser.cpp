#include "json_parser/json_parser.hpp"
#include <iostream>
#include <string>


int main(){
    std::string s;
    std::getline(std::cin >> std::ws, s);
    json_parser(s);
    return 0;
}
