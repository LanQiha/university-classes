;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname AnnaleMardi) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
;(require racket/math)

;Questions

;Écrire une fonction qui renvoie une liste de nombres correspondant à la somme des couples de nombres consécutifs dans la liste fournie en argument. L’éventuel singleton reste inchangé. (3 pts)
;(somme_couples '(1 2 3 4 5 6 7)) → (3 7 11 7)
;Définir une fonction qui parcourt une liste en profondeur pour remplacer toutes les occurrences de l’élément e passé en paramètre par "toto". (3 pts)
;(remplace 1 '(a 1 (2 1 (b a 1)) a 1)) → (a "toto" (2 "toto" (b a "toto")) a "toto")
;(remplace 'a '(a 1 (2 1 (b a 1)) a 1)) → ("toto" 1 (2 1 (b "toto" 1)) "toto" 1)
;Définir une fonction qui compte le nombre d'occurrences d'un élément e dans une liste plate, et renvoie ce nombre ainsi que la liste privée des éléments e, sans changer l’ordre des éléments dans la liste. (4 pts)
;(occ '(6 b "e" 3 6 b 9 6 7) 6) → (3 (b "e" 3 b 9 7))
;(occ '(6 b "e" 3 6 b 9 6 7) 'b) → (2 (6 "e" 3 6 9 6 7))
;Définir une fonction qui compte le nombre de nœuds n’ayant qu’un seul fils dans un arbre binaire. (3 pts)
;(noeud-unique '(5(4()(2()()))(7(1(3()())())()))) → 3
;Écrire une fonction qui, étant donné un arbre de nombres, construit un arbre de même structure, dans lequel la valeur de chaque nœud est égale au minimum des valeurs des nœuds descendant de ce nœud (y compris lui-même).
;Indication : vous pouvez utiliser la fonction min. (5 pts)
;(arbremin '(5(12(1()())())(7(3(4()())(6()()))(9()())))) → (1(1(1()())())(3(3(4()())(6()()))(9()())))

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

(define somme_couples
(lambda (l)
(if (null? (cdr l)) l
(cons (+ (car l) (cadr l)) (somme_couples (cddr l)))
)
)
)

(somme_couples '(1 2 3 4 5 6 7))

(define remplace
(lambda (e l)
(if (null? l) l
(if (list? (car l)) (cons (remplace e (car l)) (remplace e (cdr l)))
(if (equal? e (car l)) 
(cons "toto" (remplace e (cdr l)))
(cons (car l) (remplace e (cdr l)))
)
)
)
)
)

(remplace 1 '(a 1 (2 1 (b a 1)) a 1))
(remplace 'a '(a 1 (2 1 (b a 1)) a 1))

(define occ
(lambda (l e)
(occ2 l '() e 0)
)
)

(define occ2
(lambda (l ls e p)
(if (null? l) (list p ls)
(if (equal? (car l) e) 
(occ2 (cdr l) ls e (+ 1 p))
(occ2 (cdr l) (append ls (list (car l))) e p)
)
)
)
)

(occ '(6 b "e" 3 6 b 9 6 7) 6)
(occ '(6 b "e" 3 6 b 9 6 7) 'b)

(define noeud-unique
(lambda (a)
(if (or (arbre-vide? a) (feuille? a)) 0
(if (arbre-vide? (fils-g a)) (+ 1 (noeud-unique (fils-d a)))
(if (arbre-vide? (fils-d a)) (+ 1 (noeud-unique (fils-g a)))
(+ (noeud-unique (fils-g a)) (noeud-unique (fils-d a)))
)
)
)
)
)

(noeud-unique '(5(4()(2()()))(7(1(3()())())())))

(define minimum
(lambda (a)
(if (or (feuille? a) (arbre-vide? a)) (valeur a)
(if (arbre-vide? (fils-g a)) (min (valeur a) (minimum (fils-d a)))
(if (arbre-vide? (fils-d a)) (min (valeur a) (minimum (fils-g a)))
(min (valeur a) (minimum (fils-g a)) (minimum (fils-d a)))
)
)
)
)
)

(minimum '(5(12(1()())())(7(3(4()())(6()()))(9()()))))

(define arbremin
(lambda (a)
(if (or (feuille? a) (arbre-vide? a)) a
(cons-binaire (minimum a) (arbremin (fils-g a)) (arbremin (fils-d a)))
)
)
)

(arbremin '(5(12(1()())())(7(3(4()())(6()()))(9()()))))
