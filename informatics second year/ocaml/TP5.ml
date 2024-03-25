(* En utilisant List.map, coder les fonctions suivantes:

Une fonction f1 qui prend une liste d'int et renvoie la liste de leur représentation sous forme de string.
Une fonction f2 qui prend un int x et une liste d'int l et renvoie la liste transformée en multipliant 
chaque élément de l par x.
Une fonction f3 qui prend deux int x et y et une liste d'int l et renvoie la liste (de bool) indiquant 
pour chacun des éléments de l s'il est bien compris entre x et y. *)

(* En utilisant List.filter, coder les fonctions suivantes:

Une fonction f4 qui prend deux int x et y et une liste d'int l et renvoie la liste des éléments de l qui 
sont compris entre x et y.
Une fonction f5 qui prend une liste de liste d'int et renvoie la liste sans les (sous-)listes vides. *)

(* Recoder la fonction f5 sans le mot clé fun en utilisant une application partielle de (!=).
On peut bien sûr combiner List.map et List.filter.
Coder une fonction f6 qui prend une liste d'int option l et renvoie une liste d'int contenant les valeurs
int contenues dans l. Par exemple, f6 [ Some 3; None; Some 18; Some 42; None; Some 37; None] 
vaudra [3; 18; 42; 37]. *)

(* Recoder List.map, List.filter et List.for_all *)

let f1 (l : int list) : string list = List.map string_of_int l;;
let f2 (l : int list) (x : int) : int list = List.map (fun y -> y * x) l;;
let f3 (l: int list) (x : int) (y : int) : bool list = 
  List.map (fun z -> if z >= x && z <= y then true else false) l;;
let f4 (l : int list) (x : int) (y : int) : int list =
  List.filter (fun z -> if z >= x && z <= y then true else false) l;;
let f5 (l : int list list) : int list list =
  List.filter (fun z -> z != []) l;;
let f5' (l : int list list) : int list list =
  List.filter ((!=) []) l;;

type 'a option = 
  | None
  | Some of 'a
;;

(* let f6 (l : ('a option * int) list) : int list = *)

let rec lm (f : 'a -> 'b) (l : 'a list) : 'a list =
  match l with 
  | [] -> []
  | h :: t -> f h :: lm f t
;;

let rec lf (f : 'a -> 'b) (l : 'a list) : 'a list =
  match l with 
  | [] -> []
  | h :: t -> if f h then h :: lf f l else lf f l 
;;

let rec lfa (f : 'a -> 'b) (l : 'a list) : 'a list = 
  match l with 
  | [] -> [] 
  | h :: t -> if f h then lfa f l else false (* A corriger *)
;;

type 'a arbre_n =
| Feuille of 'a (* C'est un constructeur qui représente une feuille de l'arbre n-aire. *)
| Noeud of 'a arbre_n list (* C'est un autre constructeur qui représente un nœud de l'arbre n-aire. *)
;;

assert(f1 [1;2;3] = ["1";"2";"3"]);;
assert(f2 [1;2;3] 2 = [2;4;6]);;
assert(f3 [1;2;3] 1 2 = [true;true;false]);;
assert(f4 [1;2;3] 1 2 = [1;2]);;
assert(f5 [[1];[];[2;3]] = [[1];[2;3]]);;
assert(f5' [[1];[];[2;3]] = [[1];[2;3]]);;

assert(lm (fun x -> x * 2) [1;2;3] = [2;4;6]);;
assert(lf (fun z -> z != []) [[1];[];[2;3]] = [[1];[2;3]]);;
