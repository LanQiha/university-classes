		.ORIG x3000
		LD R1,a
		LD R2,b
loop:	ADD R3,R2,#-1
		BRn end
		ADD R0,R0,R1
		ADD R2,R2,#-1
		BR loop
end:	ST R0,r
a:		.FILL 4
b:		.FILL 3
r:		.BLKW 1

