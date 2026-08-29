// pms150c.h — 应广 (Feeling) PMS150C 最小编译目标定义
// PMS150C: PDK14 内核、1KW OTP 程序、64B RAM、6 引脚（PA0-PA3 可用）、
//          内部 1MHz~32kHz RC、无 UART —— 只做寄存器/GPIO 级基础控制。
// 注：此文件供本地语法检查；PM-IDE 工程中可用官方头文件替换。
#ifndef PMS150C_H
#define PMS150C_H

#include <stdint.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#define TRUE 1
#define FALSE 0

// PMS150C I/O 端口寄存器（PDK14，等效数据内存地址）
// 实际 PM-IDE 汇编中用 IOST/PA 端口指令；此处给出等效地址供 C 语法检查
#define SFR(addr) (*(volatile u8 *)(addr))
#define PA    SFR(0x00)   // 端口 A 数据
#define IOSTA SFR(0x01)   // 端口 A 方向（1=输入）
#define PAC   SFR(0x02)   // 端口 A 控制（上拉等）
#define T16M  SFR(0x03)   // 定时器模式
#define T16   SFR(0x04)   // 定时器计数

// 引脚（SOT23-6: VDD/VSS/PA0/PA1/PA3/PA4? 常见 PA0-PA3）
#define PIN_PA0 0
#define PIN_PA1 1
#define PIN_PA2 2
#define PIN_PA3 3
#define PMSPIN_MAX 4

#endif // PMS150C_H
