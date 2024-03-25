(* 1. Concaténations de listes *)
let rec concatene (l1 : 'a list) (l2 : 'a list) : 'a list =
  match l1 with 
  | [] -> l2 
  | h :: t -> h :: concatene t l2
;;

let rec applatit (l : 'a list list) : 'a list = 
  match l with 
  | [] -> [] 
  | h :: t -> concatene h (applatit t) 
;;

let rec applatit2 (l : 'a list list) : 'a list = 
  match l with 
  | [] -> [] 
  | h :: t -> h @ (applatit t) 
;;

(* 2. Retournement de liste *)

let rec renverse_ajoute (l1 : 'a list) (l2 : 'a list) : 'a list =
  match l1 with 
  | [] -> l2 
  | h :: t -> renverse_ajoute t (h :: l2)
;;

let renverse (l1 : 'a list) : 'a list =
  let rec renverse_ajoute_2 (l1 : 'a list) (l2 : 'a list) : 'a list =
    match l1 with 
    | [] -> l2 
    | h :: t -> renverse_ajoute_2 t (h :: l2)
  in renverse_ajoute_2 l1 []
;;

(* 3. Tri par insertion *)

let rec insertion (e : int) (l : int list) : int list = 
  match l with 
  | [] -> [e]
  | h :: t -> if e < h then e :: l else h :: insertion e t
;; 

let rec tri_insertion (l : int list) : int list = 
  match l with 
  | [] -> [] 
  | h :: t -> insertion h (tri_insertion t)
;;

(* 4. Recherche dans une liste d'association *)
type key = int;;
type valeur = string;;
type assoc = key * valeur;;
type assoc_list = assoc list;;

type resultat = Ok of string | Err;;

let rec cherche (a : assoc_list) (k : key) : resultat = 
  match a with 
  | [] -> Err 
  (* (k', v) :: t *)
  | h :: t -> match h with
              | (ky, v) -> if ky = k then Ok v else cherche t k
;;

let test_assoc_list = [(1, "one"); (2, "two"); (3, "three"); (4, "four")];;

(* Tests *)
assert (concatene [ 1; 2; 3 ] [ 4; 5; 6 ] = [ 1; 2; 3; 4; 5; 6 ]);;
assert (concatene [] [ 4; 5; 6 ] = [ 4; 5; 6 ]);;

assert (applatit [ [ 1; 2 ]; [ 3; 4; 5 ]; []; [ 6 ] ] = [ 1; 2; 3; 4; 5; 6 ]);;
assert (applatit [ [ 1 ] ] = [ 1 ]);;

assert (applatit2 [ [ 1; 2 ]; [ 3; 4; 5 ]; []; [ 6 ] ] = [ 1; 2; 3; 4; 5; 6 ]);;
assert (applatit2 [ [ 1 ] ] = [ 1 ]);;

assert (renverse_ajoute [ 1; 2; 3 ] [ 4; 5; 6 ] = [ 3; 2; 1; 4; 5; 6]);;

assert (renverse [ 1; 2; 3 ] = [ 3; 2; 1]);;

assert (insertion 3 [ 1; 2; 4; 5 ] = [ 1; 2; 3; 4; 5 ]);;
assert (insertion 3 [ 1; 2; 3; 4; 5 ] = [ 1; 2; 3; 3; 4; 5 ]);;

assert (tri_insertion [ 1; 4; 2; 3 ] = [ 1; 2; 3; 4 ]);;
assert (tri_insertion [ 1; 2; 3; 4 ] = [ 1; 2; 3; 4 ]);;

assert (cherche test_assoc_list 3 = Ok "three");;
