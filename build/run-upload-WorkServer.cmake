EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E echo http://127.0.0.1:4001/api/upload_and_publish -Fsuse=@WorkServer.tgz -Fapplication=SoleApp -Fmodule_name=WorkServer -Fcomment=developer-auto-upload)
EXECUTE_PROCESS(COMMAND curl http://127.0.0.1:4001/api/upload_and_publish?ticket= -Fsuse=@WorkServer.tgz -Fapplication=SoleApp -Fmodule_name=WorkServer -Fcomment=developer-auto-upload)
EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E echo 
---------------------------------------------------------------------------)
