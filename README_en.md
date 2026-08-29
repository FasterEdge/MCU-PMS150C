<div align="center">
<img src="https://avatars.githubusercontent.com/u/245985800?s=200&v=4" style="width:100px;" width="100"/>
<h2>FasterEdge MCU - PMS150C</h2>
<h3>FasterEdge framework on Feeling PMS150C (PM-IDE / PlatformIO editions)</h3>
</div>

### 1. Introduction

This repo implements the **[FasterEdge](https://github.com/FasterEdge/FasterEdge)** framework on the **Feeling Technology PMS150C** in minimal form. The PMS150C is a PDK14 core with **1KW OTP program, 64B RAM, 6 pins, no UART** — one of the smallest MCUs. Following the "**register-only base control**" design, it is trimmed to GPIO control + chip info.

- ✅ **pm_ide/ (official Feeling PM-IDE)** + **platformio_ide/ (Free-PDK open-source toolchain)** dual editions
- ✅ Register-level GPIO control (direct IOSTA/PA)
- ✅ Minimal command set fitting 1KW OTP / 64B RAM limit

### 2. Implemented Capabilities (minimal subset)

| Name | Type | Commands/Function | Description |
|------|------|-------------------|-------------|
| `GpioAbility` | Ability | `mode` / `write` / `read` | PA0 output (LED), PA1 input (button), register-level |
| `ChipData` | Data | `info` | chip info (fixed string) |

**Example (main loop):** button PA1 pressed → light PA0, else off.

### 3. Excluded Capabilities

| Capability | Reason |
|------------|--------|
| Base/Role/Time/OneKey/Serial/Modbus/RegAbility | No UART (no serial command channel), RAM only 64B, OTP only 1KW |
| ConfigData | No EEPROM/Flash to persist |
| All network abilities | PMS150C has no network |

### 4. Directory Layout

```
MCU-PMS150C/
├── pm_ide/                     # official Feeling PM-IDE
│   ├── pms150c.h               # register map / pin constants
│   ├── fe_port.h               # porting layer (GPIO / info)
│   └── src/main.c              # register-level GPIO demo
└── platformio_ide/             # PlatformIO + free-pdk (open-source)
    ├── platformio.ini          # board = padauk-pms150c
    └── src/main.asm            # PDK assembly (PA0 out / PA1 in)
```

> PMS150C has no UART; both editions demo **register-level GPIO control** and do not provide a serial command interpreter.

### 5. Usage

1. **pm_ide edition**: PM-IDE → New Project → chip PMS150C → add `src/main.c` (or Mini-C/assembly) → Build → OTP Writer
2. **platformio_ide edition**: `cd platformio_ide && pio run -t upload` (free-pdk platform)
3. Wiring: PA0 → LED (series resistor), PA1 → button

### 6. Platform Differences

| Aspect | ESP32/ESP8266 | PMS150C |
|--------|---------------|---------|
| Architecture | Xtensa 32-bit | **PDK14 (14-bit instructions)** |
| Program / RAM | KB~MB | **1KW OTP / 64B** |
| Peripherals | WiFi/UART/ADC etc | **GPIO + timer only** |
| Serial | Yes | **No** |
| Storage | NVS / Flash | **OTP one-time programmable** |

### 7. Capability Trimming Notes

PMS150C, like [PIC10F200](../MCU-PIC10F200), is ultra-low-end and only does **register-level GPIO base control**. For the full capability set, switch to [MCU-C51](../MCU-C51) / [MCU-CH32V003](../MCU-CH32V003) and other larger-resource platforms.

### 8. Sibling Projects

- **[FasterEdge MCU - C51](https://github.com/FasterEdge/MCU-C51)**: 8-bit 8051 (full capabilities)
- **[FasterEdge MCU - PIC10F200](https://github.com/FasterEdge/MCU-PIC10F200)**: also ultra-low-end
- **[FasterEdge MCU - Arduino Uno R3](https://github.com/FasterEdge/MCU-Arduino-Uno-R3)**: 8-bit AVR
- **[FasterEdge](https://github.com/FasterEdge/FasterEdge)**: framework main repo
