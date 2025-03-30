#include <SFML/Graphics.hpp>
#include<string.h>
using namespace std;
using namespace sf;
class Player {
public:
	int rowNo;
	Texture tex;
	Sprite sprite;
	float speed = 0.5;
	int x, y;
	int lives;
	float speedMultiplier; // Member variable to store the speed multiplier
	sf::Clock speedTimer;  // Clock to track the time elapsed since speed increase

	Player() {
		x = 0; y = 0; rowNo = 3;
	}
	int getRowNo() const {
		return rowNo;
	}
	Player(std::string png_path)
	{
		rowNo = 3;
		x = 0;
		y = 0;
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 330; y = 154;      //initial position of sprite
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);
	}

	void resetSpeed()
	{
		speedMultiplier = 1.0f;
		speedTimer.restart(); // Restart the speed timer
	}

	void speedUp()
	{
		// Increase the speed multiplier
		speed *= 1.5;
		//cout << "kek";
		// Restart the speed timer
		speedTimer.restart();
	}

	void updateSpeed()
	{
		// Check if the elapsed time since speed increase is greater than 10 seconds
		if (speedTimer.getElapsedTime().asSeconds() < 10.0f)
		{
			// Reset the speed to normal if more than 10 seconds have passed
			speedUp();
		}

		if (speedTimer.getElapsedTime().asSeconds() > 10.0f)
		{
			// Reset the speed to normal if more than 10 seconds have passed
			resetSpeed();
		}
	}

	void move(string s) {
		bool condition = true;
		float delta_x = 0, delta_y = 0;
		if (s == "a") {
			//Movement between walls when user presses a
			//delta_x -= 1;

			//movement from 3rd road to 2nd road from right
			if (rowNo == 3 && int(sprite.getPosition().x) == 695 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 391);
				rowNo = 2;
				condition = false;
			}
			//movement from 2nd road to 1st road from right

			else if (rowNo == 2 && int(sprite.getPosition().x) == 604 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(491, 391);
				rowNo = 1;
				condition = false;
			}
			//movement from 1st road to 2nd road from right

			else if (rowNo == 1 && int(sprite.getPosition().x) == 231 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 335);
				rowNo = 2;
				condition = false;
			}
			//movement from 2nd road to 3rd road from right

			else if (rowNo == 2 && int(sprite.getPosition().x) == 123 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(30, 335);
				rowNo = 3;
				condition = false;
			}

		}
		if (s == "d") {
			//Movement between walls when user presses d

			//cout << sprite.getPosition().x << ", " << sprite.getPosition().y << "\n";

			//delta_x += 1;
			//movement from 3rd road to 2nd road from left

			if (rowNo == 3 && int(sprite.getPosition().x) == 30 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 335);
				rowNo = 2;
				condition = false;
			}

			//movement from 2nd road to 1st road from left

			else if (rowNo == 2 && int(sprite.getPosition().x) == 123 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(231, 335);
				rowNo = 1;
				condition = false;
			}

			//movement from 1st road to 2nd road from left

			else if (rowNo == 1 && int(sprite.getPosition().x) == 491 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 391);
				rowNo = 2;
				condition = false;
			}

			//movement from 2nd road to 3rd road from left

			else if (rowNo == 2 && int(sprite.getPosition().x) == 604 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(695, 391);
				rowNo = 3;
				condition = false;
			}
			/*if (sprite.getPosition().x > 750)
			{
				sprite.setPosition(750, sprite.getPosition().y);
			}*/
		}
		else if (s == "s") {
			//Movement between walls when user presses s
			//cout << sprite.getPosition().x << ", " << sprite.getPosition().y << "\n";
			//delta_y = 1;

			//movement from 3rd road to 2nd road from below

			if (rowNo == 3 && int(sprite.getPosition().y) == 154 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 225);
				rowNo = 2;
				condition = false;
			}

			//movement from 2nd road to 1st road from below

			else if (condition == true && rowNo == 2 && int(sprite.getPosition().y) == 225 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(360, 296);
				rowNo = 1;
				condition = false;
			}

			//movement from 2nd road to 3rd road from below

			else if (condition == true && rowNo == 2 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(360, 567);
				rowNo = 3;
				condition = false;
			}
			//movement from 1st road to 2nd road from below

			else if (condition == true && rowNo == 1 && int(sprite.getPosition().y) == 414 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 492);
				rowNo = 2;
				condition = false;
			}
			/*if (sprite.getPosition().y > 750)
			{
				sprite.setPosition(sprite.getPosition().x, 750);

			}*/
		}

		else if (s == "w") {
			//Movement between walls when user presses w

			//delta_y = -1;
			//movement from 3rd road to 2nd road from above

			//cout << sprite.getPosition().x << ", " << sprite.getPosition().y << "\n";

			if (rowNo == 3 && int(sprite.getPosition().y) == 567 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 492);
				rowNo = 2;
			}


			//movement from 2nd road to 3rd road from above

			else if (rowNo == 2 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(360, 414);
				rowNo = 1;
			}
			//movement from 2nd road to 3rd road from above

			else if (rowNo == 2 && int(sprite.getPosition().y) == 225 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(366, 154);
				rowNo = 3;
			}
			//movement from 1st road to 2nd road from below

			else if (rowNo == 1 && int(sprite.getPosition().y) == 296 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 225);
				rowNo = 2;
			}
		}

		delta_x *= speed;
		delta_y *= speed;
		sprite.move(delta_x, delta_y);
	}
	void move() {
		float delta_x = 0, delta_y = 0;

		//player movement, player goes clockwise

		//bottom row
		if (int(sprite.getPosition().y) == 567 && int(sprite.getPosition().x) > 30 && rowNo == 3) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}
		//leftmost column
		if (int(sprite.getPosition().y) > 154 && int(sprite.getPosition().x) == 30 && rowNo == 3) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		////top row

		if (int(sprite.getPosition().y) == 154 && int(sprite.getPosition().x) < 330 && rowNo == 3) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}
		//top row
		if (int(sprite.getPosition().y) == 154 && int(sprite.getPosition().x) < 695 && rowNo == 3) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////rightmost column

		if (int(sprite.getPosition().y) < 567 && int(sprite.getPosition().x) == 695 && rowNo == 3) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////bottom row

		if (int(sprite.getPosition().y) == 567 && int(sprite.getPosition().x) > 330 && rowNo == 3) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//middle row

		if (int(sprite.getPosition().y) == 225 && int(sprite.getPosition().x) < 604 && rowNo == 2) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//right middle  column
		if (int(sprite.getPosition().y) < 492 && int(sprite.getPosition().x) == 604 && rowNo == 2) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//bottom middle row
		if (int(sprite.getPosition().y) == 492 && int(sprite.getPosition().x) >= 367 && rowNo == 2) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//bottom middle row
		if (int(sprite.getPosition().y) == 492 && int(sprite.getPosition().x) > 123 && rowNo == 2) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//right middle row
		if (int(sprite.getPosition().x) == 123 && int(sprite.getPosition().y) > 225 && rowNo == 2) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//top middle row
		if (int(sprite.getPosition().x) < 366 && int(sprite.getPosition().y) == 225 && rowNo == 2) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////top innermost row
		if (int(sprite.getPosition().x) < 491 && int(sprite.getPosition().y) == 296 && rowNo == 1) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//right innermost column 
		if (int(sprite.getPosition().x) == 491 && int(sprite.getPosition().y) < 414 && rowNo == 1) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}



		//bottom innermost row
		if (int(sprite.getPosition().x) > 360 && int(sprite.getPosition().y) == 414 && rowNo == 1) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//bottom innermost row
		if (int(sprite.getPosition().x) > 231 && int(sprite.getPosition().y) == 414 && rowNo == 1) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//left innermost column
		if ((int(sprite.getPosition().x) == 229 || int(sprite.getPosition().x) == 231 || int(sprite.getPosition().x) == 230) && int(sprite.getPosition().y) > 296 && rowNo == 1) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//top innermost row
		if (int(sprite.getPosition().x) <= 360 && int(sprite.getPosition().y) == 296 && rowNo == 1) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);

	}

};
