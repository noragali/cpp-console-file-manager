#include <iostream>
#include "Menu.h"
#include "FileManager.h"
using namespace std;

void Menu::showMenu(){
    cout<<"-- Console file manager -- " <<endl;
    cout<<"1. Show current directory" <<endl;
    cout<<"2. List files" <<endl;
    cout<<"3. Create file" <<endl;
    cout<<"4. Delete file" <<endl;
    cout<<"5. Rename file" <<endl;
    cout<<"6. Exit" <<endl;
    cout<<"Choice: ";
}

void Menu::run() {
    int choice = 0;

    while(choice != 6) {
        showMenu();
        cin >> choice;

        FileManager fileManager;

        switch(choice) {
            case 1:
                fileManager.currentDictionary();
                break;
            case 2:
                fileManager.listFiles();
                break;
            case 3:
                fileManager.createFile();
                break;
            case 4:
                fileManager.deleteFile();
                break;
            case 6:
                cout<<"Exiting..";
                break;
            default:
                cout<<"Invalid option!";
        }
    }
}
