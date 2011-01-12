set(fgeo_SRC
	main.cpp
        fgeodatabase.cpp
        fgeoapplication.cpp
        fgeosession.cpp

        lib/core/siprefix.cpp
)
INCLUDE_DIRECTORIES(../../lib . .. ~/usr/boost/include)

ADD_EXECUTABLE(fgeo ${fgeo_SRC})

TARGET_LINK_LIBRARIES(fgeo orm dbmodel dbconn app)

add_dependencies(fgeo orm dbmodel dbconn app)
