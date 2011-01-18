set(orm_SRC
	mapping.cpp
        mappedproperty.cpp
        entity.cpp
        identifiedentity.cpp
        namedentity.cpp
        standardentity.cpp
        session.cpp
        property.cpp
        entityvisitor.cpp
        persistancevisitor.cpp
        insertvisitor.cpp

)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include ~/usr/postgres/git/include)
LINK_DIRECTORIES(~/usr/postgres/git/lib)

add_library(orm SHARED ${orm_SRC})
TARGET_LINK_LIBRARIES(orm dbconn dbmodel)
add_dependencies(orm dbmodel)
