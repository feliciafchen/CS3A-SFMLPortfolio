#include "SFML/Graphics.hpp"
#include "ShootaGame.h"
#include "GreenCircle.h"
#include "PongGame.h"
#include "BouncingBall.h"
#include "PlayingCard.h"
#include "PokerAnalysis.h"
#include "Screen.h"
#include "Games.h"

int main()
{
    srand(time(nullptr));

    sf::RenderWindow window({2560, 1600, 32}, "Felicia Chen PORTFOLIO");
    window.setFramerateLimit(60);

    Arrows arrows(window);

    ListItem back("back", {250, 100});
    back.enableState(HIDDEN);

    ShootaGame shootaGame(window);
    Screen shootaScreen("party poopers!", window);

    GreenCircle greenCircle;
    Screen greenCircleScreen("green circle", window);

    PongGame pongGame(window);
    Screen pongScreen("pong", window);

    BouncingBall bouncingBall;
    Screen bouncingBallScreen("bouncing ball", window);

    PlayingCard playingCard;
    Screen playingCardScreen("playing card", window);

    PokerAnalysis pokerAnalysis(window);
    Screen pokerAnalysisScreen("poker analysis", window);

    std::vector<Screen> screens;
    screens.push_back(greenCircleScreen);
    screens.push_back(pongScreen);
    screens.push_back(bouncingBallScreen);
    screens.push_back(playingCardScreen);
    screens.push_back(pokerAnalysisScreen);
    screens.push_back(shootaScreen);

    int iter = 0;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            shootaGame.eventHandler(window, event);
            back.eventHandler(window, event);

            screens[iter].eventHandler(window, event);

            if(!back.checkState(HIDDEN) && back.isClick(window))
            {
                shootaGame.enableState(HIDDEN);
                greenCircle.enableState(HIDDEN);
                pongGame.enableState(HIDDEN);
                bouncingBall.enableState(HIDDEN);
                playingCard.enableState(HIDDEN);
                pokerAnalysis.enableState(HIDDEN);
                screens[iter].disableState(HIDDEN);
                back.enableState(HIDDEN);
                arrows.disableState(HIDDEN);
            }

            if(screens[iter].isClick(window) && iter == 5)
            {
                shootaGame.disableState(HIDDEN);
                screens[iter].enableState(HIDDEN);
                back.disableState(HIDDEN);
                arrows.enableState(HIDDEN);
            }
            else if(screens[iter].isClick(window) && iter == 0)
            {
                greenCircle.disableState(HIDDEN);
                screens[iter].enableState(HIDDEN);
                back.disableState(HIDDEN);
                arrows.enableState(HIDDEN);

            }
            if(screens[iter].isClick(window) && iter == 1)
            {
                pongGame.disableState(HIDDEN);
                screens[iter].enableState(HIDDEN);
                back.disableState(HIDDEN);
                arrows.enableState(HIDDEN);
            }
            if(screens[iter].isClick(window) && iter == 2)
            {
                bouncingBall.disableState(HIDDEN);
                screens[iter].enableState(HIDDEN);
                back.disableState(HIDDEN);
                arrows.enableState(HIDDEN);
            }
            if(screens[iter].isClick(window) && iter == 3)
            {
                playingCard.disableState(HIDDEN);
                screens[iter].enableState(HIDDEN);
                back.disableState(HIDDEN);
                arrows.enableState(HIDDEN);
            }
            if(screens[iter].isClick(window) && iter == 4)
            {
                pokerAnalysis.disableState(HIDDEN);
                screens[iter].enableState(HIDDEN);
                back.disableState(HIDDEN);
                arrows.enableState(HIDDEN);
            }

            if(arrows.leftIsClicked(window))
            {
                if(iter != 0)
                    --iter;
            }
            if(arrows.rightIsClicked(window))
            {
                if(iter != 5)
                    ++iter;
            }

        }

        window.clear();

        arrows.update(window);
        shootaGame.update(window);
        greenCircle.update(window);
        pongGame.update(window);
        bouncingBall.update(window);
        playingCard.update(window);
        pokerAnalysis.update(window);

        if(!back.checkState(HIDDEN))
        {
            window.draw(back);
        }
        if(!screens[iter].checkState(HIDDEN))
            window.draw(screens[iter]);

        window.display();
    }

    return 0;
}