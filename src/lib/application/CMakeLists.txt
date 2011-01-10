set(app_SRC
	application.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)
add_library(app SHARED ${app_SRC})
add_dependencies(app orm)
