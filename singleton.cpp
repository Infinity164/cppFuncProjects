

#include <iostream>
#include <map>
using namespace std;

class ConfigManager {
    static ConfigManager* instance;
    string key;
    string value;
    map<string, string> parameters;
    ConfigManager(){}
public:
    static ConfigManager* getInstance() {
        if (instance == nullptr) { instance = new ConfigManager(); }
        return instance;
    }
    void setParameter(string key, string value) { parameters[key] = value; }
    string getParameter(string key) { return parameters[key]; }
};

ConfigManager* ConfigManager::instance = nullptr;

int main()
{
   
}

