PROJECT(fgeo)
cmake_minimum_required(VERSION 2.8)

add_subdirectory(src/lib/common)
add_subdirectory(src/lib/dbmodel)
add_subdirectory(src/lib/orm)
add_subdirectory(src/lib/dbconn)
add_subdirectory(src/lib/application)
add_subdirectory(src/bin/fgeo)

INCLUDE_DIRECTORIES(~/usr/boost/include)