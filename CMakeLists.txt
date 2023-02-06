cmake_minimum_required(VERSION 3.14)
project(FeliciaChenCS3Aportfolio)

set(CMAKE_CXX_FLAGS " -std=c++11")

# Find's all the source files within a project and groups them within the (PROJECTNAME)_SRC file.
file(GLOB FeliciaChenCS3Aportfolio_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

set(SOURCE_FILES main.cpp)

# Add's all the found source files within the executable
add_executable(FeliciaChenCS3Aportfolio ${FeliciaChenCS3Aportfolio_SRC} States.cpp States.h statesEnum.h Circle.cpp Circle.h Fonts.cpp Fonts.h fontsEnum.h Textures.cpp Textures.h Position.cpp Position.h MouseEvents.cpp MouseEvents.h Helper.cpp Helper.h Images.cpp Images.h imageEnum.h AnimatedSprite.cpp AnimatedSprite.h ListItem.cpp ListItem.h List.cpp List.h Menu.cpp Menu.h Player.cpp Player.h PlayerHealth.cpp PlayerHealth.h Mob.cpp Mob.h Screen.cpp Screen.h Bullet.cpp Bullet.h Hittable.h Mobs.cpp Mobs.h ShootaGame.cpp ShootaGame.h GreenCircle.cpp GreenCircle.h BouncingBall.cpp BouncingBall.h PlayingCard.cpp Games.cpp Games.h Arrows.cpp Arrows.h Arrow.cpp Arrow.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories()
target_link_libraries(FeliciaChenCS3Aportfolio sfml-system sfml-window sfml-graphics sfml-audio sfml-network)