#include <iostream>
#include "MessageQueue/MessageQueue.h"
#include "MessageQueue/IMessageQueue.h"



int main() {
    MessageQueue queue;

    // Add 2 messages for 10 users
    for (int user = 1; user <= 10; ++user) {
        queue.addMessage({100 + user, user, "Hello user " + std::to_string(user)});
        queue.addMessage({200 + user, user, "World user " + std::to_string(user)});
    }

    // Check and print messages for each user
    for (int user = 1; user <= 10; ++user) {
        std::cout << "\n--- Messages for user " << user << " ---\n";

        while (queue.hasMessages(user)) {
            auto msg = queue.getMessage(user);
            std::cout << "Got message: " << msg->text << "\n";
            queue.ackMessage(user); // remove after processing
        }

        if (!queue.hasMessages(user))
            std::cout << "All messages processed for user " << user << "\n";
    }

    return 0;
}