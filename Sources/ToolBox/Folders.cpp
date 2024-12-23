#include "../../Headers/ToolBox.h"

string Current_Folder()
{
    string rslt;
    char Dir[1024];
    _getcwd(Dir, 1024); // getting the current cpp file directory

    int i = 0;
    while (Dir[i] != 0) {
        rslt += Dir[i];
        ++i;
    }

    return rslt;
}

string Get_Folder_Name(string path, int num)
{
    int n = 1;
    string str = "";
    reverse(path.begin(), path.end());

    int i = 0;
    while(true) {
        if((path[i] == '/' || path[i] == '\\') && n >= num)
            break;
        if (path[i] == '/' || path[i] == '\\') {
            ++n;
        }
        str += path[i];
        ++i;
    }
    reverse(str.begin(),str.end());

    return str;
}

vector<path> Get_Folder_Contents(const string& From, bool getFolders, bool getFiles, bool deep)
{
    vector<path> result;

    for(const auto & entry :directory_iterator{From}) {
        if(deep == true && entry.is_directory()) {
            vector<path> temp = Get_Folder_Contents(entry.path().string(), getFolders, getFiles, 1);
            for (int i = 0; i < temp.size(); ++i) {
                result.push_back(To_Comment(temp.at(i)));
            }
        }

        if(entry.is_directory() && getFolders == true) { //is folder
            // cout << "Folder: ";
            // cout << entry.path() << endl;
            result.push_back(To_Comment(entry.path()));
        }

        else if (entry.is_regular_file() && getFiles == true) { //is file
            // cout << "File: ";
            // cout << entry.path() << endl;
            result.push_back(To_Comment(entry.path()));
        }

    }

    return result ;
}

void Create_Folder(const string& destination, const string& folderName)
{
        create_directories(destination + '/' +folderName);
}

void Delete_Folder(const string& Path, bool contentsOnly)
{
    vector<path> contents = Get_Folder_Contents(Path,1, 1, 1);
    vector<path> folders, files;

    // Orgarize The Contents
    for (int i = 0; i < contents.size(); ++i) {
        if (is_directory(contents.at(i))) {
            folders.push_back(contents.at(i));
        }
        else {
            files.push_back(contents.at(i));
        }
        // cout << contents.at(i) << endl;
    }

    // Sorting The Sontents
    sort(files.begin(),files.end());
    sort(folders.begin(),folders.end());
    reverse(folders.begin(), folders.end());

    // Deleting Files
    for (int i = 0; i < files.size(); ++i) {
        // cout << files.at(i) << endl;
        Delete_File(files.at(i).string());
    }

    // Deleting Folders
    for (int i = 0; i < folders.size(); ++i) {
        // cout << folders.at(i) << endl;
        if(rmdir(folders.at(i).string().c_str()) != 0) {
        cout << "Error deleting (" << folders.at(i).string() << ") folder" << endl;
        }
    }

    if (!contentsOnly)
        if(rmdir(Path.c_str()) != 0) {
            cout << "Error deleting the Main folder" << endl;
        }
}

bool Copy_Folder(const string& sourceFolder, const string& destFolder, bool changable) {
    vector<path> contents = Get_Folder_Contents(sourceFolder, 1, 1, 1);
    vector<path> folders, files;
    vector<int>  foldersLength, filesLength;

    // for deleting the same copy if exists
    if (exists(destFolder+'/'+Get_Folder_Name(sourceFolder)) && changable) {
        Delete_Folder(destFolder+'/'+Get_Folder_Name(sourceFolder));
    }

    // Spilite The Contents
    for (int i = 0; i < contents.size(); ++i) {
        if (is_directory(contents.at(i))) {
            folders.push_back(contents.at(i));
        }
        else {
            files.push_back(contents.at(i));
        }
        // cout << contents.at(i) << endl;
    }

    // Sorting The Sontents
    sort(folders.begin(),folders.end());
    sort(files.begin(),files.end());

    // Get The Length
    for (int i = 0; i < folders.size(); ++i) {
        foldersLength.push_back(Chars_Count('/', folders.at(i).string()));
    }
    for (int i = 0; i < files.size(); ++i) {
        filesLength.push_back(Chars_Count('/', files.at(i).string()));
    }

    // Creating All Folders
    for (int i = 0; i < folders.size(); ++i) {
        Create_Folder(destFolder +'/'+ Get_Folder_Name(sourceFolder), Get_Folder_Name(folders.at(i).string() , foldersLength.at(i)-foldersLength.at(0)+1));
        // cout << foldersLength.at(i)-foldersLength.at(0)+1 << endl;
        // cout << folders.at(i) << endl;
    }

    // Creating All Files
    for (int i = 0; i < files.size(); ++i) {
        Create_File(Get_Folder_Name(files.at(i).string() , filesLength.at(i)-filesLength.at(0)+1), "", destFolder +'/'+ Get_Folder_Name(sourceFolder), Get_File_Contents(files.at(i).string()));
        // cout << filesLength.at(i)-filesLength.at(0)+1 << endl;
        // cout << files.at(i) << endl;
    }

    return 1;
}

void Move_Folder(const string& from, const string& to)
{
    Copy_Folder(from, to);
    Delete_Folder(from);
}
