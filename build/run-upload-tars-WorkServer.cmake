EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E echo http://127.0.0.1:4001/api/upload_tars_file -Fsuse=@WorkServer-merge.tars -Fapplication=SoleApp -Fserver_name=WorkServer)
EXECUTE_PROCESS(COMMAND curl http://127.0.0.1:4001/api/upload_tars_file?ticket= -Fsuse=@WorkServer-merge.tars -Fapplication=SoleApp -Fserver_name=WorkServer)
EXECUTE_PROCESS(COMMAND /home/testuser/cmake/cmake/bin/cmake -E echo 
---------------------------------------------------------------------------)
