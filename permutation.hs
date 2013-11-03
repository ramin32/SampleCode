(******************************************************
 * An implementation of a permutation generator in F#.
 * Uses both high-order and regular functions.
 *
 *	 Usage:
 *
 *	 > perms [1;2;3];;
 *	 val it : int list list =
 *	   [[3; 2; 1]; [3; 1; 2]; [1; 3; 2]; [2; 3; 1]; [2; 1; 3]; [1; 2; 3]]
 *	 > perms [1;2;3;4];;
 *	 val it : int list list =
 *	   [[2; 3; 4; 1]; [2; 3; 1; 4]; [2; 1; 3; 4]; [1; 2; 3; 4]; [3; 2; 4; 1];
 *	    [3; 2; 1; 4]; [3; 1; 2; 4]; [1; 3; 2; 4]; [3; 4; 2; 1]; [3; 4; 1; 2];
 *	    [3; 1; 4; 2]; [1; 3; 4; 2]; [2; 4; 3; 1]; [2; 4; 1; 3]; [2; 1; 4; 3];
 *	    [1; 2; 4; 3]; [4; 2; 3; 1]; [4; 2; 1; 3]; [4; 1; 2; 3]; [1; 4; 2; 3];
 *	    [4; 3; 2; 1]; [4; 3; 1; 2]; [4; 1; 3; 2]; [1; 4; 3; 2]]
 * 
 * Author:
 * Ramin Rakhamimov
 * ramin32 AT gmail DOT com
 * http://raminrakhamimov.com
 ******************************************************)

// Returns a list with the specified element inserted in every possible postion
let insert_elem_into_every_index elem list = 
    let rec insert_elem_into_every_index_h elem left right acc =
        match right with
        | []    -> (left @ [elem])::acc
        | r::rs -> insert_elem_into_every_index_h elem 
                                                  (left @ [r]) 
                                                  rs 
                                                  ((left @ [elem] @ right)::acc)
    insert_elem_into_every_index_h elem [] list  []

let flatten_list list = List.fold (fun acc2 t1 -> t1 @ acc2) [] list

let rec perms l =
    let insert_into_every_permutation_at_each_index x xs =
        flatten_list (List.map (fun perm -> insert_elem_into_every_index x perm) (perms xs) )
    match l with
    | [] -> []
    | [x] -> [[x]]
    | [x;y] -> [[x;y];[y;x]]
    | x::xs -> insert_into_every_permutation_at_each_index x xs

