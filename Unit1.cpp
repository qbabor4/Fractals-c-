//---------------------------------------------------------------------------
//TODO:

#include <typeinfo>
#include <cmath>

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

// Width and heigth of fractal drawing field
int canvasWidth = 800;
int canvasHeigth = 600;

// Maximum numbers of iterations while choosing color for pixel
int maxIterations = 250;

// Fractals variables
int offsetX = - canvasWidth / 2;
int offsetY = - canvasHeigth / 2;
int panX = -100; // move to the right for better view
int panY = 0;
double zoom = 200;

//values for shape changes
float value1Iter = 0;
float value2Iter = 0;

int roffset = 0;   // 0
int goffset = 21;   // 21
int boffset = 34;   // 34
int ScrollBar1Position, ScrollBar2Position, ScrollBar3Position;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner)
{
}

//---------------------------------------------------------------------------

struct Color{
        int red;
        int green;
        int blue;
};   

int palette[256][3];

void generatePalette() { // dostaje wskaznik do palety
        roffset = ScrollBar1Position;  
        goffset = ScrollBar2Position;
        boffset = ScrollBar3Position;

    for ( int i = 0; i < 256; i++ ) {
        palette[i][0] = roffset;
        palette[i][1] = goffset;
        palette[i][2] = boffset;

        if ( i < 85 ) {
                if (roffset < 253){
                        roffset += 3;
                }
        } else if ( i < 170 ) {
                if (goffset < 253){
                        goffset += 3;
                }
        } else if ( i < 256 ) {
                if (boffset < 253){
                        boffset += 3;
                }
        }
    }
}

// Get palette color based on the number of iterations
Color getColorFromIterations( int iterations ){
    Color color1 = { 0, 0, 0 };
    if ( iterations != maxIterations ){
        int index = ( (float)iterations / ( maxIterations-1)) * 255;
        color1.red = palette[ index ][0];
        color1.green = palette[ index ][1];
        color1.blue = palette[ index ][2];
    }
    return color1;
}

Color calculate_mandelbrot(int x, int y){
        // Convert the screen coordinate to a fractal coordinate
        double x0 = ( x + offsetX + panX ) / zoom;
        double y0 = ( y + offsetY + panY ) / zoom;
       
        // Iteration variables
        float a = value1Iter; //0 // zmiana tego co 0.01 //1.7 max
        float b = value2Iter; // 1.2 max co 0.01
        double rx = 0;
        double ry = 0;
        
        int iterations = 0;
        while ( (iterations < maxIterations) && ( rx * rx + ry * ry <= 4 ) ) {
                rx = a * a - b * b + x0;
                ry = 2 * a * b + y0;
            
                a = rx;
                b = ry;
                iterations++;
        }

        Color color2;
        color2  =  getColorFromIterations( iterations );

        return color2;
}



void draw(){
        for(int i = 0; i < canvasWidth; i++)  {
                for (int j = 0; j < canvasHeigth; j++){
                        Color color3;
                        color3  = calculate_mandelbrot(i, j);
                        // Tu bierze zwrocona wartosc przez calculateFractal i zmienia kolor pixela
                        Form1->Canvas->Pixels[i][j] =  RGB(color3.red, color3.green, color3.blue);   //0xff0000; //0Xffffff; // 0
                }
        }

}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Button1 -> Enabled = false;
        generatePalette();
        draw();
        Button1 -> Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::changeRed(TObject *Sender)
{
        ScrollBar1Position = ScrollBar1 -> Position;
        Label1 -> Caption = ScrollBar1Position;
        roffset = ScrollBar1Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::changeGreen(TObject *Sender)
{
        ScrollBar2Position = ScrollBar2 -> Position;
        Label3 -> Caption = ScrollBar2Position;
        goffset = ScrollBar2Position;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::changeBlue(TObject *Sender)
{
        ScrollBar3Position = ScrollBar3 -> Position;
        Label5 -> Caption = ScrollBar3Position;
        boffset = ScrollBar3Position;
}
//---------------------------------------------------------------------------

