// Projeto Prolog
// Sistema de genrenciamento de voo 
// Bruno  Pedroso 12662136
// Murilo Santana 12662185


/* 
	Funções necessárias para as perguntas. 

	voo_direto(cidade_origem, cidade_destino, empresa, dia, hora)
	roteiro(cidade origem, cidade_destino, ListaVoos)
	filtro_voo_dia_semana(cidade origem, cidade destino, dia da semana, hora saida, hora chegada, empresa)
	menor_duracao(origem, destino, dia, horario saida, horario chegada, empresa)
	voo_escalas(origem,[ordem  de lugares até chegar no destino])
*/


//voo(origem, destino)

	voo(saopaulo,madrid,gl1,8:25,(mesmo,20:25),0,gol,[qua,sex,dom]).
	voo(saopaulo,mexico,gl2,9:25,(seguinte,23:25),0,gol,[sex,dom]).

//lista de voos disponíveis. 
	voo(saopaulo, mexico).
	voo(saopaulo, novayork).
	voo(saopaulo, londres).
	voo(saopaulo, lisboa).
	voo(saopaulo, madrid).
	voo(saopaulo, paris).
	voo(mexico, novayork).
	voo(mexico, madrid).
	voo(novayork, londres).
	voo(londres, lisboa).
	voo(londres, paris).
	voo(londres, estocolmo).
	voo(madrid, paris).
	voo(madrid, roma).
	voo(madrid, frankfurt).
	voo(frankfurt, estocolmo).
	voo(frankfurt, roma).