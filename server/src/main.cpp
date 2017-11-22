#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

int main() {
    try {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1024));

        cout << "Waiting for clients" << endl;

        while (1) {
            tcp::socket socket(io_service);

            // Wait for a client to connect.
            acceptor.accept(socket);

            cout << "Client connected" << endl;

            // Recieve a message from the client.
            boost::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof) {
                break; // Connection closed cleanly by peer.
            }
            else if (error) {
                throw boost::system::system_error(error); // Some other error.
            }
            else {
                // Use the recieved message.
                cout << "\tREAD: ";
                cout.write(&buf[0], len);
                cout << endl;
            }
        }
    }
    catch (std::exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
