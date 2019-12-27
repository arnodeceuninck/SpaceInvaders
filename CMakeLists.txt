cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)


set(CMAKE_CXX_STANDARD 17)

add_executable(SpaceInvaders src/main.cpp src/Game.cpp src/Game.h src/EntityModel/EntityModel.cpp src/EntityModel/EntityModel.h src/EntityController/EntityController.cpp src/EntityController/EntityController.h src/EntityRepresentation/EntityRepresentation.cpp src/EntityRepresentation/EntityRepresentation.h src/EntityController/GameController.cpp src/EntityController/GameController.h src/EntityRepresentation/GameRepresentation.cpp src/EntityRepresentation/GameRepresentation.h src/EntityModel/WorldModel.cpp src/EntityModel/WorldModel.h src/EntityModel/GameModel.cpp src/EntityModel/GameModel.h src/Observer/Observable.cpp src/Observer/Observable.h src/Observer/Observer.cpp src/Observer/Observer.h src/EntityModel/Ship.cpp src/EntityModel/Ship.h src/EntityModel/PlayerShip.cpp src/EntityModel/PlayerShip.h src/EntityModel/EnemyShip.cpp src/EntityModel/EnemyShip.h src/EntityRepresentation/BackgroundTiles.cpp src/EntityRepresentation/BackgroundTiles.h src/Stopwatch.cpp src/Stopwatch.h src/Events/ControllerEvent.cpp src/Events/ControllerEvent.h src/Events/ModelChangedEvent.cpp src/Events/ModelChangedEvent.h src/GameWindow.cpp src/GameWindow.h src/EntityController/WindowCloseListener.cpp src/EntityController/WindowCloseListener.h src/EntityRepresentation/Transformation.cpp src/EntityRepresentation/Transformation.h src/EntityModel/Dimensions.cpp src/EntityModel/Dimensions.h src/EntityModel/Coordinate.cpp src/EntityModel/Coordinate.h src/Events/Event.cpp src/Events/Event.h src/EntityController/PlayerController.cpp src/EntityController/PlayerController.h src/Events/WindowInteractionEvent.cpp src/Events/WindowInteractionEvent.h src/Loader/Loader.cpp src/Loader/Loader.h src/Loader/ShipLoader.cpp src/Loader/ShipLoader.h src/EntityRepresentation/MovingEntityRepresentation.cpp src/EntityRepresentation/MovingEntityRepresentation.h src/Loader/LevelLoader.cpp src/Loader/LevelLoader.h src/Events/EntityCreatedEvent.cpp src/Events/EntityCreatedEvent.h src/Events/DrawUpdate.cpp src/Events/DrawUpdate.h src/Events/MovingEntityEvent.cpp src/Events/MovingEntityEvent.h src/Events/MovingLeft.cpp src/Events/MovingLeft.h src/Events/StoppedMovingLeft.cpp src/Events/StoppedMovingLeft.h src/Events/UpdateEvent.cpp src/Events/UpdateEvent.h src/EntityModel/RocketModel.cpp src/EntityModel/RocketModel.h src/EntityModel/MovingEntity.cpp src/EntityModel/MovingEntity.h src/Events/FireBullet.cpp src/Events/FireBullet.h src/EntityController/ShipController.cpp src/EntityController/ShipController.h src/EntityController/EnemiesController.cpp src/EntityController/EnemiesController.h src/EntityController/EnemyController.cpp src/EntityController/EnemyController.h src/Events/RocketPositionUpdated.cpp src/Events/RocketPositionUpdated.h src/Events/DestroyedEvent.cpp src/Events/DestroyedEvent.h src/Events/ReprDestroyEvent.cpp src/Events/ReprDestroyEvent.h src/Events/GoDirection.cpp src/Events/GoDirection.h src/Events/ControllerCreated.cpp src/Events/ControllerCreated.h)


TARGET_LINK_LIBRARIES(SpaceInvaders ${SFML_LIBRARIES})

INSTALL(TARGETS SpaceInvaders DESTINATION ${PROJECT_SOURCE_DIR}/bin)