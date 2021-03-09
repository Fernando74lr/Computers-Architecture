#include <MaxMatrix.h>

#include <string.h>

#define DEBUG(a, b) for (int index = 0; index < b; index++) Serial.print(a[index]);
Serial.println();

PROGMEM const byte CH[] = {
3, 8, B0000000, B0000000, B0000000, B0000000, B0000000, // space 32
1, 8, B1011111, B0000000, B0000000, B0000000, B0000000, // !
3, 8, B0000011, B0000000, B0000011, B0000000, B0000000, // "
5, 8, B0010100, B0111110, B0010100, B0111110, B0010100, // #
4, 8, B0100100, B1101010, B0101011, B0010010, B0000000, // $
5, 8, B1100011, B0010011, B0001000, B1100100, B1100011, // %
5, 8, B0110110, B1001001, B1010110, B0100000, B1010000, // &
1, 8, B0000011, B0000000, B0000000, B0000000, B0000000, // '
3, 8, B0011100, B0100010, B1000001, B0000000, B0000000, // (
3, 8, B1000001, B0100010, B0011100, B0000000, B0000000, // )
5, 8, B0101000, B0011000, B0001110, B0011000, B0101000, // *
5, 8, B0001000, B0001000, B0111110, B0001000, B0001000, // +
2, 8, B10110000, B1110000, B0000000, B0000000, B0000000, // ,
4, 8, B0001000, B0001000, B0001000, B0001000, B0000000, // -
2, 8, B1100000, B1100000, B0000000, B0000000, B0000000, // .
4, 8, B1100000, B0011000, B0000110, B0000001, B0000000, // /
4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // 0
3, 8, B1000010, B1111111, B1000000, B0000000, B0000000, // 1
4, 8, B1100010, B1010001, B1001001, B1000110, B0000000, // 2
4, 8, B0100010, B1000001, B1001001, B0110110, B0000000, // 3
4, 8, B0011000, B0010100, B0010010, B1111111, B0000000, // 4
4, 8, B0100111, B1000101, B1000101, B0111001, B0000000, // 5
4, 8, B0111110, B1001001, B1001001, B0110000, B0000000, // 6
4, 8, B1100001, B0010001, B0001001, B0000111, B0000000, // 7
4, 8, B0110110, B1001001, B1001001, B0110110, B0000000, // 8
4, 8, B0000110, B1001001, B1001001, B0111110, B0000000, // 9
2, 8, B01010000, B0000000, B0000000, B0000000, B0000000, // :
2, 8, B10000000, B01010000, B0000000, B0000000, B0000000, // ;
3, 8, B0010000, B0101000, B1000100, B0000000, B0000000, // <
3, 8, B0010100, B0010100, B0010100, B0000000, B0000000, // =
3, 8, B1000100, B0101000, B0010000, B0000000, B0000000, // >
4, 8, B0000010, B1011001, B0001001, B0000110, B0000000, // ?
5, 8, B0111110, B1001001, B1010101, B1011101, B0001110, // @
4, 8, B1111110, B0010001, B0010001, B1111110, B0000000, // A
4, 8, B1111111, B1001001, B1001001, B0110110, B0000000, // B
4, 8, B0111110, B1000001, B1000001, B0100010, B0000000, // C
4, 8, B1111111, B1000001, B1000001, B0111110, B0000000, // D
4, 8, B1111111, B1001001, B1001001, B1000001, B0000000, // E
4, 8, B1111111, B0001001, B0001001, B0000001, B0000000, // F
4, 8, B0111110, B1000001, B1001001, B1111010, B0000000, // G
4, 8, B1111111, B0001000, B0001000, B1111111, B0000000, // H
3, 8, B1000001, B1111111, B1000001, B0000000, B0000000, // I
4, 8, B0110000, B1000000, B1000001, B0111111, B0000000, // J
4, 8, B1111111, B0001000, B0010100, B1100011, B0000000, // K
4, 8, B1111111, B1000000, B1000000, B1000000, B0000000, // L
5, 8, B1111111, B0000010, B0001100, B0000010, B1111111, // M
5, 8, B1111111, B0000100, B0001000, B0010000, B1111111, // N
4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // O
4, 8, B1111111, B0001001, B0001001, B0000110, B0000000, // P
4, 8, B0111110, B1000001, B1000001, B10111110, B0000000, // Q
4, 8, B1111111, B0001001, B0001001, B1110110, B0000000, // R
4, 8, B1000110, B1001001, B1001001, B0110010, B0000000, // S
5, 8, B0000001, B0000001, B1111111, B0000001, B0000001, // T
4, 8, B0111111, B1000000, B1000000, B0111111, B0000000, // U
5, 8, B0001111, B0110000, B1000000, B0110000, B0001111, // V
5, 8, B0111111, B1000000, B0111000, B1000000, B0111111, // W
5, 8, B1100011, B0010100, B0001000, B0010100, B1100011, // X
5, 8, B0000111, B0001000, B1110000, B0001000, B0000111, // Y
4, 8, B1100001, B1010001, B1001001, B1000111, B0000000, // Z
2, 8, B1111111, B1000001, B0000000, B0000000, B0000000, // [
4, 8, B0000001, B0000110, B0011000, B1100000, B0000000, // backslash
2, 8, B1000001, B1111111, B0000000, B0000000, B0000000, // ]
3, 8, B0000010, B0000001, B0000010, B0000000, B0000000, // hat
4, 8, B1000000, B1000000, B1000000, B1000000, B0000000, // _
2, 8, B0000001, B0000010, B0000000, B0000000, B0000000, // `
4, 8, B0100000, B1010100, B1010100, B1111000, B0000000, // a
4, 8, B1111111, B1000100, B1000100, B0111000, B0000000, // b
4, 8, B0111000, B1000100, B1000100, B0101000, B0000000, // c
4, 8, B0111000, B1000100, B1000100, B1111111, B0000000, // d
4, 8, B0111000, B1010100, B1010100, B0011000, B0000000, // e
3, 8, B0000100, B1111110, B0000101, B0000000, B0000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B0000000, // g
4, 8, B1111111, B0000100, B0000100, B1111000, B0000000, // h
3, 8, B1000100, B1111101, B1000000, B0000000, B0000000, // i
4, 8, B1000000, B10000000, B10000100, B1111101, B0000000, // j
4, 8, B1111111, B0010000, B0101000, B1000100, B0000000, // k
3, 8, B1000001, B1111111, B1000000, B0000000, B0000000, // l
5, 8, B1111100, B0000100, B1111100, B0000100, B1111000, // m
4, 8, B1111100, B0000100, B0000100, B1111000, B0000000, // n
4, 8, B0111000, B1000100, B1000100, B0111000, B0000000, // o
4, 8, B11111100, B0100100, B0100100, B0011000, B0000000, // p
4, 8, B0011000, B0100100, B0100100, B11111100, B0000000, // q
4, 8, B1111100, B0001000, B0000100, B0000100, B0000000, // r
4, 8, B1001000, B1010100, B1010100, B0100100, B0000000, // s
3, 8, B0000100, B0111111, B1000100, B0000000, B0000000, // t
4, 8, B0111100, B1000000, B1000000, B1111100, B0000000, // u
5, 8, B0011100, B0100000, B1000000, B0100000, B0011100, // v
5, 8, B0111100, B1000000, B0111100, B1000000, B0111100, // w
5, 8, B1000100, B0101000, B0010000, B0101000, B1000100, // x
4, 8, B10011100, B10100000, B10100000, B1111100, B0000000, // y
3, 8, B1100100, B1010100, B1001100, B0000000, B0000000, // z
3, 8, B0001000, B0110110, B1000001, B0000000, B0000000, // {
1, 8, B1111111, B0000000, B0000000, B0000000, B0000000, // |
3, 8, B1000001, B0110110, B0001000, B0000000, B0000000, // }
3, 8, B0010000, B0111000, B1111100, B0000000, B0000000, // ~ </////////126
3, 8, B0011000, B0011000, B0011000, B0000000, B0000000, // =/////////127
};

int data = 12;
int load = 10;
int clock = 11;
int maxInUse = 4; //change this variable to set how many MAX7219's you'll use
MaxMatrix m(data, load, clock, maxInUse);
byte buffer[10];
int i;

int flagCommand = 0;
boolean flagControl = false;

boolean flagWrite = false; //write normal
boolean flagWrite2 = false; //write data
boolean flagFPS = false;

boolean flagBlank = false;

boolean pause = false;
boolean commandPause = false;

String newString = "";
int sizeString = 0;

boolean asterisco = false;

char cadena[10];
char cadenaTemp[10];

size_t dataIndex = 0;

void setup() {
  m.init();
  m.setIntensity(8);
  Serial.begin(9600);
}

void loop() {
    int j = 0;
    while (Serial.available()) {
      char character = Serial.read();
      if (character == '*') {
        asterisco = true;
      }
      if (character != '\n') {
        if (!asterisco)
          newString.concat(character);
      } else {

        if (flagControl) {
          if (newString == "write!") {
            //Serial.println(newString);
            flagCommand = 1;
          } else if (newString == "data!") {
            if (flagCommand == 1) {
              flagWrite = true;
              flagCommand = 2;
              //Serial.println(newString+" Write");
            } else if (flagCommand == 5) {
              flagFPS = true;
              flagCommand = 2;
              //Serial.println(newString+ " Fps");
            }
          } else if (newString == "blank!") {
            flagCommand = 3;
            //Serial.println(newString);
            flagControl = false;
            Serial.println("OK");
          } else if (newString == "pause!") {
            commandPause = true;
            //Serial.println(newString);
          } else if (newString == "fps!") {
            flagCommand = 5;
            //Serial.println(newString);
          } else if (newString == "show!") {
            flagCommand = 6;
            flagWrite2 = true; //Permite que se muestre lo que está en "cadena"
            strcpy(cadena, cadenaTemp);
            //cadena = cadenaTemp;
            //Serial.println(newString);
            Serial.println("OK");
          } else if (newString == "logo!") {
            flagCommand = 7;
            //Serial.println(newString);
            flagControl = false;
            Serial.println("OK");
          } else if (newString == "true!") {
            if (commandPause) {
              flagCommand = 8;
              pause = false;
              //Serial.println(newString);
              flagControl = false;
              Serial.println("OK");
            }
          } else if (newString == "false!") {
            if (commandPause) {
              flagCommand = 9;
              pause = true;
              //Serial.println(newString);
              flagControl = false;
              Serial.println("OK");
            }
          } else if (newString == "control!") {
            flagControl = true;
            //Serial.println(newString);
          } else {
            if (flagWrite) {
              if (asterisco) {
                sizeString = newString.length();
                //newString.toCharArray(cadena, 10);
                newString.toCharArray(cadenaTemp, 10);
                //flagWrite2 = true; //Mostrar
                asterisco = false;
                Serial.println("OK");
              }
            } else {
              flagWrite2 = false;
            }
            flagCommand = 10;
            flagControl = false;
          }

        }
        if (newString == "control!") {
          flagControl = true;
        }
        newString = "";
      }
      j++;
    }
    if (!pause) {
      switch (flagCommand) {
      case 2: //data
        //
        break;
      case 3: //blank
        writeMatrix("                              ");
        flagWrite = false;
        flagWrite2 = false;
        break;
      case 7: //logo
        writeMatrixLogo();
        flagWrite = false;
        flagWrite2 = false;
        break;
      default:
        break;

        if (flagWrite2) {
          writeMatrix(cadena);
        } else if (flagFPS) {
          //No se hace nada
        }

      } //fin if(pause)
    } //fin loop

    void writeMatrix(char newCadena[]) {
      for (i = 0; i < sizeString; i++) {
        printCharWithShift(newCadena[i], 100);
      }
      delay(100);
      m.shiftLeft(false, true);
    }

    void printCharWithShift(char c, int shift_speed) {
      if (c < 32) return;
      c -= 32;
      memcpy_P(buffer, CH + 7 * c, 7);
      m.writeSprite(32, 0, buffer);
      m.setColumn(32 + buffer[0], 0);

      for (int i = 0; i < buffer[0] + 1; i++) {
        delay(shift_speed);
        m.shiftLeft(false, false);
      }
    }

    void printStringWithShift(char * s, int shift_speed) {
      while ( * s != 0) {
        printCharWithShift( * s, shift_speed);
        s++;
      }
    }

    /* LOGO */

    void writeMatrixLogo() {
      char charLogo[] = "<=         ";
      //Serial.println(newCadena);
      for (i = 0; i < 11; i++) {
        if (i == 0) {
          printCharWithShift(126, 100);
        }
        if (i == 1) {
          printCharWithShift(127, 100);
        }
        if (i != 0 && i != 1) {
          printCharWithShift(charLogo[i], 100);
        }
      }
      delay(100);
      m.shiftLeft(false, true);
    }
