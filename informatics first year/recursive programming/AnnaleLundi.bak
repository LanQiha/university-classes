;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname AnnaleLundi) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
(require racket/math)
;Questions

;Définir une fonction qui, étant donnée une liste plate, inverse les paires d'éléments successifs. (3 pts)
;(valse '(1 3 5 7)) → (3 1 7 5)
;(valse '(1 3 5)) → (3 1 5)
;Définir une fonction qui parcourt une liste en profondeur pour remplacer tous les nombres négatifs par leur carré. (3 pts)
;(remplace '(a -1 (-2 1 (b "t" 1) -4) a 3)) → (a 1 (4 1 (b "t" 1) 16) a 3)
;Écrire une fonction qui renvoie une liste de deux éléments : le premier élément correspond à la liste initiale dont les nombres ont été multipliés par un nombre passé en paramètre de la fonction ; le second élément correspond au nombre de multiplications qui ont été réalisées. Attention de ne parcourir la liste qu’une seule fois. (4 pts)
;(multiplication '(1 4 7 a b 9) 3) → ((3 12 21 a b 27) 4)
;Définir une fonction qui compte le nombre de nœuds ayant une valeur paire dans un arbre binaire de nombres entiers. (3 pts)
;(noeud-pair '(5(4()(2()()))(7(1(3()())())()))) → 2
;Écrire une fonction qui, étant donné un arbre, construit un arbre de même structure, dans lequel la valeur de chaque nœud est égale au nombre de nœuds descendants de ce nœud (y compris lui-même). (5 pts)
;(nbnoeuds '(5(12(1()())())(7(3(4()())(6()()))(9()())))) → (8(2(1()())())(5(3(1()())(1()()))(1()())))

;;;;;; PRIMITIVES SUR LES ARBRES VUES EN COURS
(define arbre-vide ; -> arbre
  (lambda ()  ; necessite de passer dans le niveau de langage "Advanced Student"
    '()))

(define arbre-vide? ; -> booleen
  (lambda (a) ; arbre
    (null? a)))

(define valeur ; -> atome
  (lambda (a) ; arbre non vide
    (car a)))

(define fils-g ; -> arbre
  (lambda (a) ; arbre non vide
    (cadr a)))

(define fils-d ; -> arbre
  (lambda (a) ; arbre non vide
    (caddr a)))

(define cons-binaire ; -> arbre
  (lambda (v g d) ; v atome, g et d arbres
    (list v g d)))

(define arbre=? ; -> booleen
  (lambda (a1 a2) ; arbres
    (equal? a1 a2)))

(define feuille? ; -> booleen
  (lambda (a) ; a arbre
    (and (not (arbre-vide? a)) (arbre-vide? (fils-g a)) (arbre-vide? (fils-d a)))))

(define arbre? ; -> booleen
  (lambda (l) ; liste
    (or (null? l)  ; l'arbre vide
      (and 	(= 3 (length l))
        (not (list? (car l)))
        (list? (cadr l))
        (arbre? (cadr l))
        (list? (caddr l))
        (arbre? (caddr l))))))

;;;;;; Annales

(define valse ; -> liste plate
  (lambda (l) ; l: liste plate
    (if (null? l) '()
      (if (null? (cdr l)) (list (car l))
        (cons (cadr l) (cons (car l) (valse (cddr l))))
        )
      )
    )
  )

(valse '(1 3 5 7))
(valse '(1 3 5))

(define remplace ; -> liste de liste
  (lambda (l) ; l: liste de liste
    (if (null? l) '()
      
      (if (list? (car l)) (cons (remplace (car l)) (remplace (cdr l)))
        (if (and (number? (car l)) (< (car l) 0))
          (cons (* (car l) (car l)) (remplace (cdr l)))
          (cons (car l) (remplace (cdr l)))
          )
        )
      )
    )
  )

(remplace '(a -1 (-2 1 (b "t" 1) -4) a 3))

(define multiplication
  (lambda (l n)
    (mult '() l n 0)
    )
  )

(define mult
  (lambda (ls l n p)
    (if (null? l) (list ls p)
      (if (number? (car l))
        (mult (append (list (* (car l) n)) ls) (cdr l) n (+ 1 p))
        (mult (append (list (car l)) ls) (cdr l) n p)
        )
      )
    )
  )

(multiplication '(1 4 7 a b 9) 3)

(define noeud-pair ; -> nombre
  (lambda (a) ; a: arbre
    (if (arbre-vide? a) 0
      (if (and (feuille? a) (even? (valeur a))) 1
        (+ (noeud-pair (fils-g a)) (noeud-pair (fils-d a)) (if (even? (valeur a)) 1 0))
        )
      )
    )
  )

(noeud-pair '(5(4()(2()()))(7(1(3()())())())))

(define nbnoeuds ; -> arbre
  (lambda (a) ; a: arbre
    (nbnoeuds2 a 0)
    )
  )
  
(define nbnoeuds2 ; -> arbre
  (lambda (a p) ; a: arbre, p: nombre
    (if (arbre-vide? a) (arbre-vide)
        (let ((fg (nbnoeuds2 (fils-g a) (+ 1 p)))
              (fd (nbnoeuds2 (fils-d a) (+ 1 p))))
          (cons-binaire (+ 1 (if (arbre-vide? fg) 0 (valeur fg)) (if (arbre-vide? fd) 0 (valeur fd))) fg fd)
          )
        )
    )
  )

(nbnoeuds '(5(12(1()())())(7(3(4()())(6()()))(9()()))))
