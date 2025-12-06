//
// Created by musae on 30.11.2025.
//

#ifndef SERVER_PARSER_H
#define SERVER_PARSER_H

#include "Commands.h"
#include <string>
#include <sstream>


struct Parser {
    Commands type;
    int senderId;
    int recipientId;
    std::string text;
    Parser(const std::string& str);

};



#endif //SERVER_PARSER_H