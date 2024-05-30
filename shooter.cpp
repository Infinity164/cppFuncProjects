#include <iostream>
#include <string>
#include <stack>
#include <type_traits>
#include <concepts>

#define random(min,max) (min + rand() % (max - min + 1))
using namespace std;

class Ammo {
protected:
    int damage;
    string name;
public:
    virtual int getDamage() = 0;
    virtual string getName() = 0;
};
class Ammo556 : public Ammo {

};
class Ammo762 : public Ammo {
};
class Ammo919 : public Ammo {
};
class Ammo556_BP : public Ammo556 {

public:
    Ammo556_BP(int damage = 7, string name = "Ammo556BP") {
        this->damage = damage;
        this->name = name;
    }
    int getDamage() {
        return this->damage;
    }
    string getName() {
        return this->name;
    }
};
class Ammo556_PS : public Ammo556 {
public:
    Ammo556_PS(int damage = 3, string name = "Ammo556PS") {
        this->damage = damage;
        this->name = name;
    }
    int getDamage() {
        return this->damage;
    }
    string getName() {
        return this->name;
    }
};
class Ammo762_BP : public Ammo762 {
public:
    Ammo762_BP(int damage = 12, string name = "Ammo762BP") {
        this->damage = damage;
        this->name = name;
    }
    int getDamage() {
        return this->damage;
    }
    string getName() {
        return this->name;
    }
};
class Ammo762_PS : public Ammo762 {
public:
    Ammo762_PS(int damage = 9, string name = "Ammo762PS") {
        this->damage = damage;
        this->name = name;
    }
    int getDamage() {
        return this->damage;
    }
    string getName() {
        return this->name;
    }
};
class Ammo919_BP : public Ammo919 {
public:
    Ammo919_BP(int damage = 15, string name = "Ammo919BP") {
        this->damage = damage;
        this->name = name;
    }
    int getDamage() {
        return this->damage;
    }
    string getName() {
        return this->name;
    }
};
class Ammo919_PS : public Ammo919 {
public:
    Ammo919_PS(int damage = 12, string name = "Ammo762PS") {
        this->damage = damage;
        this->name = name;
    }
    int getDamage() {
        return this->damage;
    }
    string getName() {
        return this->name;
    }
};

template <typename T>
concept AmmoType = is_base_of<Ammo, remove_pointer_t <T>>::value &&
!is_same_v<Ammo, remove_pointer_t<T>>;
template <AmmoType T>

class Magazine {
    int amount;
    stack<T> bullets;
public:
    Magazine(int amount) : amount(amount) {};
    void loadto(T bullet) {
        if (bullets.size() >= amount) throw out_of_range("Magazine is fully");
        bullets.push(bullet);
    }
    T unloadto() {
        if (bullets.empty()) throw out_of_range("Magazine is empty");
        T bullet = bullets.top();
        bullets.pop();
        return bullet;
    }

    stack<T> fullunload() {
        if (bullets.empty()) throw out_of_range("Magazine is empty");
        stack<T> unloadBullets = bullets;
        while (!bullets.empty()) bullets.pop();
        return unloadBullets;
    }

    void info() { 
        cout << "Bullets: " << bullets.size() << endl;
        cout << "Type: " << bullets.top()->getName() << endl;
    }
};












int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    Magazine<Ammo556*> m5_56(5);
    for (int i = 0; i < 5; i++) m5_56.loadto(new Ammo556_BP);
    m5_56.info();
}