#include "stdafx.h"  //________________________________________ MyShine.cpp
#include "MyShine.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	MyShine app;
	return app.BeginDialog(IDI_MyShine, hInstance);
}

void MyShine::Window_Open(Win::Event& e)
{
	wstring texto;
	double tsine = 0.0;
	double error = 0.0;
	double taylor = 0.0;
	Sys::Format(texto, L"X\r\tsin(x)\r\tTaylor(x)\r\tError\r\n");
	tbxSalida.Text += texto;
	Sys::Format(texto, L"----------\r\t----------\r\t----------\r\t----------\r\n");
	tbxSalida.Text += texto;
	for (double x = 0.10; x < 4.5; x = x + .20)
	{
		tsine = sin(x);
		taylor = taylorShine(x);
		error = tsine - taylor;
		Sys::Format(texto, L"%.5f\r\t%.5f\r\t%.5f\r\t%.8f\r\n",x,tsine,taylor,error);
		tbxSalida.Text += texto;
	}
}
double MyShine::taylorShine(double x)
{
	double A[5];
	double suma = 0.0;
	A[0] = x;
	suma += A[0];
	for (int i = 1,j=2,k=3; i < 5; i++,j=j+2,k=k+2)
	{
		A[i] = A[i - 1] * (x / j)*(x / k)*(-1);
		suma += A[i];
	}
	return suma;
}

