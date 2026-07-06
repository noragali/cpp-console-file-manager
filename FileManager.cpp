#include <iostream>
#include "FileManager.h"
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

void FileManager::listFiles(){
    for (const auto& entry : fs::directory_iterator(".")) {
        cout << entry.path().filename() << endl;
    }
}

void FileManager::currentDictionary(){
    cout << fs::current_path() << endl;
}

void FileManager::createFile() {
    string name;
    char answer;
    cout<<"Write the name of the file: ";
    cin >> name;

    ofstream file(name + ".txt");
    cout << "Do you want to write something into the file? Y/N" << endl;
    cin >> answer;
    cin.ignore();

    if(answer == 'Y' || answer == 'y') {
        string text;
        cout << "Write the text: ";
        getline(cin, text);
        file << text;
    }

    file.close();
}

void FileManager::deleteFile() {
    string name;
    cout << "Write the file name that you want to delete: ";
    cin >> name;

    bool deleted = fs::remove(name);
    if(deleted) cout<<"File is deleted!" << endl;
    else cout <<"File with the name doesn't exist!" << endl;
}

void FileManager::renameFile() {
    string oldName;
    string newName;
    cout<<"Enter the current name: ";
    cin >> oldName;
    cout<< "Enter the new name: ";
    cin >> newName;

    if(fs::exists(oldName)) {
        fs::rename(oldName, newName);
        cout << "File renamed!" << endl;
    } else {
        cout<< "File with the name wasn't found!" << endl;
    }

}
