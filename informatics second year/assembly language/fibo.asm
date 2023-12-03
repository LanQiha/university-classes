		.orig x3000
		AND R0,R0,#0
		AND R1,R1,#0
		AND R2,R2,#0
		AND R3,R3,#0
		ADD R1,R1,#1
		ADD R2,R2,#3
loop:	ADD R4,R2,#-11
		BRp end
		ADD R3,R0,R1
		ADD R0,R1,#0
		ADD R1,R3,#0
		ADD R2,R2,#1
		BR loop
end:	ST R3,fibo
	HALT
fibo:	.FILL #0

