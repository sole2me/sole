EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E make_directory /home/tarsproto/SoleApp/WorkServer)
EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E echo cp -rf /home/app_user/sole/SoleApp/src/WorkServer/src/Service.h /home/tarsproto/SoleApp/WorkServer)
EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E copy /home/app_user/sole/SoleApp/src/WorkServer/src/Service.h /home/tarsproto/SoleApp/WorkServer)
EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E echo cp -rf /home/app_user/sole/SoleApp/src/WorkServer/src/Service.tars /home/tarsproto/SoleApp/WorkServer)
EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E copy /home/app_user/sole/SoleApp/src/WorkServer/src/Service.tars /home/tarsproto/SoleApp/WorkServer)
