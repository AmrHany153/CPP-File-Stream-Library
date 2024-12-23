#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <unistd.h>
#include <regex>
#include <cstdio>

#define T
#define b Bold
#define tc Tcolor
#define bc Bcolor
#define tcb Tcolor(Blue,
#define tcr Tcolor(Red,
#define tcg Tcolor(Green,
#define tcy Tcolor(Yellow,
#define tb Bcolor

using namespace std::filesystem;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios;
using std::to_string;


enum Color {
    Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
};
enum TimeType {
    Seconds = 1, Minutes = 60, Hours = 60*60
};


// Global Tools
void Run(const string& path);
void Shutdown(int time, TimeType timeType);
void Restart(int time, TimeType timeType);
path To_Comment(path dir);
path To_Back_Slash(path dir);
void Play_Sound(const string& sourceFile);

// Texts Tools
void Clear();
string Bold(const string& text);
string Tcolor(Color color, const string& text);
string Bcolor(Color color, const string& text);
int Chars_Count(const char& chr, const string& text);
int Words_Count(const string& word, const string& text);
int Lines_Count(const string& from, bool fromFile);

// Folders Tools
string Current_Folder();
string Get_Folder_Name(string path, int num = 1);
vector<path> Get_Folder_Contents(const string& From, bool getFolders, bool getFiles, bool deep);
void Create_Folder(const string& destination, const string& folderName);
void Delete_Folder(const string& Path, bool contentsOnly = false);
bool Copy_Folder(const string& sourceFolder, const string& destFolder, bool changable = false);
void Move_Folder(const string& from, const string& to);

// Files Tools
string Get_File_Contents(const string& from);
string Get_File_Line(const string& from, int lineNum);
void Create_File(const string& name, const string& extension, const string& destination, const string& content);
void Create_File(const string& name, const string& extension, const string& destination, const path& content);
void Delete_File(const string& path);
bool Copy_File(const string& sourceFile, const string& destFile, bool changable = false);
void Move_File(const string& sourceFile, const string& destFile);

#endif //TOOLS_H
