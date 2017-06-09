%Projeto Prolog
%Bruno Pedroso 12662136
%Murilo Santana 12662185

%Voos
%@params (origem,destino,códigoVoo,horário,(chegadadia,horário),numConexoes,companhia,[dias que o voo acontece]).

%partida de sao_paulo
	voo(sao_paulo, mexico,gl1,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(sao_paulo, nova_york,gl2,8:25,(mesmo,20:25),0,gol,[qua]).
	voo(sao_paulo, nova_york,gl2,7:10,(mesmo,20:25),0,gol,[seg,qua,sab]).
	voo(sao_paulo, nova_york,gl2,8:25,(seguinte,20:24),0,gol,[seg,qua]).
	voo(sao_paulo, nova_york,gl2,7:10,(mesmo,20:25),3,gol,[seg,qua,sab]).
	voo(sao_paulo, londres,gl3,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
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
%@params (origem, destino, companhia, dia da semana, horário)

	voodireto(O, D, E, W, H):-
		voo(O, D,_,H,(_,_),0,E,T),
		contem(T, W).

%conexoes
%@%params (origem, destino)
%pergunta roteiro(Origem, Destino, ListaVoos).

	/*voodireto(H, Y), diferente(X, H), diferente(X, Y), diferente(Y, H).
	diferente(X, Y):- X \= Y.*/
	
%voos direto  dia da semana
%pergunta filtra_voo_dia_semana(Origem,Destino, DiaSemana, HorarioSaida,HorarioChegada,Companhia).

	filtra_voo_dia_semana(O, D, W, S, C, E):-
		voo(O, D,_,S,(_,C),0,E,T),
		contem(T, W).

%voos direto menor duracao
%@params (origem, destino, dia da semana)
%pergunta menorDuracao(Origem,Destino,dia,HorarioSaida,HorarioChegada,Companhia).
	
	menorDuracao(O,D,W,S,C,E):- 
		setof([T,S,C,E,W],menorduracaoaux(O,D,_,S,(_,C),_,E,W,T),L), 
		comecolista(L,[_,S,C,E,W]).

	menorduracaoaux(O,D,Cod,Hora:Min,(_,HoraC:MinC),_,Comp,Dia,Duração):-
		voo(O,D,Cod,Hora:Min,(DiaC,HoraC:MinC),_,Comp,Dias),
		contem(Dias,Dia),soma60(Hora,Min,DuraçãoS),
		soma60(HoraC,MinC,DuraçãoC),soma24(DiaC,DuraçãoC,DuraçãoC2),
		numero(DuraçãoC2,DuraçãoS,Duração).

%voos diretos calculando a duração
%@params (Origem, Destino dia semana)
%pergunta (roteiro(Origem, Destino, DiaSaída, HorSaida, Duração).

%auxiliares
	contem([X|_],X).
	contem([_|Cauda],X):- contem(Cauda,X).

	comecolista([L|_],L).

	numero(X,0,X).
	numero(0,Y,Y).
	numero(X,Y,C):- X1 is X-1,Y1 is Y-1,numero(X1,Y1,C),!.

	soma60(0,Y,Y).
	soma60(X,Y,C):- X1 is X-1,Y1 is Y+60, soma60(X1,Y1,C),!.

	soma24(mesmo,Y,Y).
	soma24(seguinte,Y,C):- C is Y + 1440,!.
