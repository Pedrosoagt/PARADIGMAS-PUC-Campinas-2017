%prova prolog 2016 - Engenharia de Computação. 
%1 
	nasceu(pedro, brasil).
	nasceu(maria, brasil).
	pai(pedro, joao).
	mae(maria, joao).
	casou(natalia, pedro).
	cidadaobrasileiro(X):- nasceu(X, brasil).
	cidadaobrasileiro(Y):- pai(X, Y), nasceu(X, brasil).
	cidadaobrasileiro(X):- casou(X, Y), nasceu(Y, brasil).
	
%2 - exibe o último elemento

	f([X], X).
	f([_|T], L):- f(T, L).

%3 calcula o fatorial de uma número ?-fatorial(3,F).

	fatorial(0,1).
	fatorial(N, F) :- N1 is N - 1, 
		fatorial(N1, F1), 
		F is N * F1.

%4 encontra o menor da lista ?-menorDaLista(M,[X]).

	menorDaLista(M, [M]).
	menorDaLista(X, [M|N]):- 
		menorDaLista(N, O), 
		(M<O -> X=M; X=0).

min([X],X).      %  Calcula o menor elemento de uma lista.
min([X|Y],M):-
	min(Y,N),
	(X<N -> M=X; M=N


%prova prolog 2017 05/06

%1 - o que o prolog ira exibir 
	A ) X=2, Y=X+1. 
		R.: Y = 2+1.

	B ) X=2, Y is X+1.
		R.: Y = 3.

	C ) X=2, Y==X+1.
		R.: false.

%2 - o que sera exibido e
	f([X,A], X).
	f([_|T]):- f(T,L).

%3 - faça uma função que retorne o somatório de uma lista somatório. 

		soma([], 0).
		soma([X | Y], S):-
			S is R+X,
			soma(Y, R).

%4 - faça uma função insere/3 em uma lista em ordem crescente. 