#include <SFML/Graphics.hpp>
#include <time.h>
#include "addons.h"
#include<fstream>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"
const char title[] = "OOP-Project, Fall-2023";
using namespace sf;

class Game
{
public:

    Sprite background; //Game background sprite
    Texture bg_texture;
    Player* p; //player 
    Enemy * en; //enemy
    Enemy * en1;
    // add other game attributes
    //vector<Box> smallBoxes; // Declare the vector here
    int direction = 1; // Variable to store the direction of movement
    Text levelText; // Text to display the level
    Text highScoreText;//Text to display highscore
    Text livesText; //Text to display available lives
    Text scoreText; // Text to display the current score
    Text Addt; // Text to indicate the new addons which are being dropped 
    //texts for the pause window
    Text mains;//displaying the main pause in the center
    Text rg;//displaying resume game
    Text guides;//dipslaying guides
    Text theend;//displaying the end
    Text hst;
    Sprite Gameover;//sprite for the gameover screen
    Texture Gameot;//texture for the gameover screen
    Sprite winner;//sprite for the winner screen
    Texture wint;//texture for the winner screen
    //Pause pa;
    //int pas;
    Sprite pb; // Pause background sprite
    Texture pt;
    Font font;
    RedRect red_rect[30];
    RedRect* Redrect;
    greencircle *Greencirc;
    orangeHex *orangehex;
    whitetri *Whitetri;
    int highScore;
    bool paused;
    int c_score;
    bool red_rectCollected[30];
    int a_wall_h;
    int a_wall_v;
    int a_wall_hs;
    int a_wall_vs;
    int a_wall_hi;
    int a_wall_vi;
    Sprite wall_v[100];
    Texture wall_vt;
    Sprite wall_h[100];
    Texture wall_ht;
    Sprite wall_vs[100];
    Texture wall_vts;
    Sprite wall_hs[100];
    Texture wall_hts;
    Sprite wallvi[4];
    Texture wall_vti;
    Sprite wallhi[4];
    Texture wall_hti;
    int currentLevel ;  // Start from level 1
    int maxLevels ;     // Set the maximum number of levels
    // Initialize the first level
    
    Clock clk;
    float cordx = 0, cordy = 0;
    float collisionTimer=0.0f;
    Game()
    {
        p =  new Player("img/car1.png");
        en = new Enemy("img/car2.png");
        en1 = new Enemy("img/car2.png");
        Redrect = new RedRect();
        Greencirc = new greencircle();
        Whitetri = new whitetri();
        orangehex = new orangeHex();
        pt.loadFromFile("img/background_1.png");
        font.loadFromFile("Typewriter.ttf");
        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
    
        highScore = 0;
        paused = false;
        c_score = 0;
        p->lives = 3;
    
        a_wall_h = 16;
        a_wall_v = 14;
        a_wall_hs = 4;
        a_wall_vs = 4;
        a_wall_hi = 2;
        a_wall_vi = 4;
        currentLevel = 1;  // Start from level 1
        maxLevels = 4;     // Set the maximum number of levels
        // Initialize the first level
        
        en1->sprite.setPosition(-100, -100);
        cordx = en->sprite.getPosition().x;
        cordy = en->sprite.getPosition().y;
        ifstream highScoreFile("highestcore.txt");
        if (highScoreFile.is_open())
        {
            highScoreFile >> highScore;
            highScoreFile.close();
        }
        highScoreText.setString("High Score: " + std::to_string(highScore));
        livesText.setFont(font);
        livesText.setCharacterSize(24);
        livesText.setFillColor(Color::White);
        livesText.setPosition(670, 10);	// Position below the high total_Score text
        livesText.setString("Lives: " + std::to_string(p->lives));
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(10, 640);
        highScoreText.setFont(font);
        highScoreText.setCharacterSize(24);
        highScoreText.setFillColor(Color::White);
        highScoreText.setPosition(10, 670);	// Position below the total_Score text
        Addt.setFont(font);
        Addt.setCharacterSize(24);
        Addt.setFillColor(Color::White);
        Addt.setPosition(10, 730);	// Position below the lives text
        mains.setFont(font);
        mains.setString("Game Paused");
        mains.setCharacterSize(65);
        mains.setFillColor(Color::White);
        mains.setPosition(200, 200);
        rg.setFont(font);
        rg.setString("   Resume Game");
        rg.setCharacterSize(28);
        rg.setFillColor(Color::Blue);
        rg.setPosition(300, 350);
        guides.setFont(font);
        guides.setString("   Guide");
        guides.setCharacterSize(28);
        guides.setFillColor(Color::White);
        guides.setPosition(350, 450);
        hst.setFont(font);
        hst.setString("   High Score");
        hst.setCharacterSize(28);
        hst.setFillColor(Color::White);
        hst.setPosition(325, 550);
        theend.setFont(font);
        theend.setString("   End Game");
        theend.setCharacterSize(28);
        theend.setFillColor(Color::White);
        theend.setPosition(325, 550);
        Redrect->setter("img/redrect.png");
        Redrect->sprite.setScale(0.010, 0.025);
        Redrect->sprite.setPosition(380, 165);
        orangehex->setter("img/orangehex.png");
        orangehex->sprite.setScale(0.1, 0.1);
	    orangehex->sprite.setPosition(370, 570);
        Greencirc->setter("img/greencirc.png");
        Greencirc->sprite.setScale(0.1, 0.1);
        Greencirc->sprite.setPosition(40, 375);
        Whitetri->setter("img/whitetri.png");
	    Whitetri->sprite.setScale(0.2, 0.2);
        Whitetri->sprite.setPosition(700, 375);
        for (int i = 0; i < 30; i++)
        {
            red_rectCollected[i] = false;
        }
        for (int i = 0; i < 30; i++)
        {
            red_rect[i].setter("img/redrect.png");
            red_rect[i].sprite.setScale(0.010, 0.025);
        }
        wall_ht.loadFromFile("img/wall_h.png");
        for (int i = 0; i < 100; i++)
        {
            wall_h[i].setTexture(wall_ht);
            wall_h[i].setScale(0.5, 0.5);
        }
    
        wall_vt.loadFromFile("img/wall_v.png");
        for (int i = 0; i < 100; i++)
        {
            wall_v[i].setTexture(wall_vt);
            wall_v[i].setScale(0.5, 0.5);
        
        }
        wall_vts.loadFromFile("img/wall_v1.png");
        for (int i = 0; i < 100; i++)
        {
            wall_vs[i].setTexture(wall_vt);
            wall_vs[i].setScale(0.5, 0.2);
        }
        wall_hts.loadFromFile("img/wall_h.png");
        for (int i = 0; i < 100; i++)
        {
            wall_hs[i].setTexture(wall_hts);
            wall_hs[i].setScale(0.4, 0.5);
        }
        wall_hti.loadFromFile("img/wall_h.png");
        for (int i = 0; i < 4; i++)
        {
            wallhi[i].setTexture(wall_hts);
            wallhi[i].setScale(0.4, 0.2);
        }
        wall_vti.loadFromFile("img/wall_v1.png");
        for (int i = 0; i < 4; i++)
        {
            wallvi[i].setTexture(wall_vti);
            wallvi[i].setScale(0.4, 0.2);
        }
     /*   for (int i = 0; i < 30; i++)
        {
            red_rectCollected[i] = false;
        }*/
    }
    //void initializeSmallBoxes()
    //{
    //    // Add code here to initialize small boxes as needed
    //    smallBoxes.emplace_back(29.0f, 300.f, 30.f, 30.f, 1); // Initial direction is 1 (right)
    //    smallBoxes.emplace_back(200.f, 300.f, 30.f, 30.f, 1); // Initial direction is -1 (left) (x,y, x-width of teh box, y width of the box)
    //}
    bool checkCollision(Sprite a, Sprite b)
    {
        return a.getGlobalBounds().intersects(b.getGlobalBounds());
    }
    void load_game()
    {
        ifstream loadFile("saved.txt");
        if (loadFile.is_open())
        {
            loadFile >> c_score;
            scoreText.setString("Score: " + std::to_string(c_score));
            loadFile >> p->lives;
            livesText.setString("Lives: " + std::to_string(p->lives));
            float x, y;
            loadFile >> x >> y;
            p->sprite.setPosition(x, y);
            loadFile.close();
        }
    }
    //highscore updater
    void updateHS()
    {
        if (c_score > highScore)
        {
            highScore = c_score;
            ofstream highScoreFile("highestcore.txt");
            if (highScoreFile.is_open())
            {
                highScoreFile << highScore;
                cout << "hi";
                highScoreFile.close();
            }
            highScoreText.setString("High Score: " + std::to_string(highScore));
        }
    }
    void initializeLevel() {
    
        if  (currentLevel==2)
        {
            
			/*p->lives = 3;*/
            p->move();
            en->sprite.setPosition(30, 567);
            en->move1(p->getRowNo());
            
			Redrect->sprite.setPosition(380, 165);
			orangehex->sprite.setPosition(370, 570);
			Greencirc->sprite.setPosition(40, 375);
			Whitetri->sprite.setPosition(700, 375);
			c_score = 0;
			scoreText.setString("Score: " + std::to_string(c_score));
			livesText.setString("Lives: " + std::to_string(p->lives));
			for (int i = 0; i < 30; i++)
			{
				red_rectCollected[i] = false;
			}
            red_rectspawner();
            addon();
        }
        if (currentLevel == 3) {
            p->move();
			
            en->speed = 0.60;
            en->sprite.setPosition(30,567);
            en->move1(p->getRowNo());
            Redrect->sprite.setPosition(380, 165);
			orangehex->sprite.setPosition(370, 570);
			Greencirc->sprite.setPosition(40, 375);
			Whitetri->sprite.setPosition(700, 375);
			c_score = 0;
			scoreText.setString("Score: " + std::to_string(c_score));
			livesText.setString("Lives: " + std::to_string(p->lives));
			for (int i = 0; i < 30; i++)
			{
				red_rectCollected[i] = false;
			}
			red_rectspawner();
			addon();
        }
        //Level 4: At this level, two opponent cars start chasing the player car in the active mode as in level 2. For this level, the opponent cars should not start at the same location.At the completion of thelevel4, the game finishes after displaying a message, �You won!�.
        if (currentLevel == 4)
        {
            p->move();
            en->speed = 0.75;
            en1->speed = 0.75;
            en->move1(p->getRowNo());
            en1->move(p->getRowNo());
            en->sprite.setPosition(30, 567);
            en1->sprite.setPosition(695, 567);
            Redrect->sprite.setPosition(380, 165);
            orangehex->sprite.setPosition(370, 570);
            Greencirc->sprite.setPosition(40, 375);
            Whitetri->sprite.setPosition(700, 375);
            c_score = 0;
            scoreText.setString("Score: " + std::to_string(c_score));
            livesText.setString("Lives: " + std::to_string(p->lives));
            for (int i = 0; i < 30; i++)
            {
                red_rectCollected[i] = false;
            }
            red_rectspawner();
            addon();
        }
    }
    bool isLevelCompleted() {
        if(c_score == 150)
		{
			return true;
		}
		else
		{
			return false;
		}
    }
    void di()
    {
        Text instructions;
        instructions.setFont(font);
        instructions.setCharacterSize(24);
        instructions.setFillColor(Color::White);
        instructions.setPosition(50, 50);
        instructions.setString("\t\t\t\t\t\t\tRules\n\n\n\n"
            "1. Use the W,A,S and D keys to control your car.\n\n\n"
            "2. Dodge the enemy car.\n\n\n"
            "3. Press 'Esc' to pause the game(while in game)\n\n\n"
            "4. Press 'Esc' to return to the main menu.");
        RenderWindow window(VideoMode(780, 780), "How to operate?", Style::Close);
        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Num4))
            {
                return;
            }
            window.clear();
            window.draw(pb);
            window.draw(instructions);
            window.display();
        }
    }
    void ds()
    {
        ifstream file("highestcore.txt");
        if (!file.is_open())
        {
            cout << "Highscore file couldn't be openened :(" << endl;
        }
        RenderWindow window(VideoMode(780, 780), "Highest Score Even Made?", Style::Close);
        Text  hst;
        Text note;
        hst.setFont(font);
        // hst.setString("Press esc to end");
        hst.setCharacterSize(24);
        hst.setFillColor(Color::White);
        hst.setPosition(150, 280);
        note.setFont(font);
        note.setCharacterSize(24);
        note.setFillColor(Color::Red);
        note.setPosition(100, 730);
        note.setString("Note: Press Esc to return to the main menu.");
        string line;
        string  hs;
        hs = "The highest score ever made is: ";
        while (getline(file, line)) {
            hs += line + "\n";
        }
        hst.setString(hs);
        while (window.isOpen()) {
            Event e;
            while (window.pollEvent(e)) {
                if (e.type == Event::Closed)
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                return;
            }
            window.clear(Color::Black);
            window.draw(pb);
            window.draw(hst);
            window.draw(note);
            window.display();
        }
    }
    void pause_game(RenderWindow& window)
    {
        Game g;
        paused = !paused;
        if (paused)
        {
            RenderWindow pauseWindow(VideoMode(780, 780), "Time is Stopped, you are safe for the mean time", Style::Close);
            while (pauseWindow.isOpen())
            {
                Event e;
                while (pauseWindow.pollEvent(e))
                {
                    if (e.type == Event::KeyPressed && e.key.code == Keyboard::Num1)
                    {
                        pauseWindow.close();
                        paused = !paused;
                    }
                
                    if (e.type == Event::KeyPressed && e.key.code == Keyboard::Num2)
                    {
                        di();
                    }
                    if (e.type == Event::Closed || (e.type == Event::KeyPressed && e.key.code == Keyboard::Num3))
                    {
                        pauseWindow.close();
                        window.close();	// don't close the main window here
                    }
                }
                pauseWindow.clear();
                pauseWindow.draw(pb);
                pauseWindow.draw(mains);
                pauseWindow.draw(rg);
                pauseWindow.draw(guides);
                pauseWindow.draw(theend);
                pauseWindow.display();
            }
        }
    }

    void wallDraw() {
	    //inner wall 1
        wall_h[0].setPosition(110, 480);
        wall_h[14].setPosition(150, 480);
        wall_v[0].setPosition(17, 415);
        wall_v[1].setPosition(17, 200);
       wall_h[1].setPosition(110, 135);
       wall_h[15].setPosition(150, 135);
        wall_v[12].setPosition(600, 415);
       wall_h[10].setPosition(480, 480);
        wall_h[11].setPosition(520, 480);
        wall_v[13].setPosition(600, 200);
        wall_h[12].setPosition(520, 135);
        wall_h[13].setPosition(471, 135);
        //outer wall
        wall_h[2].setPosition(0, 550);
        wall_h[9].setPosition(156, 550);
        wall_v[2].setPosition(-65, 459);
        wall_v[3].setPosition(-65, 415);
        wall_v[4].setPosition(-65, 200);
        wall_v[5].setPosition(-65, 135);
        wall_h[3].setPosition(29, 60);
        wall_h[4].setPosition(156,60);
        wall_v[11].setPosition(-65, 123);
        wall_v[6].setPosition(685, 459);
        wall_v[10].setPosition(685, 415);
        wall_h[5].setPosition(620, 550);
        wall_v[7].setPosition(685, 200);
        wall_v[8].setPosition(685, 135);
        wall_v[9].setPosition(685, 125);
        wall_h[6].setPosition(592, 60);
        wall_h[7].setPosition(466, 60);
       wall_h[8].setPosition(484, 550);
   
        //innter wall 2
        wall_hs[0].setPosition(177, 400);
        wall_vs[0].setPosition(110, 415);
        wall_vs[1].setPosition(110, 295);
        wall_hs[1].setPosition(177, 210);
        wall_hs[2].setPosition(470, 210);
        wall_vs[2].setPosition(502, 295);
	    wall_vs[3].setPosition(502, 415);
        wall_hs[3].setPosition(470, 400);
        //most inner wall
        wallvi[0].setPosition(270, 347);
        wallhi[0].setPosition(325, 320);
        wallvi[1].setPosition(376, 347);
        wallvi[2].setPosition(270, 385);
        wallhi[1].setPosition(325, 382);
        wallvi[3].setPosition(376, 385);
    }
    void addon_spwaner() {
    }
    void red_rectspawner() {
        int temp = 0;
        //left line
    
        for (int i = 0; i < 4; i++)
        {
            if (!red_rectCollected[i])
            red_rect[temp++].sprite.setPosition(40, 560 - i * 120);
        }
        //right line
        for (int i = 0; i < 4; i++)
        {
            if (!red_rectCollected[i])
            red_rect[temp++].sprite.setPosition(700, 560 - i * 120);
        }
        //top line
        for (int i = 0; i < 4; i++)
        {
            if (!red_rectCollected[i])
            red_rect[temp++].sprite.setPosition(90 + i * 190, 160);
        }
        for (int i = 0; i < 4; i++)
        {
            if (!red_rectCollected[i])
            red_rect[temp++].sprite.setPosition(90 + i * 190, 580);
        }
        //inner 1st
        //top
        for (int i = 0; i < 3; i++)
	    {
            if (!red_rectCollected[i])
		    red_rect[temp++].sprite.setPosition(180 + i * 190, 235);
	    }
        //bottom
        for (int i = 0; i < 3; i++) {
            if (!red_rectCollected[i])
    	    red_rect[temp++].sprite.setPosition(180 + i * 190, 505);
        }
        //right
        for (int i = 0; i < 2; i++) {
            if (!red_rectCollected[i])
		    red_rect[temp++].sprite.setPosition(620, 310 + i * 120);
	    }
	    //left
        for (int i = 0; i < 2; i++) {
            if(!red_rectCollected[i])
            red_rect[temp++].sprite.setPosition(130, 310 + i * 120);
        }
        //inner 2nd with red_rect on edges
        for (int i = 0; i < 2; i++)
        {
            if (!red_rectCollected[i])
            red_rect[temp++].sprite.setPosition(250 + i * 250, 320);
        }
        for (int i = 0; i < 2; i++)
	    {
            if (!red_rectCollected[i])
		    red_rect[temp++].sprite.setPosition(250 + i * 250, 420);
	    }
        for (int i = 0; i < 30; i++)
        {
            if (checkCollision(p->sprite, red_rect[i].sprite) && red_rectCollected[i] == false)
            {
                red_rect[i].sprite.setPosition(-100, -100);
                /*if (red_rect[i].sprite.getPosition().x != -100 && red_rect[i].sprite.getPosition().y != -100) {*/
                c_score += 10;
                scoreText.setString("Score: " + std::to_string(c_score));
                red_rectCollected[i] = true;
            }
        }
        // Check collision for each coin
        //for (int i = 0; i < 30; i++) {
        //    if (!red_rectCollected[i] && checkCollision(p->sprite, red_rect[i].sprite)) {
        //        red_rectCollected[i] = true;  // Mark the coin as collected
        //        c_score += 1;
        //        scoreText.setString("Score: " + std::to_string(c_score));
        //    }
        //}
    }
    void addon() {
        if (checkCollision(p->sprite, Redrect->sprite))
        {
            c_score += 10;
            scoreText.setString("Score: " + std::to_string(c_score));
            Redrect->sprite.setPosition(-100, -100);
        }
        if (checkCollision(p->sprite, Greencirc->sprite))
        {
            p->lives += 1;
            c_score += 20;
            scoreText.setString("Score: " + std::to_string(c_score));
            Greencirc->sprite.setPosition(-100, -100);
        }
        if (checkCollision(p->sprite, orangehex->sprite))
        {
            p->updateSpeed();
            c_score += 10;
            scoreText.setString("Score: " + std::to_string(c_score));
            orangehex->sprite.setPosition(-100, -100);
            clk.restart();
            if (clk.getElapsedTime().asSeconds() > 10 && clk.getElapsedTime().asSeconds() < 11) {
                p->resetSpeed();  // Reset player's speed to normal
            }
        }
        if (checkCollision(p->sprite, Whitetri->sprite))
	    {
            {
                cordx= en->sprite.getPosition().x;
                cordy= en->sprite.getPosition().y;
                en->sprite.setPosition(-100, -100);
                clk.restart();
            }
		    Whitetri->sprite.setPosition(-100, -100);
	    }
        if (clk.getElapsedTime().asSeconds() > 10 && clk.getElapsedTime().asSeconds() <11) {
           p->resetSpeed();  // Reset player's speed to normal
            en->sprite.setPosition(cordx, cordy);
          //  en->move(p->getRowNo());
        }
    }
    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock;
        float timer = 0;        
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            //cout<<time<<endl; 
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game                        	    
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)|| Keyboard::isKeyPressed(Keyboard::P))	// Pause/unpause the game if P is pressed
            {
                pause_game(window);
            }
            if (Keyboard::isKeyPressed(Keyboard::L))
            {
                load_game();
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) //If left key is pressed
                p->move("a");    // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::D)) // If right key is pressed
                p->move("d");  //player will move to right
            if (Keyboard::isKeyPressed(Keyboard::W)) //If up key is pressed
                p->move("w");    //playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::S)) // If down key is pressed
                p->move("s");  //player will move downwards
            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            //////////////////////////////////////////////
        
            scoreText.setString("Score: " + std::to_string(c_score));
            updateHS();
            wallDraw();
            red_rectspawner();
            addon();
            collisionTimer -= time;
            if(checkCollision(p->sprite, en->sprite) && collisionTimer <= 0.0f)
		    {
			    p->lives -= 1;
                collisionTimer = 1.0f;
			    livesText.setString("Lives: " + std::to_string(p->lives));
		    }
            if (checkCollision(p->sprite, en1->sprite) && collisionTimer <= 0.0f)
            {
                p->lives -= 1;
                collisionTimer = 1.0f;
                livesText.setString("Lives: " + std::to_string(p->lives));
            }
            if (isLevelCompleted()&&currentLevel<=3)
            {
                currentLevel++;
				cout<<currentLevel<<endl;
                initializeLevel();
            }
            if (currentLevel == 4 && c_score == 150)
            {
            Text won;
				wint.loadFromFile("img/background_1.png");
				winner.setTexture(wint);
				winner.setScale(2, 1.5);
				won.setFont(font);
				won.setCharacterSize(50);
				won.setFillColor(Color::White);
				won.setPosition(250, 320);	// Position the game over text in the middle of the screen
				won.setString("YOU WON:) ");
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
						{
							window.close();
						}
					}
					window.clear();
					window.draw(Gameover);
					window.draw(won);
					window.display();
				}
            }
            if (p->lives <= 0) {
                
                    // Game Over logic goes here
                    Text gameOverText;
                    Gameot.loadFromFile("img/background_1.png");
                    Gameover.setTexture(Gameot);
                    Gameover.setScale(2, 1.5);
                    gameOverText.setFont(font);
                    gameOverText.setCharacterSize(50);
                    gameOverText.setFillColor(Color::White);
                    gameOverText.setPosition(250, 320);	// Position the game over text in the middle of the screen
                    gameOverText.setString("MOYE MOYE:) ");
                    while (window.isOpen())
                    {
                        Event event;
                        while (window.pollEvent(event))
                        {
                            if (event.type == Event::Closed)
                            {
                                window.close();
                            }
                        }
                        window.clear();
                        window.draw(Gameover);
                        window.draw(gameOverText);
                        window.display();
                    }
                }
            
        
            p->move();
            en->move(p->getRowNo());
            window.clear(Color::Black); //clears the screen
            window.draw(background);  // setting background
       
        
            window.draw(p->sprite);
            window.draw(scoreText);
            window.draw(highScoreText);
            window.draw(livesText);
            window.draw(Redrect->sprite);
            window.draw(orangehex->sprite);
            window.draw(Whitetri->sprite);
            window.draw(Greencirc->sprite);
            window.draw(en->sprite);
            window.draw(en1->sprite);
            //for (int i = 0; i < 30; i++)
            //{
            //    if (checkCollision(p->sprite, red_rect[i].sprite))
            //    {
            //        c_score += 10;
            //        scoreText.setString("Score: " + std::to_string(c_score));
            //        red_rect[i].sprite.setPosition(-100, -100);
            //    }
            //}
            for (int i = 0; i < 30; i++) {
                if (red_rectCollected[i] == false) {
                    window.draw(red_rect[i].sprite);
                    red_rect[i].sprite.setPosition(-100, -100);
                }
            }
            
            //for (int i = 0; i < 30; i++)
            //{
            //    window.draw(red_rect[i].sprite);
            //}
            for (int i = 0; i < a_wall_h; i++)
            {
                window.draw(wall_h[i]);
            }
            for (int i = 0; i < a_wall_v; i++)
            {
                window.draw(wall_v[i]);
            }
            for (int i = 0; i < a_wall_vs; i++)
            {
                window.draw(wall_vs[i]);
            }
            for (int i = 0; i < a_wall_hs; i++)
            {
                window.draw(wall_hs[i]);
            }
        
            for (int i = 0; i < a_wall_hi; i++)
            {
                window.draw(wallhi[i]);
            }
            for (int i = 0; i < a_wall_vi; i++)
            {
                window.draw(wallvi[i]);
            }
        
            window.display();  //Displying all the sprites
        }
    }
};