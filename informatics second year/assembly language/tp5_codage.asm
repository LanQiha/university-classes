	.ORIG x3000

; Partie dédiée au code
	LEA R0,msg	; charge l'adresse du message à déchiffrer dans R0
	LD R1,cle	; charge la clé dans R1
	JSR dechiffre	; déchiffrement du message
	PUTS		; affiche la chaîne pointée par R0
	HALT		; rend la main à l'OS

; Fonction dechiffre
; Entrée : R0 contient l'adresse du message à déchiffrer
;          R1 contient la clé à utiliser pour déchiffrer
dechiffre: 
ADD R2,R0,0
	loop:	LDR R3,R2,#0
	BRz endloop
	NOT R4,R1
	NOT R5,R3
	AND R3,R4,R3
	NOT R3,R3
	AND R4,R1,R5
	NOT R4,R4
	AND R3,R3,R4
	NOT R3,R3
	STR R3,R2,0
	ADD R2,R2,1
	BR loop
endloop:	RET

; Partie dédiée aux données
cle:	.FILL x001A
msg:    .FILL x0052 ; début de la chaîne
	.FILL x007F
	.FILL x0076
	.FILL x0076
	.FILL x0075
	.FILL x003A
	.FILL x007B
	.FILL x007D
	.FILL x007B
	.FILL x0073
	.FILL x0074
	.FILL x003B
	.FILL x0000 ; caractère 0 final
	.END
