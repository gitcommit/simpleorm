set(libdbconn_SRC
	conn.cpp
        connectiondata.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(libdbconn SHARED ${libdbconn_SRC})
