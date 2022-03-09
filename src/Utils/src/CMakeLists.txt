set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_definitions("-Wall -g")

aux_source_directory(. DIR_SRCS)
add_library(soleutils ${DIR_SRCS})
##add_dependencies(soleutils TarsComm)

install(TARGETS soleutils LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
