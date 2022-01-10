clear

g++ server.cpp server-client/Server.cpp entities/ICMP.cpp -o server

g++ client.cpp server-client/Client.cpp entities/ICMP.cpp -o client