/*
========================================================================
 Name        : Tap2MenuAppUi.h
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2011

 Description : 
========================================================================
*/
#ifndef TAP2MENUAPPUI_H
#define TAP2MENUAPPUI_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknviewappui.h>
// ]]] end generated region [Generated Includes]
#include <w32std.h>
// [[[ begin generated region: do not modify [Generated Forward Declarations]
class CMainView;
// ]]] end generated region [Generated Forward Declarations]
#include <fgrobserver.h>


class CContainerButton: public CCoeControl
	{
public:
	~CContainerButton();
	static CContainerButton* NewL(RWindowGroup* aWg);
	static CContainerButton* NewLC(RWindowGroup* aWg);
	void ConstructL(RWindowGroup* aWg);
	CContainerButton();
	void Draw(const TRect& aRect) const;
	CGulIcon* iIcon;
	void SetIcon(CGulIcon* aIcon);
	void SetObserver(MCoeControlObserver* aObserver);
	MCoeControlObserver* iObserver;
	void HandlePointerEventL(const TPointerEvent& aEvent);
	CPeriodic* iTimer;
	static TInt Tick(TAny* aObj);
	TTime iTimeUp;
	TTime iTimeDown;
	};


_LIT(KSettingPath,"C:\\system\\apps\\Tap2Menu\\config.ini");
_LIT(KExceptionsPath,"C:\\system\\apps\\Tap2Menu\\exceptions.ini");
const TInt KPosXP=290;
const TInt KPosYP=38;
const TInt KPosXL=400;
const TInt KPosYL=315;
const TInt KSize=50;

class CTap2MenuAppUi : public CAknViewAppUi, public MFgrCallBack
	{
public: 
	// constructor and destructor
	CTap2MenuAppUi();
	void ScreenChangeEventL();
	virtual ~CTap2MenuAppUi();
	void ConstructL();
	RWsSession* iWsSession;
	RWindowGroup* iWinGroup;
	CContainerButton* iButton;
	CGulIcon* LoadAppIconEasy(TUid aUid);
	RArray<TUid> iExceptions;
	RArray<TInt> iSettings;\
	void ReadSettings();
	void WriteSettings();
	void ReadExceptions();
	void WriteExceptions();
	void UpdateSettings();
	CGulIcon* LoadAppIconHard(TUid aUid);
	CFgrObserver* iObserver;
	void CopyBitmapL(CFbsBitmap *aSource, CFbsBitmap *aTarget);
	TBool GlobalMsgQuery(TPtrC aText,TPtrC aHeader);
	void FocusChangeEventL();
public:
	// from CCoeAppUi
	TKeyResponse HandleKeyEventL(
				const TKeyEvent& aKeyEvent,
				TEventCode aType );

	// from CEikAppUi
	void HandleCommandL( TInt aCommand );
	void HandleResourceChangeL( TInt aType );

	// from CAknAppUi
	void HandleViewDeactivation( 
			const TVwsViewId& aViewIdToBeDeactivated, 
			const TVwsViewId& aNewlyActivatedViewId );

private:
	void InitializeContainersL();
	// [[[ begin generated region: do not modify [Generated Methods]
public: 
	// ]]] end generated region [Generated Methods]
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
private: 
	CMainView* iMainView;
	// ]]] end generated region [Generated Instance Variables]
	
	
	// [[[ begin [User Handlers]
protected: 
	// ]]] end [User Handlers]
	
	};

#endif // TAP2MENUAPPUI_H			
