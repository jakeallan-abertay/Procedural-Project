#ifndef VERTICALBLURSHADERCLASS_H
#define VERTICALBLURSHADERCLASS_H

#include <d3d11.h>
#include <D3DX10math.h>
#include <d3dx11async.h>
#include <fstream>
using namespace std;

class VerticalBlurShaderClass
{
private:
	struct MatrixBufferType
	{
		D3DXMATRIX world;
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};
	struct ScreenSizeBufferType
	{
		float screenHeight;
		D3DXVECTOR3 padding;
	};

public:
	VerticalBlurShaderClass();
	VerticalBlurShaderClass(const VerticalBlurShaderClass&);
	~VerticalBlurShaderClass();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, int, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D11ShaderResourceView*, float);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D11ShaderResourceView*, float);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_screenSizeBuffer;

};


#endif // !VERTICALBLURSHADERCLASS_H


