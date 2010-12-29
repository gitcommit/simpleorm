set(fgeo_SRC
	main.cpp
        fgeodatabase.cpp
)
INCLUDE_DIRECTORIES(../../lib .)

ADD_EXECUTABLE(fgeo ${fgeo_SRC})
TARGET_LINK_LIBRARIES(fgeo liborm libdbmodel libomodel libdbconn)
add_dependencies(fgeo liborm libdbmodel libomodel libdbconn)
