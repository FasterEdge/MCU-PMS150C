# FasterEdge MCU - PMS150C（PlatformIO + Free-PDK 版）

**Free-PDK** 是应广 (Padauk/Feeling) 芯片的开源工具链（基于 SDCC），PlatformIO 有 `free-pdk` 平台。

## 使用方法

```bash
cd platformio_ide
pio run            # 编译（PMS150C → bin）
pio run -t upload  # 烧录（需 free-pdk 支持的烧录器/或配合 PM-IDE）
```

## 能力裁剪说明

PMS150C 无 UART、RAM 仅 64B、OTP 仅 1KW，只实现：
- **GpioAbility**：PA0 输出 / PA1 输入，寄存器级 IOSTA/PA 操作
- **ChipData.info**：芯片信息

示例 `src/main.asm`（汇编）与 `../pm_ide/` 的 C 逻辑一致。
