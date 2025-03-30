#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Addons{
public:
	Texture t1;
	Sprite sprite;
	
	int posX, posY;

	virtual void setter(string s) = 0; 

};

class RedRect : public Addons {
public:
	void setter(string s) {
		t1.loadFromFile(s);
		sprite.setTexture(t1);
		sprite.setScale(0.04, 0.04);
	}
};

class orangeHex: public Addons {
public:
	void setter(string s) {
		t1.loadFromFile(s);
		sprite.setTexture(t1);
		sprite.setScale(0.1, 0.1);
	}
};

class greencircle : public Addons {
public:
	void setter(string s) {
		t1.loadFromFile(s);
		sprite.setTexture(t1);
		sprite.setScale(0.1, 0.1);
	}
};

class whitetri : public Addons {
public:
	void setter(string s) {
		t1.loadFromFile(s);
		sprite.setTexture(t1);
		sprite.setScale(0.1, 0.1);
	}
};
//for (auto& smallBox : smallBoxes)
//{
//    // Adjust the movement speed
//    float speed = 0.5f;

//    // Move the box
//    smallBox.move(speed, 0.5f);

//    // Check if the box reached the right or left boundary
//    if (smallBox.shape.getPosition().x + smallBox.shape.getSize().x > window.getSize().x ||
//        smallBox.shape.getPosition().x < 0 || smallBox.shape.getPosition().y + smallBox.shape.getSize().y > window.getSize().y ||
//        smallBox.shape.getPosition().y < 0)
//    {
//        // Reflect the direction if the box reached the boundary
//        smallBox.direction = -smallBox.direction;
//    }

//    // Continue movement
//    for (int i = 0; i < 20; i++)
//    {
//        if (smallBox.shape.getGlobalBounds().intersects(wall_h[i].getGlobalBounds()) ||
//            smallBox.shape.getGlobalBounds().intersects(wall_v[i].getGlobalBounds()) ||
//            smallBox.shape.getGlobalBounds().intersects(wall_vs[i].getGlobalBounds()) ||
//            smallBox.shape.getGlobalBounds().intersects(wall_hs[i].getGlobalBounds()))
//        {
//            // Adjust box movement based on collision direction
//            if (smallBox.shape.getPosition().x + smallBox.shape.getSize().x > wall_h[i].getPosition().x &&
//                smallBox.shape.getPosition().x < wall_h[i].getPosition().x) {
//                // Box collided from the left
//                smallBox.direction = -smallBox.direction;
//            }
//            else if (smallBox.shape.getPosition().x < wall_h[i].getPosition().x + wall_h[i].getGlobalBounds().width &&
//                smallBox.shape.getPosition().x + smallBox.shape.getSize().x > wall_h[i].getPosition().x + wall_h[i].getGlobalBounds().width) {
//                // Box collided from the right
//                smallBox.direction = -smallBox.direction;
//            }

//            if (smallBox.shape.getPosition().y + smallBox.shape.getSize().y > wall_h[i].getPosition().y &&
//                smallBox.shape.getPosition().y < wall_h[i].getPosition().y) {
//                // Box collided from the top
//                smallBox.direction = -smallBox.direction;
//            }
//            else if (smallBox.shape.getPosition().y < wall_h[i].getPosition().y + wall_h[i].getGlobalBounds().height &&
//                smallBox.shape.getPosition().y + smallBox.shape.getSize().y > wall_h[i].getPosition().y + wall_h[i].getGlobalBounds().height) {
//                // Box collided from the bottom
//                smallBox.direction = -smallBox.direction;
//            }
//        }
//    }

//    // Continue box movement
//    smallBox.shape.move(speed * smallBox.direction, speed * smallBox.direction);

//    window.draw(smallBox.shape);
//}

				//for (int i = 0; i < 30; i++)
				//{
				//    window.draw(red_rect[i].sprite);
				//}