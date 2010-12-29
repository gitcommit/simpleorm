set(libdbmodel_SRC
	component.cpp
        componentvisitor.cpp
        database.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(libdbmodel SHARED ${libdbmodel_SRC})
