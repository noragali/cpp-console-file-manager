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
    cout<<"6. Change directory" << endl;
    cout<<"7. Exit" <<endl;
    cout<<"Choice: ";
}

void Menu::run() {
    int choice = 0;
    FileManager fileManager;

    while(choice != 7) {
        showMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                fileManager.currentDirectory();
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
            case 5:
                fileManager.renameFile();
                break;
            case 6:
                fileManager.changeDirectory();
                break;
            case 7:
                cout<<"Exiting..";
                break;
            default:
                cout<<"Invalid option!";
        }
    }
}
