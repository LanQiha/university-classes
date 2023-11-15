           .ORIG x3000     ; adresse de début de programme
; partie dédiée au code
           LEA R0,debut    ; charge l'adresse de début du tableau
           LEA R1,fin      ; charge l'adresse de fin du tableau
           JSR mul6tab     ; appel à une routine
           HALT            ; termine le programme

; partie dédiée aux données
mask:      .FILL x000F     ; constante x000F
debut:     .FILL 4         ; adresse de début de tableau
           .FILL 5
           .FILL 6
fin:       .FILL 3         ; adresse de fin de tableau

; Routine mul6tab, pour multiplier les entiers d'un tableau par 6 modulo 16.
; Les multiplications se feront sur place.
; paramètres d'entrée   : R0, adresse de début du tableau
;                         R1, adresse de fin du tableau
mul6tab: ADD R2,R0,#0
loop:	NOT R3,R1
	ADD R3,R3,R2
	ADD R3,R3,#1
	BRp endloop
	LDR R3,R2,#0
	ADD R3,R3,R3
	ADD R4,R3,R3
	ADD R3,R3,R4
	AND R3,R3,#15
	STR R3,R2,#0
	ADD R2,R2,#1
	BR loop
endloop: HALT

          .END		; marque la fin du code source

