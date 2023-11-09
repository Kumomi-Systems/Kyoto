cmake_minimum_required(VERSION 3.1...3.27)

set(ProjectName Kyoto)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
	Kyoto
	VERSION 0.1
	LANGUAGES CXX
)

include_directories(
	${CMAKE_SOURCE_DIR}
)

add_executable(
	${PROJECT_NAME}
	
	src/compiler.h

	src/kyoto.cpp

	src/core/tryte.cpp
)