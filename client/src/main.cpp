#include <iostream>
#include "client.h"

int main(int argc, char **argv){
    Client client;
    client.setEndpoint("127.0.0.1", "1024");
    client.startClient();
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return EXIT_SUCCESS;
}
