set(orm_SRC
	mapping.cpp
        entity.cpp
        identifiedentity.cpp
        namedentity.cpp
        standardentity.cpp
        session.cpp

)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(orm SHARED ${orm_SRC})
add_dependencies(orm dbmodel)
