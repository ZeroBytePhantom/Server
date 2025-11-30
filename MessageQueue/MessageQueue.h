//
// Created by musae on 24.11.2025.
//

#ifndef SERVER_MESSAGEQUEUE_H
#define SERVER_MESSAGEQUEUE_H

#include "IMessageQueue.h"
#include <unordered_map>
#include <deque>
#include <memory>

class MessageQueue : public IMessageQueue {
private:
    // Очередь сообщений для каждого пользователя
    std::unordered_map<int, std::deque<std::shared_ptr<Message>>> inbox;

public:
    MessageQueue() = default;
    ~MessageQueue() override = default;

    void addMessage(const Message& msg) override;
    void ackMessage(const int recipient) override;
    std::shared_ptr<Message> getMessage(const int recipient) override;
    bool hasMessages(int recipient) const override;
};


#endif //SERVER_MESSAGEQUEUE_H