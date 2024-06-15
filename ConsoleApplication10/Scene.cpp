
#include "scene.h"
#include <thread> // pentru a utiliza std::this_thread::sleep_for
#include <chrono> // pentru a specifica durata de întârziere
#include <iostream>
#include <cstdlib>
#include <Windows.h> // Pentru redarea sunetelor


void IntroScene::play(Player& player) {
    std::cout << player.introText << std::endl;
    std::cout << "Ești pregătit să începi jocul? (Da/Nu): ";
    std::string response;
    std::cin >> response;
    if (response == "da" || response == "Da")
    { }
    else
    {
        std::cout << "La revedere!";
        exit(0);
    }
    system("cls");
}

void SetupPlayerScene::play(Player& player) {
    std::cout << "Ce clasă vrei să fii? (0 - Wizard, 1 - Warrior, 2 - Rogue): ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case WIZARD:
        player.characterClass = WIZARD;
        
        break;
    case WARRIOR:
        player.characterClass = WARRIOR;
  
        break;
    case ROGUE:
        player.characterClass = ROGUE;
        
        break;
    default:
        std::cout << "Alegere invalidă. Clasa implicită: Wizard." << std::endl;
        player.characterClass = WIZARD;
       
    }
    
    switch (player.characterClass) {
    case WIZARD:
        std::cout << "Bine ai venit în lumea magiei! Ești gata să-ți începi aventura?\n";
        break;
    case WARRIOR:
        std::cout << "Bine ai venit în lumea războiului! Ești pregătit să-ți începi călătoria?\n";
        break;
    case ROGUE:
        std::cout << "Bine ai venit în lumea furtunii și a umbrelor! Ești pregătit să-ți începi ascensiunea?\n";
        break;
    }
    std::cout << "Ai ales clasa ";
    switch (player.characterClass) {
    case WIZARD:
        std::cout << "Wizard";
        break;
    case WARRIOR:
        std::cout << "Warrior";
        break;
    case ROGUE:
        std::cout << "Rogue";
        break;
    }
    std::cout << " Felicitări, " << player.name << "!" << std::endl;
    system("cls");
}

void CrossRoadsScene::play(Player& player) {
    std::cout << "Te afli la o răscruce de drumuri. Încotro?" << std::endl;
    std::cout << "1. Drumul către pădure - o călătorie în mijlocul naturii, plină de pericole și descoperiri." << std::endl;
    std::cout << "2. Drumul către sat - locul unde poți găsi odihnă și resurse utile pentru călătoria ta." << std::endl;
    std::cout << "3. Drumul către peșteră - o aventură întunecată și periculoasă, dar plină de comori ascunse." << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        std::cout << "Ai ales să mergi spre pădure. Să înceapă aventura!" << std::endl;
        break;
    case 2:
        std::cout << "Ai ales să mergi spre sat. Să vezi ce te așteaptă acolo!" << std::endl;
        break;
    case 3:
        std::cout << "Ai ales să mergi spre peșteră. Fii pregătit pentru provocări!" << std::endl;
        break;
    default:
        std::cout << "Alegere invalidă. Te întorci la răscruce." << std::endl;
   
    }
    system("cls");
}

void ChestScene::play(Player& player) {
    std::cout << "Ai găsit un cufăr! Vrei să-l deschizi? (Da/Nu): ";
    std::string response;
    std::cin >> response;
      if (response == "Nu" || response == "NU" || response == "nU" || response == "nu") {
        std::cout << "Ai ales să nu deschizi cufărul." << std::endl;
        }
    else if ( player.characterClass == WIZARD) {
        std::cout << "Ai primit o bagheta magica,felicitari!!\n";
        }
    else if ( player.characterClass == WARRIOR) {
        std::cout << "Wow, ai primit o sabie cu două lame,felicitari!! \n";
    }
    else if (  player.characterClass == ROGUE) {
        std::cout << "Wow ,ai primit  niște pumnale,felicitaari!!\n";
    }
    else if (response == "Nu"||response == "NU" || response == "nU" || response == "nu"  ) {
        std::cout << "Ai ales să nu deschizi cufărul." << std::endl;
    }
    else {

    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
}

void BattleScene::play(Player& player) {
    std::cout << "Un inamic apare în calea ta!" << std::endl;
    int enemyHealth = rand() % 10 + 5; 
    std::cout << "Inamicul are " << enemyHealth << " puncte de sănătate." << std::endl;
    while (player.health > 0 && enemyHealth > 0) {
        playerTurn(player, enemyHealth);
        if (enemyHealth > 0) {
            enemyTurn(player);
        }
    }
    if (player.health > 0) {
        std::cout << "Ai învins inamicul! Poți continua călătoria." << std::endl;
    }
    else {
        std::cout << "Ai fost învins! Jocul s-a încheiat." << std::endl;
    }
    system("cls");
}


void BattleScene::playerTurn(Player& player, int& enemyHealth) {
    std::cout << "Alege acțiunea: (Tine cont ca ai doar 1 folosire din atacul special) " << std::endl;
    std::cout << "1. Atac normal" << std::endl;
    std::cout << "2. Atac special" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        player.attack(enemyHealth);
        std::cout << "Ai atacat inamicul. Sănătatea inamicului este acum " << enemyHealth << std::endl;
        break;
    case 2:
        player.specialAttack(enemyHealth);
        std::cout << "Ai folosit atacul special împotriva inamicului. Sănătatea inamicului este acum " << enemyHealth << std::endl;
        break;
    default:
        std::cout << "Acțiune invalidă. Alegere implicită: atac normal." << std::endl;
        player.attack(enemyHealth);
        std::cout << "Ai atacat inamicul. Sănătatea inamicului este acum " << enemyHealth << std::endl;

    }
    
}


void BattleScene::enemyTurn(Player& player) {
    int attackType = rand() % 2; 
    switch (attackType) {
    case 0:
        std::cout << "Inamicul te atacă cu un atac normal." << std::endl;
        player.health -= 2; 
        std::cout << "Sănătatea ta este acum " << player.health << std::endl;
        break;
    case 1:
        std::cout << "Inamicul folosește un atac special." << std::endl;
        player.health -= std::rand() % 3 + 2; 
        std::cout << "Sănătatea ta este acum " << player.health << std::endl;
        break;
    }
    
}