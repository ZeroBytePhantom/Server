//
// Created by musae on 30.11.2025.
//

#include "Parser.h"

//SEND 15 Hello world

Parser::Parser(const std::string &str) {
    std::stringstream ss(str);
    std::string keyword;

    ss >> keyword;
    if (keyword == "SEND") {
        type = Commands::SEND;
        ss >> recipientId;
        std::getline(ss, text);
    }
    else if (keyword == "REGISTER") {
        type = Commands::REGISTER;
    } else if (keyword == "PING") {
        type = Commands::PING;
    } else {
        type = Commands::UNKNOWN;
    }
}
