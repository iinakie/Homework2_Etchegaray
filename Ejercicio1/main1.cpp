#include <iostream>
#include "Tiempo.hpp"

int main(){
    Tiempo T(3, 14, 45, true);
    T.show12h();
    T.show24h();
    return 0;
}