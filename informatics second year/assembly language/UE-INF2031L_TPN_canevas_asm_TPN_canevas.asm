	.ORIG x3000

	; partie dédiée au code
	; complétez ici

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

