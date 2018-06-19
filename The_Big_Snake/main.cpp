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
	in Graphics.cpp UpdateGraphics().
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

	ToDo *****************************************
	setup snake movement and the Left/Right key control
	a totaly diffrent move and controll system required.
	*/
