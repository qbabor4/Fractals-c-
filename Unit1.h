//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------

class TForm1 : public TForm
{

__published:	// IDE-managed Components
        
        TButton *Button1;
        TScrollBar *ScrollBar1;
        TLabel *Label1;
        TLabel *Label2;
        TScrollBar *ScrollBar2;
        TScrollBar *ScrollBar3;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TScrollBar *ScrollBar4;
        TLabel *Label7;
        TLabel *Label8;
        TScrollBar *ScrollBar5;
        TScrollBar *ScrollBar6;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label12;
        TLabel *Label11;
        TLabel *Label13;
        TLabel *Label14;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall changeRed(TObject *Sender);
        void __fastcall changeGreen(TObject *Sender);
        void __fastcall changeBlue(TObject *Sender);
        void __fastcall value2Change(TObject *Sender);
        void __fastcall value1Change(TObject *Sender);
        void __fastcall maxIterationsChange(TObject *Sender);
        void __fastcall FractalClick(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
