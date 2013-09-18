/*
========================================================================
 Name        : Tap2MenuAppUi.cpp
 Author      : Usanov-Kornilov Nikolay (aka Kolay)
 Copyright   : 
Contacts:
	kolayuk@mail.ru
	http://kolaysoft.ru

(c) KolaySoft, 2011

 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated System Includes]
#include <eikmenub.h>
#include <akncontext.h>
#include <akntitle.h>
#include <Tap2Menu.rsg>
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated User Includes]
#include "Tap2MenuAppUi.h"
#include "Tap2Menu.hrh"
#include "MainView.h"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]
#include <apgwgnam.h>
#include <gulicon.h>
#include <apgcli.h>
#include <bautils.h>
#include <aknutils.h>
#include <akniconutils.h>
#include <aknsutils.h>
#include <avkon.mbg>
#include <aknglobalmsgquery.h>
#include <Tap2Menu_aif.mbg>

/**
 * Construct the CTap2MenuAppUi instance
 */ 
CTap2MenuAppUi::CTap2MenuAppUi(): MFgrCallBack()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * The appui's destructor removes the container from the control
 * stack and destroys it.
 */
CTap2MenuAppUi::~CTap2MenuAppUi()
	{
	delete iButton;
	delete iWinGroup;
	iWsSession->Close();
	delete iWsSession;
	}

// [[[ begin generated function: do not modify
void CTap2MenuAppUi::InitializeContainersL()
	{
	iMainView = CMainView::NewL();
	AddViewL( iMainView );
	//SetDefaultViewL( *iMainView );
	}
// ]]] end generated function

/**
 * Handle a command for this appui (override)
 * @param aCommand command id to be handled
 */
void CTap2MenuAppUi::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{ // code to dispatch to the AppUi's menu and CBA commands is generated here
		default:
			break;
		}
	
		
	if ( !commandHandled ) 
		{
		if ( aCommand == EAknSoftkeyExit || aCommand == EEikCmdExit )
			{
			Exit();
			}
		}
	// ]]] end generated region [Generated Code]
	
	}

/** 
 * Override of the HandleResourceChangeL virtual function
 */
void CTap2MenuAppUi::HandleResourceChangeL( TInt aType )
	{
	CAknViewAppUi::HandleResourceChangeL( aType );
	// [[[ begin generated region: do not modify [Generated Code]
	// ]]] end generated region [Generated Code]
	
	}
				
/** 
 * Override of the HandleKeyEventL virtual function
 * @return EKeyWasConsumed if event was handled, EKeyWasNotConsumed if not
 * @param aKeyEvent 
 * @param aType 
 */
TKeyResponse CTap2MenuAppUi::HandleKeyEventL(
		const TKeyEvent& aKeyEvent,
		TEventCode aType )
	{
	// The inherited HandleKeyEventL is private and cannot be called
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	return EKeyWasNotConsumed;
	}

/** 
 * Override of the HandleViewDeactivation virtual function
 *
 * @param aViewIdToBeDeactivated 
 * @param aNewlyActivatedViewId 
 */
void CTap2MenuAppUi::HandleViewDeactivation( 
		const TVwsViewId& aViewIdToBeDeactivated, 
		const TVwsViewId& aNewlyActivatedViewId )
	{
	CAknViewAppUi::HandleViewDeactivation( 
			aViewIdToBeDeactivated, 
			aNewlyActivatedViewId );
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here. 
 */ 
void CTap2MenuAppUi::ConstructL()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	ReadSettings();
	ReadExceptions();
	BaseConstructL( EAknEnableSkin  | 
					 EAknEnableMSK ); 
	InitializeContainersL();
	// ]]] end generated region [Generated Contents]
	
	iWinGroup=new (ELeave) RWindowGroup(CEikonEnv::Static()->WsSession());
	iWinGroup->Construct((TUint32)&iWinGroup, EFalse);
	iWinGroup->EnableReceiptOfFocus(EFalse); // Don't capture any key events.
	iWinGroup->SetOrdinalPosition(0, ECoeWinPriorityAlwaysAtFront);
	
	CApaWindowGroupName* wn=CApaWindowGroupName::NewL(CEikonEnv::Static()->WsSession());
	wn->SetHidden(ETrue);
	wn->SetSystem(ETrue);
	wn->SetWindowGroupName(*iWinGroup);
	delete wn;
	iButton=CContainerButton::NewL(iWinGroup);
	iButton->SetSize(TSize(iSettings[4],iSettings[4]));
	iButton->SetPosition(TPoint(iSettings[0],iSettings[1]));
	iButton->MakeVisible(ETrue);
	CGulIcon* icon;
	const TUid KMenuUid=TUid::Uid(0x101f4cd2);
	TRAPD(erreasy,icon=LoadAppIconEasy(KMenuUid));
	if (erreasy==KErrNotFound)
		{
		CFbsBitmap*	AppIcon(NULL);
		CFbsBitmap*	AppIconMsk(NULL);
		AknIconUtils::CreateIconL(AppIcon,AppIconMsk,_L("\\resource\\apps\\Tap2Menu_aif.mif"), EMbmTap2menu_aifQgn_menu_tap2menu, EMbmTap2menu_aifQgn_menu_tap2menu_mask);
		AknIconUtils::SetSize(AppIcon,TSize(iSettings[4],iSettings[4]));
		AknIconUtils::SetSize(AppIconMsk,TSize(iSettings[4],iSettings[4]));
		icon=CGulIcon::NewL(AppIcon,AppIconMsk);
		}
	else if (erreasy!=KErrNone){TRAPD(errhard,icon=LoadAppIconHard(KMenuUid));}
	iButton->SetIcon(icon);
	iButton->MakeVisible(ETrue);
	iButton->DrawNow();
	iWsSession=new (ELeave) RWsSession();
	iWsSession->Connect();
	UpdateSettings();
	iObserver=CFgrObserver::NewL(*iWsSession,*this);
	CEikonEnv::Static()->RootWin().SetOrdinalPosition(-4);
	HideApplicationFromFSW(ETrue);
	}


CGulIcon* CTap2MenuAppUi::LoadAppIconEasy(TUid aUid)
	{
	RApaLsSession ls;
	ls.Connect();
	TApaAppInfo info;
	User::LeaveIfError(ls.GetAppInfo(info,aUid));
	HBufC* path=HBufC::NewL(255);
	TInt err=ls.GetAppIcon(aUid,path);
	User::LeaveIfError(err);
	CFbsBitmap*	AppIcon(NULL);
	CFbsBitmap*	AppIconMsk(NULL);
	//MAknsSkinInstance* skin = AknsUtils::SkinInstance();
	if ((err==KErrNone)&&(path->Length()!=0))
		{AknsUtils::CreateAppIconLC(AknsUtils::SkinInstance(),aUid, EAknsAppIconTypeContext,AppIcon,AppIconMsk);}
	else {User::Leave(KErrNotFound);}
	AknIconUtils::SetSize(AppIcon,TSize(iSettings[4],iSettings[4]));
	AknIconUtils::SetSize(AppIconMsk,TSize(iSettings[4],iSettings[4]));		
	CleanupStack::Pop(2);
	CGulIcon* icon=CGulIcon::NewL(AppIcon,AppIconMsk);
	ls.Close();
	return icon;
	}

CGulIcon* CTap2MenuAppUi::LoadAppIconHard(TUid aUid)
	{
	RApaLsSession ls;
	ls.Connect();
	CGulIcon *retval = NULL;
	CArrayFixFlat<TSize> *array = new CArrayFixFlat<TSize>(3);
	CleanupStack::PushL(array);
	TInt err = ls.GetAppIconSizes(aUid, *array);
	if(err == KErrNone && array->Count() > 0)
		{
		CApaMaskedBitmap *bitmap = CApaMaskedBitmap::NewLC();
		err = ls.GetAppIcon(aUid, (*array)[0], *bitmap);
		if(err == KErrNone)
			{
			CFbsBitmap* bmp = new (ELeave) CFbsBitmap();
			CleanupStack::PushL(bmp);
			CFbsBitmap* bmp_mask = new (ELeave) CFbsBitmap();
			CleanupStack::PushL(bmp_mask);
			User::LeaveIfError(bmp->Create(bitmap->SizeInPixels(), bitmap->DisplayMode()));
			User::LeaveIfError(bmp_mask->Create(bitmap->Mask()->SizeInPixels(), bitmap->Mask()->DisplayMode()));
			CopyBitmapL(bitmap, bmp);
			CopyBitmapL(bitmap->Mask(), bmp_mask);
			retval = CGulIcon::NewL(bmp, bmp_mask);
			CleanupStack::Pop(2); // bmp, bmp_mask
			}
			CleanupStack::PopAndDestroy(bitmap);
		}
		CleanupStack::PopAndDestroy(array);
		ls.Close();
		return retval;
	}

void CTap2MenuAppUi::CopyBitmapL(CFbsBitmap *aSource, CFbsBitmap *aTarget)
	{
	if(aSource != NULL && aTarget != NULL)
		{
		if(aSource->SizeInPixels() != aTarget->SizeInPixels() || aSource->DisplayMode() != aTarget->DisplayMode())
			{User::Leave(KErrArgument);}
		CFbsBitmapDevice* device = CFbsBitmapDevice::NewL(aTarget);
		CleanupStack::PushL(device);
		CFbsBitGc* gc = NULL;
		User::LeaveIfError(device->CreateContext(gc));
		CleanupStack::PushL(gc);
		gc->BitBlt(TPoint(0, 0), aSource);
		CleanupStack::PopAndDestroy(gc);
		CleanupStack::PopAndDestroy(device);
		}
	}






CContainerButton::CContainerButton():CCoeControl()
	{
	// No implementation required
	}

CContainerButton::~CContainerButton()
	{
	}

CContainerButton* CContainerButton::NewLC(RWindowGroup* aWg)
	{
	CContainerButton* self = new (ELeave) CContainerButton();
	CleanupStack::PushL(self);
	self->ConstructL(aWg);
	return self;
	}

CContainerButton* CContainerButton::NewL(RWindowGroup* aWg)
	{
	CContainerButton* self = CContainerButton::NewLC(aWg);
	CleanupStack::Pop(); // self;
	return self;
	}

void CContainerButton::ConstructL(RWindowGroup* aWg)
	{
	CreateWindowL(aWg);
	TRgb col(0,0,0,0);
	Window().SetTransparencyAlphaChannel();
	Window().SetBackgroundColor(col);
	MakeVisible(ETrue);
	SetPointerCapture(ETrue);
	EnableDragEvents();
	iTimer=CPeriodic::NewL(CActive::EPriorityHigh);
	iTimeUp.HomeTime();
	iTimeDown.HomeTime();
	ActivateL();
	}
void CContainerButton::Draw(const TRect& aRect) const
	{
	CWindowGc& gc=SystemGc();
	gc.Clear();
	if (iIcon)
		{gc.BitBltMasked(TPoint(0,0),iIcon->Bitmap(),TRect(TPoint(0,0),iIcon->Bitmap()->SizeInPixels()),iIcon->Mask(),EFalse);}
	}
void CContainerButton::SetIcon(CGulIcon* aIcon)
	{
	iIcon=aIcon;
	}
void CContainerButton::SetObserver(MCoeControlObserver* aObserver)
	{
	iObserver=aObserver;
	}
void CContainerButton::HandlePointerEventL(const TPointerEvent& aEvent)
	{
	TBuf<255> txt;
	TRawEvent ev;
	if (aEvent.iType==aEvent.EButton1Down)
		{
		iTimeDown.HomeTime();
		}
	else if (aEvent.iType==aEvent.EButton1Up)
		{
		iTimeUp.HomeTime();
		txt.Num(Abs(iTimeDown.MicroSecondsFrom(iTimeUp).Int64()));
		//User::InfoPrint(txt);
		ev.Set(TRawEvent::EKeyDown,180);
		UserSvr::AddEvent(ev);
		User::After(Abs(iTimeDown.MicroSecondsFrom(iTimeUp).Int64()));
		ev.Set(TRawEvent::EKeyUp,180);
		UserSvr::AddEvent(ev);
		}
	}
TInt CContainerButton::Tick(TAny* aObj)
	{
	TBuf<255> txt;
	TRawEvent lEvent;
	lEvent.Set(TRawEvent::EKeyRepeat, 180);
	TInt err=UserSvr::AddEvent(lEvent);
	txt.Copy(_L("Repeat "));
	txt.AppendNum(err);
	CEikonEnv::Static()->InfoMsg(txt);
	}

void CTap2MenuAppUi::ReadSettings()
	{
	TInt err=KErrNone;
	iSettings.Reset();
	if (BaflUtils::FileExists(CEikonEnv::Static()->FsSession(),KSettingPath)) //!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
		TBuf<255> val;
		RFile filesave;
		TBuf<10> t;
		TFileText ft;
		TUint32 IntVal;
		filesave.Open(CEikonEnv::Static()->FsSession(), KSettingPath, EFileRead);
		ft.Set(filesave);
		while (ft.Read(val)==KErrNone)
			{
			TLex conv(val);
			conv.Val(IntVal,EDecimal);
			iSettings.Append(IntVal);
			}
		filesave.Close();
		}
	else
		{
		TParse parse;
		CEikonEnv::Static()->FsSession().Parse(KSettingPath,parse);
		if (!BaflUtils::FolderExists(CEikonEnv::Static()->FsSession(),parse.DriveAndPath()))
			{
			CEikonEnv::Static()->FsSession().MkDirAll(parse.DriveAndPath());
			}
		iSettings.Append(KPosXP);
		iSettings.Append(KPosYP);
		iSettings.Append(KPosXL);
		iSettings.Append(KPosYL);
		iSettings.Append(KSize);
		WriteSettings();
		}
	}
void CTap2MenuAppUi::WriteSettings()
	{
		RFs iFS=CEikonEnv::Static()->FsSession();
		RFile filesave;
		TInt err1=filesave.Replace(iFS, KSettingPath, EFileWrite);
		TFileText ft;
		ft.Set(filesave);
		TBuf<255> temp;
		for (TInt i=0;i<iSettings.Count();i++)
			{
			temp.Num(iSettings[i],EDecimal);
			ft.Write(temp);
			}
		filesave.Close();
	}

void CTap2MenuAppUi::WriteExceptions()
	{
		CEikonEnv::Static()->InfoMsg(_L("CreatingFile"));
		RFs iFS=CEikonEnv::Static()->FsSession();
		RFile filesave;
		TInt err1=filesave.Replace(iFS, KExceptionsPath, EFileWrite);
		TFileText ft;
		ft.Set(filesave);
		TInt i;
		TBuf<255> t;
		CEikonEnv::Static()->InfoMsg(_L("StartWriting"));
		for (i=0;i<iExceptions.Count();i++)
			{
			t.Num(iExceptions[i].iUid,EHex);
			ft.Write(t);
			}
		filesave.Close();
		CEikonEnv::Static()->InfoMsg(_L("EndWriting"));
	}
void CTap2MenuAppUi::ReadExceptions()
	{
	TInt err=KErrNone;
	iExceptions.Reset();
	if (BaflUtils::FileExists(CEikonEnv::Static()->FsSession(),KExceptionsPath)) //!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
		TBuf<255> val;
		TLex conv;
		TUint32 IntVal;
		RFile filesave;
		TBuf<255> t;
		TFileText ft;
		filesave.Open(CEikonEnv::Static()->FsSession(), KExceptionsPath, EFileRead);
		ft.Set(filesave);
		while (ft.Read(val)==KErrNone)
			{
			conv.Assign(val);
			conv.Val(IntVal,EHex);
			iExceptions.AppendL(TUid::Uid(IntVal));
			}
		filesave.Close();
		}
	else
		{
		TParse parse;
		CEikonEnv::Static()->FsSession().Parse(KExceptionsPath,parse);
		if (!BaflUtils::FolderExists(CEikonEnv::Static()->FsSession(),parse.DriveAndPath()))
			{
			CEikonEnv::Static()->FsSession().MkDirAll(parse.DriveAndPath());
			}
		}
	}
void CTap2MenuAppUi::ScreenChangeEventL()
	{
	//User::InfoPrint(_L("Screen changed"));
	UpdateSettings();
	}
void CTap2MenuAppUi::UpdateSettings()
	{
	
	AknIconUtils::SetSize(iButton->iIcon->Bitmap(),TSize(iSettings[4],iSettings[4]));
	AknIconUtils::SetSize(iButton->iIcon->Mask(),TSize(iSettings[4],iSettings[4]));
	TInt scrX=CEikonEnv::Static()->ScreenDevice()->SizeInPixels().iWidth;
	TInt scrY=CEikonEnv::Static()->ScreenDevice()->SizeInPixels().iHeight;
	iButton->SetSize(TSize(iSettings[4],iSettings[4]));
	if (scrY>scrX)
		{iButton->SetPosition(TPoint(iSettings[0],iSettings[1]));}
	else if (scrX>scrY)
		{iButton->SetPosition(TPoint(iSettings[2],iSettings[3]));}
	iButton->DrawNow();
	}

TBool CTap2MenuAppUi::GlobalMsgQuery(TPtrC aText,TPtrC aHeader)
	{
	
	    TInt queryAnswer = 1;
	    char* querystr = NULL;
	    int querystr_l = 0;
	    char* headerstr = NULL;
	    int headerstr_l = 0;
	    TRequestStatus msgQueryStatus = KRequestPending;
	    TRequestStatus timerStatus = KRequestPending;
	    int delayInSeconds = 0;
	    TInt timeout = 0;
	    
	    TTimeIntervalMicroSeconds32 timeoutValue = TTimeIntervalMicroSeconds32(timeout);

	    CAknGlobalMsgQuery *msgQueryDialog = NULL;
	    
	    TRAPD(err,
	        {
	            msgQueryDialog = CAknGlobalMsgQuery::NewL();
	        });
	    CleanupStack::PushL(msgQueryDialog);
	    TRAPD(err1,
	        {
	            msgQueryDialog->ShowMsgQueryL(msgQueryStatus,aText,R_AVKON_SOFTKEYS_OK_CANCEL,aHeader, KNullDesC);
	        });
	    if(err1 != KErrNone||err!=KErrNone){
	       CleanupStack::PopAndDestroy(msgQueryDialog);
	    } 
		User::WaitForRequest(msgQueryStatus);
	    
	    CleanupStack::PopAndDestroy(msgQueryDialog);
	    return msgQueryStatus.Int() == EAknSoftkeyOk ? 1 : 0;		
	}
void CTap2MenuAppUi::FocusChangeEventL()
	{
	CApaWindowGroupName* wg=CApaWindowGroupName::NewL(*iWsSession,iWsSession->GetFocusWindowGroup());
	TUid uid=wg->AppUid();
	delete wg;
	if (iExceptions.Find(uid)!=KErrNotFound)
		{iButton->MakeVisible(EFalse);}
	else
		{iButton->MakeVisible(ETrue);}
	iButton->DrawNow();
	}
