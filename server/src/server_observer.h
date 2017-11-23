#include <string>

#ifndef server_observer_h
#define server_observer_h

// An abstract class that is subclassed to allow messages recieved by a Server
// to be read.
class ServerObserverInterface {
public:
    virtual ~ServerObserverInterface() {}
    void notify(string message) = 0;
};

#endif // server_observer_h
