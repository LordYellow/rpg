cmake_minimum_required(VERSION 3.12)
project(rpg)

set(CMAKE_CXX_STANDARD 14)

include_directories(header)

add_executable(rpg
        header/character.hpp
        header/config.hpp
        header/debug.hpp
        header/dialog.hpp
        header/enemy.hpp
        header/entity.hpp
        header/game.hpp
        header/karte.hpp
        header/npc.hpp
        header/player.hpp
        header/rpg_definitions.hpp
        header/textureloader.hpp
        header/ui.hpp
        maps/cave
        maps/testmap
        maps/testmap2
        resources/dialog.png
        resources/dialog2.png
        resources/map.png
        resources/player.png
        "resources/Ubuntu Mono derivative Powerline Bold.ttf"
        resources/ui.png
        source/character.cpp
        source/config.cpp
        source/dialog.cpp
        source/enemy.cpp
        source/entity.cpp
        source/game.cpp
        source/karte.cpp
        source/npc.cpp
        source/player.cpp
        source/textureloader.cpp
        configfile
        README.md
        rpg.cpp
        testdialog
        todolist.todo)
