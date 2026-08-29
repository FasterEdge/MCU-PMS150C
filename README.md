<div align="center">
<img src="https://avatars.githubusercontent.com/u/245985800?s=200&v=4" style="width:100px;" width="100"/>
<h2>FasterEdge MCU - PMS150C</h2>
<h3>FasterEdge 框架的应广 PMS150C 平台实现（PM-IDE / PlatformIO 版）</h3>
</div>

### 一、简介

本项目是 **[FasterEdge](https://github.com/FasterEdge/FasterEdge)** 框架在 **应广科技 (Feeling) PMS150C** 上的极简实现。PMS150C 为 PDK14 内核、**1KW OTP 程序、64B RAM、6 引脚、无 UART**，是资源最小的 MCU 之一，因此按「**只实现基础寄存器控制**」裁剪为 GPIO 控制 + 芯片信息。

- ✅ **pm_ide/（应广官方 PM-IDE）** + **platformio_ide/（Free-PDK 开源工具链）** 双版本
- ✅ 寄存器级 GPIO 控制（IOSTA/PA 直接操作）
- ✅ 极简命令集，适配 1KW OTP / 64B RAM 极限

### 二、已实现能力（极简裁剪）

| 名称 | 类型 | 命令/功能 | 说明 |
|------|------|-----------|------|
| `GpioAbility` | Ability | `mode` / `write` / `read` | PA0 输出（LED）、PA1 输入（按键），寄存器级 |
| `ChipData` | Data | `info` | 芯片信息（固定字符串）|

**示例（主循环逻辑）：** PA1 按键按下 → 点亮 PA0，否则熄灭。

### 三、排除项与理由

| 能力 | 排除原因 |
|------|---------|
| Base/Role/Time/OneKey/Serial/Modbus/RegAbility | 无 UART（无串口命令通道）、RAM 仅 64B、OTP 仅 1KW |
| ConfigData | 无 EEPROM/Flash 可持久化 |
| 所有网络能力 | PMS150C 无网络 |

### 四、目录结构

```
MCU-PMS150C/
├── pm_ide/                     # 应广官方 PM-IDE
│   ├── pms150c.h               # 寄存器映射 / 引脚常量
│   ├── fe_port.h               # 移植层接口（GPIO / 信息）
│   └── src/main.c              # 寄存器级 GPIO 控制演示
└── platformio_ide/             # PlatformIO + free-pdk（开源工具链）
    ├── platformio.ini          # board = padauk-pms150c
    └── src/main.asm            # PDK 汇编（PA0 输出 / PA1 输入）
```

> PMS150C 无 UART，两个版本均以 **GPIO 寄存器控制** 演示，不提供串口命令解释器。

### 五、使用说明

1. **pm_ide 版**：PM-IDE 新建工程 → 芯片选 PMS150C → 加入 `src/main.c`（或转 Mini-C/汇编）→ Build → OTP Writer 烧录
2. **platformio_ide 版**：`cd platformio_ide && pio run -t upload`（free-pdk 平台）
3. 接线：PA0 → LED（串联电阻），PA1 → 按键

### 六、平台适配要点

| 差异点 | ESP32/ESP8266 | PMS150C |
|--------|--------------|---------|
| 架构 | Xtensa 32 位 | **PDK14（14 位指令）** |
| 程序 / RAM | KB~MB | **1KW OTP / 64B** |
| 外设 | WiFi/UART/ADC 等 | **仅 GPIO + 定时器** |
| 串口 | 有 | **无** |
| 存储 | NVS / Flash | **OTP 一次性可编程** |

### 七、能力裁剪说明

PMS150C 与 [PIC10F200](../MCU-PIC10F200) 同为极低端，只做**寄存器级 GPIO 基础控制**。若需完整能力集，请改用 [MCU-C51](../MCU-C51) / [MCU-CH32V003](../MCU-CH32V003) 等更大资源平台。

### 八、姊妹项目

- **[FasterEdge MCU - C51](https://github.com/FasterEdge/MCU-C51)**：8 位 8051（能力全）
- **[FasterEdge MCU - PIC10F200](https://github.com/FasterEdge/MCU-PIC10F200)**：同为极低端
- **[FasterEdge MCU - Arduino Uno R3](https://github.com/FasterEdge/MCU-Arduino-Uno-R3)**：8 位 AVR
- **[FasterEdge](https://github.com/FasterEdge/FasterEdge)**：框架主仓库
