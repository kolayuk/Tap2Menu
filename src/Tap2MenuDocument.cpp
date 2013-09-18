/*
========================================================================
 Name        : Tap2MenuDocument.cpp
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2011

 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated User Includes]
#include "Tap2MenuDocument.h"
#include "Tap2MenuAppUi.h"
// ]]] end generated region [Generated User Includes]
#include <apgwgnam.h>
/**
 * @brief Constructs the document class for the application.
 * @param anApplication the application instance
 */
CTap2MenuDocument::CTap2MenuDocument( CEikApplication& anApplication )
	: CAknDocument( anApplication )
	{
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here.  
 */ 
void CTap2MenuDocument::ConstructL()
	{
	}
	
/**
 * Symbian OS two-phase constructor.
 *
 * Creates an instance of CTap2MenuDocument, constructs it, and
 * returns it.
 *
 * @param aApp the application instance
 * @return the new CTap2MenuDocument
 */
CTap2MenuDocument* CTap2MenuDocument::NewL( CEikApplication& aApp )
	{
	CTap2MenuDocument* self = new ( ELeave ) CTap2MenuDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * @brief Creates the application UI object for this document.
 * @return the new instance
 */	
CEikAppUi* CTap2MenuDocument::CreateAppUiL()
	{
	return new ( ELeave ) CTap2MenuAppUi;
	}
void CTap2MenuDocument::UpdateTaskNameL(CApaWindowGroupName* aWg)
	{
	CAknDocument::UpdateTaskNameL(aWg);
	aWg->SetHidden(ETrue);
	aWg->SetSystem(ETrue);
	}
