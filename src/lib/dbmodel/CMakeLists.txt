set(libdbmodel_SRC
	component.cpp
        componentvisitor.cpp
        database.cpp
        indatabasecomponent.cpp
        datatype.cpp
        crebasvisitor.cpp
        schema.cpp
        inschemacomponent.cpp
        sequence.cpp
        table.cpp
        databaseconstant.cpp
        defaultgenerator.cpp
        databaseconstantdefaultgenerator.cpp
        sequencedefaultgenerator.cpp
        intablecomponent.cpp
        tablecolumn.cpp
        intablecolumncomponent.cpp
        numericdefaultgenerator.cpp
        textdefaultgenerator.cpp
)

INCLUDE_DIRECTORIES(.. . ~/usr/boost/include)

add_library(libdbmodel SHARED ${libdbmodel_SRC})
