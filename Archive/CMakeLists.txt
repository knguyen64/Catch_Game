cmake_minimum_required(VERSION 3.19)
project(CatChase)

set(CMAKE_CXX_STANDARD 14)

add_executable(CatChase main.cpp Animation.cpp Animation.h Player.cpp Player.h Platform.cpp Platform.h States.cpp States.h State.h Button.cpp Button.h File.h Files.cpp Files.h FallingObject.cpp FallingObject.h LinkedList.cpp LinkedList.h Score.cpp Score.h Node.h Red_Mushroom.cpp Red_Mushroom.h ObjectName.h Poison_Mushroom.cpp Poison_Mushroom.h Mega_Mushroom.cpp Mega_Mushroom.h CatchGame.cpp CatchGame.h Stack.cpp Stack.h Queue.cpp Queue.h PowerUp.cpp PowerUp.h FallingObjects.cpp FallingObjects.h Platforms.cpp Platforms.h Gauge.cpp Gauge.h ObjectCategory.h EndScreen.cpp EndScreen.h Background.cpp Background.h Green_Mushroom.cpp Green_Mushroom.h Blue_Mushroom.cpp Blue_Mushroom.h PowerUpDisplay.cpp PowerUpDisplay.h TitleScreen.cpp TitleScreen.h)

target_link_libraries(CatChase sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)