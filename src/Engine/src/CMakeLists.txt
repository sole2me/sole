set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_definitions("-Wall -g")

aux_source_directory(. DIR_SRCS)
add_library(soleengine ${DIR_SRCS})
add_dependencies(soleengine TarsComm)

install(TARGETS soleengine LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

