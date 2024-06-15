#include "Sound.h"
#include <windows.h>
#include <iostream>
bool CheckPath(const std::string& path)
{
	std::ifstream f(path.c_str());
	if (f.good())
		return true;
	else
		return false;

}
void playSound(const std::string& soundPath) 
{
	std::string temp = soundPath;
    std::string path = "C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav";
	if (CheckPath(path)) 
	{
		std::cout<<"path ok\n";

		PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav"), NULL, SND_LOOP | SND_ASYNC);
	}/*PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti_Molly_Edit_by_Destxmido_Instrumental.mp3"), NULL, SND_LOOP | SND_ASYNC);*/
}