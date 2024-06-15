


#include "player.h"

class Scene {
public:
    virtual void play(Player& player) = 0;
};

class IntroScene : public Scene {
public:
    void play(Player& player) override;
};

class SetupPlayerScene : public Scene {
public:
    void play(Player& player) override;
};

class CrossRoadsScene : public Scene {
public:
    void play(Player& player) override;
};

class ChestScene : public Scene {
public:
    void play(Player& player) override;
};

class BattleScene : public Scene {
public:
    void play(Player& player) override;

private:
    void playerTurn(Player& player, int& enemyHealth);
    void enemyTurn(Player& player);
};



