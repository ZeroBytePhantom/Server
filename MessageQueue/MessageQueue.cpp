//
// Created by musae on 24.11.2025.
//

#include "MessageQueue.h"


MessageQueue::~MessageQueue() {

}


void MessageQueue::addMessage(const Message& msg) {
    inbox[msg.recipientId].push_back(std::make_shared<Message>(msg));
}


bool MessageQueue::hasMessages(int recipient) const {
    auto it = inbox.find(recipient);
    return it != inbox.end() && !it->second.empty();
}

std::shared_ptr<Message> MessageQueue::getMessage(const int recipient) {
    auto it = inbox.find(recipient);
    if (it != inbox.end() && !it->second.empty()) {
        return it->second.front();
    }
    return nullptr;

}

void MessageQueue::ackMessage(const int recipient) {
    auto it = inbox.find(recipient);
    if (it != inbox.end() && !it->second.empty()) {
        it->second.pop_front(); // удаляем сообщение после успешной обработки
    }
}

