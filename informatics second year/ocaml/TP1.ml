let rec concatene (l1 : 'a list) (l2 : 'a list) : 'a list =
  match l1 with
  | [] -> l2
  | tete :: queue -> tete :: concatene queue l2
;;

let rec len (l : 'a list) : int =
  match l with 
  | [] -> 0
  | _ :: t -> 1 + len l
;;

let rec applatit (l : 'a list list) : 'a list =
  match l with
  | [] -> []
  | h :: t -> concatene h (applatit t)
;;

let rec reverse (l : 'a list) : 'a list = 
  match l with 
  | [] -> []
  | h :: t -> concatene (reverse t) [h]
;;

let rec renverse_ajoute (l1 : 'a list) (l2 : 'a list) : 'a list =
  match l1 with
  | [] -> l2
  | h :: t -> renverse_ajoute t (h :: l2)
;;

let rec rev (l : 'a list) : 'a list = 
  match l with
  | [] -> []
  | _ :: _ -> renverse_ajoute l []
;;

let rec insertion (nb : int) (l : 'a list) : 'a list = 
  match l with 
  | [] -> l
  | h :: t -> if nb < h then nb :: l else h :: insertion nb t
  ;;  

let rec tri_insertion (l : 'a list) : 'a list =
  match l with 
  | [] -> []
  | h :: t -> insertion h (tri_insertion t)
;;

let print_list lst =
  print_string "[";
  List.iteri (fun i x -> if i > 0 then print_string "; "; print_int x) lst;
  print_string "]"

let () =
  (* print_list (concatene [ 1; 2; 3 ] [ 4; 5; 6 ]);;
  print_list (concatene [] [ 4; 5; 6 ]);;
  print_list (applatit [ [ 1; 2 ]; [ 3; 4; 5 ]; []; [ 6 ] ]);;
  print_list (applatit [ [ 1 ] ]);;
  print_list (renverse_ajoute [ 1; 2; 3 ] [ 4; 5; 6 ]);;
  print_list (rev [ 1; 2; 3 ]);;
  print_list (insertion 3 [ 1; 2; 4; 5 ]);;
  print_list (insertion 3 [ 1; 2; 3; 4; 5 ]);; *)
  print_list (tri_insertion [ 1; 4; 2; 3 ]);;
  print_newline ()
