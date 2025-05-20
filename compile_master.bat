@echo off

:: Options
:: audio
:: code
:: run

::echo %audio%
::echo %code%
::echo %run%

set name="main"

set path=%path%;bin\

IF DEFINED audio (
	text2data.exe 	content\\audio\songs.txt -ca65
	nsf2data.exe 	content\\audio\sounds.nsf -ca65
)

IF DEFINED code (
	REM -g adds debug information, but the end result .nes file is not
	REM affected, so leave it in all the time.
	cc65 -g -Oirs src\\%name%.c --add-source
	ca65 src\\crt0.s
	ca65 src\\%name%.s -g

	REM -dbgfile does not impact the resulting .nes file.
	ld65 -C cfg\\nrom_32k_vert.cfg --dbgfile src\\%name%.dbg -o src\\%name%.nes src\\crt0.o src\\%name%.o lib\\nes.lib -Ln src\\labels.txt

	del src\\*.o

	REM mkdir build\
	move /Y src\\%name%.dbg build\ 
	move /Y src\\labels.txt build\ 
	move /Y src\\%name%.s build\ 
	move /Y src\\%name%.nes build\ 
)

if DEFINED run (
	BUILD\%name%.nes
)

::set audio
::set code
::set run