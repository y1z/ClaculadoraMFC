
// CrearCalculadora.cpp: define los comportamientos de las clases para la aplicación.
//


#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "CrearCalculadora.h"
#include "MainFrm.h"

#include "CrearCalculadoraDoc.h"
#include "CrearCalculadoraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCrearCalculadoraApp

BEGIN_MESSAGE_MAP(CCrearCalculadoraApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CCrearCalculadoraApp::OnAppAbout)
	// Comandos de documento estándar basados en archivo
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Comando de configuración de impresión estándar
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// Construcción de CCrearCalculadoraApp

CCrearCalculadoraApp::CCrearCalculadoraApp()
{
	m_bHiColorIcons = TRUE;

	// admite Administrador de reinicio
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Si la aplicación se compila para ser compatible con Common Language Runtime (/clr):
	//     1) Esta configuración adicional es necesaria para que la compatibilidad con el Administrador de reinicio funcione correctamente.
	//     2) En el proyecto, debe agregar una referencia a System.Windows.Forms para poder compilarlo.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: reemplace la cadena de identificador de aplicación siguiente por una cadena de identificador único; el formato
	// recomendado para la cadena es NombreCompañía.NombreProducto.Subproducto.InformaciónDeVersión
	SetAppID(_T("CrearCalculadora.AppID.NoVersion"));

	// TODO: agregar aquí el código de construcción,
	// Colocar toda la inicialización importante en InitInstance
}

// Único objeto CCrearCalculadoraApp

CCrearCalculadoraApp theApp;


// Inicialización de CCrearCalculadoraApp

BOOL CCrearCalculadoraApp::InitInstance()
{
	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// Se necesita AfxInitRichEdit2() para usar el control RichEdit
	// AfxInitRichEdit2();

	// Inicialización estándar
	// Si no utiliza estas funcionalidades y desea reducir el tamaño
	// del archivo ejecutable final, debe quitar
	// las rutinas de inicialización específicas que no necesite
	// Cambie la clave del Registro en la que se almacena la configuración
	// TODO: debe modificar esta cadena para que contenga información correcta
	// como el nombre de su compañía u organización
	SetRegistryKey(_T("Aplicaciones generadas con el Asistente para aplicaciones local"));
	LoadStdProfileSettings(4);  // Cargar opciones de archivo INI estándar (incluidas las de la lista MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Registrar las plantillas de documento de la aplicación.  Las plantillas de documento
	//  sirven como conexión entre documentos, ventanas de marco y vistas
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCrearCalculadoraDoc),
		RUNTIME_CLASS(CMainFrame),       // Ventana de marco SDI principal
		RUNTIME_CLASS(CCrearCalculadoraView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Analizar línea de comandos para comandos Shell estándar, DDE, Archivo Abrir
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Enviar comandos especificados en la línea de comandos.  Devolverá FALSE si
	// la aplicación se inició con los modificadores /RegServer, /Register, /Unregserver o /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Se ha inicializado la única ventana; mostrarla y actualizarla
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// Controladores de mensajes de CCrearCalculadoraApp


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	long double DValorTotal = 0;
	bool Negativo = false;
	std::vector<long double> LosValores;

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBoton8();
	afx_msg void OnBnClickedBoton4();
	afx_msg void OnBnClickedBoton1();
	afx_msg void OnBnClickedBoton0();
	afx_msg void OnBnClickedBoton2();
	afx_msg void OnBnClickedBoton3();
	afx_msg void OnBnClickedBoton5();
	afx_msg void OnBnClickedBoton6();
	afx_msg void OnBnClickedBoton7();
	afx_msg void OnBnClickedBoton9();
	afx_msg void OnBnClickedBotonmenos();
	afx_msg void OnBnClickedBotonmas();
	afx_msg void OnBnClickedBotonigual();
	afx_msg void AgregarDigito(char numero);
	double PantallaValor;
	//afx_msg void OnEnChangePantallaCalculadora();
protected:
	CString PantallaDeCalculadora;
public:
	afx_msg void OnEnChangePantallaReal();
	afx_msg void OnBnClickedBotonClear();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
, PantallaValor(0)
, PantallaDeCalculadora(_T(""))
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Pantalla_Calculadora, PantallaValor);
	DDV_MinMaxDouble(pDX, PantallaValor, -99999999, 999999999999999);
	DDX_Text(pDX, IDC_Pantalla_Real, PantallaDeCalculadora);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Boton_8, &CAboutDlg::OnBnClickedBoton8)
	ON_BN_CLICKED(IDC_Boton_4, &CAboutDlg::OnBnClickedBoton4)
	ON_BN_CLICKED(IDC_Boton_1, &CAboutDlg::OnBnClickedBoton1)
	ON_BN_CLICKED(IDC_Boton_0, &CAboutDlg::OnBnClickedBoton0)
	ON_BN_CLICKED(IDC_Boton_2, &CAboutDlg::OnBnClickedBoton2)
	ON_BN_CLICKED(IDC_Boton_3, &CAboutDlg::OnBnClickedBoton3)
	ON_BN_CLICKED(IDC_Boton_5, &CAboutDlg::OnBnClickedBoton5)
	ON_BN_CLICKED(IDC_Boton_6, &CAboutDlg::OnBnClickedBoton6)
	ON_BN_CLICKED(IDC_Boton_7, &CAboutDlg::OnBnClickedBoton7)
	ON_BN_CLICKED(IDC_Boton_9, &CAboutDlg::OnBnClickedBoton9)
	ON_BN_CLICKED(IDC_Boton_menos, &CAboutDlg::OnBnClickedBotonmenos)
	ON_BN_CLICKED(IDC_Boton_mas, &CAboutDlg::OnBnClickedBotonmas)
	ON_BN_CLICKED(IDC_Boton_igual, &CAboutDlg::OnBnClickedBotonigual)
//	ON_EN_CHANGE(IDC_Pantalla_Calculadora, &CAboutDlg::OnEnChangePantallaCalculadora)
	ON_EN_CHANGE(IDC_Pantalla_Real, &CAboutDlg::OnEnChangePantallaReal)
	ON_BN_CLICKED(IDC_Boton_Clear, &CAboutDlg::OnBnClickedBotonClear)
END_MESSAGE_MAP()

// Comando de la aplicación para ejecutar el cuadro de diálogo
void CCrearCalculadoraApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Métodos para cargar o guardar personalizaciones de CCrearCalculadoraApp

void CCrearCalculadoraApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CCrearCalculadoraApp::LoadCustomState()
{
}

void CCrearCalculadoraApp::SaveCustomState()
{
}

// Controladores de mensajes de CCrearCalculadoraApp

void CAboutDlg::AgregarDigito(char numero) 
{
	PantallaDeCalculadora += numero;
	UpdateData(false);

}

void CAboutDlg::OnBnClickedBoton0()
{// este if existe para que no se agrege ceros innecesario elemplo : 000000039 en este caso el valor de verdad es 39 pero los cero hacen esto mas dificil de saber 
	if (DValorTotal == 0) {
	}
	else {
	AgregarDigito('0');
	DValorTotal = (DValorTotal * 10) + 0;
	//PantallaValor = DValorTotal;
	UpdateData(false);

	}
}

void CAboutDlg::OnBnClickedBoton1()
{
	AgregarDigito('1');
	if(Negativo == false)
	DValorTotal = (DValorTotal * 10) + 1;
	else {
		DValorTotal = (DValorTotal * 10) - 1;
	}
	UpdateData(false);
	
}


void CAboutDlg::OnBnClickedBoton2()
{
	AgregarDigito('2');
	if (Negativo == false)
	DValorTotal = (DValorTotal * 10) + 2;
	else {
		DValorTotal = (DValorTotal * 10) - 2;
	}
	UpdateData(false);

}

void CAboutDlg::OnBnClickedBoton3()
{
	AgregarDigito('3');
	if(Negativo == false)
	DValorTotal = (DValorTotal * 10) + 3;
	else {
		DValorTotal = (DValorTotal * 10) - 3;
	}
	UpdateData(false);
}

void CAboutDlg::OnBnClickedBoton4()
{
	AgregarDigito('4');
	if (Negativo == false)
		DValorTotal = (DValorTotal * 10) + 4;
	else {
		DValorTotal = (DValorTotal * 10) - 4;
	}
	UpdateData(false);
}

void CAboutDlg::OnBnClickedBoton5()
{
	AgregarDigito('5');
	if (Negativo == false)
		DValorTotal = (DValorTotal * 10) + 5;
	else {
		DValorTotal = (DValorTotal * 10) - 5;
	}
	UpdateData(false);
}


void CAboutDlg::OnBnClickedBoton6()
{
	AgregarDigito('6');
	if (Negativo == false)
		DValorTotal = (DValorTotal * 10) + 6;
	else {
		DValorTotal = (DValorTotal * 10) - 6;
	}
	UpdateData(false);
	
}


void CAboutDlg::OnBnClickedBoton7()
{
	AgregarDigito('7');
	if (Negativo == false)
		DValorTotal = (DValorTotal * 10) + 7;
	else {
		DValorTotal = (DValorTotal * 10) - 7;
	}
	UpdateData(false);
}

void CAboutDlg::OnBnClickedBoton8()
{
	AgregarDigito('8');
	if (Negativo == false)
		DValorTotal = (DValorTotal * 10) + 8;
	else {
		DValorTotal = (DValorTotal * 10) - 8;
	}
	UpdateData(false);
}

void CAboutDlg::OnBnClickedBoton9()
{
	AgregarDigito('9');
	if(Negativo == false)
	DValorTotal = (DValorTotal * 10) + 9;
	else{
		DValorTotal = (DValorTotal * 10) - 9;
	}
	UpdateData(false);
}


void CAboutDlg::OnBnClickedBotonmenos()
{
	AgregarDigito('-');
	LosValores.push_back(DValorTotal);
	Negativo = true;
	DValorTotal = 0;

}


void CAboutDlg::OnBnClickedBotonmas()
{
	LosValores.push_back(DValorTotal);
	AgregarDigito('+');
	DValorTotal = 0;
	Negativo = false;

}


void CAboutDlg::OnBnClickedBotonigual()
{
	LosValores.push_back(DValorTotal);// para poner el valor que falta antes de hacer la suma .
	DValorTotal = 0;

	std::string resultado;

	long double ValorDespuesDeIgual = 0;
	for (int i = 0; i < LosValores.size(); ++i) {
		ValorDespuesDeIgual += LosValores[i];
	
	}
	PantallaDeCalculadora = '=';
	resultado = std::to_string(ValorDespuesDeIgual);
	
	for (int j = 0; j < resultado.size(); ++j) {
		AgregarDigito(resultado[j]);
	
	}
	UpdateData(false);

}


void CAboutDlg::OnEnChangePantallaReal()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialogEx::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles
}


void CAboutDlg::OnBnClickedBotonClear()
{
	LosValores.clear();
	DValorTotal = 0;
	PantallaDeCalculadora = "";
	Negativo = false;
	UpdateData(false);
	// TODO: Agregue aquí su código de controlador de notificación de control
}
