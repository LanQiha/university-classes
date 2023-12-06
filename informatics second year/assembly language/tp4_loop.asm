	.ORIG x3000
	LD R1,N		
	NOT R1,R1	
	ADD R1,R1,#1 	; R1 = -N
	AND R2,R2,#0 	
LOOP:	ADD R3,R2,R1 	
	BRzp ELOOP	
	LD R0,STAR 	
	OUT 		
	ADD R2,R2,#1 	
	BR LOOP 	
ELOOP:	LEA R0,NEWLN	
	PUTS 		
STOP:	HALT            
N:	.FILL 6         
STAR:	.FILL x2A 	; the character to display
NEWLN:	.STRINGZ "\n"   
	.END
