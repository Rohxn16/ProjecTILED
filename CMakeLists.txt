cmake_minimum_required(VERSION 3.10)
project(projectiled)

add_executable(projectiled)

target_sources(projectiled 
PRIVATE
	src/main.c
	src/MapSystem/MapBuilder.c
	src/Destroyer/Destroyer.c
)

target_include_directories(projectiled
PRIVATE
	include
)

target_link_directories(projectiled
PRIVATE
	lib
)

target_link_libraries(projectiled
PRIVATE
	raylib m rt dl pthread
)
