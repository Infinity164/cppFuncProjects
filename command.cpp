#include <iostream>
using namespace std;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Spotlight {
private:
    string location;
public:
    Spotlight(string location) : location(location){}
    void turnOn() { cout << "Spotlight is turned on."; }
    void turnOff() { cout << "Spotlight is turnedd off."; }
};

class LightOnCommand : Command {
private:
    Spotlight* spotlight;
public:
    LightOnCommand(Spotlight* spotlight) : spotlight(spotlight){}
    void execute() override { spotlight->turnOn(); }
    void undo() override { spotlight->turnOff(); }
};

class LightOffCommand : Command {
private:
    Spotlight* spotlight;
public:
    LightOffCommand(Spotlight* spotlight) : spotlight(spotlight){}
    void execute() override { spotlight->turnOff(); }
    void undo() override { spotlight->turnOn(); }
};

class Remote {
private:
    Command* command;
public:
    void setCommand(Command* cmd) { command = cmd; }
    void pressButton() { if (command) command->execute(); }
    void pressUndo() { if (command) command->undo(); }
};

int main()
{
    
}