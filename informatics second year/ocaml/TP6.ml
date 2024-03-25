

let pairs (ls : 'a list) : 'a list =
  List.filter (fun x -> if (x mod 2 = 0) then true else false) ls;;

(* let init_2_Y (y : int) : int list =
  List.init (y-1) ((+) 2) in *)

let divisible (e : int) (ls : 'a list) : bool list = 
  List.map (fun x -> if (e mod x = 0) then true else false) ls;;

let maximal (e : int) (ls : 'a list) : bool =
  List.for_all (fun x -> if (e > x) then true else false) ls;;
  
let rec carre (ls : 'a list) : 'a list = 
  List.map (fun x -> x * x) ls;;

let ajoute (e : int) (ls : 'a list) : 'a list =
  List.map (fun x -> e + x) ls;;

let transforme (ls : int list) : string list = 
  List.map string_of_int ls;;

(* val filter : ('a -> bool) -> 'a list -> 'a list *)
(* val fold_right : ('a -> 'acc -> 'acc) -> 'a list -> 'acc -> 'acc *)
let my_map (f : 'a -> 'b) (ls : 'a list) : 'b list =  
  List.fold_right (fun x acc -> (f x) :: acc) ls [];;

let my_filter (f : 'a -> 'b) (ls : 'a list) : 'a list = 
  List.fold_right (fun x acc -> if (f x = true) then x::acc else acc) ls [];;

(* let rev (ls : 'a list) : 'a list =
  List.fold_left (fun x acc -> x::acc) [] ls;; *)

assert(pairs [1;2;3;4] = [2;4]);;
assert (divisible 2 [1;2;3;4] = [false;true;false;false]);;
assert (maximal 5 [1;2;3;4] = true);;
assert (maximal 3 [1;2;3;4] = false);;
assert (carre [1;2;3;4] = [1;4;9;16]);;
assert (ajoute 3 [1;2;3;4] = [4;5;6;7]);;
assert (transforme [1;2;3;4] = ["1";"2";"3";"4"]);;
assert (my_map (fun x -> 3 + x)  [1;2;3;4] = [4;5;6;7]);;
assert (my_filter (fun x -> if (x mod 2 = 0) then true else false)  [1;2;3;4] = [2;4]);;