#include <iostream>
using namespace std;

class Coffee {
public:
    void prepareRecipe() {
        boilWater();
        brewCoffee();
        pourInCup();
        addOptionalCondiments();
    }
protected:
    void boilWater() { cout << "Boiling water" << endl; }
    void pourInCup() { cout << "Pouring in cup" << endl; }

    virtual void brewCoffee() = 0;
    virtual void addOptionalCondiments() = 0;
};

class BlackCoffee : public Coffee {
protected:
    void brewCoffee() override { cout << "Dripping black coffee" << endl; }
    void addOptionalCondiments() override { cout << "Nothing to add, sorry" << endl; }
};

class Latte : public Coffee {
protected:
    void brewCoffee() override { cout << "Brewing espresso" << endl; }
    void addOptionalCondiments() override { cout << "Adding some milk" << endl; }
};

int main()
{
    
}


