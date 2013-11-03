%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NKnightTour.pl 
%
% Description: Prolog implementation of a N-Knights-Tour finder.
% Example:
%   ?- grid(5,5,Grid),knight_tour(Grid,[3,3],Tour),write(Tour),length(Tour,Length). 
%   [[3, 3], [1, 2], [2, 4], [4, 5], [5, 3], [4, 1], [2, 2], [1, 4], [3, 5], [5, 4], 
%   [4, 2], [2, 1], [1, 3], [2, 5], [4, 4], [5, 2], [3, 1], [2, 3], [1, 1], [3, 2], 
%   [5, 1], [4, 3], [5, 5], [3, 4], [1, 5]]
%
%   Grid = [[1, 1], [1, 2], [1, 3], [1, 4], [1, 5], [2, 1], [2, 2], [2|...], [...|...]|...],
%   Tour = [[3, 3], [1, 2], [2, 4], [4, 5], [5, 3], [4, 1], [2, 2], [1|...], [...|...]|...]
%   Length = 25
% Author: 
% Ramin Rakhamimov
% ramin32 AT gmail DOT com
% http://raminrakhamimov.com
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

difference(Xs,Ys,D) :- 
  findall(X,(member(X,Xs),not(member(X,Ys))),D).

knight_move([X,Y]) :-
  L = [1,-1,2,-2],
  member(X,L),
  member(Y,L),
  abs(X,X1), abs(Y,Y1),
  X1 =\= Y1.

execute_move([X1,Y1],[X2,Y2],[Xmove,Ymove]) :-
  Xmove is X2 - X1,
  Ymove is Y2 - Y1.
  
valid(Grid,From,To) :-
  member(To,Grid),
  execute_move(From,To,Move),
  knight_move(Move).

grid(Width,Height,Grid) :- 
  findall([X,Y],(between(1,Width,X),between(1,Height,Y)),Grid).

knight_tour(Grid,StartMove,Tour) :- 
  knight_tour(Grid,StartMove,[StartMove],Tour).

knight_tour(Grid,_,A,Tour) :-
  difference(Grid,A,Difference),
  Difference = [],
  reverse(A,Tour).
knight_tour(Grid,StartMove,A,Tour) :-
  valid(Grid,StartMove,EndMove),
  not(member(EndMove,A)),
  A1 = [EndMove|A],
  knight_tour(Grid,EndMove,A1,Tour).
