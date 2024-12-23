#include <iostream>
#include "../../Headers/ToolBox.h"
using std::string;

string Get_File_Contents(const string& from) {
    string result;

    std::ifstream file;
    file.open(from);

    if (file.fail()) {
        cout << "Error opening " << Get_Folder_Name(from) << " file" << endl;
    }
    char c;
    while (file.get(c)) {
        result += c;
    }
    file.close();

    return result;
}

string Get_File_Line(const string& from, int lineNum)
{
    string fileLines = Get_File_Contents(from);
    // cout << fileLines;
    string currentLine;
    string result;

    int i = 0;
    int n = 1;
    while(true) {
        if(fileLines[i] == '\n') {
            if (lineNum == n) {
                return result;
            }
            else {
                result.clear();
                ++n;
            }
        }
        else
            result += fileLines[i];
        ++i;
    }
    return "";
}

void Create_File(const string& name, const string& extension, const string& destination, const string& content)
{
    fstream file;
    file.open(destination + '/' + name + '.' + extension, ios::out);
    file << content;
    file.close();
}
void Create_File(const string& name, const string& extension, const string& destination, const path& content)
{
    fstream file;
    file.open(destination + '/' + name + '.' + extension, ios::out);
    file << content;
    file.close();
}

void Delete_File(const string& path)
{
        if (remove(path.c_str()) != 0) {
            cout << "Failed to delete the (" << path << ") file" << endl;
        }
}

bool Copy_File(const string& sourceFile, const string& destFile, bool changable)
{
    std::ifstream source(sourceFile, ios::binary);
    std::ofstream destination(destFile +"/"+ Get_Folder_Name(sourceFile), ios::binary);

    // deleting the same copy if exists
    if(exists(destFile +'/'+ Get_Folder_Name(sourceFile)) && changable) {
        Delete_File(destFile +'/'+ Get_Folder_Name(sourceFile));
    }

    if(!source.is_open() || !destination.is_open())
    {
        cout << "Error opening " << sourceFile << " file" << endl;
        return false;
    }

    destination << source.rdbuf();

    if(!source.good() || !destination.good())
    {
        cout << "Error during file copy\n";
        return false;
    }

    return true;
}

void Move_File(const string& sourceFile, const string& destFile) {
    if (Copy_File(sourceFile, destFile) != 0)
        if (remove(sourceFile.c_str()) != 0) {
            cout << "Failed to delete the (" << sourceFile << ") file" << endl;
        }
}
