/*
========================================================================
 Name        : Tap2MenuDocument.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2011

 Description : 
========================================================================
*/
#ifndef TAP2MENUDOCUMENT_H
#define TAP2MENUDOCUMENT_H

#include <akndoc.h>
		
class CEikAppUi;

/**
* @class	CTap2MenuDocument Tap2MenuDocument.h
* @brief	A CAknDocument-derived class is required by the S60 application 
*           framework. It is responsible for creating the AppUi object. 
*/
class CTap2MenuDocument : public CAknDocument
	{
public: 
	// constructor
	static CTap2MenuDocument* NewL( CEikApplication& aApp );
	void UpdateTaskNameL(CApaWindowGroupName* aWg);
private: 
	// constructors
	CTap2MenuDocument( CEikApplication& aApp );
	void ConstructL();
	
public: 
	// from base class CEikDocument
	CEikAppUi* CreateAppUiL();
	};
#endif // TAP2MENUDOCUMENT_H
