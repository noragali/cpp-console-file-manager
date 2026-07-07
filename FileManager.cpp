#include <iostream>
#include "FileManager.h"
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

void FileManager::listFiles(){
    for (const auto& entry : fs::directory_iterator(currentPath)) {
        if(entry.is_directory()) cout << "[DIR]";
        else cout << "[FILE]";
        cout << entry.path().filename();

        if(!entry.is_directory()) cout<< "(" << entry.path().extension() << ")" << endl;
    }
}

void FileManager::currentDirectory(){
    cout << currentPath << endl;
}

void FileManager::createFile() {
    string name;
    char answer;
    cout<<"Write the name of the file: ";
    cin >> name;

    fs::path filePath = currentPath / name;
    ofstream file(filePath);
    if (filePath.extension() == ".txt") {
        cout << "Do you want to write something into the file? Y/N" << endl;
        cin >> answer;
        cin.ignore();

        if(answer == 'Y' || answer == 'y') {
            string text;
            cout << "Write the text: ";
            getline(cin, text);
            file << text;
        }
    }

    file.close();
}

void FileManager::deleteFile() {
    string name;
    cout << "Write the file name that you want to delete: ";
    cin >> name;

    fs::path filePath = currentPath / name;
    bool deleted = fs::remove(filePath);
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

    fs::path oldPath = currentPath / oldName;
    fs::path newPath = currentPath / newName;

    if(fs::exists(oldPath)) {
        fs::rename(oldPath, newPath);
        cout << "File renamed!" << endl;
    } else {
        cout<< "File with the name wasn't found!" << endl;
    }

}

FileManager::FileManager() {
    currentPath = std::filesystem::current_path();
}

void FileManager::changeDirectory() {
    string folder;
    cout << "Enter a folder name: ";
    cin >> folder;

    fs::path newPath = currentPath / folder;

    if (fs::exists(newPath) && fs::is_directory(newPath))
    {
        currentPath = newPath;
        cout << "Changed directory to: " << currentPath << endl;
    }
    else
    {
        cout << "Folder does not exist!" << endl;
    }
}
