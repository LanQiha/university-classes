	.ORIG X3000     ; spécifie l'adresse de chargement du programme
	LD R1,a
	LD R2,b
	ADD R0,R1,R2
	ADD R0,R0,-1
	ST R0, r
stop:	BR stop		; bloque l'exécution ici (boucle sur soi-même)
r:	.BLKW 1
a:	.FILL 10
b:	.FILL 6
.END
