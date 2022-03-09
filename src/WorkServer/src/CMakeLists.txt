gen_server(SoleApp WorkServer)
add_definitions("-Wall -g")

##message("xxx:         ${xxxx}")

add_dependencies(WorkServer TarsComm)

target_link_libraries(WorkServer soleengine soleutils soleparse)