#pragma once

#include "src/Rendering/Window3D.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	void BeginFrame();
	void EndFrame();

	void test();

	// Gets

	// Sets
	void SetRoot(Qt3DCore::QEntity *rootEntity);

private:
	Qt3DCore::QEntity *m_rootEntity = nullptr;
	Qt3DCore::QEntity *m_entity = nullptr;
};
