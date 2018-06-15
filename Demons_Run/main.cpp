#include <QGuiApplication>
#include "src/Rendering/Window3D.h"
#include "src/Game.h"


int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);

	Window3D wnd;
	wnd.setBackgroundColor(Qt::black);
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
		hmmm....I think we're better going for collision detection.
		that makes invisible walls much easier.

		create a model loader for each component mesh,material etc
	ModelLoader:
		LoadMesh - done
		Material - basics done
		Texture - basics done
		applied to Player and map - much faster Startup - YAY!

	Enemy:
		Copied Player to create an Enemy class.
		lets get them moving
		add a velocity
		check for boundary -> alter direction
	MoveEnemy:
		Added to Physx
	
	Dice:
		Initialized in Game.cpp 
		files in GameRules.

	Startup Screen function
		Hit Return to Play.
	

	*/

	/**
	* GameRules: here i will lay down the outline for AmberRPG Rule Set.
	*
	* Basic Dice Rolls useing 3d6:
	* Success Rolls
	*
	* Genral Game Rules:
	* Physical Feats
	* Mental Feats
	* Combat
	* Injury, Illness, Fatigue
	*
	* Magic:
	* Game World:
	* Jobs:
	* Tech Levels:
	* Travel Between Game Worlds:
	* Game Time:
	**/
