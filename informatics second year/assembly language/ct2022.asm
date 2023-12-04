		.ORIG x3000
		LEA R0,tabdeb
		LEA R1,tabfin
		LDR R2,R0,0
		ST R2,min
		NOT R1,R1
		ADD R1,R1,#1
loop:	ADD R3,R0,R1
		BRp end
		LD R4,min
		LDR R2,R0,1
		NOT R4,R4
		ADD R4,R4,#1
		ADD R5,R2,R4
		BRp else
		ST R2,min
else:	ADD R0,R0,#1
		BR loop
end:	
tabdeb:	.FILL 45
		.FILL 98
		.FILL 34
		.FILL 56
		.FILL 9
tabfin:	.FILL 16
min:	.BLKW 1
		HALT
		.END

