# FasterEdge MCU - PMS150C（应广 PM-IDE 版）

PMS150C 为应广科技 (Feeling) 极低端 8 位 MCU（PDK14 内核）：**1KW OTP / 64B RAM / 无 UART / 6 引脚**。
资源过小，本平台按「只实现基础寄存器控制」裁剪：PA0 输出 LED、PA1 按键输入、芯片信息。

## 开发环境

- **PM-IDE**（应广官方 IDE，免费，含汇编/Mini-C 编译器与 OTP Writer 烧录）
- 芯片：**PMS150C**（SOT23-6）
- 烧录：PM-IDE 内置 OTP Writer（需应广烧录器）

## 使用方法

1. 安装 PM-IDE，`File → New Project`，芯片选 **PMS150C**
2. 将 `src/main.c`（或改写成 Mini-C / 汇编）加入工程
3. PM-IDE 会自动带 `PMS150C.h` 等官方头文件（本目录同名头仅供语法检查参考）
4. Build → 生成 `.pdk/.bin` → OTP Writer 烧录

## 能力裁剪说明

| 能力 | 状态 | 说明 |
|------|------|------|
| GpioAbility | ✅ | PA0 输出 / PA1 输入（IOSTA+PA 寄存器级） |
| ChipData.info | ✅ | 芯片信息 |
| Base / Role / Time / OneKey / Serial / Modbus / Reg | ❌ | 无 UART、RAM 仅 64B、OTP 仅 1KW |

> Free-PDK 开源工具链（PlatformIO）版本见 `../platformio_ide/`。
