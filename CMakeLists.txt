cmake_minimum_required(VERSION 4.0)
project(Server)

set(CMAKE_CXX_STANDARD 23)


add_executable(Server main.cpp
        MessageQueue/IMessageQueue.h
        MessageQueue/MessageQueue.cpp
        MessageQueue/MessageQueue.h
        Protocol/Commands.h
        Protocol/Parser.cpp
        Protocol/Parser.h
        Users/UserManager.cpp
        Users/UserManager.h)
