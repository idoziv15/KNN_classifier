all:
	g++ -std=c++11 -pthread  ./Client/*.cpp ./Client/DataAndCalcs/*.cpp ./Client/Flow/*.cpp ./IO/*.cpp ./Client/Operations/*.cpp -o client.out
	g++ -std=c++11 -pthread ./Server/*.cpp ./Server/Distances/*.cpp ./Server/ServerFlow/*.cpp ./Server/DataAndAssistance/*.cpp ./Server/Commands/*.cpp ./IO/*.cpp -o server.out	
	
run-server: server.out
	./server.out 12345
	
run-client: client.out
	./client.out 127.0.0.1 12345

clean: server.out client.out
	rm -f a.out server.out client.out
