	.ORIG X3000     
	LD R0,char
	AND R1,R1,#0
loop:	ADD R2,R1,#-9
	BRp endloop
	OUT
	ADD R1,R1,#1
	BR loop
endloop: HALT
char:	.FILL 90
.END
