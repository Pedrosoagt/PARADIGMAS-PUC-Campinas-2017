
(defun ENCmembro (obj lista)
   (cond ((null lista) nil)
         ((eql obj (CAAR lista)) t)
         (t (ENCmembro obj (rest lista))))) 

(DEFUN MATRICULARAUXILIAR (ALUNOS DISCIPLINAS BD)
	(COND ((NULL (CDR DISCIPLINAS))
		(cons (cons (car DISCIPLINAS) (CONS ALUNOS NIL)) 
		NIL)
		)
		(T (APPEND (cons (cons (car DISCIPLINAS) (CONS ALUNOS NIL)) 
		BD)(MATRICULARAUXILIAR ALUNOS (CDR DISCIPLINAS) BD)))
	)
)

(DEFUN MATRICULAR-PR (ALUNOS DISCIPLINAS BD)
	(IF (NULL (CDR DISCIPLINAS))
		(cons (cons (car DISCIPLINAS) (CONS ALUNOS NIL)) 
		NIL)
		(APPEND (cons (cons (car DISCIPLINAS) (CONS ALUNOS NIL)) 
		NIL)(MATRICULARAUXILIAR ALUNOS (CDR DISCIPLINAS) BD))
	)
)

(DEFUN MATRICULAR (ALUNOS DISCIPLINAS BD)
	(COND ((NULL BD)
		(MATRICULAR-PR ALUNOS DISCIPLINAS BD))
		((NULL DISCIPLINAS) bd)
		((NOT (NULL (ENCmembro (CAR DISCIPLINAS) BD)))
		 (REC DISCIPLINAS BD ALUNOS)
		)
		(T (APPEND (MATRICULAR-PR ALUNOS DISCIPLINAS BD) BD))
	)
)