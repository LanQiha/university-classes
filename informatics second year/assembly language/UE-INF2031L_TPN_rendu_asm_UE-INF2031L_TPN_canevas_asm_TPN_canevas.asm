	.ORIG x3000

	; partie dédiée au code
	; complétez ici
	LEA R0,tabdeb
	LEA R1,tabfin
	LDR R3,R0,0
	NOT R0,R0
loop:	ADD R2,R0,R1
	BRn end
	LDR R4,R0,1
	NOT R3,R3
	BRn else
	ST R4,max
	ST R3,min
else:	ST R3,max
	ST R4,min
	ADD R0,R0,#-1
	BR loop
end:	
	HALT

	; partie dédiée aux données
min:	.BLKW 1
max:	.BLKW 1
tabdeb:	.FILL x0000
	.FILL x0014
	.FILL xFFF8
	.FILL x000E
	.FILL xFFD8
	.FILL xFFB4
	.FILL x0041
	.FILL xFFFF
	.FILL x000A
tabfin:	.FILL xFFFC

	.END

