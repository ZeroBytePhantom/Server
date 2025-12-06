//
// Created by musae on 30.11.2025.
//

#include "UserManager.h"
#include <random>
#include <sstream>
#include <iomanip>

bool UserManager::registerUser(int connectionId, const std::string& name) {
    // Проверка: имя уже занято
    if (usersByName.find(name) != usersByName.end()) {
        return false;
    }

    // Проверка: соединение уже зарегистрировано
    if (usersByConnection.find(connectionId) != usersByConnection.end()) {
        return false;
    }

    // Создаём нового пользователя
    auto user = std::make_shared<User>();
    user->id = generateUUID();
    user->name = name;
    user->connectionId = connectionId;

    // Записываем во все индексы
    usersById[user->id] = user;
    usersByName[user->name] = user;
    usersByConnection[connectionId] = user;

    return true;
}

bool UserManager::removeUserByConnection(int connectionId) {
    auto it = usersByConnection.find(connectionId);
    if (it == usersByConnection.end()) {
        return false; // нет такого пользователя
    }

    auto user = it->second;

    // Удаляем из всех таблиц
    usersById.erase(user->id);
    usersByName.erase(user->name);
    usersByConnection.erase(connectionId);

    return true;
}

std::shared_ptr<User> UserManager::getUserById(const std::string& id) {
    auto it = usersById.find(id);
    if (it != usersById.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<User> UserManager::getUserByConnection(int connectionId) {
    auto it = usersByConnection.find(connectionId);
    if (it != usersByConnection.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<User> UserManager::getUserByName(const std::string& name) {
    auto it = usersByName.find(name);
    if (it != usersByName.end()) {
        return it->second;
    }
    return nullptr;
}

// ============================================================================
// UUID генератор (без зависимостей)
// ============================================================================
std::string UserManager::generateUUID() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    static std::uniform_int_distribution<uint64_t> dist;

    uint64_t part1 = dist(gen);
    uint64_t part2 = dist(gen);

    std::stringstream ss;
    ss << std::hex << std::setfill('0')
       << std::setw(16) << part1
       << std::setw(16) << part2;

    return ss.str();
}
