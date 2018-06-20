#include <QGuiApplication>
#include "src/Rendering/Window3D.h"
#include "src/Game.h"


int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.SetBackgroundColor(Qt::black);

	Game myGame(wnd);
	myGame.Go();

	return a.exec();
}

// Notes : 
/*
	main wind/screen :
		light
		camera
		background color
		mouse input event capture
		Key input event capture
	Game :
		game(window)
		game go
		composeFrame for game logic
		updateModel for the main game Update

	Just for giggles made a custom aspect - for FPS !!!!!!! - lol.
	- its setup in Window3D Initialize and used (badly i may say) 
	in Graphics.cpp UpdateGraphics() - relocated to GameLogic..
	it works and does not interfere with 3D rendering - Nice !
	- so ho humm onwards :

	Ray Cast Object Picking for a 3D menu. Tested in UpdateGraphics
	works a charm - only after the first movement instruction to the renderer.
	so carefull with this.
	Had to add a small light movement to the Right mouse click to make it work
	properly as the game starts up.

	when mouse hovers over player - it changes colour.

	Make boundaries for movement.

	MoveSnake:
		files setup 
		borders and border collision added.
		setup snake movement and the Left/Right key control
		a totaly diffrent move and controll system.
		Left Arrow and Right Arrow to turn Snake.

	Seperate game logic out of gfx 
		this will help out when developing furthur.
		its allways good practice to keep logic and graphics apart.

	MoveSnake :: FinalMove has the test implimented.
		each segment of the snake has to follow the next segment
		starting from the tail and working up to the head.

		Player needs to Grow and track direction of movement for each segment.
		so store position and direction for each segment - then starting from the back
		each segment takes the movement from the one in front with the player controlling
		input for the Head. use an array of segments to complete this task.

	ToDo *****************************************

	check if snake eats itself
		be aware that you need to skip checking the tail as it moves out of the way.

	Goal : random object placement ie do - random.x, random.y - while(Tile !isEmpty)
		reaching goal = Grow snake + speed up

		Startup and Game over screens.

	Obsticles ???? - canr see why not - just for fun.
	*/
