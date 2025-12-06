//
// Created by musae on 30.11.2025.
//

#ifndef SERVER_USERMANAGER_H
#define SERVER_USERMANAGER_H

#include <memory>
#include <unordered_map>

struct User {
    std::string id;        // UUID (генерируется сервером)
    std::string name;      // имя (клиент вводит)
    int connectionId;      // условный id соединения
};

class UserManager {
public:
    bool registerUser(int connectionId, const std::string& name);
    bool removeUserByConnection(int connectionId);

    std::shared_ptr<User> getUserById(const std::string& id);
    std::shared_ptr<User> getUserByConnection(int connectionId);
    std::shared_ptr<User> getUserByName(const std::string& name);

private:
    std::unordered_map<std::string, std::shared_ptr<User>> usersById;
    std::unordered_map<std::string, std::shared_ptr<User>> usersByName;
    std::unordered_map<int, std::shared_ptr<User>> usersByConnection;

    std::string generateUUID();
};



#endif //SERVER_USERMANAGER_H