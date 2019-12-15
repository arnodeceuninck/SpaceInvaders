cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpaceInvaders src/main.cpp src/Game.cpp src/Game.h src/EntityModel/EntityModel.cpp src/EntityModel/EntityModel.h src/EntityController/EntityController.cpp src/EntityController/EntityController.h src/EntityRepresentation/EntityRepresentation.cpp src/EntityRepresentation/EntityRepresentation.h src/EntityController/GameController.cpp src/EntityController/GameController.h src/EntityRepresentation/GameRepresentation.cpp src/EntityRepresentation/GameRepresentation.h src/EntityModel/WorldModel.cpp src/EntityModel/WorldModel.h src/EntityModel/GameModel.cpp src/EntityModel/GameModel.h src/Observer/Observable.cpp src/Observer/Observable.h src/Observer/Observer.cpp src/Observer/Observer.h src/EntityModel/Ship.cpp src/EntityModel/Ship.h src/EntityModel/PlayerShip.cpp src/EntityModel/PlayerShip.h src/EntityModel/EnemyShip.cpp src/EntityModel/EnemyShip.h src/EntityRepresentation/BGTile.cpp src/EntityRepresentation/BGTile.h src/Clock.cpp src/Clock.h)


TARGET_LINK_LIBRARIES(SpaceInvaders ${SFML_LIBRARIES})

INSTALL(TARGETS SpaceInvaders DESTINATION ${PROJECT_SOURCE_DIR}/bin)