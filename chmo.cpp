
#include <iostream>
using namespace std;
#define random(min,max) (min + rand() % (max - min + 1))

class Weapon {
public:
    string name;
    float impact_speed;
    float draw_speed;
    float melee_damage;
    float damage_boost;
    string damage_modificator;
    string weaponclass;
    virtual ~Weapon() = default;
};

class Melee : public Weapon {};

class Knife : public Melee {
    Knife(string name, float impact_speed = 2.0, float draw_speed = 4.0, float melee_damage, string damage_modificator = "none", string weaponclass = "light") {

    }
};
class Firearm : public Weapon {};

class Pistol : public Firearm {};

class Submachinegun : public Firearm {};

int main()
{
    
}


