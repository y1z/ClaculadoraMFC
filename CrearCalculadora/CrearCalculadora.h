
// CrearCalculadora.h: archivo de encabezado principal para la aplicación CrearCalculadora
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales
#include <chrono> // para usar el tiempo esto no estaba aqui por defecto yo lo agrege 
#include <thread> // esta libreria es para ulitizar el tiempo 
#include <vector>// esto es para guardar el valor ingresado en la calculadora 
#include <string>
// CCrearCalculadoraApp:
// Consulte CrearCalculadora.cpp para obtener información sobre la implementación de esta clase
//

class CCrearCalculadoraApp : public CWinAppEx
{
public:
	CCrearCalculadoraApp();


// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCrearCalculadoraApp theApp;
