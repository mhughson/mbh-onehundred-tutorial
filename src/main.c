/** (C) Matt Hughson 2025 */

#include "../inc/neslib.h"
#include "../inc/nesdoug.h"

#include "main.h"

#pragma bss-name(push, "ZEROPAGE")

#pragma bss-name(pop)

#pragma bss-name(push, "BSS")

#pragma bss-name(pop)

#pragma bss-name(push, "CODE")

void main (void)
{
	ppu_off(); // screen off

	// use the second set of tiles for sprites
	// both bg and sprites are set to 0 by default
	bank_spr(1);

	set_vram_buffer(); // do at least once, sets a pointer to a buffer
	clear_vram_buffer();

	ppu_on_all(); // turn on screen

	// infinite loop
	while (1)
	{
		ppu_wait_nmi(); // wait till beginning of the frame

		// pad1 = pad_poll(0); // read the first controller
		// pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first

		// pad2 = pad_poll(1);
		// pad2_new = get_pad_new(1);

		// Combine both controllers into one.
		// pad_all = pad1 | pad2;
		// pad_all_new = pad1_new | pad2_new;

		clear_vram_buffer(); // do at the beginning of each frame

		// TODO: Game
	}
}

#pragma bss-name(pop)