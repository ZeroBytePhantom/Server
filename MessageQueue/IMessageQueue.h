//
// Created by musae on 24.11.2025.
//

#ifndef SERVER_IMESSAGEQUEUE_H
#define SERVER_IMESSAGEQUEUE_H

#include <string>

struct Message {
    int senderId;
    int recipientId;
    std::string text;

    Message(int s, int r, const std::string& t)
        : senderId(s), recipientId(r), text(t) {}
};


class IMessageQueue {
public:
    virtual ~IMessageQueue();
};







#endif //SERVER_IMESSAGEQUEUE_H