%Projeto Prolog
%Bruno Pedroso 12662136
%Murilo Santana 12662185

%Voos
%@params (origem, destino, código voo, horário, (chegadadia, horário), n conexoes, companhia, [dias que o voo acontece])

%partida de sao_paulo
	voo(sao_paulo, mexico,gl1,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(sao_paulo, nova_york,gl2,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
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
%@paramentros (origem, destino, companhia, dia da semana, horário)

	voodireto(X, Y):- voo(X, Y,_,_,(_,_),0,_,[_,_,_]).

%conexoes
%@%params (origem, destino)
%pergunta roteiro(Origem, Destino, ListaVoos).
	
	conexoes(X, Y):- voodireto(X,H), voodireto(H, Y).
	
%voo direto  dia da semana
%pergunta filtra_voo_dia_semana(Origem,Destino, DiaSemana, HorarioSaida,HorarioChegada,Companhia).
	voo_direto_dia_semana(X, Y, [X]):- voo(X,Y,_,_,(_,_),0,_,[X]).

%voo direto menor duracao
%@params (origem, destino, dia da semana)
%pergunta menorDuracao(Origem,Destino,dia,HorarioSaida,HorarioChegada,Companhia).

%teste de print 
	show_records([]).
	show_records([A|B]) :-
	  format('Origem = ~w\tName = ~w\tGrade = ~w~n',A),
	  show_records(B).
