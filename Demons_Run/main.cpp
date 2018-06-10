#include <QGuiApplication>
#include "src/Rendering/Window3D.h"
#include "src/Game.h"


int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.setBackgroundColor(Qt::darkBlue);
	//wnd.show();
	Game myGame(wnd);
	myGame.Go();

	return a.exec();
}

// Notes : Demons Run
/*
	moved assets up 1 directory level.
	copied Basic_Framework.

	ToDo:
		stop the player from going outside the grid

		create a model loader for each component mesh,material etc
	ModelLoader:
		LoadMesh - done
		Material - basics done
		applied to Player and map - much faster Startup - YAY!
	
	*/
