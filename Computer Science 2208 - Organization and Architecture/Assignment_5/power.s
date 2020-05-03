	AREA power, CODE, READONLY
	ENTRY
		
Initial	ADR r0, Result				; Place the returned result variable in register 0.
	MOV r1, #Const_n				; Place the constant 'n' in register 1.
	MOV r2, #Const_x				; Place the constant 'x' in register 2.
	ADR sp, Stack  				; Define the stack in address sp.
		
Main	STMFD sp!, {r1-r2}				; Store the constants x and n inside the stack.
	BL PowCase				; Branch to the power function case.
	LDR r4, [fp, #-20]				; Load in the result, all 20 bytes/5 words, from the stack into register 4.
	STR r4, [r0]				; Store the result in register 4.
	ADD sp, sp, #8				; Cleans the memory space for the stack.
	MOV sp, fp    				; Reset the stack pointer to the first pointer - p1.
	LDR fp, [sp]  				; Reset the stack pointer to the first pointer - p2.
	ADD sp, sp, #4 				; Restore the stack by moving the stack pointer down 4 bytes.
	loop	b loop				; Ends the program when reached.

Realign	STREQ r4, [fp, #-4]				; Store the first pointer into the temporary pointer in register 4.
	MOV sp, fp       				; Then reset the stack pointer.
	LDR fp, [sp]     				; Reset the first pointer to the stack pointer.
	ADD sp, sp, #8	  			; Move the stack pointer down another 4 bytes.
	LDR lr, [sp, #-4]				; Load the stack pointer to the last pointer in order to return.
	MOV pc, lr					; Then return to the previous frame.
		
PowCase	STMFD sp!, {fp, lr}				; Store a space for the first pointer in the stack memory.
	MOV fp, sp				; Point the first pointer to the stack's base.
	SUB sp, sp, #4    				; Moving the stack pointer by 4 bytes reaches y.
	LDR r3, [fp, #12]  				; Load constant x from the previous stack frame.
	STMFD sp!, {r3}				; Push the constant x onto the stack and update the stack pointer.
	LDR r3, [fp, #8]  				; load constant n from the previous stack frame.
	CMP r3, #0				; Do a comparison between that previous constant n and the constant 0.
	MOVEQ r4, #1				; If equal to 0, move 1 to the temporary pointer in register 4.
	BEQ Realign				; If equal to 0, branch to the realigning function. Otherwise continue.
	STMFD sp, {r9}				; Push the constant n onto the stack and update the stack pointer.
	AND r3, r3, #0x1				; Now check if constant n is odd.
	CMP r3, #1				; Do a comparison of the previous result with 1.
	BEQ OddCase				; If equal to 1, the constant n is odd, so branch to the odd case.
		
EvnCase LDR r3, [sp, #-4]	  			; Load the constant n to another temporary pointer in register 3.
	LSR r3, r3, #1				; Divide n by a constant of 2, by shifting to the left.
	STMFD sp!, {r3}				; Push the constant n onto the stack and update the stack pointer.
	BL PowCase				; Branch to the power function with the new value for n after recursion.
	LDR r3, [sp, #-12]		  		; Load in y from the next frame into the temporary pointer in register 3.
	MUL r4, r3, r3				; Multiply y and y, and store the result in the temporary pointer in register 4.
	B Realign					; Regardless, Branch to the realigning function.
		
OddCase	LDR r3, [sp, #-4]	 	 		; Load the constant n to another temporary pointer in register 3.
	SUB r3, r3, #1				; Subtracts 1 from the constant n.
	STMFD sp!, {r3}				; Push the constant n onto the stack and update the stack pointer.
	BL PowCase				; Branch to the power function with the new value for n after recursion.
	LDR r3, [sp, #-12]			  	; Load in y from the next frame into the temporary pointer in register 3.
	MUL r4, r3, r2				; Multiply x and y, and store the result in the temporary pointer in register 4.
		
	AREA power, DATA, READWRITE
			
Const_x	EQU 2					; The constant 'x'.
Const_n	EQU 4					; The constant 'n'
	space 0xE0				; The given stack space in memory.
Stack 	DCB 0x000      				; The designated memory for the stack to start at.
	align					; Aligns the stack.
Result	DCD 0x99					; Result variable.
	END					; The program Ends obviously.