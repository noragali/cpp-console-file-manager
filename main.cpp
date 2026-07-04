#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
    Menu menu;
    int choice = 1;

    while(choice != 3) {
        menu.showMenu();
        cin >> choice;
        menu.run(choice);

    }

    return 0;

}
