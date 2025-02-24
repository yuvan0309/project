	AREA ADDITION, CODE, READONLY
	ENTRY
	MOV R0,#0x4
	MOV R1,#0x5
	ADD R2,R0,R1

XS b XS
	END
spim -file add.asm
// Output:
// SPIM Version 9.1.20 of August 1, 2013
// The SPIM S20 / S21 / S22 architecture is Copyright 1990-2013 by James Larus.
// All Rights Reserved.