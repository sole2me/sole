##message(STATUS "Hello World!")
macro(complice_lex OUT_DEPENDS_LEX_LIST)
    set(DEPENDS_LIST)
    message(STATUS "DEPENDS_LIST: ${DEPENDS_LIST}")
    message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
    message(STATUS "SRC_LIST: ${SRC_LIST}")
    FILE(GLOB SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*.l")
    message(STATUS "SRC_LIST: ${SRC_LIST}")
    foreach (FILE ${SRC_LIST})
        get_filename_component(NAME_WE ${FILE} NAME_WE)
        set(LEX_IN ${FILE})
        set(LEX_CPP ${NAME_WE}.lex.cpp)
        message(STATUS "LEX_IN: ${LEX_IN}")
        message(STATUS "LEX_CPP: ${LEX_CPP}")

        message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
        message(STATUS "LEX_CPP: ${LEX_CPP}")
        add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${LEX_CPP}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                DEPENDS ${LEX_IN}
                COMMAND flex --nounist ${LEX_IN}
                COMMENT "flex --nounist ${LEX_IN}")
        list(APPEND DEPENDS_LIST ${CMAKE_CURRENT_SOURCE_DIR}/${LEX_CPP})

        message(STATUS "DEPENDS_LIST: ${DEPENDS_LIST}")

        get_filename_component(PATH ${FILE} PATH)
    endforeach (FILE)
    set(OUT_DEPENDS_LEX_LIST ${DEPENDS_LIST})
endmacro()

macro(complice_yacc OUT_DEPENDS_YACC_LIST)
    set(DEPENDS_LIST)
    FILE(GLOB SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*.y")
    foreach (FILE ${SRC_LIST})
        get_filename_component(NAME_WE ${FILE} NAME_WE)
        message(STATUS "=====================")
        message(STATUS "NAME_WE: ${NAME_WE}")
        message(STATUS "=====================")
        set(YACC_IN ${FILE})
        set(YACC_H ${NAME_WE}.tab.hpp)
        set(YACC_CPP ${NAME_WE}.tab.cpp)
        add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${YACC_H}
                OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${YACC_CPP}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                DEPENDS ${YACC_IN}
                COMMAND bison  ${YACC_IN} -o ${YACC_CPP}
                COMMENT "bison  ${YACC_IN}  -o ${YACC_CPP}")
        list(APPEND DEPENDS_LIST ${CMAKE_CURRENT_SOURCE_DIR}/${YACC_H})
        get_filename_component(PATH ${FILE} PATH)
    endforeach (FILE)
endmacro()

set(OUT_DEPENDS_LEX_LIST)
complice_lex(OUT_DEPENDS_LEX_LIST)
message(STATUS "OUT_DEPENDS_LEX_LIST ${OUT_DEPENDS_LEX_LIST}")

FILE(GLOB SRC_LEX_LIST "*.l")

foreach (FILE ${SRC_LEX_LIST})
    get_filename_component(NAME_WE ${FILE} NAME_WE)
    set(LEX_CPP ${NAME_WE}.lex.cpp)
    set(CP_SOURCE_CPP_DIR "${PROJECT_SOURCE_DIR}/src/Parser/src")
    message(STATUS "--------------------------------------")
    message(STATUS "LEX_CPP ${LEX_CPP}")
    message(STATUS "CP_SOURCE_CPP_DIR ${CP_SOURCE_CPP_DIR}")
    message(STATUS "PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}")
    message(STATUS "--------------------------------------")

    add_custom_command( OUTPUT ${CP_SOURCE_CPP_DIR}/${LEX_CPP}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMAND cp -rf ${LEX_CPP} ${CP_SOURCE_CPP_DIR}
            DEPENDS ${LEX_CPP}
            COMMENT "cp -rf ${LEX_CPP} ${CP_SOURCE_CPP_DIR}")
    #设置依赖
    list(APPEND OUT_DEPENDS_LEX_LIST ${CP_SOURCE_CPP_DIR}/${LEX_CPP})
endforeach ()

set(OUT_DEPENDS_YACC_LIST)
complice_yacc(OUT_DEPENDS_YACC_LIST)
FILE(GLOB SRC_YACC_LIST "*.y")
#将生成代码文件copy到对应的目录 

foreach (FILE ${SRC_YACC_LIST})
    get_filename_component(NAME_WE ${FILE} NAME_WE)
    set(YACC_H ${NAME_WE}.tab.hpp)
    set(YACC_CPP ${NAME_WE}.tab.cpp)
    set(CP_SOURCE_H_DIR "${PROJECT_SOURCE_DIR}/src/Parser/src")
    add_custom_command( OUTPUT ${CP_SOURCE_H_DIR}/${YACC_H}
            OUTPUT ${CP_SOURCE_H_DIR}/${YACC_CPP}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMAND cp -rf ${YACC_H} ${YACC_CPP} ${CP_SOURCE_H_DIR} DEPENDS ${YACC_H} DEPENDS ${YACC_CPP}
            COMMENT "cp -rf ${YACC_H} ${YACC_CPP} ${CP_SOURCE_H_DIR}")
    #设置依赖
    list(APPEND OUT_DEPENDS_YACC_LIST ${CP_SOURCE_H_DIR}/${YACC_H})
    ###list(APPEND OUT_DEPENDS_YACC_LIST ${CP_SOURCE_H_DIR}/${YACC_CPP})
endforeach ()

message(STATUS "**************************")
message(STATUS "OUT_DEPENDS_LEX_LIST:${OUT_DEPENDS_LEX_LIST}")
message(STATUS "OUT_DEPENDS_YACC_LIST:${OUT_DEPENDS_YACC_LIST}")
message(STATUS "**************************")
message(STATUS "COPY-LEX-YACC:${COPY-LEX-YACC}")
add_custom_target(COPY-LEX-YACC ALL DEPENDS ${OUT_DEPENDS_LEX_LIST} ${OUT_DEPENDS_YACC_LIST})
