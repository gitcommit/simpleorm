set(libomodel_SRC
	entity.cpp
        identifiedentity.cpp
        namedentity.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(libomodel SHARED ${libomodel_SRC})
