/*---------------------------------------------------------------------------------


	Simple tile mode 3 demo with more than 32k tiles
	-- alekmaul


---------------------------------------------------------------------------------*/
#include <snes.h>

extern char patterns,patterns1;
extern char palette;
extern char map, map_end;

//---------------------------------------------------------------------------------
int main(void) {
    // Initialize SNES 
	consoleInit();
	
	// Read tiles to VRAM in 2 phases because we are more than 32k
	bgInitTileSet(0, &patterns, &palette, 0, 0x8000, 256*2, BG_256COLORS, 0x1000);
	dmaCopyVram(&patterns1, 0x5000, 0x6000);

	// Copy Map to VRAM
	bgInitMapSet(0, &map, (&map_end - &map),SC_32x32, 0x0000);

	// Now Put in 256 color mode and disable other BGs except 1st one
	setMode(BG_MODE3,0); bgSetDisable(1); 
	
	// Wait for nothing :P
	while(1) {
		WaitForVBlank();
	}
	return 0;
}