
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(TARGETNAME "soleparse")

add_definitions("-Wall -g")

aux_source_directory(. DIR_SRCS)

set(DEPENDS_SRC_LIST)

set(DEPENDS_LEC_YACC_SRC_LIST) 
list(APPEND DEPENDS_LEC_YACC_SRC_LIST "sole.lex.cpp") 
list(APPEND DEPENDS_LEC_YACC_SRC_LIST "sole.tab.hpp") 
list(APPEND DEPENDS_LEC_YACC_SRC_LIST "sole.tab.cpp")

message("PROJECT_SOURCE_DIR:         ${PROJECT_SOURCE_DIR}")
set(DEPENDS_LEC_YACC_SRC_DIR "${PROJECT_SOURCE_DIR}/src/Grammar/src")

set(CURRENT_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

foreach(LEC_YACC_SRC ${DEPENDS_LEC_YACC_SRC_LIST})
    list(APPEND DEPENDS_SRC_LIST ${CURRENT_SRC_DIR}/${LEC_YACC_SRC})
    add_custom_command( OUTPUT ${CURRENT_SRC_DIR}/${LEC_YACC_SRC}
            WORKING_DIRECTORY ${CURRENT_SRC_DIR}) 
            #            COMMAND cp ${DEPENDS_LEC_YACC_SRC_DIR}/${LEC_YACC_SRC} ${CURRENT_SRC_DIR} 
            #            COMMENT "cp ${DEPENDS_LEC_YACC_SRC_DIR}/${LEC_YACC_SRC} ${CURRENT_SRC_DIR}")
endforeach()

add_library(${TARGETNAME} ${DIR_SRCS} ${DEPENDS_SRC_LIST})

if(UNIX) 
    add_dependencies(${TARGETNAME} COPY-LEX-YACC) 
endif(UNIX)

add_dependencies(soleparse TarsComm)

install(TARGETS soleparse LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
