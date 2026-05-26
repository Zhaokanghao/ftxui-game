cmake_minimum_required(VERSION 3.15)
project(ai-ftxui-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 配置 FTXUI 路径（这里写你自己的路径即可）
set(CMAKE_PREFIX_PATH "D:/libraries/ftxui_install")

find_package(ftxui REQUIRED)

add_executable(ai-ftxui-game main.cpp)

target_link_libraries(ai-ftxui-game
    PRIVATE
        ftxui::dom
        ftxui::screen
        ftxui::component
)
