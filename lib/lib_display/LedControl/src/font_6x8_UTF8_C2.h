// 6x8 ascii font
#ifndef font_6x8_UTF8_C2_h
#define font_6x8_UTF8_C2_h
/**
 * additional characters to font_6x8_base.h
 * 256 bytes
 * 
 */

/*
UTF8 after 0xC2 
    …0	…1	…2	…3	…4	…5	…6	…7	…8	…9	…A	…B	…C	…D	…E	…F
A…	NBSP¡	¢	£	¤	¥	¦	§	¨	©	ª	«	¬	SHY	®	¯
B…	°	±	²	³	´	µ	¶	·	¸	¹	º	»	¼	½	¾	¿
*/
const char font_UTF_C2_A0_BF[0xC0-0xA0][8] = {

    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x80 NBSP
    {
        0b00000100,
        0b00000000,
        0b00000100,
        0b00000100,
        0b00001110,
        0b00001110,
        0b00000100,
        0b00000000,
    }, // 0x81 ¡
    {
        0b00000000,
        0b00000100,
        0b00001110,
        0b00010000,
        0b00010000,
        0b00001110,
        0b00000100,
        0b00000000,
    }, // 0x82 ¢
    {
        0b00000110,
        0b00001001,
        0b00001000,
        0b00011110,
        0b00001000,
        0b00001001,
        0b00010111,
        0b00000000,
    }, // 0x83 £
    {
        0b00010001,
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
        0b00010001,
        0b00000000,
    }, // 0x84 ¤
    {
        0b00010001,
        0b00001010,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00000000,
    }, // 0x85 ¥
    {
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000000,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000000,
    }, // 0x86 ¦
    {
        0b00001110,
        0b00010001,
        0b00001100,
        0b00001010,
        0b00000110,
        0b00010001,
        0b00001110,
        0b00000000,
    }, // 0x87 §
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001010,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x88 ¨
    {
        0b00011110,
        0b00100001,
        0b00101101,
        0b00101001,
        0b00101101,
        0b00100001,
        0b00011110,
        0b00000000,
    }, // 0x89 ©
    {
        0b00001110,
        0b00000001,
        0b00001111,
        0b00010001,
        0b00001111,
        0b00000000,
        0b00001111,
        0b00000000,
    }, // 0x8A ª
    {
        0b00000000,
        0b00000000,
        0b00001001,
        0b00010010,
        0b00001001,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x8B «
    {
        0b00000000,
        0b00000000,
        0b00111111,
        0b00000001,
        0b00000001,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x8C ¬
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000001,
        0b00000001,
        0b00000000,
        0b11111111,
        0b00000000,
    }, // 0x8D SHY
    {
        0b00011110,
        0b00100101,
        0b00101011,
        0b00101101,
        0b00101011,
        0b00100001,
        0b00011110,
        0b00000000,
    }, // 0x8E ®
    {
        0b00000000,
        0b00001110,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x8F ¯
    {
        0b00001100,
        0b00010010,
        0b00010010,
        0b00001100,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x90 °
    {
        0b00000000,
        0b00000100,
        0b00001110,
        0b00000100,
        0b00000000,
        0b00001110,
        0b00000000,
        0b00000000,
    }, // 0x91 ±
    {
        0b00011000,
        0b00000100,
        0b00001000,
        0b00011100,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x92 ²
    {
        0b00011100,
        0b00001000,
        0b00001100,
        0b00011000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x93 ³
    {
        0b00001100,
        0b00001100,
        0b00001000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x94 ´
    {
        0b00000000,
        0b00000000,
        0b00010010,
        0b00010010,
        0b00010010,
        0b00011100,
        0b00010000,
        0b00010000,
    }, // 0x95 µ
    {
        0b00001111,
        0b00010101,
        0b00010101,
        0b00001101,
        0b00000101,
        0b00000101,
        0b00000101,
        0b00000000,
    }, // 0x96 ¶
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x97 ·
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001110,
        0b00000110,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x98 ¸
    {
        0b00001000,
        0b00011000,
        0b00001000,
        0b00001000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x99 ¹
    {
        0b00001100,
        0b00010010,
        0b00010010,
        0b00010010,
        0b00001100,
        0b00000000,
        0b00011110,
        0b00000000,
    }, // 0x9A º
    {
        0b00000000,
        0b00000000,
        0b00010010,
        0b00001001,
        0b00010010,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // 0x9B »
    {
        0b00010000,
        0b00010010,
        0b00010100,
        0b00001011,
        0b00010101,
        0b00000111,
        0b00000001,
        0b00000000,
    }, // 0x9C ¼
    {
        0b00010000,
        0b00010010,
        0b00010100,
        0b00001110,
        0b00010001,
        0b00000010,
        0b00000111,
        0b00000000,
    }, // 0x9D ½
    {
        0b00110000,
        0b00011010,
        0b00110100,
        0b00001011,
        0b00010101,
        0b00000111,
        0b00000001,
        0b00000000,
    }, // 0x9E ¾
    {
        0b00000100,
        0b00000000,
        0b00000100,
        0b00001100,
        0b00010000,
        0b00010001,
        0b00001110,
        0b00000000,
    }, // 0x9F ¿
};

#endif // font_6x8_UTF8_C2_h