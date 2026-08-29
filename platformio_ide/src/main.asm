; ============================================================
; FasterEdge MCU - PMS150C 极简版（Free-PDK / PDK14 汇编）
; PMS150C: 1KW OTP / 64B RAM / 无 UART / 6 引脚
; 能力子集（仅基础寄存器控制）：
;   PA0 输出（LED），PA1 输入（按键），寄存器级 IOST/PA 操作
; 对应能力：GpioAbility（mode/write/read）+ ChipData（info）
; 注：PDK 指令集为 14 位；以下是应广/Free-PDK 汇编风格示例，
;     实际操作符以 free-pdk 工具链文档为准（IOSTA 端口方向寄存器）。
; ============================================================
        ; 定义工作寄存器/端口（参考 free-pdk include/pms150c.inc）
        ; PA 数据端口、IOSTA 方向寄存器由汇编器宏提供

start:
        ; PA0 = 输出, PA1 = 输入
        IOST    IOSTA           ; 选择端口 A 方向寄存器
        MOV     A, #0b00000010 ; PA1 输入, PA0 输出
        MOV     IOSTA, A

loop:
        ; 读 PA1（按键按下=0 则点亮 PA0）
        T0SN    PA.1            ; PA1 为 1 则跳过
        JMP     led_on
        SET1    PA.0            ; 熄灭
        JMP     delay
led_on:
        CLR     PA.0            ; 点亮
delay:
        ; 简单延时
        MOV     A, #0xFF
        MOV     _t, A
d1:
        DZSN    _t
        JMP     d1
        JMP     loop

        END
