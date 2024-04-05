#include <iostream>
#include "Map.h"
using namespace std;


int main()
{
    srand(time(NULL));
    Map map(20, 80);
    map.generation();
    map.draw();
}
