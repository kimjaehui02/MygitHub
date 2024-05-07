////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "colorshaderclass.h"
#include <vector>

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	bool IsInProximity(float x1, float y1, float z1, float x2, float y2, float z2);
	

private:
	bool Render(float);

private:
	D3DClass* m_D3D;

	CameraClass* m_Camera;
	ModelClass* m_Model;
	ModelClass* m_Model2;
	ModelClass* m_Model3;
	ModelClass* m_Model4;
	ModelClass* m_Model5;
	ModelClass* m_Model6;
	ModelClass* m_Model7;

	float m_Rotation; // 회전 변수
	float m_RotationSpeed; // 회전 속도 변수
	float m_RotationDirection; // 회전 방향 (1 또는 -1)
	float ballx; // 회전 방향 (1 또는 -1)
	float bally; // 회전 방향 (1 또는 -1)
	float ballz; // 회전 방향 (1 또는 -1)
	float position = 0;

	bool box1 = true;
	bool box2 = true;


	ColorShaderClass* m_ColorShader;
};

#endif