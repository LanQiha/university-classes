	 .ORIG x3000
; Programme principal
         LEA R6,stackend ; initialisation du pointeur de pile
         ; *** A COMPLETER ***
         HALT

; partie dédiée aux données
msg1:    .STRINGZ "Entrez une chaîne   : "
msg2:    .STRINGZ "Vous avez tapé      : "
ch1:     .BLKW #8
ch2:     .BLKW #8

; pile
stack:    .BLKW #32
stackend: .FILL #0

