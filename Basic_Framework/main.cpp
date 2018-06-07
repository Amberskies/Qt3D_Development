#include <QGuiApplication>
#include "src/Rendering/Window3D.h"

int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.setBackgroundColor(Qt::darkBlue);
	wnd.show();
	return a.exec();
}


/*ToDo
	main wind/screen :
		light
		camera
		background color
		mouse input controller.
	game(window)
	game go
	
	*/