// ─────────────────────────────────────────────────────────────
// FasterEdge 开源项目
// Github: https://github.com/FasterEdge
// Gitee:  https://gitee.com/FasterEdge
// ─────────────────────────────────────────────────────────────
// fe_port.h — FasterEdge MCU 平台移植层（PMS150C 极简版）
// PMS150C 资源极小（1KW OTP / 64B RAM / 无 UART），
// 本平台只实现「寄存器/GPIO 基础控制」能力子集：
//   GpioAbility（GPIO 控制） / BaseData / ChipData
#ifndef FE_PORT_H
#define FE_PORT_H

#include "pms150c.h"

// ---- GPIO（GpioAbility）----
int  fe_port_gpio_set_mode(u8 pin, const char *mode); // input / output
int  fe_port_gpio_write(u8 pin, u8 level);
int  fe_port_gpio_read(u8 pin);

// ---- 信息（BaseData / ChipData）----
void fe_port_chip_info(char *out, u16 outlen);
void fe_port_delay_ms(u32 ms);

#endif // FE_PORT_H
