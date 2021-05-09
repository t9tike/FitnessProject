#include <Adafruit_GFX.h>   // grafiikka kirjasto
#include <TouchScreen.h>    //kosketusnäyttö kirjasto
#include <MCUFRIEND_kbv.h>  // näytön tulostuksen kirjasto

#include <SPI.h>            //muistikortin tarvitsema kirjasto
#include <SD.h>             //muistikortin tarvitsema kirjasto

File Fitness;

#define BLACK       0x0000  //määritellään värejä näyttöön
#define LIGHTGREY   0xC618
#define DARKGREY    0x7BEF
#define BLUE        0x001F
#define GREEN       0x07E0
#define CYAN        0x07FF
#define RED         0xF800
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define ORANGE      0xFD20

#define WIDTH 240           //määritellään näytön leveys
#define HEIGHT 320          //määritellään näytön korkeus

#define TS_MINX 110        //näytön kosketuksen kalibrointi
#define TS_MINY 81
#define TS_MAXX 902
#define TS_MAXY 898

#define LCD_RESET A4
#define LCD_CS A3           //näytön pinnit
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define YP A3
#define XM A2
#define YM 9
#define XP 8

const int pinX = A8;        //GY-61:n X-kulman pin
const int pinY = A9;        //GY-61:n Y-kulman pin
const int pinZ = A10;       //GY-61:n Z-kulman pin
const int tune = 31;        //summerin vaatima pin

const int trig = 41;        //HC-SR04:n signaalin output pin
const int echo = A11;       //HC-SR04:n signaalin input pin

const int valoPin = A12;    //valo anturin pin

int once = 1;               //käytetään toimintoja joita suoritetaan vain kerran
int laskuri = 0; 
int tavoite = 0;            //liikkeiden laskuri
int tavoitenum = 0;
int tavoitehyppy = 5;       //kunto-ohjelman tavoite toistomäärä
int tavoitevatsa = 7;
int tavoitepunnerrus = 8;
int tavoitekyykky = 9;      //kunto-ohjelman tavoite toistomäärä
int setti = 1;              //nykyinen toistomäärä
int tauko = 4;              //tauon kesto
int kalori = 0;
int kalori2 = 0;
char kalori3[4];
int kalori4 = 0;
int keypadspace = 7;        // näppäimistön väli asetus
int k = 0;
char nickname[7][10] = {    // nimien alkuasetukset
  "New user", "New user", "New user", 
  "New user", "New user", "New user", "New user"};
char nickname2[10] = "New user";
int letter = 0;
int user = 7;               // käyttäjän valinta
int SDnumero = 0;

char kirjain[] = {          // näppäimistön kirjaimet
  'Q','W','E','R','T','Y','U','I','O','P',
  'A','S','D','F','G','H','J','K','L',
  'Z','X','C','V','B','N','M'
};

int valo = 800;             // valoanturi

int cm;                     // etäisyys anturi
int distance;

unsigned long aikaNyt = 0;          //kellon muuttuja
unsigned long tapahtuma = 5000;     //apumuuttuja kellon käynnistämiseen
int second = 25;
int minute = 30;
int hour = 15;
int day = 13;
int month = 12;
int year = 2019;

int melody3[] = {190, 0, 190, 415}; //saaavutuksen ääni
int melody4[] = {190, 0, 190, 115}; //luovutuksen ääni
int divide[] = {8, 12, 8, 2};       //äänen toisto nopeus
int duration = 1000;                //äänen kesto ennen seuraavaa ääntä
int viive = 0;

int valueX = 0;                     //GY-61 kulman tarvittavia muuttujia
int valueY = 0;
int valueZ = 0;
float kulmaX = 0.0;
float kulmaY = 0.0;
float kulmaZ = 0.0;
float kulma = 0.0;

float kiihtyvyysX = 0;              //GY-61 kiihtyvyyteen tarvittavia muuttujia
float kiihtyvyysY = 0;
float kiihtyvyysZ = 0;
float kiihtyvyys = 0;
float kiihtyvyysX_Out = 0.0;
float kiihtyvyysY_Out = 0.0;
float kiihtyvyysZ_Out = 0.0;
float kiihtyvyys_Out = 0.0;

MCUFRIEND_kbv tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); //MCUFRIEND luokan määritys
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);            //TouchScreen luokan määritys
