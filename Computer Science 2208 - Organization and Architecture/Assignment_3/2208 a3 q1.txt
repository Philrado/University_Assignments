		AREA Assign3_Q1, CODE, READONLY
		ENTRY
		
Init	LDR r0, =UPC 			; Load the string into register memory for easy use.
		MOV r1, #0 				; r1 will be initialized to index 0 for odd numbers. 
		MOV r2, #1 				; r2 will be initialized to index 1 for even numbers. 
		
Loop1	LDRB r5, [r0, r1]		; Load in a single character at the index of register 1 to begin the odd sum.	
		SUB r5, r5, #48 		; Used to convert ASCII char values to int values.
		ADD r3, r3, r5			; Add every odd number to register 3 for the odd sum.
		ADD r1, r1, #2			; Add the odd digit to the odd sum stack held on r1 for later use.
		CMP r1, #11				; When the index reaches 13 stop iterating anything unnecessary.
		BLT Loop1
		
Loop2	LDRB r6, [r0, r2]		; Load in a single character at the index of register 2 to begin the even sum.	
		SUB r6, r6, #48 		; Used to convert ASCII char values to int values.
		ADD r4, r4, r6			; Add every even number to register 4 for the even sum.
		ADD r2, r2, #2			; Add the even digit to the odd sum stack held on r2 for later use.
		CMP r2, #10				; When the index reaches 13 stop iterating anything unnecessary.
		BLT Loop2
		
Calcs1	LSL r10, r3, #1;		; Multiple the odd sum by 2 by shifting left once.
		ADD r3, r3, r10			; Add r3's value once more to have it multiplied by 3.	
		ADD r7, r3, r4			; Add the multiplied odd sum and the normal even sum.
		SUB r7, #1				; Subtract 1 from the sum.
		
Loop3	SUB r7, r7, #10			; Minus 10 from the total sum, this will be done as many times as possible.
		CMP r7, #10				; When the index is less than 10 it stops the iterations as the remainder is found.
		BGT Loop3

Calcs2	LDRB r8, [r0, #11]		; Store the check digit into register 8 to be used for validity.
		SUB r8, #48				; Used to convert the ASCII char value for 8 to it's int value.
		MOV r9, #9				; Places the number 9 into register 9 for substraction.
		SUB r9, r9, r7 			; The number 9 is subtracted by the remainder of the sum division by 10.
		CMP r9, r8				; Compare the new value with the check value.
		BEQ VALID				; If they are equal, it's valid.
INVALID	MOV r0, #2				; Otherwise Invalid and store 2 in r0.
		B QUIT					; If it was invalid it just quits, completed but having failed the check.
VALID	MOV r0, #1				; If valid and store 1 in r0.
QUIT

		AREA Assign3_Q1, CODE, READONLY
UPC 	DCB "013800150738" 		; UPC string given to be read from.
		END