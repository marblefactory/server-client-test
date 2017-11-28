#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include "server.h"

using boost::asio::ip::tcp;
using namespace std;

void run_server(string msg) {
    try {
        boost::asio::io_service io_service;
        Server server(io_service, 1024);

        server.accept_client();
    }
    catch (std::exception& e) {
        cerr << e.what() << endl;
    }
}

int main() {
    // Constructs the new thread and runs it. Does not block execution.
    thread server_thread(run_server, "server");

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    server_thread.join();

    return 0;
}
