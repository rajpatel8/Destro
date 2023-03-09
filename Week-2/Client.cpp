# include </Users/aj/v.h>
# include <netinet/in.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <unistd.h>
using namespace std;

// Arithmetic Calculator using socket programming

int main(int argc, char const *argv[])
{
    // Open the socket connection
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        cout << "Error in creating socket" << endl;
        exit(1);
    }
    cout << "Socket created successfully" << endl;
    
    // Communication
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr(
    int connectionStatus = connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    )
    if (connectionStatus == -1)
    {
        cout << "Error in connecting to the server" << endl;
        exit(1);
    }
    cout << "Connected to the server" << endl;

    // Send data until the user enters "exit"
    while (true)
    {
        // Get the data from the user
        string data;
        cout << "Enter the data: ";
        getline(cin, data);
        if (data == "exit")
        {
            break;
        }

        // Send the data to the server
        int sendStatus = send(clientSocket, data.c_str(), data.size() + 1, 0);
        if (sendStatus == -1)
        {
            cout << "Error in sending data to the server" << endl;
            exit(1);
        }
        cout << "Data sent to the server" << endl;

        // Receive the data from the server
        char buffer[1024];
        int receiveStatus = recv(clientSocket, &buffer, sizeof(buffer), 0);
        if (receiveStatus == -1)
        {
            cout << "Error in receiving data from the server" << endl;
            exit(1);
        }
        cout << "Data received from the server: " << buffer << endl;
    }

    // Close the socket
    close(clientSocket);
    cout << "Socket closed successfully" << endl;
    return 0 ;

}
