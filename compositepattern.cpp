
#include <iostream>
#include <vector>
using namespace std;

class FilesystemComponent {
public:
    virtual ~FilesystemComponent() = default;
    virtual void add(FilesystemComponent* component) = 0;
    virtual void remove(string name) = 0;
    //virtual void display() = 0;
    virtual float getWeight() = 0;
};

class File : public FilesystemComponent {
private:
    float weight;
    string name;
public:
    File(string name, float weight) : name(name), weight(weight){}
    float getWeight() { return weight; }
    void add(FilesystemComponent* component) { throw logic_error("lox"); }
    void remove(string name) { throw logic_error("lox"); }

};

class Directory : public FilesystemComponent {
private:
    string name;
    vector<FilesystemComponent*> components;
public:
    Directory(string name) : name(name){}
    ~Directory() { for (auto component : components) delete component; }
    void add(FilesystemComponent* component) { components.push_back(component); }
    void remove(string name) {}
    float getWeight() {
        float result = 0;
        for (auto component : components) result += component->getWeight();
        return result;
    }
};

int main()
{
    File* f1 = new File("A1.txt", 1.1);
    Directory* d1 =
}

