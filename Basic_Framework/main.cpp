#include <QGuiApplication>
#include "src/Rendering/Window3D.h"
#include "src/Game.h"

int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.setBackgroundColor(Qt::darkBlue);

	Game myGame(wnd);
	myGame.Go();

	return a.exec();
}


/*ToDo
	main wind/screen :
		light
		camera
		background color
		mouse input event capture
		Key input event capture
	game(window)
	game go
	
	*/