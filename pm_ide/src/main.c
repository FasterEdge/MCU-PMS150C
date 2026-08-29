// main.c — FasterEdge MCU PMS150C 极简版（应广 PM-IDE）
// PMS150C 资源极小（1KW OTP / 64B RAM / 无 UART / 6 引脚），
// 只实现「寄存器/GPIO 基础控制」：PA0 输出（LED）、PA1 输入（按键）。
// 对应能力子集：GpioAbility（mode/write/read）+ ChipData（info）
#include "pms150c.h"

static void gpio_set_output(u8 pin) { IOSTA &= (u8)~(1u << pin); }
static void gpio_set_input(u8 pin)  { IOSTA |= (u8)(1u << pin); }
static void gpio_write(u8 pin, u8 v){ if (v) PA |= (u8)(1u << pin); else PA &= (u8)~(1u << pin); }
static u8   gpio_read(u8 pin)       { return (PA >> pin) & 1u; }

static void delay(void) { volatile u16 i; for (i = 0; i < 30000u; i++) ; }

int main(void) {
    gpio_set_output(PIN_PA0);   // LED
    gpio_set_input(PIN_PA1);    // 按键
    for (;;) {
        if (gpio_read(PIN_PA1)) gpio_write(PIN_PA0, 1);
        else                    gpio_write(PIN_PA0, 0);
        delay();
    }
}
