cmake_minimum_required(VERSION 3.30)
project(toy_chromium)

set(CMAKE_CXX_STANDARD 20)

add_executable(toy_chromium main.cpp
        win/hwnd_message_handler.cpp
        win/hwnd_message_handler.h
        base/files/files.cpp
        base/files/files.h
        base/time/time.cpp
        base/time/time.h)
