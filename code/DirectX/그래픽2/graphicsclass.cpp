////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;

	m_Camera = 0;
	m_Model = 0;
	m_Model2 = 0;
	m_Model3 = 0;
	m_Model4 = 0;
	m_Model5 = 0;
	m_Model6 = 0;
	m_Model7= 0;
	m_ColorShader = 0;
	ballx = 0;
	bally = 0;
	ballz = 0;
	// �ٸ� �ʱ�ȭ �ڵ�...
	m_Rotation = 0.0f;
	m_RotationSpeed = 0.02f; // ȸ�� �ӵ� (���� ����)
	m_RotationDirection = 1.0f; // �ʱ� ȸ�� ����


}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{

}


GraphicsClass::~GraphicsClass()
{

}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	m_D3D = new D3DClass;


	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);


	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -5.0f);	// for cube model
	
	// Create the model object.
	m_Model = new ModelClass;
	m_Model2 = new ModelClass;
	if(!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->Initialize(m_D3D->GetDevice(), L"./data/cube.obj");
	//result = m_Model2->Initialize(m_D3D->GetDevice(), L"./data/ball.obj");
	result = m_Model2->Initialize(m_D3D->GetDevice(), L"./data/Cylinder.obj");

#pragma region 3456
	m_Model3 = new ModelClass;
	m_Model4 = new ModelClass;
	m_Model5 = new ModelClass;
	m_Model6 = new ModelClass;
	m_Model7 = new ModelClass;
	result = m_Model3->Initialize(m_D3D->GetDevice(), L"./data/Cylinder.obj");
	result = m_Model4->Initialize(m_D3D->GetDevice(), L"./data/Cylinder.obj");
	result = m_Model5->Initialize(m_D3D->GetDevice(), L"./data/cube.obj");
	result = m_Model6->Initialize(m_D3D->GetDevice(), L"./data/cube.obj");
	result = m_Model7->Initialize(m_D3D->GetDevice(), L"./data/ball.obj");
#pragma endregion



//	result = m_Model->Initialize(m_D3D->GetDevice(), L"./data/cube.fbx");

	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the color shader object.
	m_ColorShader = new ColorShaderClass;
	if(!m_ColorShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_ColorShader->Initialize(m_D3D->GetDevice(), hwnd);

	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}





	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the texture shader object.
	if(m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	// Release the model object.
	if(m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}
	if(m_Model2)
	{
		m_Model2->Shutdown();
		delete m_Model2;
		m_Model2 = 0;
	}

#pragma region 3456
	if (m_Model3)
	{
		m_Model3->Shutdown();
		delete m_Model3;
		m_Model3 = 0;
	}
	if (m_Model4)
	{
		m_Model4->Shutdown();
		delete m_Model4;
		m_Model4 = 0;
	}
	if (m_Model5)
	{
		m_Model5->Shutdown();
		delete m_Model5;
		m_Model5 = 0;
	}
	if (m_Model6)
	{
		m_Model6->Shutdown();
		delete m_Model6;
		m_Model6 = 0;
	}
	if (m_Model7)
	{
		m_Model7->Shutdown();
		delete m_Model7;
		m_Model7 = 0;
	}
#pragma endregion


	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}



	return;
}


bool GraphicsClass::Frame()
{
	bool result;

	static float rotation = 0.0f;


	// Update the rotation variable each frame.
	rotation += (float)XM_PI * 0.01f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if(!result)
	{
		return false;
	}

	m_Rotation += m_RotationSpeed * m_RotationDirection;

	// �ִ밪 �Ǵ� �ּڰ��� �����ϸ� ������ ����
	if (m_Rotation >= 8.0f || m_Rotation <= -8.0f)
	{
		m_RotationDirection *= -1.0f;
	}

	return true;
}





bool GraphicsClass::Render(float rotation)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	XMMATRIX worldMatrix2, projectionMatrix2;
	XMMATRIX tempMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);



	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);

	if (GetAsyncKeyState('W') & 0x8000)
	{
		position -= 0.03f;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		position += 0.03f;
		//viewMatrix = XMMatrixTranslation(0,0,3);

	}


	if (GetAsyncKeyState('D') & 0x8000)
	{
		
	}
	viewMatrix = XMMatrixTranslation(0, position, 5);

#pragma region ù��°




	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);



	// Rotate the world matrix by the rotation value so that the triangle will spin.
	tempMatrix = XMMatrixRotationX(rotation);
	worldMatrix *= tempMatrix;
	tempMatrix = XMMatrixRotationY(rotation);
	worldMatrix *= tempMatrix;
	tempMatrix = XMMatrixScaling(1, 1, 1);
	worldMatrix *= tempMatrix;



	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//m_Model->Render(m_D3D->GetDeviceContext());
	//
	//
	//// Render the model using the texture shader.
	//result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model->GetIndexCount(), 
	//	worldMatrix, viewMatrix, projectionMatrix);
	//
	//if(!result)
	//{
	//	return false;
	//}
#pragma endregion

#pragma region �ι�°
	m_D3D->GetWorldMatrix(worldMatrix2); // ���� ��� 2

// �� ��° ��ü�� ��ġ, ȸ��, ũ�� ����
	worldMatrix2 = XMMatrixTranslation(4.0f, 0.0f, 8); // ���� ��ġ
	tempMatrix = XMMatrixScaling(1, 10, 1);
	worldMatrix2 *= tempMatrix;

	// �� ��° ��ü ������
	m_Model2->Render(m_D3D->GetDeviceContext());
	result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model2->GetIndexCount(),
		worldMatrix2, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}
#pragma endregion

#pragma region 3456
	m_D3D->GetWorldMatrix(worldMatrix2); // ���� ��� 2

// �� ��° ��ü�� ��ġ, ȸ��, ũ�� ����
	worldMatrix2 = XMMatrixTranslation(0, 0.0f, 8); // ���� ��ġ
	tempMatrix = XMMatrixScaling(1, 10, 1);
	worldMatrix2 *= tempMatrix;

	// �� ��° ��ü ������
	m_Model3->Render(m_D3D->GetDeviceContext());
	result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model3->GetIndexCount(),
		worldMatrix2, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	m_D3D->GetWorldMatrix(worldMatrix2); // ���� ��� 2

// �� ��° ��ü�� ��ġ, ȸ��, ũ�� ����
	worldMatrix2 = XMMatrixTranslation(-4, 0.0f, 8); // ���� ��ġ
	tempMatrix = XMMatrixScaling(1, 10, 1);
	worldMatrix2 *= tempMatrix;

	// �� ��° ��ü ������
	m_Model4->Render(m_D3D->GetDeviceContext());
	result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model4->GetIndexCount(),
		worldMatrix2, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	m_D3D->GetWorldMatrix(worldMatrix2); // ���� ��� 2

// �� ��° ��ü�� ��ġ, ȸ��, ũ�� ����
	if (box1)
	{
		worldMatrix2 = XMMatrixTranslation(-4, m_Rotation, 6); // ���� ��ġ
		tempMatrix = XMMatrixScaling(1, 1, 1);
		worldMatrix2 *= tempMatrix;

		// �� ��° ��ü ������
		m_Model5->Render(m_D3D->GetDeviceContext());
		result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model5->GetIndexCount(),
			worldMatrix2, viewMatrix, projectionMatrix);
		if (!result)
		{
			return false;
		}

		m_D3D->GetWorldMatrix(worldMatrix2); // ���� ��� 2
	}


// �� ��° ��ü�� ��ġ, ȸ��, ũ�� ����

	if (box2)
	{
		worldMatrix2 = XMMatrixTranslation(4, -m_Rotation, 6); // ���� ��ġ
		tempMatrix = XMMatrixScaling(1, 1, 1);
		worldMatrix2 *= tempMatrix;

		// �� ��° ��ü ������
		m_Model6->Render(m_D3D->GetDeviceContext());
		result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model6->GetIndexCount(),
			worldMatrix2, viewMatrix, projectionMatrix);
		if (!result)
		{
			return false;
		}

	}

	// �� ��° ��ü�� ��ġ, ȸ��, ũ�� ����
	worldMatrix2 = XMMatrixTranslation(ballx, bally, ballz); // ���� ��ġ
	ballz += 0.2f;
	tempMatrix = XMMatrixScaling(1, 1, 1);
	worldMatrix2 *= tempMatrix;
	if (GetAsyncKeyState('A') & 0x8000)
	{
		// 'A' Ű�� ������ �� ���ϴ� ��ġ�� ���� �̵�
		// ���� ���, X�� �������� -5.0f ��ŭ �̵�
		ballx = -4;
		bally = -position;
		ballz = 0;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		// 'A' Ű�� ������ �� ���ϴ� ��ġ�� ���� �̵�
		// ���� ���, X�� �������� -5.0f ��ŭ �̵�
		ballx = 4;
		bally = -position;
		ballz = 0;
	}
	// �� ��° ��ü ������
	m_Model7->Render(m_D3D->GetDeviceContext());
	result = m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model7->GetIndexCount(),
		worldMatrix2, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}
	

#pragma endregion


	if (box1)
	{
		box1 = IsInProximity(ballx, bally, ballz, -4.0f, m_Rotation, 6.0f);
	}
	if (box2)
	{
		box2 = IsInProximity(ballx, bally, ballz, 4.0f, -m_Rotation, 6.0f);
	}
	



	// Present the rendered scene to the screen.
	m_D3D->EndScene();


	return true;
}

bool GraphicsClass::IsInProximity(float x1, float y1, float z1, float x2, float y2, float z2)
{
	float distanceX = abs(x1 - x2);
	float deltaY = abs(y1 - y2);
	float deltaZ = abs(z1 - z2);

	if (deltaY <= 0.5f && deltaZ <= 0.5f && distanceX <= 0.5f)
	{
		return false;
	}




	return true;
}