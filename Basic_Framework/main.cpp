#include <QGuiApplication>
#include "src/Window3D.h"

int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.show();
	return a.exec();
}


/*ToDo
	main wind/screen : Done
	game(window)
	game go
	
	*/