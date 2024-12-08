# STM32_BareMetal_NoIDE


Minimal working example of flashing code to stm32 without ide.


just run 

make

then

sudo openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program test.bin 0x8000000 verify reset exit"
