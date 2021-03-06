/*
========================================================================
 Name        : MainView.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2011

 Description : 
========================================================================
*/
#ifndef MAINVIEW_H
#define MAINVIEW_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknview.h>
// ]]] end generated region [Generated Includes]


// [[[ begin [Event Handler Includes]
// ]]] end [Event Handler Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMain;
// ]]] end generated region [Generated Forward Declarations]

/**
 * Avkon view class for MainView. It is register with the view server
 * by the AppUi. It owns the container control.
 * @class	CMainView MainView.h
 */						

struct TApplicationInfo
{
	TFileName iCaption;
	TUid iUid;
	static TInt Compare(const TApplicationInfo& aInfo1, const TApplicationInfo& aInfo2)
	{
		return aInfo1.iCaption.CompareC(aInfo2.iCaption);
	}
};


class CMainView : public CAknView
	{
	
	
	// [[[ begin [Public Section]
public:
	// constructors and destructor
	CMainView();
	static CMainView* NewL();
	static CMainView* NewLC();        
	void ConstructL();
	virtual ~CMainView();
	void HandleLBSelect(TInt aIndex);
	void OpenBrowser(const TDesC& aUrl);
	TInt NumberQuery(TDes& aText,TInt& aNumber);
	void Init();
	void ChangeItemSubtitle(TInt aIndex,TDes16& aText);
	TPtrC GetTitle(TInt aIndex);
	void SelectExceptions();
	// from base class CAknView
	TUid Id() const;
	void HandleCommandL( TInt aCommand );
	
	// [[[ begin generated region: do not modify [Generated Methods]
	CMain* CreateContainerL();
	// ]]] end generated region [Generated Methods]
	
	// ]]] end [Public Section]
	
	
	// [[[ begin [Protected Section]
protected:
	// from base class CAknView
	void DoActivateL(
		const TVwsViewId& aPrevViewId,
		TUid aCustomMessageId,
		const TDesC8& aCustomMessage );
	void DoDeactivate();
	void HandleStatusPaneSizeChange();
	
	// [[[ begin generated region: do not modify [Overridden Methods]
	// ]]] end generated region [Overridden Methods]
	
	
	// [[[ begin [User Handlers]
	TBool Hide( TInt aCommand );
	TBool Change( TInt aCommand );
	TBool About( TInt aCommand );
	TBool Other( TInt aCommand );
	TBool Exit( TInt aCommand );
	// ]]] end [User Handlers]
	
	// ]]] end [Protected Section]
	
	
	// [[[ begin [Private Section]
private:
	void SetupStatusPaneL();
	void CleanupStatusPane();
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
	CMain* iMain;
	// ]]] end generated region [Generated Instance Variables]
	
	// [[[ begin generated region: do not modify [Generated Methods]
	// ]]] end generated region [Generated Methods]
	
	// ]]] end [Private Section]
	
	};

#endif // MAINVIEW_H
