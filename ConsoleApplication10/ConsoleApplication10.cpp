#include <thread> // pentru a utiliza std::this_thread::sleep_for
#include <chrono> // pentru a specifica durata de întârziere
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Player.h"
#include "Scene.h"
#include "Sound.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); 

   
    std::string playerName;
    std::cout << "Introdu numele jucătorului: ";
    std::cin >> playerName;
    Player player(playerName, "Bine ai venit în aventura noastră!", WIZARD); // Clasa implicită: Wizard
    system("cls");

  
    IntroScene introScene;
    SetupPlayerScene setupPlayerScene;
    CrossRoadsScene crossRoadsScene;
    ChestScene chestScene;
    BattleScene battleScene;


    introScene.play(player);
    PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav"), NULL, SND_LOOP | SND_ASYNC);
    setupPlayerScene.play(player);
    PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav"), NULL, SND_LOOP | SND_ASYNC);
    crossRoadsScene.play(player);
    PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav"), NULL, SND_LOOP | SND_ASYNC);
    chestScene.play(player);
    PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav"), NULL, SND_LOOP | SND_ASYNC);
    battleScene.play(player);
    PlaySound(TEXT("C:/Users/mariu/source/repos/ConsoleApplication10/x64/Debug/Playboicarti Molly Edit by Destxmido Instrumental.wav"), NULL, SND_LOOP | SND_ASYNC);

    return 0;
}
