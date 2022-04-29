//.............................................................................
//
//
//
//
//.............................................................................

Unit LEvntSnk;

interface
uses
	Windows, Messages, SysUtils, Classes, Graphics, COntrols, Forms,
   Dialogs, ActiveX;
Const
   // LEAD Rater Twain Object Events
   LEADRASTERTWAINEVENTS_TWAINPAGE			   = 1;
   LEADRASTERTWAINEVENTS_TWAINFILE			   = 2;
   LEADRASTERTWAINEVENTS_TWAINFILEFORMAT	   = 3;

   // LEAD Rater Process Object Events
   LEADRASTERPROCESSEVENTS_PROGRESSSTATUS	   = 1;
   LEADRASTERPROCESSEVENTS_SMOOTH			   = 2;
   LEADRASTERPROCESSEVENTS_LINEREMOVE		   = 3;
   LEADRASTERPROCESSEVENTS_BORDERREMOVE	   = 4;
   LEADRASTERPROCESSEVENTS_INVERTEDTEXT	   = 5;
   LEADRASTERPROCESSEVENTS_DOTREMOVE		   = 6;
   LEADRASTERPROCESSEVENTS_HOLEPUNCHREMOVE   = 7;

   // LEAD Rater Object Events
   LEADRASTEREVENTS_CHANGE						   = 1;
   LEADRASTEREVENTS_RGNCHANGE					   = 2;

   // LEAD Rater IO Object Events
   LEADRASTERIOEVENTS_PROGRESSSTATUS		   = 1;
   LEADRASTERIOEVENTS_LOADINFO				   = 2;
   LEADRASTERIOEVENTS_FILEPAGE				   = 3;
   LEADRASTERIOEVENTS_READYSTATECHANGE		   = 4;

   // LEAD Rater ODBC Object Events
   LEADRASTERODBCEVENTS_ODBCCHANGED			   = 1;

   ILTODBCTLEVENTS_DATALOADED					   = 1;
   ILTODBCTLEVENTS_DATASAVED					   = 2;
   ILTODBCTLEVENTS_PROGRESSSTATUS			   = 3;

   // LEAD Rater Image list Object Events
   LEADIMGLISTEVENTS_ITEMSELECTED			   = 1;
   LEADIMGLISTEVENTS_RESIZE					   = 2;
   LEADIMGLISTEVENTS_CLICK						   = 3;
   LEADIMGLISTEVENTS_DBLCLICK					   = 4;
   LEADIMGLISTEVENTS_KEYDOWN					   = 5;
   LEADIMGLISTEVENTS_KEYPRESS					   = 6;
   LEADIMGLISTEVENTS_KEYUP						   = 7;
   LEADIMGLISTEVENTS_MOUSEMOVE				   = 8;
   LEADIMGLISTEVENTS_MOUSEDOWN				   = 9;
   LEADIMGLISTEVENTS_MOUSEUP					   = 10;
   LEADIMGLISTEVENTS_SCROLL					   = 11;
   LEADIMGLISTEVENTS_ITEMUNSELECTED			   = 12;

   // LEAD Rater Annotation Object Events
   LEADRASTERANNOTATIONEVENTS_ANNENUMERATE	= 2;
   LEADRASTERANNOTATIONEVENTS_LTANNEVENT		= 4;
   LEADRASTERANNOTATIONEVENTS_ANNCREATE		= 5;
   LEADRASTERANNOTATIONEVENTS_ANNDESTROY		= 6;
   LEADRASTERANNOTATIONEVENTS_ANNCLICKED		= 7;
   LEADRASTERANNOTATIONEVENTS_ANNDRAWN			= 8;
   LEADRASTERANNOTATIONEVENTS_ANNCHANGE		= 10;
   LEADRASTERANNOTATIONEVENTS_ANNSELECT		= 11;
   LEADRASTERANNOTATIONEVENTS_ANNLOCKED		= 12;
   LEADRASTERANNOTATIONEVENTS_ANNUNLOCKED		= 13;
   LEADRASTERANNOTATIONEVENTS_ANNHYPERLINK	= 14;
   LEADRASTERANNOTATIONEVENTS_ANNHYPERLINKMENU = 15;
   LEADRASTERANNOTATIONEVENTS_ANNTOOLDESTROY	= 16;
   LEADRASTERANNOTATIONEVENTS_ANNTOOLCHECKED	= 17;
   LEADRASTERANNOTATIONEVENTS_ANNMOUSEDOWN	= 18;
   LEADRASTERANNOTATIONEVENTS_ANNMOUSEMOVE	= 19;
   LEADRASTERANNOTATIONEVENTS_ANNMOUSEUP		= 20;
   LEADRASTERANNOTATIONEVENTS_ANNMENU			= 21;
   LEADRASTERANNOTATIONEVENTS_ANNPAINT			= 22;
   LEADRASTERANNOTATIONEVENTS_ANNUSERMENU		= 23;

   // LEAD Rater OLE Object Events
   LEADRASTEROLEDBEVENTS_DATALOADED				= 1;
   LEADRASTEROLEDBEVENTS_DATASAVED				= 2;
   LEADRASTEROLEDBEVENTS_PROGRESSSTATUS		= 3;

   // LEAD Rater INET Object Events
   LEADRASTERINETEVENTS_INETRECEIVEBITMAP		= 1;
   LEADRASTERINETEVENTS_INETRECEIVEDATA		= 2;
   LEADRASTERINETEVENTS_INETCONNECTED			= 3;
   LEADRASTERINETEVENTS_INETDISCONNECTED		= 4;
   LEADRASTERINETEVENTS_INETACCEPT				= 5;
   LEADRASTERINETEVENTS_INETERROR				= 6;
   LEADRASTERINETEVENTS_INETRECEIVESTART		= 7;
   LEADRASTERINETEVENTS_INETRECEIVING			= 8;
   LEADRASTERINETEVENTS_INETDATASENT			= 9;
   LEADRASTERINETEVENTS_INETSENDING				= 10;
   LEADRASTERINETEVENTS_INETRECEIVESOUND		= 11;
   LEADRASTERINETEVENTS_INETRECEIVECMD			= 12;
   LEADRASTERINETEVENTS_INETRECEIVERSP			= 13;

   // LEAD Rater Common Dialog Object Events
   LEADRASTERDLGEVENTS_DLGHELP					= 1;

   // LEAD Events
   DLEADEVENTS_CLICK									= - 600;
   DLEADEVENTS_DBLCLICK								= - 601;
   DLEADEVENTS_KEYDOWN							   = -602;
   DLEADEVENTS_KEYPRESS								= - 603;
   DLEADEVENTS_KEYUP									= - 604;
   DLEADEVENTS_MOUSEDOWN						   = - 605;
   DLEADEVENTS_MOUSEMOVE						   = - 606;
   DLEADEVENTS_MOUSEUP							   = - 607;
   DLEADEVENTS_READYSTATECHANGE				   = - 609;
   DLEADEVENTS_PAINT									= 1;
   DLEADEVENTS_RESIZE							   = 2;
   DLEADEVENTS_SCROLL							   = 3;
   DLEADEVENTS_PROGRESSSTATUS					   = 4;
   DLEADEVENTS_TWAINPAGE						   = 5;
   DLEADEVENTS_CHANGE							   = 6;
   DLEADEVENTS_RGNCHANGE						   = 7;
   DLEADEVENTS_ANNCREATE						   = 8;
   DLEADEVENTS_ANNDESTROY						   = 9;
   DLEADEVENTS_ANNCLICKED						   = 10;
   DLEADEVENTS_ANNDRAWN								= 11;
   DLEADEVENTS_LOADINFO								= 12;
   DLEADEVENTS_ANNCHANGE						   = 13;
   DLEADEVENTS_FILEPAGE								= 14;
   DLEADEVENTS_ANIMATE							   = 15;
   DLEADEVENTS_RUBBERBAND						   = 16;
   DLEADEVENTS_ANNSELECT						   = 17;
   DLEADEVENTS_PAINTNOTIFICATION				   = 18;
   DLEADEVENTS_ANNLOCKED						   = 19;
   DLEADEVENTS_ANNUNLOCKED						   = 20;
   DLEADEVENTS_ANNHYPERLINK					   = 21;
   DLEADEVENTS_ANNHYPERLINKMENU				   = 22;
   DLEADEVENTS_ZOOMINDONE						   = 23;
   DLEADEVENTS_PANWIN							   = 24;
   DLEADEVENTS_OLEDROPFILE						   = 25;
   DLEADEVENTS_ANNENUMERATE					   = 26;
   DLEADEVENTS_ANNTOOLCHECKED					   = 27;
   DLEADEVENTS_ANNTOOLDESTROY					   = 28;
   DLEADEVENTS_ANNMOUSEDOWN					   = 29;
   DLEADEVENTS_ANNMOUSEMOVE					   = 30;
   DLEADEVENTS_ANNMOUSEUP						   = 31;
   DLEADEVENTS_ANNMENU							   = 32;
   DLEADEVENTS_SMOOTH							   = 33;
   DLEADEVENTS_LINEREMOVE						   = 34;
   DLEADEVENTS_BORDERREMOVE					   = 35;
   DLEADEVENTS_INVERTEDTEXT					   = 36;
   DLEADEVENTS_DOTREMOVE						   = 37;
   DLEADEVENTS_HOLEPUNCHREMOVE				   = 38;
   DLEADEVENTS_MAGGLASS								= 39;
   DLEADEVENTS_TWAINFILEFORMAT				   = 40;
   DLEADEVENTS_TWAINFILE						   = 41;
   DLEADEVENTS_ANNUSERMENU						   = 42;
   DLEADEVENTS_MAGGLASSEXT						   = 43;

   // LEAD Rater OCR Object Events
   LEADRASTER_OCR_EVENTS_PROGRESSSTATUS				= 1;
   LEADRASTER_OCR_EVENTS_VERIFICATIONNOTIFICATION	= 2;
   LEADRASTER_OCR_EVENTS_DRAWNOTIFICATION 			= 3;
   LEADRASTER_OCR_EVENTS_XDOCPARSE 						= 4;
   LEADRASTER_OCR_EVENTS_PROGRESSSTATUS2 				= 5;
   LEADRASTER_OCR_EVENTS_VERIFICATIONNOTIFICATION2 = 6;
   LEADRASTER_OCR_EVENTS_DRAWNOTIFICATION2 			= 7;
   LEADRASTER_OCR_EVENTS_XDOCPARSE2 					= 8;

   // LEAD Rater Twain 2 Object Events
   LEADRASTER_TWAIN2_EVENTS_ACQUIREPAGEEVENT 		= 1;
   LEADRASTER_TWAIN2_EVENTS_SAVETEMPLATEEVENT		= 2;
   LEADRASTER_TWAIN2_EVENTS_LOADTEMPLATEEVENT		= 3;
   LEADRASTER_TWAIN2_EVENTS_FASTCONFIGEVENT			= 4;
   LEADRASTER_TWAIN2_EVENTS_ACQUIREMULTIEVENT		= 5;

type

	TInvokeEvent = procedure (Sender: TObject; DispID: Integer;
                             const IID: TGUID; LocaleID: Integer;
                             Flags: Word; Params: TDispParams;
                             varResult, ExcepInfo, ArgErr: Pointer) of object;

	TLEADAbstractEventSink = class(TInterfacedObject, IDispatch, IUnknown)

   private
   	FDispatch: IDispatch;
      FDispIntfIID: TGUID;
      FConnection: Integer;
      FOwner: TComponent;
   protected
		{IUnknown}
      function QueryInterface(const IID: TGUID; out Obj): HRESULT; stdcall;
      function _AddRef: Integer; stdcall;
      function _Release: Integer; stdcall;
      {IDispatch}
      function GetTypeInfoCount(out Count: Integer): HRESULT; stdcall;
      function GetTypeInfo (Index, localeID: Integer; out TypeInfo):HRESULT; stdcall;
		function GetIDsOfNames (const IID: TGUID; Names: Pointer;
      			NameCount, LocaleID: Integer; DispIDs: Pointer): HRESULT; stdcall;
      function Invoke(DispID: Integer; const IID: TGUID; localeID: Integer;
      			Flags: Word; var Params; varResult, ExcepInfo, ArgErr: Pointer): HRESULT; stdcall;

	public
   	Constructor Create(AOwner: TComponent);
      Destructor  Destroy; override;
      procedure Connect(AnAppDispatch: IDispatch; const AnAppDispIntfIID: TGUID);
      procedure Disconnect;
   end;

   TLEADEventSink= class(TComponent)
   private
   	{Private declarations }
      FSink: TLEADAbstractEventSink;
      FOnInvoke: TInvokeEvent;
   protected
   	procedure DoInvoke(DispID: Integer; const IID: TGUID;localeID: Integer;
      						 Flags: Word; var Params; VarResult, ExcepInfo,
                         ArgErr: Pointer); virtual;
   public
   	constructor Create(AOwner: TComponent); override;
      Destructor Destroy; override;
      Procedure Connect (AnAppDispatch: IDispatch; const AnAppDispIntfIID: TGUID);
   published
   	property OnInvoke: TInvokeEvent read FOnInvoke write FOnInvoke;
   end;

procedure Register;

implementation
uses
	ComObj;
Procedure Register;
begin
	RegisterComponents('ActiveX', [TLEADEventSink]);
end;

{$IFDEF VER100}
Procedure INterfaceConnect (const Source: IUnknown; const IID: TIID;
									 const Sink: IUnknown; var Connection: longint);
var
	CPC: IConnectionPointContainer;
   CP: IConnectionPoint;
begin
	Connection:= 0;
   if ( Succeeded ( Source.QueryInterface(IConnectionPointContainer, CPC))) then
   	if ( Succeeded (CPC.FindConnectionPoint(IID, CP))) then
      CP.Advise(Sink, Connection);
end;
Procedure InterfaceDisconnect ( const Source: IUnknown; const IID: TIID; var Connection: longint);
var
	CPC: IConnectionPointContainer;
   CP: IConnectionPoint;
begin
	 if (Connection <> 0) then
    	if (Succeeded (Source.QueryInterface(IConnectionPointContainer, CPC))) then
      	if (Succeeded (CPC.FindConnectionPoint(IID, CP))) then
         	if (Succeeded (CP.Unadvise(Connection))) then
            	Connection:= 0;
end;
{$ENDIF}
{ TAbstractEventSink }
function TLEADAbstractEventSink._AddRef: Integer;
begin
	Result:= -1;
end;

function TLEADAbstractEventSink._Release: Integer;
begin
	Result:= -1;
end;

Constructor TLEADAbstractEventSink.Create (AOwner: TComponent);
begin
	inherited Create;
   FOwner:= AOwner;
end;

Destructor TLEADAbstractEventSink.Destroy;
begin
	Disconnect ( );
   inherited Destroy;
end;

function TLEADAbstractEventSink.GetIDsOfNames (const IID: TGUID; Names: Pointer;
														 NameCount, localeID: Integer; DispIDs: Pointer): HRESULT;
begin
	Result:= E_NOTIMPL;
end;
function TLEADAbstractEventSink.GetTypeInfo (Index, localeID: integer; out TypeInfo): HRESULT;
begin
	Result:= E_NOTIMPL;
end;

function TLEADAbstractEventSink.GetTypeInfoCount (out Count: Integer): HRESULT;
begin
	Count:= 0;
   Result:= S_OK;
end;

function TLEADAbstractEventSink.Invoke (DispID: Integer; const IID: TGUID; LocaleID: Integer;
												Flags: Word; var Params; varResult,
                                    ExcepInfo, ArgErr: Pointer): HRESULT;
begin
	(FOwner as TLEADEventSink).DoInvoke(DispID, IID, localeID, Flags, Params, varResult, ExcepInfo, ArgErr);
   Result:= S_OK;
end;

function TLEADAbstractEventSink.QueryInterface (const IID: TGUID; out Obj): HRESULT;
begin
	Result:= E_NOINTERFACE;

   if (GetInterface(IID, Obj)) then
   	Result:= S_OK ;
   if (IsEqualGUID(IID, FDispIntfIID) and (GetInterface(IDispatch, Obj))) then
   	Result:= S_OK;
end;
procedure TLEADAbstractEventSink.Connect(AnAppDispatch: IDispatch;
  const AnAppDispIntfIID: TGUID);
begin
	FDispIntfIID:= AnAppDispIntfIID;
   FDispatch:= AnAppDispatch;

   InterfaceConnect (FDispatch, FDispIntfIID, Self, FConnection);
end;

procedure TLEADAbstractEventSink.Disconnect;
begin
	if (Assigned(FDispatch)) then
   begin
   	InterfaceDisconnect (FDispatch, FDispIntfIID, FConnection);
      FDispatch:= Nil;
      FConnection:= 0;
   end;
end;

{ TEventSink }

procedure TLEADEventSink.Connect(AnAppDispatch: IDispatch;
  const AnAppDispIntfIID: TGUID);
begin
	FSink.Connect (AnAppDispatch, AnAppDispIntfIID);
end;

Constructor TLEADEventSink.Create(AOwner: TComponent);
begin
	Inherited Create(AOwner);
   FSink:= TLEADAbstractEventSink.Create (Self);
end;

Destructor TLEADEventSink.Destroy;
begin
	FSink.Free ();
   Inherited Destroy;
end;

procedure TLEADEventSink.DoInvoke(DispID: Integer; const IID: TGUID;
  localeID: Integer; Flags: Word; var Params; VarResult, ExcepInfo,
  ArgErr: Pointer);
begin
	if (Assigned(FOnInvoke)) then
   	FOnInvoke (Self, DispID, IID, localeID, Flags, TDispParams(Params), varResult, ExcepInfo, ArgErr);
end;
end.
//end.of.file .................................................................
