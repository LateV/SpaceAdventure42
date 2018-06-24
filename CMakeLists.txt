cmake_minimum_required(VERSION 3.9)
project(d04)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    add_executable(space_fantasy main.cpp main.cpp Window.cpp Window.h space_fantasy.h Game.cpp Game.h player.cpp player.hpp)
    target_link_libraries (space_fantasy ${CURSES_LIBRARIES})
endif()

