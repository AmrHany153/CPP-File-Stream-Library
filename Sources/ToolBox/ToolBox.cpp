#include "../../Headers/ToolBox.h"

void Run(const string& path) { // done
    // _chdir("C:/Program Files/VideoLAN/VLC");
    system(path.c_str());
}

void Shutdown(int time, TimeType timeType) { // done

    switch (timeType) {
        case Minutes:
            time *= Minutes;
        break;
        case Hours:
            time *= Hours;
        break;
    }

    sleep(time);
    system("c:\\WINDOWS\\System32\\shutdown /s /f");
}

void Restart(int time, TimeType timeType) { // done
    string test = "hi";
    switch (timeType) {
        case Minutes:
            time *= Minutes;
            break;
        case Hours:
            time *= Hours;
            break;
    }

    sleep(time);
    system("c:\\WINDOWS\\System32\\shutdown /r /f");
}

path To_Comment(path dir) { // done
    const string str = dir.string();
    string result = "";
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == '\\')
            result += '/';

        else
            result += str[i];
    }
    path pth= result;
    return pth;
}

path To_Back_Slash(path dir) { // done
    const string str = dir.string();
    string result = "";
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == '/')
            result += '\\';

        else
            result += str[i];
    }
    path pth= result;
    return pth;
}

void Play_Sound(const string& sourceFile) { // underworking
    char audiofile_char[] = "C:/Users/Administrator/Desktop/correct.wav";
    string audiofile_str;
    fstream fp;
    fp.open(audiofile_char, ios::in);
    audiofile_str = audiofile_char;
    // Play_Sound(audiofile_str.c_str(),NULL,SND_SYNC);
    fp.close();
}

