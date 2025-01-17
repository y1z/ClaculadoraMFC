
// CrearCalculadoraView.cpp: implementación de la clase CCrearCalculadoraView
//

#include "stdafx.h"
// Se pueden definir SHARED_HANDLERS en un proyecto ATL implementando controladores de vista previa, miniatura
// y filtro de búsqueda, y permiten compartir código de documentos con ese proyecto.
#ifndef SHARED_HANDLERS
#include "CrearCalculadora.h"
#endif

#include "CrearCalculadoraDoc.h"
#include "CrearCalculadoraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCrearCalculadoraView

IMPLEMENT_DYNCREATE(CCrearCalculadoraView, CView)

BEGIN_MESSAGE_MAP(CCrearCalculadoraView, CView)
	// Comandos de impresión estándar
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCrearCalculadoraView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Construcción o destrucción de CCrearCalculadoraView

CCrearCalculadoraView::CCrearCalculadoraView()
{
	// TODO: agregar aquí el código de construcción

}

CCrearCalculadoraView::~CCrearCalculadoraView()
{
}

BOOL CCrearCalculadoraView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CCrearCalculadoraView

void CCrearCalculadoraView::OnDraw(CDC* /*pDC*/)
{
	CCrearCalculadoraDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Impresión de CCrearCalculadoraView


void CCrearCalculadoraView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCrearCalculadoraView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Preparación predeterminada
	return DoPreparePrinting(pInfo);
}

void CCrearCalculadoraView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar inicialización adicional antes de imprimir
}

void CCrearCalculadoraView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar limpieza después de imprimir
}

void CCrearCalculadoraView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCrearCalculadoraView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Diagnósticos de CCrearCalculadoraView

#ifdef _DEBUG
void CCrearCalculadoraView::AssertValid() const
{
	CView::AssertValid();
}

void CCrearCalculadoraView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCrearCalculadoraDoc* CCrearCalculadoraView::GetDocument() const // La versión de no depuración está alineada
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCrearCalculadoraDoc)));
	return (CCrearCalculadoraDoc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensajes de CCrearCalculadoraView
