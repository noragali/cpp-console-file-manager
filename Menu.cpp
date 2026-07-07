#include <iostream>
#include "Menu.h"
#include "FileManager.h"
using namespace std;

void Menu::showMenu(){
    cout<<"-- Console file manager -- " <<endl;
    cout<<"1. Show current directory" <<endl;
    cout<<"2. List files" <<endl;
    cout<<"3. Create file" <<endl;
    cout<<"4. Create folder" <<endl;
    cout<<"5. Delete file" <<endl;
    cout<<"6. Rename file" <<endl;
    cout<<"7. Change directory" << endl;
    cout<<"8. Go back" << endl;
    cout<<"9. Exit" <<endl;
    cout<<"Choice: ";
}

void Menu::run() {
    int choice = 0;
    FileManager fileManager;

    while(choice != 9) {
        showMenu();

        if(!(cin>>choice)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if(choice > 9 || choice < 1) {
            cout << "Input has to be from 1 - 9!" << endl;
            continue;
        }

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
                fileManager.createFolder();
                break;
            case 5:
                fileManager.deleteFile();
                break;
            case 6:
                fileManager.renameFile();
                break;
            case 7:
                fileManager.changeDirectory();
                break;
            case 8:
                fileManager.goBack();
                break;
            case 9:
                cout<<"Exiting..";
                break;
            default:
                cout<<"Invalid option!";
        }
    }
}
