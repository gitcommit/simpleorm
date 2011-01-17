set(dbconn_SRC
	conn.cpp
        connectiondata.cpp
        query.cpp
        insertquery.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(dbconn SHARED ${dbconn_SRC})
