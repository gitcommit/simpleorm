set(liborm_SRC
	mapping.cpp
        session.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(liborm SHARED ${liborm_SRC})
