#include "Window3D.h"

Window3D::Window3D(QScreen *parent)
	: Qt3DWindow(parent)
{
}

Window3D::~Window3D()
{
	qWarning("Window 3D : Destroyed");
}
