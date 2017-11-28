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

void run_game(string message) {
    while (1) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "GAME TICK" << endl;
    }
}

int main() {
    // Constructs the new thread and runs it. Does not block execution.
    thread server_thread(run_server, "server");
    thread game_thread(run_game, "game");

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    server_thread.join();
    //game_thread.join();

    return 0;
}
