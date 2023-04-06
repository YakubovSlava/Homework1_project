#include "json_parser/json_parser.hpp"
#include <string>
#include <iostream>

void array_parser(std::string json){
    std::string::iterator end_pos = std::remove(json.begin(), json.end(), ' ');
    json.erase(end_pos, json.end());
    end_pos = std::remove(json.begin(), json.end(), '\n');
    json.erase(end_pos, json.end());
    end_pos = std::remove(json.begin(), json.end(), '\t');
    json.erase(end_pos, json.end());
    int quotes = 0;
    int quotes_dict = 0;
    char temp = '_';
    int count_open = 0;
    int count_close = 0;
    int j = 0;
    for(int i=0; i<json.size(); ++i){
        if(json[i]=='"'){
            quotes += 1;
        }
        if(json[i]=='{'){
            quotes_dict+=1;
        }
        if(json[i]=='}'){
            quotes_dict-=1;
        }
        if(quotes%2==0 and quotes_dict==0) {
            if (json[i + 1] == '"') {
                temp = json[i + 2];
                j = i + 1;
                while (temp != '"' and j <= json.size()) {
                    j += 1;
                    temp = json[j];
                }
                std::cout << json.substr(i + 1, j + 1 - i - 1) << " - " << "STRING" << std::endl;
            }

            if ((std::isdigit((json[i + 1])) or json[i + 1]=='-') and (json[i]=='[' or json[i]==',')) {
                temp = json[i + 2];
                j = i + 1;
                while (temp != ',' and temp != '}' and temp != ']') {
                    j += 1;
                    temp = json[j];
                }
                std::cout << json.substr(i + 1, j  - i - 1) << " - " << "INT" << std::endl;
            }

            if (json[i + 1] == '{') {
                count_open = 1;
                count_close = 0;
                temp = json[i + 2];
                j = i + 1;
                while (temp != '}' or count_open != count_close) {
                    j += 1;
                    temp = json[j];
                    if (temp == '{') {
                        count_open += 1;
                    }
                    if (temp == '}') {
                        count_close += 1;
                    }
                }
                std::cout << json.substr(i + 1, j + 1 - i - 1) << " - " << "DICT" << std::endl;
                json_parser(json.substr(i + 1, j + 1 - i - 1));
            }
        }
    }
}


void json_parser(std::string json){
    std::string::iterator end_pos = std::remove(json.begin(), json.end(), ' ');
    json.erase(end_pos, json.end());
    end_pos = std::remove(json.begin(), json.end(), '\n');
    json.erase(end_pos, json.end());
    end_pos = std::remove(json.begin(), json.end(), '\t');
    json.erase(end_pos, json.end());
    int quotes = 0;
    char temp = 0;
    int j = 0;
    int count_open = 0;
    int count_close = 0;
    for (int i=0; i<json.size()-1; ++i){

        if(json[i]=='"'){
            quotes += 1;
        }
        if(json[i] == ':' and quotes%2==0) {

            if (json[i + 1] == '"') {
                temp = json[i + 2];
                j = i + 1;
                while (temp != '"') {
                    j += 1;
                    temp = json[j];
                }
                std::cout << json.substr(i + 1, j + 1 - i - 1) << " - " << "STRING" << std::endl;
            }

            if (std::isdigit(json[i + 1]) or json[i + 1]=='-') {
                temp = json[i + 2];
                j = i + 1;
                while (temp != ',' and temp != '}' and temp != ']') {
                    j += 1;
                    temp = json[j];
                }
                std::cout << json.substr(i + 1, j  - i - 1) << " - " << "INT" << std::endl;
            }


            if (json[i + 1] == '{') {
                count_open = 1;
                count_close = 0;
                temp = json[i + 2];
                j = i + 1;
                while (temp != '}' or count_open != count_close) {
                    j += 1;
                    temp = json[j];
                    if (temp == '{') {
                        count_open += 1;
                    }
                    if (temp == '}') {
                        count_close += 1;
                    }
                }
                std::cout << json.substr(i + 1, j + 1 - i - 1) << " - " << "DICT" << std::endl;
            }

            if (json[i + 1] == '[') {
                count_open = 1;
                count_close = 0;
                temp = json[i + 2];
                j = i + 1;
                while (temp != ']' or count_open != count_close) {
                    j += 1;
                    temp = json[j];
                    if (temp == '[') {
                        count_open += 1;
                    }
                    if (temp == ']') {
                        count_close += 1;
                    }
                }
                std::cout << json.substr(i + 1, j + 1 - i - 1) << " - " << "ARRAY" << std::endl;
                array_parser(json.substr(i + 1, j + 1 - i - 1));
            }

        }

    }
}
