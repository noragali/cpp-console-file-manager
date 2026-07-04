#include <iostream>
#include "Menu.h"
using namespace std;

void Menu::showMenu(){
    cout<<"-- Console file manager -- " <<endl;
    cout<<"1. Show current directory" <<endl;
    cout<<"2. List files" <<endl;
    cout<<"3. Exit" <<endl;
    cout<<"Choice: ";
}

void Menu::run(int x) {
    switch(x) {
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
