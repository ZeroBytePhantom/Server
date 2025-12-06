//
// Created by musae on 30.11.2025.
//

#ifndef SERVER_COMMANDS_H
#define SERVER_COMMANDS_H

enum Commands {
    REGISTER, // регистрация рользователя
    AUTH, // аунтефекация пользователя
    SEND, // отправить сообщение
    GET,
    ACK,
    DELETE_MSG,
    PING,
    UNKNOWN // ошибка
};

#endif //SERVER_COMMANDS_H