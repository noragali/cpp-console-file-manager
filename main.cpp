#include <iostream>
#include "Menu.h"
using namespace std;

int main() {
    Menu menu;
    int choice = 1;

    while(choice != 3) {
        menu.showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout<<"Current dictionary!";
                break;
            case 2:
                cout<<"List of files!";
                break;
            case 3:
                cout<<"Exiting..";
                break;
            default:
                cout<<"Invalid option!";
        }
    }


    return 0;

}
