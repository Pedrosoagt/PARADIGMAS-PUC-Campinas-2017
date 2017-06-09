/*
	Projeto Prolog

	Bruno Pedroso  - 12662136
	Murilo Santana - 12662185
*/

%Voos
%@params (origem,destino,códigoVoo,horário,(chegadadia,horário),numConexoes,companhia,[dias que o voo acontece]).
%partida de sao_paulo
	voo(sao_paulo, mexico,gl1,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(sao_paulo, nova_york,gl2,8:25,(mesmo,20:25),0,gol,[qua]).
	voo(sao_paulo, nova_york,gl2,7:10,(mesmo,20:25),0,gol,[seg,qua,sab]).
	voo(sao_paulo, nova_york,bla,8:30,(mesmo,20:25),0,gol,[seg,qua]).
	voo(sao_paulo, nova_york,gl2,7:10,(mesmo,20:25),3,gol,[seg,qua,sab]).
	voo(sao_paulo, londres,gl3,8:25,(mesmo,12:25),0,gol,[qua,sex,dom]).
	voo(sao_paulo, lisboa,gl4,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(sao_paulo, madrid,gl5,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(sao_paulo, paris,gl6,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas do mexico
	voo(mexico, nova_york,gl7,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(mexico, madrid,gl8,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(mexico, sao_paulo,gl1,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de nova_york
	voo(nova_york, londres,gl9,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(nova_york, sao_paulo,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(nova_york, mexico,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de londres
	voo(londres, lisboa,gl10,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(londres, paris,gl11,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(londres, estocolmo,gl12,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(londres, sao_paulo,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(londres, nova_york,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de madrid
	voo(madrid, paris,gl13,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(madrid, roma,gl14,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(madrid, frankfurt,gl15,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(madrid, sao_paulo,gl15,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(madrid, mexico,gl15,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de frankfurt
	voo(frankfurt, estocolmo,gl16,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(frankfurt, roma,gl17,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(frankfurt, madrid,gl17,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de estocolmo
	voo(estocolmo, londres,gl12,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(estocolmo, frankfurt,gl12,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de roma
	voo(roma, frankfurt, gl17,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(roma, madrid, gl17,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de paris
	voo(paris, sao_paulo,gl6,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(paris, londres,gl6,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(paris, madrid,gl6,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%partidas de lisboa
	voo(lisboa, sao_paulo,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(lisboa, londres,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).

%VoosDiretos
%pergunta voodireto(origem, destino, companhia, dia da semana, horário)

	voodireto(O, D, E, W, H):-
		voo(O, D,_,H,(_,_),0,E,T),
		membro(T, W).

%conexoes
%pergunta roteiro(Origem, Destino, ListaVoos).

	roteiro(O,D,L):-
		\+ aux(O,D),
		voo(O,X,C1,_,_,_,_,_),
		voo(X,D,C2,_,_,_,_,_),
		conc([C1],[C2],L).

	aux(O,D):-
	voo(O,D,_,_,_,_,_,_),!.

%voos direto  dia da semana
%pergunta filtra_voo_dia_semana(Origem,Destino, DiaSemana, HorarioSaida,HorarioChegada,Companhia).

	filtra_voo_dia_semana(O, D, W, S, C, E):-
		voo(O, D,_,S,(_,C),0,E,T),
		membro(T, W).

%voos direto de menor duracao
%pergunta menorDuracao(Origem,Destino,dia,HoraSaida,HoraChegada,Companhia).

	menorDuracao(O,D,W,S,C,E):-
		setof([T,S,C,E,W],auxMenorDuracao(O,D,_,S,(_,C),_,E,W,T),L),
		inicioLista(L,[_,S,C,E,W]).

	auxMenorDuracao(O,D,_,Hora:Min,(_,HoraC:MinC),_,E,Dia,Duracao):-
		voo(O,D,_,Hora:Min,(DiaC,HoraC:MinC),0,E,Dias),
		membro(Dias,Dia),
		somaHora(Hora,Min,DuracaoS),
		somaHora(HoraC,MinC,DuracaoC),
		somaDia(DiaC,DuracaoC,DuracaoC2),
		numero(DuracaoC2,DuracaoS,Duracao).

%voos diretos calculando a duração
%pergunta roteiro(Origem, Destino, DiaSaída, HoraSaida, Duração).

	roteiro(O, D, DiaS, Hora:Min, Duracao):-
		menorDuracao(O, D,_,_,_,_),
		voo_dirireto(O,D,_,DiaS,Hora:Min,HoraC:MinC,DiaC),
		somaHora(Hora,Min,DuracaoS),
		somaHora(HoraC,MinC,DuracaoC),
		somaDia(DiaC,DuracaoC,DuracaoC2),
		numero(DuracaoC2,DuracaoS,Duracao),!.

	voo_dirireto(O, D, E, W, Hora:Min, HoraC:MinC, DiaC):-
		voo(O,D,_,Hora:Min,(DiaC,HoraC:MinC),0,E,T),
		membro(T, W).

%auxiliares
	membro([X|_],X).
	membro([_|T],X):-
		membro(T,X).

	diferente(X,Y):- X \= Y. %função não mais usada

	conc([],L,L).
	conc([X|L1],L2,[X|L]) :-
		conc(L1,L2,L).

	inicioLista([L|_],L).

	somaHora(0,Y,Y).
	somaHora(X,Y,C):-
		X1 is X-1,Y1 is Y+60,
		somaHora(X1,Y1,C),!.

	somaDia(mesmo,Y,Y).
	somaDia(seguinte,Y,C):-
		C is Y + 1440,!.

	numero(X,0,X).
	numero(0,Y,Y).
	numero(X,Y,C):-
		X1 is X-1,Y1 is Y-1,
		numero(X1,Y1,C),!.