        .ORIG x3000
        LD R0,a
        LD R1,b
        ADD R2,R0,R1
        ST R2,c
        LD R3,c
        NOT R0,R0
        ADD R1,R1,#1
loop:	ADD R4,R1,R0
	BRn endloop
	ADD R0,R0,#-1
	BR  loop    
endloop:     
a:	.FILL #10
b:	.FILL #20
c:	.FILL #0

	.END

