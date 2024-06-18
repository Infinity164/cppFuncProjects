

#include <iostream>
using namespace std;

class BaseHandler {
protected:
    BaseHandler* next;
public:
    BaseHandler() : next(nullptr){}
    void setNext(BaseHandler* nextHandler) { next = nextHandler; }
    virtual void handleRequest(string request) { 
        if (next) next->handleRequest(request);
        else throw logic_error("Request not recognized.");
    }
};

class SimpleRequestHandler : public BaseHandler {
public:
    void handleRequest(string request) {
        if (request == "simple") cout << "Handled the request (simple)" << endl;
        else BaseHandler::handleRequest(request);
    }
};

class ComplexRequestHandler : public BaseHandler {
public:
    void handleRequest(string request) {
        if (request == "complex") cout << "Handled the request (complex)" << endl;
        else BaseHandler::handleRequest(request);
    }
};

class CriticalRequestHandler : public BaseHandler {
public:
    void handleRequest(string request) {
        if (request == "critical") cout << "Handled the request (critical)" << endl;
        else BaseHandler::handleRequest(request);
    }
};

int main()
{
    SimpleRequestHandler* sreqh = new SimpleRequestHandler();
    ComplexRequestHandler* creqh = new ComplexRequestHandler();
    CriticalRequestHandler* crreqh = new CriticalRequestHandler();

    sreqh->setNext(creqh);
    creqh->setNext(crreqh);
    sreqh->handleRequest("critical");
}