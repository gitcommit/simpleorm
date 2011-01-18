set(fgeo_SRC
	main.cpp
        fgeodatabase.cpp
        fgeoapplication.cpp
        fgeosession.cpp

        lib/core/siprefix.cpp
)
INCLUDE_DIRECTORIES(../../lib . .. ~/usr/boost/include ~/usr/postgres/git/include)
LINK_DIRECTORIES(~/usr/postgres/git/lib)

ADD_EXECUTABLE(fgeo ${fgeo_SRC})

TARGET_LINK_LIBRARIES(fgeo orm dbmodel dbconn app pq)

add_dependencies(fgeo orm dbmodel dbconn app)
