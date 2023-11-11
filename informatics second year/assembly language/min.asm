	.ORIG x3000
	LD R1,a ; x
	LD R2,b ; y
	NOT R2,R2
	ADD R3,R1,R2
	ST R2,r    
	BRp endif
else:	ST R1,r
endif:	                   
	HALT             
a:	.FILL 10
b:	.FILL 15
r:	.BLKW 1
	.END
