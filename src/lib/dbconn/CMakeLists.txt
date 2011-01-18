set(dbconn_SRC
	conn.cpp
        connectiondata.cpp
        query.cpp
        insertquery.cpp
        error.cpp
        connectionerror.cpp
        transactionerror.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include ~/usr/postgres/git/include)
LINK_DIRECTORIES(~/usr/postgres/git/lib)

add_library(dbconn SHARED ${dbconn_SRC})
TARGET_LINK_LIBRARIES(dbconn pq)
