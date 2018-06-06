#pragma once

#include <Qt3DWindow>

class Window3D : public Qt3DExtras::Qt3DWindow
{
private:

	Q_OBJECT

public:
	Window3D(QScreen *parent = nullptr);
	~Window3D();
};
