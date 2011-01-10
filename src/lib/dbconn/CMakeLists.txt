set(dbconn_SRC
	conn.cpp
        connectiondata.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(dbconn SHARED ${dbconn_SRC})
