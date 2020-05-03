		AREA Assign3_Q2, CODE, READONLY
		ENTRY
		
Init	LDR r1, = STRING 	; Load the string into register memory for easy use.
		LDR r2, = EoS 		; Load the EoS value into register memory for easy use.
		SUB r2, #1 			;
		MOV r0, #2 			
		
GetLCh	LDRB r3, [r1], #1 	; Computes the left side for comparison.
		CMP r3, #65		 	;
		CMPGT r3, #90	 	;
		BLT	GetRCh		 	;
		CMPGT r3, #97 		;
		CMPGT r3, #122 		;
		BGT GetLCh 			;

GetRCh	LDRB r4, [r1], #-1 	; Computes the right side for comparison.
		CMP r4, #65 		;
		CMPGT r4, #90 		;
		BLT	GetRCh 			;
		CMPGT r4, #97 		;
		CMPGT r4, #122 		;
		BGT GetLCh 			;

Calcs	SUBS r5, r2, r1 	; Final calculations to confirm if a palindrome.
		CMPGE r3, r4 		
		BNE VALID 			; If valid, go to put 1 in r0.
		CMP r5, #1 			; Otherwis do another check.
		BGT GetLCh 			
INVALID MOV r0, #2 			; If invalid then out 2 in r0. 
		BNE EXIT 			; Exit the program.
VALID	MOV r0, #1 			
EXIT

		AREA Assign3_Q1, CODE, READONLY
STRING 	DCB "He lived as a devil, eh?" ;string
EoS 	DCB 0x00 ;end of string 
		END
