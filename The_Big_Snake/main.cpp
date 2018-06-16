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
	- so ho humm onwards :

	ToDo *****************************************
	Ray Cast Object Picking for a 3D menu.
	*/
