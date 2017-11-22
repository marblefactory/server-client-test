#include "server.h"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using std::cout;
using std::endl;

// // A sychronous TCP server, this is fine since we only have one client suppling
// // JSON actions.
// class Server {
// private:
//     // Used to accept connections from clients.
//     tcp::acceptor *acceptor;
//
// public:
//     Server();
//
//     // Listen to connections from clients, and read the message they send.
//     void start_accept();
// };

// Create a server listening on the specified port for connections, for
// IP version 4.
Server::Server(boost::asio::io_service &io_service, int port):
    io_service(io_service),
    acceptor(io_service, tcp::endpoint(tcp::v4(), port))
{
}

// Listen for a connection from a single client. This blocks until a
// client has connected and send a message.
void Server::accept_client() throw(boost::system::system_error) {
    // Represents the connection to the client.
    tcp::socket socket(io_service);
    // Wait for a client to connect, this is a blocking call.
    acceptor.accept(socket);

    cout << "Client connected" << endl;

    // Recieve a message from the client.
    boost::array<char, MAX_BUFFER_SIZE> buf;
    boost::system::error_code error;

    size_t len = socket.read_some(boost::asio::buffer(buf), error);

    if (error == boost::asio::error::eof) {
        // Connection closed cleanly by peer.
        return;
    }
    else if (error) {
        // Some other error.
        throw boost::system::system_error(error);
    }
    else {
        // Use the recieved message.
        cout << "\tREAD: ";
        cout.write(&buf[0], len);
        cout << endl;
    }
}

// Listen to connections from clients, and read the message they send.
// It is expected that each client that connects will send a message.
void Server::start_accepts() throw(boost::system::system_error) {
    while (true) {
        accept_client();
    }
}
