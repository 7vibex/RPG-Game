#ifndef SOUND_H
#define SOUND_H
#include<fstream>
#include <string>
bool CheckPath(const std::string& path);

void playSound(const std::string& soundPath);

#endif 