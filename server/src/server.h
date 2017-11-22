
#ifndef server_h
#define server_h

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// A sychronous TCP server, this is fine since we only have one client suppling
// JSON actions.
class Server {
private:
    // Used to accept connections from clients.
    tcp::acceptor *acceptor;

public:
    Server();

    // Listen to connections from clients, and read the message they send.
    void listen();
};

#endif // server_h
