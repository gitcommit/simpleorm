set(app_SRC
	application.cpp
        settings.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include ~/usr/postgres/git/include)
LINK_DIRECTORIES(~/usr/postgres/git/lib)

add_library(app SHARED ${app_SRC})
add_dependencies(app orm dbconn)
TARGET_LINK_LIBRARIES(app dbconn)
