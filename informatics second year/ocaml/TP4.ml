  (* 1. Arbres n-aires *)
  (* 1.1. Type arbre n-aire *)
  type 'a arbre_n =
    | Feuille of 'a (* C'est un constructeur qui représente une feuille de l'arbre n-aire. *)
    | Noeud of 'a arbre_n list (* C'est un autre constructeur qui représente un nœud de l'arbre n-aire. *)
  ;;

  (* Un type polymorphe est un concept de programmation qui permet 
  à une fonction, une classe ou une structure de données d'accepter des arguments de types variés, 
  tout en conservant la même structure ou le même comportement. (Type 'a)*)

  let arbre : int arbre_n =
    Noeud [
      Feuille 1;
      Noeud [
        Feuille 2;
        Noeud [
          Feuille 3;
        ];
      ];
      Noeud [
        Feuille 4;
        Noeud [
          Feuille 5;
          Feuille 6;
          Feuille 7;
        ];
      ];
    ];
  ;;

  let arbre_vide = Noeud [];;
  (* Feuille ();; crée une feuille d'arbre n-aire sans valeur particulière. 
  Cela signifie qu'il s'agit simplement d'une feuille qui ne contient aucune donnée. *)
  let arbre_vide_2 = Feuille ();; 

  (* 1.2. Hauteur d'un arbre *)
  let rec hauteur_arbre (arbre : 'a arbre_n) : int =
    match arbre with 
    | Feuille _ -> 0
    | Noeud foret -> 1 + hauteur_foret foret 

    and hauteur_foret (foret : 'a arbre_n list) : int =
      match foret with 
      | [] -> 0
      | arbre :: reste_foret -> max (hauteur_arbre arbre) (hauteur_foret reste_foret)
  ;;

  (* les fonctions hauteur_arbre et hauteur_foret sont définies de manière mutuellement récursive. 
  Elles dépendent l'une de l'autre pour calculer la hauteur d'un arbre n-aire, 
  où hauteur_arbre calcule la hauteur d'un arbre et hauteur_foret calcule la hauteur d'une liste d'arbres.
  La substitution de let rec par and permet de définir ces fonctions 
  dans le même contexte de manière plus compacte et plus lisible, 
  tout en précisant explicitement leur interdépendance.*)

  let rec list_of_arbre_aux (arbre : 'a arbre_n) : 'a list =
    match arbre with
    | Feuille f -> [f]
    | Noeud foret -> list_of_foret foret
  
    and list_of_foret (foret : 'a arbre_n list) : 'a list =
      match foret with
      | [] -> []
      | arbre :: reste_foret -> list_of_arbre_aux arbre @ list_of_foret reste_foret
  ;;

  let list_of_arbre (arbre : 'a arbre_n) : 'a list = 
    let rec list_of_arbre_aux_acc (arbre : 'a arbre_n) (acc : 'a list) : 'a list =
      match arbre with
      | Feuille f -> f :: acc
      | Noeud foret -> list_of_foret_acc foret acc
    
      and list_of_foret_acc (foret : 'a arbre_n list) (acc : 'a list) : 'a list =
        match foret with
        | [] -> acc
        | arbre :: reste_foret -> list_of_arbre_aux_acc arbre (list_of_foret_acc reste_foret acc)
    in
    list_of_arbre_aux_acc arbre []
  ;;

  (* En OCaml, 'a option est un type de données qui représente 
  la possibilité qu'une valeur soit présente ou absente.
  C'est une manière élégante de gérer les cas où une valeur pourrait ne pas être définie. *)

  (* 1.4. Minimum d'un arbre *)

  type option = Ok of int | Err;;
  (* type option =
  | Ok of int
  | Err
  ;; *)

  let rec minimum (arbre : 'a arbre_n) : int = 
    match arbre with 
    | Feuille f -> f
    | Noeud foret -> minimum_foret foret 

    and minimum_foret (foret : 'a arbre_n list) : int =
      match foret with 
      | [] -> max_int
      | arbre :: reste_foret -> min (minimum arbre) (minimum_foret reste_foret)
  ;;

  let rec minimum_option (arbre : 'a arbre_n) : option = 
    match arbre with 
    | Feuille f -> Ok f
    | Noeud foret -> minimum_foret_option foret 

    and minimum_foret_option (foret : 'a arbre_n list) : option =
      match foret with 
      | [] -> Err
      | arbre :: reste_foret -> match minimum_option arbre, minimum_foret_option reste_foret with
                                | Ok m1, Ok m2 -> Ok (min m1 m2)
                                | Ok m, Err -> Ok m 
                                | Err, Ok m -> Ok m 
                                | Err, Err -> Err 
  ;;

  (* 1.5. Reduce *)

  (* On peux utiliser reduce avec différentes fonctions f 
  pour effectuer différentes opérations sur l'arbre, 
  comme trouver le minimum, le maximum, la somme, etc.*)

  let rec reduce (arbre : 'a arbre_n) (f : 'a -> 'a -> 'a) : int =
    match arbre with 
    | Feuille f -> f
    | Noeud foret -> reduce_foret foret f

    and reduce_foret (foret : 'a arbre_n list) (f : 'a -> 'a -> 'a) : int =
      match foret with 
      | [] -> 0
      | arbre :: reste_foret -> f (reduce arbre f) (reduce_foret reste_foret f)
  ;;

  let rec reduce_option (arbre : 'a arbre_n) (f : 'a -> 'a -> 'a) : option =
    match arbre with 
    | Feuille f -> Ok f
    | Noeud foret -> reduce_foret_option foret f

    and reduce_foret_option (foret : 'a arbre_n list) (f : 'a -> 'a -> 'a) : option =
      match foret with 
      | [] -> Err
      | arbre :: reste_foret -> match reduce_option arbre f, reduce_foret_option reste_foret f with 
                                | Ok m1, Ok m2 -> Ok (f m1 m2)
                                | Ok m, Err -> Ok m 
                                | Err, Ok m -> Ok m 
                                | Err, Err -> Err
  ;;

  (* 2.2 Type FIFO et ajout d'éléments *)

  (* La définition | List_g of 'a list indique qu'une valeur de type 'a fifo peut être 
  soit une liste 'a placée à gauche (List_g), soit une liste 'a placée à droite (List_d). 
  En OCaml, les constructeurs de variantes sont généralement écrits 
  en commençant par une lettre majuscule. *)
  type 'a fifo =
  | List_g of 'a list
  | List_d of 'a list
  ;;

  let fifo_list = List_g [];;
  let add_list = [1;2;3];;
      
  let push_fifo (e : 'a) (f : 'a fifo) : 'a fifo =
    match f with
    | List_g g -> List_g (e :: g)
    | List_d d -> List_d d
  ;;

  (* Ordre inversé *)
  let rec push_list_fifo (l : 'a list) (f : 'a fifo) : 'a fifo =
    match l with 
    | [] -> f
    | h :: t -> push_list_fifo t (push_fifo h f) 
  ;;

  let transfert_fifo (f : 'a fifo) : 'a fifo =
    match f with 
    | List_g g -> push_list_fifo g (List_d [])
    | List_d _ -> f
  ;;

  (* pop_fifo *)
  (* pop_all_fifo *)

  (* Tests *)
  let print_list lst =
    print_string "[";
    List.iteri (fun i x -> if i > 0 then print_string "; "; print_int x) lst;
    print_string "]";
    print_newline();;
  ;;  

  let () =
  print_int (hauteur_arbre arbre);
  print_newline();
  print_list (list_of_arbre_aux arbre);
  print_list (list_of_arbre arbre);
  print_int (minimum arbre);
  print_newline();
  print_int (reduce arbre max);
  print_newline();
  ;;

  assert (minimum_option arbre = Ok 1);;
  assert (reduce_option arbre max = Ok 7);;

  assert (push_fifo 1 fifo_list = List_g [1]);;
  assert (push_fifo 'a' fifo_list = List_g ['a']);;

  assert (push_list_fifo add_list fifo_list = List_g [3;2;1]);;

  assert (transfert_fifo (push_list_fifo add_list fifo_list) = List_d [1;2;3]);;