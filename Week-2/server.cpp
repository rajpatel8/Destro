// Arithmetic Calculator using socket programming

# include </Users/aj/v.h>
# include <netinet/in.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <unistd.h>
using namespace std;



int main(int argc, char const *argv[])
{
    // create a server
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        cout << "Error in creating socket" << endl;
        exit(1);
    }
    cout << "Socket created successfully" << endl;

    // bind the socket to an IP and port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    int bindStatus = bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    if (bindStatus == -1)
    {
        cout << "Error in binding the socket" << endl;
        exit(1);
    }
    cout << "Socket binded successfully" << endl;

    // listen to the client
    int listenStatus = listen(serverSocket, 10);
    if (listenStatus == -1)
    {
        cout << "Error in listening to the client" << endl;
        exit(1);
    }
    cout << "Listening to the client" << endl;

    // accept the client
    struct sockaddr_in newAddr;
    socklen_t newAddrSize = sizeof(newAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *) &newAddr, &newAddrSize);
    if (clientSocket == -1)
    {
        cout << "Error in accepting the client" << endl;
        exit(1);
    }
    cout << "Client accepted" << endl;

    // receive data from the client
    char buffer[1024];
    int receiveStatus = recv(clientSocket, &buffer, sizeof(buffer), 0);
    if (receiveStatus == -1)
    {
        cout << "Error in receiving data from the client" << endl;
        exit(1);
    }
    cout << "Data received from the client: " << buffer << endl;

    // evaluate the expression and send the result to the client
    string data = buffer;
    int result = evaluate(data);
    int sendStatus = send(clientSocket, to_string(result).c_str(), to_string(result).size() + 1, 0);
    if (sendStatus == -1)
    {
        cout << "Error in sending data to the client" << endl;
        exit(1);
    }
    cout << "Data sent to the client" << endl;

    // close the socket
    close(serverSocket);

    return 0;

}