#include <Arduino.h>


const unsigned char fontAnime [] PROGMEM = {
  // space
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  2,

  // !
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  0,

  // "
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  0,

  // #
  B00000011,
  B00001100,
  B00001000,
  B00010000,
  B00110000,
  B11000000,
  8,

  // $
  B11000000,
  B00110000,
  B00010000,
  B00001000,
  B00001100,
  B00000011,
  8,

  // %
  B01000000,
  B00000000,
  B00000001,
  B00000101,
  B00010101,
  B01010101,
  8,

  // &
  B00010000,
  B01010100,
  B01010101,
  B01010101,
  B01010101,
  B01010101,
  8,

  // '
  B00000101,
  B00000001,
  B00000000,
  B01000000,
  B01010000,
  B01010100,
  8,

  // (
  B01010101,
  B01010101,
  B01010101,
  B00010101,
  B00000101,
  B00000001,
  8,

  // )
  B01010101,
  B01010101,
  B01010100,
  B01010000,
  B01000000,
  B00000000,
  8,

  // *
  B00000000,
  B01110000,
  B11111000,
  B11111000,
  B11111000,
  B01110000,
  8,

  // +
  B00000000,
  B01110000,
  B00111000,
  B00011000,
  B00111000,
  B01110000,
  8,

  // ,
  B00000000,
  B00010000,
  B00011000,
  B00011000,
  B00011000,
  B00010000,
  8,

  // -
  B00000000,
  B01110000,
  B00111000,
  B00011000,
  B00111000,
  B01110000,
  8,

  // .
  B00000000,
  B01110000,
  B11111000,
  B00111000,
  B11111000,
  B01110000,
  8,

  // /
  B11001100,
  B01100110,
  B00110011,
  B00110011,
  B01100110,
  B11001100,
  8,

  // 0
  B00110011,
  B01100110,
  B11001100,
  B11001100,
  B01100110,
  B00110011,
  8,

  // 1
  B01000000,
  B11000000,
  B01000000,
  B01000000,
  B01000000,
  B11100000,
  4,

  // 2
  B01000000,
  B10100000,
  B00100000,
  B01000000,
  B10000000,
  B11100000,
  4,

  // 3
  B11000000,
  B00100000,
  B11000000,
  B00100000,
  B00100000,
  B11000000,
  4,

  // 4
  B10100000,
  B10100000,
  B11100000,
  B00100000,
  B00100000,
  B00100000,
  4,

  // 5
  B11100000,
  B10000000,
  B11000000,
  B00100000,
  B00100000,
  B11000000,
  4,

  // 6
  B01100000,
  B10000000,
  B11000000,
  B10100000,
  B10100000,
  B01000000,
  4,

  // 7
  B11100000,
  B00100000,
  B01000000,
  B01000000,
  B10000000,
  B10000000,
  4,

  // 8
  B01000000,
  B10100000,
  B01000000,
  B10100000,
  B10100000,
  B01000000,
  4,

  // 9
  B01000000,
  B10100000,
  B01100000,
  B00100000,
  B10100000,
  B01000000,
  4,

  // :
  B00000000,
  B10000000,
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  2,

  // ;
  B00000000,
  B01000000,
  B00000000,
  B00000000,
  B01000000,
  B10000000,
  3,

  // <
  B00000000,
  B00100000,
  B01000000,
  B10000000,
  B01000000,
  B00100000,
  4,

  // =
  B00000000,
  B00000000,
  B11100000,
  B00000000,
  B11100000,
  B00000000,
  4,

  // >
  B00000000,
  B10000000,
  B01000000,
  B00100000,
  B01000000,
  B10000000,
  4,

  // ?
  B01000000,
  B10100000,
  B00100000,
  B01000000,
  B00000000,
  B01000000,
  4,

  // @
  B01110000,
  B10001000,
  B10101000,
  B10110000,
  B10000000,
  B01110000,
  6,

  // A
  B01000000,
  B10100000,
  B11100000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // B
  B11000000,
  B10100000,
  B11000000,
  B10100000,
  B10100000,
  B11000000,
  4,

  // C
  B01100000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B01100000,
  4,

  // D
  B11000000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B11000000,
  4,

  // E
  B11100000,
  B10000000,
  B11000000,
  B10000000,
  B10000000,
  B11100000,
  4,

  // F
  B11100000,
  B10000000,
  B11100000,
  B10000000,
  B10000000,
  B10000000,
  4,

  // G
  B01100000,
  B10000000,
  B10000000,
  B10100000,
  B10100000,
  B01100000,
  4,

  // H
  B10100000,
  B10100000,
  B11100000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // I
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  2,

  // J
  B11000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B10000000,
  3,

  // K
  B10100000,
  B10100000,
  B11000000,
  B11000000,
  B10100000,
  B10100000,
  4,

  // L
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B11100000,
  4,

  // M
  B11011000,
  B10101000,
  B10101000,
  B10001000,
  B10001000,
  B10001000,
  6,

  // N
  B10010000,
  B11010000,
  B10110000,
  B10010000,
  B10010000,
  B10010000,
  5,

  // O
  B11100000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B11100000,
  4,

  // P
  B11100000,
  B10100000,
  B11100000,
  B10000000,
  B10000000,
  B10000000,
  4,

  // Q
  B11100000,
  B10100000,
  B11100000,
  B00100000,
  B00100000,
  B00100000,
  4,

  // R
  B11000000,
  B10100000,
  B11000000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // S
  B01100000,
  B10000000,
  B01000000,
  B00100000,
  B00100000,
  B11000000,
  4,

  // T
  B11100000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  4,

  // U
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B11100000,
  4,

  // V
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B01000000,
  4,

  // W
  B10001000,
  B10001000,
  B10001000,
  B10101000,
  B10101000,
  B01010000,
  6,

  // X
  B10100000,
  B10100000,
  B01000000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // Y
  B10100000,
  B10100000,
  B11100000,
  B00100000,
  B00100000,
  B11000000,
  4,

  // Z
  B11100000,
  B00100000,
  B01100000,
  B11000000,
  B10000000,
  B11100000,
  4,

  // [
  B11000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B11000000,
  3,

  // bslash
  B10000000,
  B10000000,
  B01000000,
  B01000000,
  B00100000,
  B00100000,
  4,

  // ]
  B11000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B11000000,
  3,

  // ^
  B01000000,
  B10100000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  4,

  // _
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11100000,
  4,

  // `
  B11000000,
  B01000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  3,

  // a
  B01000000,
  B10100000,
  B11100000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // b
  B11000000,
  B10100000,
  B11000000,
  B10100000,
  B10100000,
  B11000000,
  4,

  // c
  B01100000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B01100000,
  4,

  // d
  B11000000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B11000000,
  4,

  // e
  B11100000,
  B10000000,
  B11000000,
  B10000000,
  B10000000,
  B11100000,
  4,

  // f
  B11100000,
  B10000000,
  B11100000,
  B10000000,
  B10000000,
  B10000000,
  4,

  // g
  B01100000,
  B10000000,
  B10000000,
  B10100000,
  B10100000,
  B01100000,
  4,

  // h
  B10100000,
  B10100000,
  B11100000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // i
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  2,

  // j
  B11000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B10000000,
  3,

  // k
  B10100000,
  B10100000,
  B11000000,
  B11000000,
  B10100000,
  B10100000,
  4,

  // l
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B11100000,
  4,

  // m
  B11011000,
  B10101000,
  B10101000,
  B10001000,
  B10001000,
  B10001000,
  6,

  // n
  B10010000,
  B11010000,
  B10110000,
  B10010000,
  B10010000,
  B10010000,
  5,

  // o
  B11100000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B11100000,
  4,

  // p
  B11100000,
  B10100000,
  B11100000,
  B10000000,
  B10000000,
  B10000000,
  4,

  // q
  B11100000,
  B10100000,
  B11100000,
  B00100000,
  B00100000,
  B00100000,
  4,

  // r
  B11000000,
  B10100000,
  B11000000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // s
  B01100000,
  B10000000,
  B01000000,
  B00100000,
  B00100000,
  B11000000,
  4,

  // t
  B11100000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  4,

  // u
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B11100000,
  4,

  // v
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B10100000,
  B01000000,
  4,

  // w
  B10001000,
  B10001000,
  B10001000,
  B10101000,
  B10101000,
  B01010000,
  6,

  // x
  B10100000,
  B10100000,
  B01000000,
  B10100000,
  B10100000,
  B10100000,
  4,

  // y
  B10100000,
  B10100000,
  B11100000,
  B00100000,
  B00100000,
  B11000000,
  4,

  // z
  B11100000,
  B00100000,
  B01100000,
  B11000000,
  B10000000,
  B11100000,
  4,

  // {
  B01100000,
  B01000000,
  B10000000,
  B10000000,
  B01000000,
  B01100000,
  4,

  // |
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  2,

  // }
  B11000000,
  B01000000,
  B00100000,
  B00100000,
  B01000000,
  B11000000,
  4,

  // ~
  B01000000,
  B10101000,
  B00010000,
  B00000000,
  B00000000,
  B00000000,
  6
};


