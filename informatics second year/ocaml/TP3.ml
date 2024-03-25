(* 2. Arbres binaires *)

type 'a arbre =
| Vide 
| Noeud of ('a arbre) * 'a * ('a arbre) ;;

let arbre_entiers = 
  Noeud (
    Noeud (Noeud (Vide, 1, Vide), 2, Noeud (Vide, 3, Vide)),
    4,
    Noeud (Noeud (Vide, 5, Vide), 6, Noeud (Vide, 7, Vide))
  )
;;
  
let arbre_vide = 
  Vide
;;

let rec taille_ab (a : 'a arbre) : int = 
  match a with 
  | Vide -> 0
  | Noeud (fils_g, _, fils_d) -> 1 + taille_ab (fils_g) + taille_ab (fils_d)
;;

let rec produit_ab (a : int arbre) : int =
  match a with 
  | Vide -> 1 
  | Noeud (fils_g, feuille, fils_d) -> feuille * produit_ab fils_g * produit_ab fils_d 
;;

(* On prendra la convention que le produit d'un arbre vide est 1 (expliquer pourquoi on a choisi cette valeur). *)
(* La fonction est récursive et l'élément neutre de la multiplication est 1.*)

let rec insere_arbre_bin_recherche (a : int arbre) (e : int) : int arbre =
  match a with 
  | Vide -> Noeud (Vide, e, Vide) 
  | Noeud (fils_g, feuille, fils_d) -> if e < feuille then 
    Noeud ((insere_arbre_bin_recherche fils_g e), feuille, fils_d)
    else if e > feuille then
    Noeud (fils_g, feuille, (insere_arbre_bin_recherche fils_d e))
    else a (* L'élément est déjà présent dans l'arbre, on ne fait aucune modification *)
;;

let rec list_of_arbre_bin (a : 'a arbre) : 'a list = 
  match a with 
  | Vide -> [] 
  | Noeud (fils_g, feuille, fils_d) -> (list_of_arbre_bin fils_g) @ [feuille] @ (list_of_arbre_bin fils_d)
;;

(* let rec arbre_bin_rech_of_int_list (l : int list) : int arbre =
  match l with 
  | [] -> Vide 
  | h :: t -> insere_arbre_bin_recherche (arbre_bin_rech_of_int_list t) h  
;;

let rec tri_abr (l : int list) : int list = 
  list_of_arbre_bin (arbre_bin_rech_of_int_list l) 
;; *)

(* 3. Évaluation d'expressions arithmétiques *)

type binop = Plus | Moins | Mult | Div;;

type expr =
  | Cst of int
  | Binop of binop * expr * expr
;;

let expr = Binop (Mult, Binop (Plus, Cst 4, Cst 2), Cst 3)

type resultat = Ok of int | Err

let rec string_of_expr (e : expr) : string =
  match e with 
  | Cst c -> string_of_int c 
  | Binop (op, expr_g, expr_d) -> match op with 
                                  | Plus -> "(" ^ (string_of_expr expr_g) ^ " + " ^ (string_of_expr expr_d) ^ ")"
                                  | Moins -> "(" ^ (string_of_expr expr_g) ^ " - " ^ (string_of_expr expr_d) ^ ")"
                                  | Mult -> "(" ^ (string_of_expr expr_g) ^ " * " ^ (string_of_expr expr_d) ^ ")"
                                  | Div -> "(" ^ (string_of_expr expr_g) ^ " / " ^ (string_of_expr expr_d) ^ ")"
;;

let rec eval_expr (e : expr) : resultat =
  match e with 
  | Cst c -> Ok c 
  | Binop (op, expr_g, expr_d) -> match op, eval_expr expr_g, eval_expr expr_d with
                                  | (Plus, Ok g, Ok d) -> Ok (g + d)
                                  | (Plus, _, Err) -> Err
                                  | (Plus, Err, _) -> Err
                                  | (Moins, Ok g, Ok d) -> Ok (g - d)
                                  | (Moins, _, Err) -> Err
                                  | (Moins, Err, _) -> Err
                                  | (Mult, Ok g, Ok d) -> Ok (g * d)
                                  | (Mult, _, Err) -> Err
                                  | (Mult, Err, _) -> Err
                                  | (Div, Ok g, Ok d) -> if d != 0 then Ok (g / d) else Err
                                  | (Div, _, Err) -> Err
                                  | (Div, Err, _) -> Err
;;

(* Tests *)

assert (taille_ab arbre_entiers = 7);;
assert (taille_ab arbre_vide = 0);;

assert (produit_ab arbre_entiers = 5040);;
assert (produit_ab arbre_vide = 1);;

assert (insere_arbre_bin_recherche arbre_entiers 8 = 
  Noeud (
    Noeud (Noeud (Vide, 1, Vide), 2, Noeud (Vide, 3, Vide)),
    4,
    Noeud (Noeud (Vide, 5, Vide), 6, Noeud (Vide, 7, Noeud (Vide, 8, Vide)))
  )
);;

assert (insere_arbre_bin_recherche arbre_vide 9 = 
  Noeud (Vide, 9, Vide)
);;

assert (list_of_arbre_bin arbre_entiers = [1;2;3;4;5;6;7]);;
assert (list_of_arbre_bin arbre_vide = []);;

assert (string_of_expr expr = "((4 + 2) * 3)");;
assert (eval_expr expr = Ok 18);;

let test_arbre = arbre_bin_rech_of_int_list [3; 1; 4; 5; 2] in

assert (
  match test_arbre with
  | Noeud (Noeud (Vide, 1, Noeud (Vide, 2, Vide)), 3, Noeud (Vide, 4, Noeud (Vide, 5, Vide))) -> true
  | _ -> false
)