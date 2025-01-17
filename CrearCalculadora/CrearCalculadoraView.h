
// CrearCalculadoraView.h: interfaz de la clase CCrearCalculadoraView
//

#pragma once


class CCrearCalculadoraView : public CView
{
protected: // Crear sólo a partir de serialización
	CCrearCalculadoraView();
	DECLARE_DYNCREATE(CCrearCalculadoraView)

// Atributos
public:
	CCrearCalculadoraDoc* GetDocument() const;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementación
public:
	virtual ~CCrearCalculadoraView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versión de depuración en CrearCalculadoraView.cpp
inline CCrearCalculadoraDoc* CCrearCalculadoraView::GetDocument() const
   { return reinterpret_cast<CCrearCalculadoraDoc*>(m_pDocument); }
#endif

