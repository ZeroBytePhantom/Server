//
// Created by musae on 24.11.2025.
//

#ifndef SERVER_IMESSAGEQUEUE_H
#define SERVER_IMESSAGEQUEUE_H

#include <string>
#include <memory>

struct Message {
    int senderId;
    int recipientId;
    std::string text;

    Message(int r, const std::string& t)
        : senderId(0), recipientId(r), text(t) {} // senderId = 0 по умолчанию

    Message(int s, int r, const std::string& t)
        : senderId(s), recipientId(r), text(t) {}
};



class IMessageQueue {
public:
    virtual void addMessage(const Message& msg) = 0;
    virtual void ackMessage(const int recipient) = 0;
    virtual std::shared_ptr<Message> getMessage(int recipient) = 0;
    virtual bool hasMessages(int recipient) const = 0;
    virtual ~IMessageQueue() {}
};


#endif //SERVER_IMESSAGEQUEUE_H