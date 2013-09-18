
#ifndef TAP2MENU_PAN_H
#define TAP2MENU_PAN_H

/** Tap2Menu application panic codes */
enum TTap2MenuPanics
	{
	ETap2MenuUi = 1
	// add further panics here
	};

inline void Panic(TTap2MenuPanics aReason)
	{
	_LIT(applicationName,"Tap2Menu");
	User::Panic(applicationName, aReason);
	}

#endif // TAP2MENU_PAN_H
