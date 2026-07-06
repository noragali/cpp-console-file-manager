#include <filesystem>

class FileManager{
private:
    std::filesystem::path currentPath;
public:
    FileManager();
    void currentDirectory();
    void listFiles();
    void createFile();
    void deleteFile();
    void renameFile();
    void changeDirectory();
};
