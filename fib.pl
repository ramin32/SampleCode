%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% fib.pl
% 
% Prolog implementation of fib that runs in linear time.
% Author: Ramin Rakhamimov
% http://raminrakhamimov.com
% ramin32 AT gmail DOT com
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fib(0,0).
fib(1,1).
fib(2,2).
fib(F,R) :- fib(F,3,1,2,R).

fib(F,F,_,Y,R) :- R is Y, !.
fib(F,I,X,Y,R) :-
  I1 is I + 1,
  X1 is Y,
  Y1 is X + Y,
  fib(F,I1,X1,Y1,R).
  
