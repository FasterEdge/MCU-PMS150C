// ─────────────────────────────────────────────────────────────
// FasterEdge 开源项目
// Github: https://github.com/FasterEdge
// Gitee:  https://gitee.com/FasterEdge
// ─────────────────────────────────────────────────────────────
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
#define PA    SFR(0x10)   // 端口 A 数据寄存器(pa)
#define PAC   SFR(0x11)   // 端口 A 方向寄存器(pac): 1=输出 0=输入
// 注: PMS150C 无 IOSTA; 方向由 pac(0x11) 控制。旧定义 IOSTA SFR(0x01) 指向
// SP/flag 区, 读写方向从不生效。

// 引脚（SOT23-6: VDD/VSS/PA0/PA1/PA3/PA4? 常见 PA0-PA3）
#define PIN_PA0 0
#define PIN_PA1 1
#define PIN_PA2 2
#define PIN_PA3 3
#define PMSPIN_MAX 4

#endif // PMS150C_H
