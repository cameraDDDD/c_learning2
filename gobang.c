#include<graphics.h>
#define N 20


/*�������*/
#define up 0x4800
#define down 0x5000
#define left 0x4b00
#define right 0x4d00
#define esc 0x011b
#define enter 0x1c0d
#define A 0x1e61
#define S 0x1f73
#define D 0x2064
#define W 0x1177
#define space 0x3920
#define Y 0x1579
#define n 0x316e
int gamespeed=5000;
int i,j,key;
struct Sor
{
     int x;
     int y;/*x,y��ʾ��ǰ����λ��*/
     int yes[N][N];/* 0��ʾ�����ӣ�1��ʾ��ɫ���ӣ�2��ʾ��ɫ����*/
     int kao;/* 1��ʾ����׼�����ӣ�2��ʾ��������*/
     int ok;/*1��ʾ����ʤ����2��ʾ����ʤ��*/
}sor;
char hong64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x1E,0x00,0x00,0x03,0xE0,0x00,
  0x00,0x00,0x1C,0x18,0x00,0x1F,0xE0,0x00,
  0x00,0x00,0x3C,0x38,0x7F,0xFF,0xE0,0x00,
  0x00,0x00,0x78,0x70,0xFF,0xFF,0xE0,0x00,
  0x00,0x00,0xFF,0xE0,0xFF,0xFF,0xE0,0x00,
  0x00,0x01,0xFF,0xE0,0x7F,0xFF,0x80,0x00,
  0x00,0x07,0xFF,0xC0,0x7F,0xFF,0x00,0x00,
  0x00,0x1F,0xFF,0x80,0x7F,0xFC,0x00,0x00,
  0x00,0x0F,0xFF,0x00,0x7F,0xF8,0x00,0x00,
  0x00,0x0F,0xFE,0x00,0x01,0xF8,0x00,0x00,
  0x00,0x0F,0xFE,0x00,0x01,0xF8,0x00,0x00,
  0x00,0x07,0x1C,0x20,0x01,0xF0,0x00,0x00,
  0x00,0x04,0x1F,0xE0,0x01,0xF0,0x00,0x00,
  0x00,0x00,0x3F,0xE0,0x01,0xF0,0x00,0x00,
  0x00,0x00,0x7F,0xE0,0x01,0xF0,0x00,0x00,
  0x00,0x00,0x7F,0xC0,0x01,0xF0,0x00,0x00,
  0x00,0x00,0xFF,0x80,0x01,0xF0,0x00,0x00,
  0x00,0x01,0xFE,0x00,0x01,0xF0,0x00,0x00,
  0x00,0x07,0xF8,0x00,0x01,0xF0,0x00,0x00,
  0x00,0x03,0xE0,0x00,0x01,0xF0,0x00,0x00,
  0x00,0x03,0xC0,0x60,0x03,0xE0,0x00,0x00,
  0x00,0x01,0x80,0xE0,0x03,0xF0,0x00,0x00,
  0x00,0x00,0x03,0xE0,0x03,0xFF,0xFE,0x00,
  0x00,0x00,0x07,0x80,0x07,0xFF,0xFF,0x80,
  0x00,0x00,0x1F,0x00,0x3F,0xFF,0xFF,0x80,
  0x00,0x00,0x7E,0x01,0xFF,0xFF,0xFF,0xC0,
  0x00,0x00,0xF8,0x0F,0xFF,0xFF,0xFF,0xC0,
  0x00,0x03,0xF0,0x7F,0xF0,0x00,0x03,0xC0,
  0x00,0x0F,0xE0,0xFE,0x00,0x00,0x00,0x00,
  0x00,0x0F,0xC0,0x70,0x00,0x00,0x00,0x00,
  0x00,0x0F,0x80,0x40,0x00,0x00,0x00,0x00,
  0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char fang64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xC0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,
  0x00,0x00,0x00,0x00,0x03,0xFF,0xFC,0x00,
  0x00,0x00,0x00,0x00,0x3F,0xFF,0xFE,0x00,
  0x00,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x00,
  0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFE,0x00,
  0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFE,0x00,
  0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFE,0x00,
  0x00,0x00,0x7F,0xFF,0xF8,0x00,0x1E,0x00,
  0x00,0x0F,0xFF,0xFF,0xF8,0x00,0x00,0x00,
  0x00,0xFF,0xFF,0x00,0xF8,0x00,0x00,0x00,
  0x00,0x7F,0xE0,0x01,0xFC,0x00,0x00,0x00,
  0x00,0x7F,0x00,0x01,0xE6,0x00,0x00,0x00,
  0x00,0x60,0x00,0x03,0xC3,0x80,0x00,0x00,
  0x00,0x00,0x00,0x07,0x81,0xC0,0x00,0x00,
  0x00,0x00,0x00,0x07,0x00,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x0F,0x00,0xF8,0x00,0x00,
  0x00,0x00,0x00,0x1E,0x00,0xFC,0x00,0x00,
  0x00,0x00,0x00,0x3C,0x00,0xFC,0x00,0x00,
  0x00,0x00,0x00,0x78,0x00,0xF8,0x00,0x00,
  0x00,0x00,0x01,0xF0,0x01,0xF0,0x00,0x00,
  0x00,0x00,0x03,0xE0,0x01,0xE0,0x00,0x00,
  0x00,0x00,0x07,0xC0,0x03,0xE0,0x00,0x00,
  0x00,0x00,0x1F,0x80,0x03,0xC0,0x00,0x00,
  0x00,0x00,0x7F,0x00,0x07,0xC0,0x00,0x00,
  0x00,0x01,0xFF,0x00,0x0F,0x80,0x00,0x00,
  0x00,0x07,0xFF,0x00,0x0F,0x80,0x00,0x00,
  0x00,0x1F,0xF8,0x00,0x1F,0x00,0x00,0x00,
  0x00,0x3F,0xC0,0x10,0x3E,0x00,0x00,0x00,
  0x00,0x00,0x00,0x0F,0xFE,0x00,0x00,0x00,
  0x00,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xF8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char huo64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0xE0,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x03,0xC0,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x03,0xC0,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x03,0x80,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x07,0x81,0xC0,0x00,
  0x00,0x00,0x00,0xF0,0x07,0xFF,0xC0,0x00,
  0x00,0x00,0x00,0xF0,0x0F,0xFF,0xC0,0x00,
  0x00,0x00,0x00,0x7F,0xFF,0xFF,0x00,0x00,
  0x00,0x00,0x01,0xFF,0xFF,0xE0,0x00,0x00,
  0x00,0x00,0x3F,0xFC,0x1F,0x00,0x00,0x00,
  0x00,0x00,0x7F,0xF8,0x1C,0x00,0x00,0x00,
  0x00,0x00,0x7F,0x38,0x18,0x00,0x00,0x00,
  0x00,0x00,0x3C,0x10,0x30,0x00,0x00,0x00,
  0x00,0x00,0x10,0x00,0x30,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x0E,0x00,0x80,0x00,
  0x00,0x00,0x00,0x20,0x04,0x00,0xE0,0x00,
  0x00,0x00,0x30,0x70,0x04,0x00,0xF0,0x00,
  0x00,0x00,0x1F,0xF0,0x04,0x00,0xF8,0x00,
  0x00,0x00,0x0F,0xF0,0x0C,0x00,0x78,0x00,
  0x00,0x00,0x07,0xE0,0x0C,0x00,0x00,0x00,
  0x00,0x00,0x07,0xC0,0x0F,0xF8,0x00,0x00,
  0x00,0x00,0x0F,0xC0,0x0F,0xF8,0x00,0x00,
  0x00,0x00,0x1F,0xE0,0x1F,0xF8,0x00,0x00,
  0x00,0x00,0x1F,0xF0,0xFF,0xF0,0x00,0x00,
  0x00,0x00,0x39,0xFF,0xFF,0xC0,0x00,0x00,
  0x00,0x00,0x61,0xFF,0xFF,0x00,0x00,0x00,
  0x00,0x00,0xC1,0xC3,0xFE,0x00,0x00,0x00,
  0x00,0x01,0x83,0xC1,0xFC,0x00,0x00,0x00,
  0x00,0x0F,0x03,0xC1,0x9C,0x00,0x00,0x00,
  0x00,0x0C,0x07,0xC0,0x1E,0x00,0x00,0x00,
  0x00,0x0C,0x0C,0xC0,0x1F,0x00,0x00,0x00,
  0x00,0x00,0x10,0xC0,0x1F,0x80,0x00,0x00,
  0x00,0x00,0x20,0xC0,0x3F,0xC0,0x00,0x00,
  0x00,0x00,0x60,0xC0,0x3F,0xE0,0x00,0x00,
  0x00,0x00,0xC0,0xC0,0x3F,0xF0,0x00,0x00,
  0x00,0x03,0x80,0xC0,0x60,0x38,0x00,0x00,
  0x00,0x07,0x80,0x80,0xE0,0x0E,0x00,0x00,
  0x00,0x0F,0x00,0x81,0xC0,0x07,0x00,0x00,
  0x00,0x3C,0x00,0x87,0xC0,0x07,0xC0,0x00,
  0x00,0x00,0x01,0xFF,0x80,0x03,0xF0,0x00,
  0x00,0x00,0x01,0xFF,0x00,0x03,0xFE,0x00,
  0x00,0x00,0x01,0xFC,0x00,0x01,0xFF,0xC0,
  0x00,0x00,0x01,0xE0,0x00,0x00,0xFF,0xF0,
  0x00,0x00,0xFF,0x80,0x00,0x00,0x7F,0xF8,
  0x00,0x00,0x7F,0x80,0x00,0x00,0x1F,0xF8,
  0x00,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0F,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char sheng64H[]={
/* ������ 'ʤ' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,
  0x00,0x00,0x00,0xE0,0x00,0x0F,0x00,0x00,
  0x00,0x00,0x07,0xFC,0x00,0x1F,0x00,0x00,
  0x00,0x00,0x7F,0xFC,0x00,0x1E,0x00,0x00,
  0x00,0x00,0xF0,0x7C,0x00,0x1E,0x00,0x00,
  0x00,0x00,0xC0,0x78,0x00,0x1E,0x00,0x00,
  0x00,0x00,0xC0,0x78,0x00,0x1E,0x00,0x00,
  0x00,0x01,0xC0,0x38,0x00,0x1E,0x00,0x00,
  0x00,0x01,0x80,0x38,0x00,0x1E,0x00,0x00,
  0x00,0x01,0x80,0x30,0x00,0x1E,0x00,0x00,
  0x00,0x01,0x80,0x30,0x00,0x1E,0x00,0x00,
  0x00,0x01,0xCC,0x70,0x00,0x1E,0x00,0x00,
  0x00,0x01,0xFE,0x70,0x10,0x1E,0x30,0x00,
  0x00,0x01,0xFC,0x70,0x38,0x1F,0xF0,0x00,
  0x00,0x01,0xFC,0x70,0x3F,0xFF,0xF0,0x00,
  0x00,0x01,0xF8,0x70,0x3F,0xFF,0xF0,0x00,
  0x00,0x01,0xE0,0x70,0x7F,0xFF,0xE0,0x00,
  0x00,0x01,0xC0,0x70,0x7F,0xFF,0xC0,0x00,
  0x00,0x01,0x80,0x70,0xFF,0xFF,0x00,0x00,
  0x00,0x03,0x00,0x71,0xF1,0xFC,0x00,0x00,
  0x00,0x03,0x0C,0x71,0xC0,0x7C,0x00,0x00,
  0x00,0x03,0xFC,0x73,0x80,0x3C,0x00,0x00,
  0x00,0x03,0xFC,0x7F,0x00,0x3C,0x00,0x00,
  0x00,0x03,0xFC,0x7E,0x00,0x3C,0x00,0x00,
  0x00,0x03,0xF8,0x7C,0x00,0x3F,0xF0,0x00,
  0x00,0x07,0xF0,0x70,0x00,0x7F,0xF0,0x00,
  0x00,0x07,0xC0,0x30,0x1F,0xFF,0xF0,0x00,
  0x00,0x07,0x00,0x30,0x1F,0xFF,0xF0,0x00,
  0x00,0x0E,0x00,0x30,0x0F,0xFF,0xE0,0x00,
  0x00,0x08,0x00,0x30,0x0F,0xFF,0x80,0x00,
  0x00,0x08,0x00,0x30,0x0F,0xFC,0x00,0x00,
  0x00,0x18,0x00,0x30,0x00,0x38,0x00,0x00,
  0x00,0x18,0x00,0x30,0x00,0x38,0x00,0x00,
  0x00,0x38,0x00,0x30,0x00,0x38,0x00,0x00,
  0x00,0x78,0x00,0x30,0x00,0x3C,0x00,0x00,
  0x00,0x78,0x00,0x70,0x00,0x3C,0x00,0x00,
  0x00,0xF0,0x00,0x60,0x00,0x3E,0x03,0x00,
  0x01,0xF0,0x00,0x60,0x00,0x7F,0xFF,0x80,
  0x03,0xE0,0x00,0x60,0x03,0xFF,0xFF,0xC0,
  0x03,0xC0,0x00,0xE0,0x3F,0xFF,0xFF,0xC0,
  0x07,0x80,0x7F,0xF1,0xFF,0xFF,0xFF,0xC0,
  0x0F,0x00,0x3F,0xF1,0xFF,0xF8,0x07,0xC0,
  0x1C,0x00,0x1F,0xF0,0xF0,0x00,0x00,0x00,
  0x10,0x00,0x0F,0xF0,0x80,0x00,0x00,0x00,
  0x00,0x00,0x03,0xF0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char bai64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xC0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x1F,0x80,0x00,0x00,0x00,
  0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,
  0x00,0x00,0x01,0xF0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x70,0x00,0x0F,0xF0,0x00,0x00,
  0x00,0x00,0x60,0x01,0xFF,0xFE,0x00,0x00,
  0x00,0x00,0xE0,0x0F,0xFF,0xFF,0xC0,0x00,
  0x00,0x01,0xE0,0x7F,0xF0,0x3F,0xF0,0x00,
  0x00,0x03,0xE3,0xFF,0x80,0x0F,0xF0,0x00,
  0x00,0x07,0xFF,0xFC,0x00,0x0F,0xE0,0x00,
  0x00,0x0F,0xFF,0xF0,0x00,0x0F,0xE0,0x00,
  0x00,0x1F,0xFF,0xC0,0x00,0x0F,0xC0,0x00,
  0x00,0x3F,0xFF,0x00,0x00,0x0F,0xC0,0x00,
  0x00,0x7F,0xFE,0x00,0xF8,0x0F,0xC0,0x00,
  0x00,0x7C,0x7C,0x0F,0xF8,0x0F,0x80,0x00,
  0x00,0x70,0x3C,0x1F,0xF0,0x0F,0x80,0x00,
  0x00,0x40,0x3C,0x1F,0xF0,0x1F,0x80,0x00,
  0x00,0x00,0x3C,0x1F,0xC0,0x1F,0x00,0x00,
  0x00,0x00,0x3C,0x0F,0x00,0x1F,0x00,0x00,
  0x00,0x00,0x1E,0x06,0x00,0x1F,0x00,0x00,
  0x00,0x00,0x1E,0x00,0x00,0x3E,0x00,0x00,
  0x00,0x00,0x0E,0x00,0x00,0x3E,0x00,0x00,
  0x00,0x00,0x0E,0x00,0x00,0x3E,0x00,0x00,
  0x00,0x00,0x0F,0x00,0xE0,0x7C,0x00,0x00,
  0x00,0x00,0x07,0x03,0xF0,0x7C,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xF8,0xFC,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xFF,0xF8,0x00,0x00,
  0x00,0x00,0x01,0xFF,0x87,0xF8,0x00,0x00,
  0x00,0x00,0x01,0xF0,0x03,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x80,0x00,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

char wu64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,
  0x00,0x00,0x00,0x00,0x07,0xF8,0x00,0x00,
  0x00,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,
  0x00,0x00,0x00,0x03,0xFF,0xF8,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xFF,0xF0,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xFF,0xC0,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xFF,0x80,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x00,
  0x00,0x00,0x01,0xFF,0xFC,0x00,0x00,0x00,
  0x00,0x00,0x01,0xFF,0xF8,0x00,0x00,0x00,
  0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x07,0xFF,0xC0,0x00,0x00,
  0x00,0x00,0x00,0x07,0xFF,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x0F,0xFF,0xFC,0x00,0x00,
  0x00,0x00,0x00,0x3F,0xFF,0xFC,0x00,0x00,
  0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,
  0x00,0x00,0x1F,0xFF,0x83,0xF0,0x00,0x00,
  0x00,0x00,0x3F,0xFF,0x03,0xF0,0x00,0x00,
  0x00,0x00,0x18,0x1F,0x03,0xF0,0x00,0x00,
  0x00,0x00,0x00,0x1E,0x03,0xE0,0x00,0x00,
  0x00,0x00,0x00,0x1C,0x03,0xE0,0x00,0x00,
  0x00,0x00,0x00,0x3C,0x03,0xE0,0x00,0x00,
  0x00,0x00,0x00,0x38,0x03,0xC0,0x00,0x00,
  0x00,0x00,0x00,0x78,0x07,0xC0,0x00,0x00,
  0x00,0x00,0x00,0x78,0x07,0x80,0x00,0x00,
  0x00,0x00,0x00,0x70,0x07,0x80,0x00,0x00,
  0x00,0x00,0x00,0xF0,0x0F,0x80,0x00,0x00,
  0x00,0x00,0x00,0xF0,0xFF,0x80,0x00,0x00,
  0x00,0x00,0x01,0xFF,0xFF,0xFF,0xF8,0x00,
  0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFC,0x00,
  0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFE,0x00,
  0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,
  0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,
  0x00,0xFF,0xFF,0xC0,0x00,0x01,0xFF,0x00,
  0x00,0xFF,0xE0,0x00,0x00,0x00,0x1F,0x00,
  0x00,0xFE,0x00,0x00,0x00,0x00,0x07,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char zi64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xFF,0x00,0x00,0x00,
  0x00,0x00,0x00,0x1F,0xFF,0xC0,0x00,0x00,
  0x00,0x00,0x00,0x7F,0xFF,0xE0,0x00,0x00,
  0x00,0x00,0x01,0xFE,0x0F,0xE0,0x00,0x00,
  0x00,0x00,0x07,0xF8,0x0F,0xC0,0x00,0x00,
  0x00,0x00,0x1F,0xE0,0x0F,0x80,0x00,0x00,
  0x00,0x00,0x7F,0xC0,0x0F,0x00,0x00,0x00,
  0x00,0x00,0x7F,0x00,0x1E,0x00,0x00,0x00,
  0x00,0x00,0x3C,0x00,0x1C,0x00,0x00,0x00,
  0x00,0x00,0x18,0x00,0x38,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xFF,0xFF,0xE0,0x00,
  0x00,0x00,0x00,0x00,0xFF,0xFF,0xF0,0x00,
  0x00,0x00,0x00,0x03,0xFF,0xFF,0xF0,0x00,
  0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF8,0x00,
  0x00,0x00,0x01,0xFF,0xFF,0xFF,0xF8,0x00,
  0x00,0x00,0x0F,0xFF,0xFC,0x00,0x3C,0x00,
  0x00,0x00,0x7F,0xFF,0xF8,0x00,0x04,0x00,
  0x00,0x07,0xFF,0xF8,0x78,0x00,0x00,0x00,
  0x00,0x7F,0xFF,0x80,0x78,0x00,0x00,0x00,
  0x00,0x7F,0xE0,0x00,0x78,0x00,0x00,0x00,
  0x00,0x7E,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x30,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x20,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x06,0x00,0xF0,0x00,0x00,0x00,
  0x00,0x00,0x03,0xFF,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x03,0xE0,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char qi64H[]={
/* ������ '��' �� 64��������κ ��ģ��512 byte */
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x03,0x80,0x00,0x04,0x00,0x00,
  0x00,0x00,0x03,0x00,0x00,0x07,0x00,0x00,
  0x00,0x00,0x03,0x00,0x00,0x0F,0x00,0x00,
  0x00,0x00,0x03,0x00,0x00,0x0F,0x00,0x00,
  0x00,0x00,0x03,0x00,0x00,0x0E,0x00,0x00,
  0x00,0x00,0x02,0x00,0x00,0x0E,0x00,0x00,
  0x00,0x00,0x02,0x00,0x30,0x0E,0x00,0x00,
  0x00,0x00,0x02,0x00,0x30,0x0E,0x00,0x00,
  0x00,0x00,0x02,0x00,0x30,0x0E,0x00,0x00,
  0x00,0x00,0x02,0x00,0x30,0x0E,0x00,0x00,
  0x00,0x00,0x06,0x00,0x30,0x0F,0x80,0x00,
  0x00,0x00,0x06,0x00,0x30,0x3F,0xE0,0x00,
  0x00,0x00,0x07,0x00,0x3F,0xFF,0xE0,0x00,
  0x00,0x00,0x07,0xE0,0x7F,0xFF,0xE0,0x00,
  0x00,0x00,0x3F,0xE3,0xFF,0xFF,0x80,0x00,
  0x00,0x01,0xFF,0xE3,0xFF,0xFE,0x00,0x00,
  0x00,0x3F,0xFF,0xC1,0xFF,0x9E,0x00,0x00,
  0x00,0x3F,0xFF,0x81,0xF0,0x1E,0x00,0x00,
  0x00,0x3F,0xFF,0x00,0x70,0x1E,0x00,0x00,
  0x00,0x3F,0xFE,0x00,0x7F,0x1C,0x00,0x00,
  0x00,0x1F,0x3E,0x00,0x7F,0x1C,0x00,0x00,
  0x00,0x18,0x1E,0x00,0x7F,0x1C,0x00,0x00,
  0x00,0x00,0x1F,0x00,0x78,0x1C,0x00,0x00,
  0x00,0x00,0x3F,0x80,0x70,0x1C,0x00,0x00,
  0x00,0x00,0x3F,0xC0,0x70,0x1C,0x00,0x00,
  0x00,0x00,0x7F,0xC0,0x7F,0x1C,0x00,0x00,
  0x00,0x00,0xFF,0xC0,0x7E,0x1C,0x00,0x00,
  0x00,0x01,0xFC,0x00,0x7E,0x1C,0x00,0x00,
  0x00,0x03,0xFC,0x00,0x78,0x1C,0x00,0x00,
  0x00,0x03,0xCC,0x00,0x70,0x1C,0x02,0x00,
  0x00,0x07,0x0C,0x00,0x60,0x1F,0xFF,0x00,
  0x00,0x0E,0x0C,0x00,0x60,0xFF,0xFF,0x00,
  0x00,0x1C,0x0C,0x00,0x7F,0xFF,0xFF,0x80,
  0x00,0x38,0x0C,0x07,0xFF,0xFF,0xFF,0x80,
  0x00,0xF0,0x0F,0xFF,0xFF,0xE0,0x00,0x80,
  0x01,0xE0,0x0F,0xFF,0x00,0x00,0x00,0x00,
  0x01,0x80,0x0F,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0C,0x00,0x00,0x08,0x00,0x00,
  0x00,0x00,0x0C,0x00,0x40,0x07,0xC0,0x00,
  0x00,0x00,0x0C,0x01,0xC0,0x03,0xF0,0x00,
  0x00,0x00,0x0C,0x07,0x80,0x01,0xF8,0x00,
  0x00,0x00,0x0C,0x1F,0x00,0x01,0xF8,0x00,
  0x00,0x00,0x0C,0x1F,0x00,0x00,0xF8,0x00,
  0x00,0x00,0x0C,0x0E,0x00,0x00,0x38,0x00,
  0x00,0x00,0x0C,0x04,0x00,0x00,0x18,0x00,
  0x00,0x00,0x1C,0x00,0x00,0x00,0x08,0x00,
  0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char zuo16H[]={
/* ������ '��' �� 16������� ��ģ��32 byte */
  0x18,0xC0,0x18,0xC0,0x19,0x80,0x31,0xFE,
  0x33,0xFE,0x76,0xC0,0xF0,0xFC,0xB0,0xFC,
  0x30,0xC0,0x30,0xC0,0x30,0xFE,0x30,0xFE,
  0x30,0xC0,0x30,0xC0,0x30,0xC0,0x00,0x00,
};
char zhe16H[]={
/* ������ '��' �� 16������� ��ģ��32 byte */
  0x03,0x00,0x03,0x0C,0x1F,0xCC,0x1F,0xD8,
  0x03,0x30,0xFF,0xFE,0xFF,0xFE,0x03,0x00,
  0x0F,0xF8,0x3F,0xF8,0xEC,0x18,0xCF,0xF8,
  0x0C,0x18,0x0F,0xF8,0x0F,0xF8,0x00,0x00,
};
char tian16H[]={
/* ������ '��' �� 16������� ��ģ��32 byte */
  0x00,0x00,0x3F,0xFC,0x3F,0xFC,0x31,0x8C,
  0x31,0x8C,0x31,0x8C,0x3F,0xFC,0x3F,0xFC,
  0x31,0x8C,0x31,0x8C,0x31,0x8C,0x3F,0xFC,
  0x3F,0xFC,0x30,0x0C,0x00,0x00,0x00,0x00,
};
char xue16H[]={
/* ������ 'ѧ' �� 16������� ��ģ��32 byte */
  0x33,0x18,0x19,0x98,0x08,0xB0,0x7F,0xFC,
  0x7F,0xFC,0x60,0x0C,0x1F,0xF0,0x1F,0xF0,
  0x00,0xC0,0x7F,0xFC,0x7F,0xFC,0x01,0x80,
  0x01,0x80,0x07,0x80,0x03,0x00,0x00,0x00,
};
char ke16H[]={
/* ������ '��' �� 16������� ��ģ��32 byte */
  0x00,0x00,0x0C,0x18,0xFD,0x98,0xF8,0xD8,
  0x18,0x58,0xFE,0x18,0xFE,0x98,0x18,0xD8,
  0x3C,0x58,0x7E,0x1E,0xDB,0xFE,0x9B,0xF8,
  0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,
};

void init(void)       /*graph drive*/
{
     int driver=DETECT,mode=0;
     registerbgidriver(EGAVGA_driver);
     initgraph(&driver,&mode,"");
}



void drawmat(char *mat,int matsize,int x,int y,int color)
{
     int i,j,k,m;
     m=(matsize-1)/8+1;
     for(j=0;j<matsize;j++)
     for(i=0;i<m;i++)
          for(k=0;k<8;k++)
               if(mat[j*m+i]&(0x80>>k))
                    putpixel(x+i*8+k,y+j,color);
}


void show(void)/*input word*/
{
     drawmat(wu64H,64,438,49,0);
     drawmat(zi64H,64,488,49,0);
     drawmat(qi64H,64,538,49,0);

     drawmat(wu64H,64,440,50,13);
     drawmat(zi64H,64,490,50,13);
     drawmat(qi64H,64,540,50,13);

     drawmat(zuo16H,16,480,450,8);
     drawmat(zhe16H,16,498,450,8);
     drawmat(tian16H,16,518,450,8);
     drawmat(xue16H,16,536,450,8);
     drawmat(ke16H,16,554,450,8);
}

void drawqp(void)/*draw qi pan*/
{
     setcolor(3);
     for(i=50;i<=(N-1)*20+30;i+=20)
     {
          line(50,i,(N-1)*20+30,i);
          line(i,50,i,(N-1)*20+30);
     }
     setcolor(11);
     for(i=1;i<3;i++)
     {
          circle((N-1)*10+40,(N-1)*10+40,i);
          circle(130,130,i);
          circle(130,330,i);
          circle(330,130,i);
          circle(330,330,i);
     }
}

void clew(void)  /*input message*/
{
     setcolor(15);
     settextstyle(0,0,1);
     outtextxy(50,20,"1P: Up Down Left Right Enter       2P: W S A D Space");
}

void place(void)/*��������λ��*/
{
     line(sor.x-10,sor.y-10,sor.x-7,sor.y-10);
     line(sor.x-10,sor.y-10,sor.x-10,sor.y-7);

     line(sor.x-10,sor.y+10,sor.x-10,sor.y+7);
     line(sor.x-10,sor.y+10,sor.x-7,sor.y+10);

     line(sor.x+10,sor.y-10,sor.x+10,sor.y-7);
     line(sor.x+10,sor.y-10,sor.x+7,sor.y-10);

     line(sor.x+10,sor.y+10,sor.x+7,sor.y+10);
     line(sor.x+10,sor.y+10,sor.x+10,sor.y+7);

 }

void win(void)/*�ж��Ƿ�ʤ��*/
{
     for(i=1;i<N;i++)
     {
          for(j=1;j<N;j++)
          {
               if(((j+4)<N&&sor.yes[i][j]!=0&&
                    sor.yes[i][j]==sor.yes[i][j+1]&&
                    sor.yes[i][j+1]==sor.yes[i][j+2]&&
                    sor.yes[i][j+2]==sor.yes[i][j+3]&&
                    sor.yes[i][j+3]==sor.yes[i][j+4])||

                    ((i+4)<N&&sor.yes[i][j]!=0&&
                    sor.yes[i][j]==sor.yes[i+1][j]&&
                    sor.yes[i+1][j]==sor.yes[i+2][j]&&
                    sor.yes[i+2][j]==sor.yes[i+3][j]&&
                    sor.yes[i+3][j]==sor.yes[i+4][j])||

                    ((i+4)<N&&(j+4)<N&&sor.yes[i][j]!=0&&
                    sor.yes[i][j]==sor.yes[i+1][j+1]&&
                    sor.yes[i+1][j+1]==sor.yes[i+2][j+2]&&
                    sor.yes[i+2][j+2]==sor.yes[i+3][j+3]&&
                    sor.yes[i+3][j+3]==sor.yes[i+4][j+4])||

                    ((i+4)<N&&j>4&&sor.yes[i][j]!=0&&
                    sor.yes[i][j]==sor.yes[i+1][j-1]&&
                    sor.yes[i+1][j-1]==sor.yes[i+2][j-2]&&
                    sor.yes[i+2][j-2]==sor.yes[i+3][j-3]&&
                    sor.yes[i+3][j-3]==sor.yes[i+4][j-4]))
               {
                    if(sor.yes[i][j]==1)
                         sor.ok=1;
                    else
                         sor.ok=2;
                         break;
               }
          }
          if(sor.ok!=0)
               break;
     }
}

void gameover(void)
{
     if(sor.ok==1)
     {
          drawmat(bai64H,64,488,119,0);
          drawmat(bai64H,64,490,120,4);
     }
     else
     {
          drawmat(hong64H,64,488,119,0);
          drawmat(hong64H,64,490,120,4);
     }

     drawmat(fang64H,64,488,189,0);
     drawmat(huo64H,64,488,259,0);
     drawmat(sheng64H,64,488,329,0);

     drawmat(fang64H,64,490,190,4);
     drawmat(huo64H,64,490,260,4);
     drawmat(sheng64H,64,490,330,4);
}

void xandy(void)/*��ʾ���ĺ�������*/
{
     char str1[10],str2[10];
     setfillstyle(SOLID_FILL,7);
     bar(50,440,205,470);
     setcolor(14);
     settextstyle(0,0,2);
     sprintf(str1,"X:%d",(sor.x-30)/20);
     sprintf(str2,"Y:%d",(sor.y-30)/20);
     outtextxy(60,450,str1);
     outtextxy(135,450,str2);
}

void gameplay(void)
{
     for(i=1;i<N;i++)/*���̳�ʼ��*/
          for(j=1;j<N;j++)
               sor.yes[i][j]=0;
     sor.kao=1; /*��������*/
     sor.ok=0;/*˫��ʤ��δ��*/
     sor.x=(N-1)*10+40;
     sor.y=(N-1)*10+40;/*��ʼ�����,����궨λ�����̵�����*/
     setcolor(15);
     place();

     while(1)
     {
          xandy();
          key=bioskey(0);
          if(key==esc)
               break;

          /*��������ƶ�*/
          else if(key==up&&sor.y>50&&sor.kao==1)
          {
               setcolor(0);place();
               sor.y-=20;
          }
          else if(key==down&&sor.y<(N-1)*20+30&&sor.kao==1)
          {
               setcolor(0);place();
               sor.y+=20;
          }
          else if(key==left&&sor.x>50&&sor.kao==1)
          {
               setcolor(0);place();
               sor.x-=20;
          }
          else if(key==right&&sor.x<(N-1)*20+30&&sor.kao==1)
          {
               setcolor(0);place();
               sor.x+=20;
          }

          /*�췽�����ƶ�*/
          else if(key==W&&sor.y>50&&sor.kao==2)
          {
               setcolor(0);place();
               sor.y-=20;
          }
          else if(key==S&&sor.y<(N-1)*20+30&&sor.kao==2)
          {
               setcolor(0);place();
               sor.y+=20;
          }
          else if(key==A&&sor.x>50&&sor.kao==2)
          {
               setcolor(0);place();
               sor.x-=20;
          }
          else if(key==D&&sor.x<(N-1)*20+30&&sor.kao==2)
          {
               setcolor(0);place();
               sor.x+=20;
          }
          else if(key==space&&sor.yes[(sor.x-30)/20][(sor.y-30)/20]==0&&sor.kao==2)
          {
               setcolor(13);
               for(i=1;i<=9;i++)
               {
                    circle(sor.x,sor.y,i);
                    delay(10000);
               }
               sor.yes[(sor.x-30)/20][(sor.y-30)/20]=2;
               sor.kao=1;
               win();
               if(sor.ok!=0)
               {
                    gameover();
                    break;
               }
          }
          else if(key==enter&&sor.yes[(sor.x-30)/20][(sor.y-30)/20]==0&&sor.kao==1)
          {
               setcolor(15);
               for(i=1;i<=9;i++)
               {
                    circle(sor.x,sor.y,i);
                    delay(10000);
               }
               sor.yes[(sor.x-30)/20][(sor.y-30)/20]=1;
               sor.kao=2;
               win();
               if(sor.ok!=0)
               {
                    gameover();
                    break;
               }
          }
          else
               continue;
          if(sor.ok!=0)
               break;
          if(sor.kao==1)
               setcolor(15);
          else
               setcolor(13);
          place();
     }/*endwhile(1)*/
}

main()
{
     while(1)
     {
          init();
          cleardevice();
          clew();
          drawqp();
          setfillstyle(SOLID_FILL,7);
          bar(430,50,620,410);
          show();
          gameplay();
          setcolor(15);
          settextstyle(0,0,2);
          outtextxy(230,450,"CONTINUE(Y/N)?");
          while(1)
          {
               key=bioskey(0);
               if(key==Y||key==n||key==esc)
                    break;
          }
          if(key==n||key==esc)
               break;
     }
     closegraph();
}