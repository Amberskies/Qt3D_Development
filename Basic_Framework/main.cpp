#include <QGuiApplication>
#include "src/Rendering/Window3D.h"
#include "src/Game.h"


int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.SetBackgroundColor(Qt::darkBlue);

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

	ToDo *****************************************
	Player:
	Map:
	MovePlayer:
	
	*/
