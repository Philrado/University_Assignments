		AREA Assign_4, CODE, READONLY
		ENTRY
		
Init	ADR r0, STRG		; Load the string into register memory for easy use.
		MOV r1, #0			; r1 will hold the current index
		ADR r2, STRG2		; r2 is the pointer for final string, and r3 is a separate incremenetor.
		LDR r10, #0x00		; For end of string checking.
		
Loop0	CMP r1, r10			; Exit check
		BEQ loop			; ^
		LDRB r9, [r0, r1]	; Loads in the first character.
		CMP r9, #"t"		; Is the current char t
		BNE Loop1			; If it's not t and is therefore another char, just add normally.
		ADD r1, r1, #1		; If it is t. Increment the index.
		CMP r9, #"h"		; Is the current char h
		BNE Loopt			; If it's not h and is therefore another char, just add t.
		ADD r1, r1, #1		; If it is h. Increment the index.
		CMP r9, #"e"		; Is the current char e
		BNE Looph			; If it's not e and is therefore another char, just add t, then h.
		ADD r1, r1, #1		; If it is h. Increment the index.
		CMP r9, #" " 		; Is the current char  
		BNE Loope			; If it's not " " and is therefore just the and something else, just add t, h, e.
		ADD r1, r1, #1		; If it is " ". Increment the index.
		B Loop0				; But don't add anything, just move on to the next characters.			
		
Loop1	STR r9, [r2,r3]		; Add the current letter.
		ADD r1, r1, #1		; Increment the index.
		B Loop0				; Go to the beginning to read further in.

Loopt	MOV r8, #"t"
		STR r8, [r2, r3]	; add the letter t
		ADD r3, r3, #1		; Increment the pointer.		
		B Loop0
		
Looph	MOV r8, #"t"
		STR r8, [r2, r3]	; add the letter t
		ADD r3, r3, #1		; Increment the pointer.	
		MOV r8, #"h"
		STR r8, [r2, r3]	; add the letter h
		ADD r3, r3, #1		; Increment the pointer.	
		B Loop1		
		
Loope	MOV r8, #"t"
		STR r8, [r2, r3]	; add the letter t
		ADD r3, r3, #1		; Increment the pointer.	
		MOV r8, #"h"
		STR r8, [r2, r3]	; add the letter h
		ADD r3, r3, #1		; Increment the pointer.	
		MOV r8, #"e"
		STR r8, [r2, r3]	; add the letter e	
		ADD r3, r3, #1		; Increment the pointer.	
		B Loop1		
		
loop b loop
		
		AREA Assign_4, DATA, READWRITE
		ALIGN
STRG 	DCB "the 123 " 			; test string to be translated.
		ALIGN
STRG2	space 0xFF			; the new string after "the"'s are removed.
		ALIGN
EoS		DCB 0x00
		END