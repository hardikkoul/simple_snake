#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int i, j, height = 30, width = 30,gameOver, score, x, y, fruitX, fruitY, flag; 

void setup() 
{ 
	gameOver = 0; 

	x = height / 2; 
	y = width / 2; 
label1: 
	fruitX = rand() % 20; 
	if (fruitX == 0) 
		goto label1; 
label2: 
	fruitY = rand() % 20; 
	if (fruitY == 0) 
		goto label2; 
	score = 0; 
} 

void draw() 
{ 
	system("cls"); 
	for (i = 0; i < height; i++) { 
		for (j = 0; j < width; j++) { 
			if (i == 0 || i == width - 1 
				|| j == 0 
				|| j == height - 1) { 
				printf("#"); 
			} 
			else { 
				if (i == x && j == y) 
					printf("0"); 
				else if (i == fruitX 
						&& j == fruitY) 
					printf("*"); 
				else
					printf(" "); 
			} 
		} 
		printf("\n"); 
	} 

	printf("score = %d", score); 
	printf("\n"); 
	printf("press X to quit the game"); 
} 

void input() 
{ 
	if (kbhit()) { 
		switch (getch()) { 
		case 'a': 
			flag = 1; 
			break; 
		case 's': 
			flag = 2; 
			break; 
		case 'd': 
			flag = 3; 
			break; 
		case 'w': 
			flag = 4; 
			break; 
		case 'x': 
			gameOver = 1; 
			break; 
		} 
	} 
} 

void logic() 
{ 
	sleep(0.01); 
	switch (flag) { 
	case 1: 
		y--; 
		break; 
	case 2: 
		x++; 
		break; 
	case 3: 
		y++; 
		break; 
	case 4: 
		x--; 
		break; 
	default: 
		break; 
	} 

	if (x < 0 || x > height 
		|| y < 0 || y > width) 
		gameOver = 1; 

	if (x == fruitX && y == fruitY) { 
	label3: 
		fruitX = rand() % 20; 
		if (fruitX == 0) 
			goto label3; 

	label4: 
		fruitY = rand() % 20; 
		if (fruitY == 0) 
			goto label4; 
		score += 10; 
	} 
} 

void main()
{ 
	int m, n; 

	setup(); 

	while (!gameOver) { 

		draw(); 
		input(); 
		logic(); 
	}

}
