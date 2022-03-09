EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake  -E echo upload tars all)
EXECUTE_PROCESS(COMMAND cmake -P /home/app_user/sole/SoleApp/build/run-upload-tars-WorkServer.cmake)
