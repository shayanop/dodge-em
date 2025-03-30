#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<string.h>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace sf;
class Enemy : public Player {
public:

	int level = 1;
	int modifiedRowNo = getRowNo();
	int EnemyrowNo = 3;
	Texture tex;
	Sprite sprite;
	float speed = 0.5;
	int x, y;
	int lives;

	Enemy(std::string png_path)
	{

		x = 0;
		y = 0;
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		srand(time(0));

		// initial random position of enemy 
		int random = rand() % 2 + 1;
		if (random == 1) {
			x = 695; y = 567;
		}
		else {
			x = 30; y = 567;
		}
		sprite.setPosition(x, y);
		sprite.setScale(0.5, 0.5);

	}


	void move(int rowNo) {
		float delta_x = 0, delta_y = 0;
		//Enemy will follow player sprite

		if (rowNo == 2) {
			//Enemy movement from 3rd road to 2nd road 
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 30 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 154 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(299, 225);
			// 	EnemyrowNo = 2;
			// }
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 695 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 567 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(433, 492);
			// 	EnemyrowNo = 2;
			// }

			//Enemy movement from 1st road to 2nd road


			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 231 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 296 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(299, 225);
			// 	EnemyrowNo = 2;
			// }
			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 491 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(433, 567);
			// 	EnemyrowNo = 2;
			// }
		}
		//If player is at 3rd road and enemy is at 1st road, Enemy moves from 1st road to 2nd road before moving to 3rd road 
		if (EnemyrowNo == 1 && rowNo == 3) {
			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 231 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 296 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(299, 225);
			// 	EnemyrowNo = 2;
			// }
			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 491 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(433, 567);
			// 	EnemyrowNo = 2;
			// }

		}
		//If player is at 1st road and enemy is at 3rd road, Enemy moves from 3rd road to 2nd road before moving to 1st road 

		if (EnemyrowNo == 3 && rowNo == 1) {
			//Enemy movement from 3rd road to 2nd road
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 30 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 154 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(299, 225);
			// 	EnemyrowNo = 2;
			// }
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 695 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			// if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 567 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(433, 492);
			// 	EnemyrowNo = 2;
			// }

		}
		if (rowNo == 1) {
			//Enemy movement from 2nd road to 1st road

			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 123 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(231, 391);
				EnemyrowNo = 1;
			}
			// if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 225 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(299, 296);
			// 	EnemyrowNo = 1;
			// }
			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 604 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(491, 335);
				EnemyrowNo = 1;
			}
			// if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(433, 414);
			// 	EnemyrowNo = 1;
			// }
		}
		if (rowNo == 3) {
			//Enemy movement from 2nd road to 3rd road

			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 123 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(30, 391);
				EnemyrowNo = 3;
			}
			// if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 225 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(299, 154);
			// 	EnemyrowNo = 3;
			// }
			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 604 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(695, 335);
				EnemyrowNo = 3;
			}
			// if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
			// 	sprite.setPosition(433, 567);

			// 	EnemyrowNo = 3;
			// }
		}

		//bottom row, enemy moves counter clockwise
		if (int(sprite.getPosition().y) == 567 && int(sprite.getPosition().x) < 695 && EnemyrowNo == 3) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
			//modifiedRowNo = 3;
		}
		//righmost column
		if (int(sprite.getPosition().y) > 154 && int(sprite.getPosition().x) == 695 && EnemyrowNo == 3) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////top row

		if (int(sprite.getPosition().y) == 154 && int(sprite.getPosition().x) > 330 && EnemyrowNo == 3) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		if (int(sprite.getPosition().y) == 154 && int(sprite.getPosition().x) > 30 && EnemyrowNo == 3) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////left column

		if (int(sprite.getPosition().y) < 567 && int(sprite.getPosition().x) == 30 && EnemyrowNo == 3) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////bottom row

		if (int(sprite.getPosition().y) == 567 && int(sprite.getPosition().x) < 330 && EnemyrowNo == 3) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}




		//top middle column



		if (int(sprite.getPosition().y) == 225 && int(sprite.getPosition().x) > 123 && EnemyrowNo == 2) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//left middle row
		if (int(sprite.getPosition().y) < 492 && int(sprite.getPosition().x) == 123 && EnemyrowNo == 2) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//down middle row
		if (int(sprite.getPosition().y) == 492 && int(sprite.getPosition().x) <= 604 && EnemyrowNo == 2) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//right middle row
		if (int(sprite.getPosition().y) >= 225 && int(sprite.getPosition().x) == 604 && EnemyrowNo == 2) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//top middle row
		if (int(sprite.getPosition().x) >= 330 && int(sprite.getPosition().y) == 225 && EnemyrowNo == 2) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//Top 1st row
		if (int(sprite.getPosition().x) >= 231 && int(sprite.getPosition().y) == 296 && EnemyrowNo == 1) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////left row 1
		if (int(sprite.getPosition().x) == 231 && int(sprite.getPosition().y) < 414 && EnemyrowNo == 1) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//bottom row 1
		if (int(sprite.getPosition().y) == 414 && int(sprite.getPosition().x) < 491 && EnemyrowNo == 1) {

			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}



		//right row 1
		if (int(sprite.getPosition().x) == 491 && int(sprite.getPosition().y) > 296 && EnemyrowNo == 1) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//top row 1
		if (int(sprite.getPosition().x) > 330 && int(sprite.getPosition().y) == 296 && EnemyrowNo == 1) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);

	}




	void move1(int rowNo) {
		float delta_x = 0, delta_y = 0;
		//Enemy will follow player sprite

		if (rowNo == 2) {
			//Enemy movement from 3rd road to 2nd road 
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 30 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 154 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 225);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 695 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 567 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 492);
				EnemyrowNo = 2;
			}

			//Enemy movement from 1st road to 2nd road


			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 231 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 296 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 225);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 491 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 567);
				EnemyrowNo = 2;
			}
		}
		//If player is at 3rd road and enemy is at 1st road, Enemy moves from 1st road to 2nd road before moving to 3rd road 
		if (EnemyrowNo == 1 && rowNo == 3) {
			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 231 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 296 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 225);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 1 && int(sprite.getPosition().x) == 491 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 1 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 567);
				EnemyrowNo = 2;
			}

		}
		//If player is at 1st road and enemy is at 3rd road, Enemy moves from 3rd road to 2nd road before moving to 1st road 

		if (EnemyrowNo == 3 && rowNo == 1) {
			//Enemy movement from 3rd road to 2nd road
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 30 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(123, 391);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 154 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 225);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 3 && int(sprite.getPosition().x) == 695 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(604, 335);
				EnemyrowNo = 2;
			}
			if (EnemyrowNo == 3 && int(sprite.getPosition().y) == 567 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 492);
				EnemyrowNo = 2;
			}

		}
		if (rowNo == 1) {
			//Enemy movement from 2nd road to 1st road

			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 123 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(231, 391);
				EnemyrowNo = 1;
			}
			if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 225 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 296);
				EnemyrowNo = 1;
			}
			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 604 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(491, 335);
				EnemyrowNo = 1;
			}
			if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 414);
				EnemyrowNo = 1;
			}
		}
		if (rowNo == 3) {
			//Enemy movement from 2nd road to 3rd road

			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 123 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(30, 391);
				EnemyrowNo = 3;
			}
			if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 225 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(299, 154);
				EnemyrowNo = 3;
			}
			if (EnemyrowNo == 2 && int(sprite.getPosition().x) == 604 && (int(sprite.getPosition().y) >= 336 && int(sprite.getPosition().y <= 390))) {
				sprite.setPosition(695, 335);
				EnemyrowNo = 3;
			}
			if (EnemyrowNo == 2 && int(sprite.getPosition().y) == 492 && (int(sprite.getPosition().x) >= 300 && int(sprite.getPosition().x <= 432))) {
				sprite.setPosition(433, 567);

				EnemyrowNo = 3;
			}
		}

		//bottom row, enemy moves counter clockwise
		if (int(sprite.getPosition().y) == 567 && int(sprite.getPosition().x) < 695 && EnemyrowNo == 3) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
			//modifiedRowNo = 3;
		}
		//righmost column
		if (int(sprite.getPosition().y) > 154 && int(sprite.getPosition().x) == 695 && EnemyrowNo == 3) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////top row

		if (int(sprite.getPosition().y) == 154 && int(sprite.getPosition().x) > 330 && EnemyrowNo == 3) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		if (int(sprite.getPosition().y) == 154 && int(sprite.getPosition().x) > 30 && EnemyrowNo == 3) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////left column

		if (int(sprite.getPosition().y) < 567 && int(sprite.getPosition().x) == 30 && EnemyrowNo == 3) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////bottom row

		if (int(sprite.getPosition().y) == 567 && int(sprite.getPosition().x) < 330 && EnemyrowNo == 3) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_l.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}




		//top middle column



		if (int(sprite.getPosition().y) == 225 && int(sprite.getPosition().x) > 123 && EnemyrowNo == 2) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//left middle row
		if (int(sprite.getPosition().y) < 492 && int(sprite.getPosition().x) == 123 && EnemyrowNo == 2) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//down middle row
		if (int(sprite.getPosition().y) == 492 && int(sprite.getPosition().x) <= 604 && EnemyrowNo == 2) {
			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//right middle row
		if (int(sprite.getPosition().y) >= 225 && int(sprite.getPosition().x) == 604 && EnemyrowNo == 2) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_d.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}


		//top middle row
		if (int(sprite.getPosition().x) >= 330 && int(sprite.getPosition().y) == 225 && EnemyrowNo == 2) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//Top 1st row
		if (int(sprite.getPosition().x) >= 231 && int(sprite.getPosition().y) == 296 && EnemyrowNo == 1) {
			delta_x = -1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		////left row 1
		if (int(sprite.getPosition().x) == 231 && int(sprite.getPosition().y) < 414 && EnemyrowNo == 1) {
			delta_x = 0;
			delta_y = +1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//bottom row 1
		if (int(sprite.getPosition().y) == 414 && int(sprite.getPosition().x) < 491 && EnemyrowNo == 1) {

			delta_x = +1;
			delta_y = 0;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}



		//right row 1
		if (int(sprite.getPosition().x) == 491 && int(sprite.getPosition().y) > 296 && EnemyrowNo == 1) {
			delta_x = 0;
			delta_y = -1;
			tex.loadFromFile("img/car_r.png");
			sprite.setTexture(tex);
			sprite.setScale(0.6, 0.4);
		}

		//top row 1
		if (int(sprite.getPosition().x) > 330 && int(sprite.getPosition().y) == 296 && EnemyrowNo == 1) {
			delta_x = -1;
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
