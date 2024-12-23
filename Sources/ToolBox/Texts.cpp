#include "../../Headers/ToolBox.h"

void Clear() {
    cout << "\x1B[2J\x1B[H";
}

string Bold(const string& text) {
    return "\e[1m" + text + "\e[0m";
}


string Tcolor(const Color color, const string& text){
    string result = "\033[1;3";

    switch (color) {
        case Black:
            result += to_string(Black);
            break;
        case Red:
            result += to_string(Red);
            break;
        case Green:
            result += to_string(Green);
            break;
        case Blue:
            result += to_string(Blue);
            break;
        case Yellow:
            result += to_string(Yellow);
            break;
        case Magenta:
            result += to_string(Magenta);
            break;
        case Cyan:
            result += to_string(Cyan);
            break;
        case White:
            result += to_string(White);
            break;
    }

    return result + "m" + text + "\033[1;0m";
}


string Bcolor(const Color color, const string& text){
    string result = "\033[1;4";

    switch (color) {
        case Black:
            result += to_string(Black);
        break;
        case Red:
            result += to_string(Red);
        break;
        case Green:
            result += to_string(Green);
        break;
        case Blue:
            result += to_string(Blue);
        break;
        case Yellow:
            result += to_string(Yellow);
        break;
        case Magenta:
            result += to_string(Magenta);
        break;
        case Cyan:
            result += to_string(Cyan);
        break;
        case White:
            result += to_string(White);
        break;
    }

    return result + "m" + text + "\033[1;0m";
}


int Chars_Count(const char& chr, const string& text) {
    int result = 0;

    for (int i = 0;i < text.length(); ++i) {
        if (text[i] == chr) {
            ++result;
        }
    }

    return result;
}

int Words_Count(const string& word, const string& text) {
    int tlen = text.length();
    int wlen = word.length();
    int end = tlen - wlen + 1;
    int result = 0;

    for (int i = 0; i < end; ++i) {
        bool wordFound = true;
        for (int j = 0; j < wlen; ++j) {
            if (word[j] != text[i + j]) {
                wordFound = false;
                break;
            }
        }
        wordFound ? ++result : 0;
    }
    return result;
}

int Lines_Count(const string& from, bool fromFile) {
    // from file
    if (fromFile == true) {
        string str = Get_File_Contents(from);
        return Chars_Count('\n',str) + 1;
    }
    // from string
    return Chars_Count('\n',from) + 1;
}

