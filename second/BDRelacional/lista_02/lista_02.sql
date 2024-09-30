-- parte 1
use lista2;
select * from venda;

-- 1) Pesquise os itens que foram vendidos sem desconto. As colunas presentes no resultado da consulta são: ID_NF, ID_ITEM, COD_PROD E VALOR_UNIT. --
select ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT 
from venda
where DESCONTO = 0;

-- 2) Pesquise os itens que foram vendidos com desconto. As colunas presentes no resultado da consulta são: ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT E O VALOR VENDIDO. 
-- OBS: O valor vendido é igual ao VALOR_UNIT - (VALOR_UNIT*(DESCONTO/100)). 
select ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT, (VALOR_UNIT-(VALOR_UNIT*(DESCONTO/100))) as 'Valor Vendido', DESCONTO 
from venda
where DESCONTO > 0;

-- 3) Altere o valor do desconto (para zero) de todos os registros onde este campo é nulo.
-- 4) Pesquise os itens que foram vendidos. As colunas presentes no resultado da consulta são: ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT, VALOR_TOTAL, DESCONTO, VALOR_VENDIDO. --
-- OBS: O VALOR_TOTAL é obtido pela fórmula: QUANTIDADE * VALOR_UNIT. O VALOR_VENDIDO é igual a VALOR_UNIT - (VALOR_UNIT*(DESCONTO/100)). --
select ID_NF, ID_ITEM, COD_PROD, VALOR_UNIT, (QUANTIDADE * VALOR_UNIT) as 'Valor Total', DESCONTO, (VALOR_UNIT-(VALOR_UNIT*(DESCONTO/100))) as 'Valor Vendido' 
from venda;

-- 5) Pesquise o valor total das NF e ordene o resultado do maior valor para o menor. As colunas presentes no resultado da consulta são: ID_NF, VALOR_TOTAL. --
 -- OBS: O VALOR_TOTAL é obtido pela fórmula: Σ QUANTIDADE * VALOR_UNIT. --
 select ID_NF, (QUANTIDADE * VALOR_UNIT) as 'Valor Total' 
 from venda
 order by VALOR_TOTAL desc;
 
 -- 6) Pesquise o valor vendido das NF e ordene o resultado do maior valor para o menor. As colunas presentes no resultado da consulta são: ID_NF, VALOR_VENDIDO. --
 -- OBS: O VALOR_TOTAL é obtido pela fórmula: Σ QUANTIDADE * VALOR_UNIT. O VALOR_VENDIDO é igual a Σ VALOR_UNIT - (VALOR_UNIT*(DESCONTO/100)). --
select ID_NF, (VALOR_UNIT - (VALOR_UNIT*(DESCONTO/100))) as 'Valor Vendido' 
from venda
order by VALOR_VENDIDO desc;
use lista2;
-- 7) Consulte o produto que mais vendeu no geral. As colunas presentes no resultado da consulta são: COD_PROD, QUANTIDADE.
select COD_PROD, QUANTIDADE 
from venda
order by QUANTIDADE desc limit 1;

-- 8) Consulte as NF que foram vendidas mais de 10 unidades de pelo menos um produto. As colunas presentes no resultado da consulta são: ID_NF, COD_PROD, QUANTIDADE.
select ID_NF, COD_PROD, QUANTIDADE 
from venda
where QUANTIDADE > 10;

-- 9) 9) Pesquise o valor total das NF, onde esse valor seja maior que 500, e ordene o resultado do maior valor para o menor. As colunas presentes no resultado da consulta são: ID_NF, VALOR_TOT.
-- OBS: O VALOR_TOTAL é obtido pela fórmula: Σ QUANTIDADE* VALOR_UNIT.
select ID_NF, sum(QUANTIDADE * VALOR_UNIT) as 'Valor Total' 
from venda
group by ID_NF
having VALOR_TOTAL > 500
order by VALOR_TOTAL desc;

 -- 10) Qual o valor médio dos descontos dados por produto. As colunas presentes no resultado da consulta são: COD_PROD, MEDIA.
 select COD_PROD, avg(DESCONTO) as 'Media' from venda
 group by COD_PROD;
 
 -- 11) Qual o menor, maior e o valor médio dos descontos dados por produto. As colunas presentes no resultado da consulta são: COD_PROD, MENOR, MAIOR, MEDIA.
  select COD_PROD, min(DESCONTO) as 'Menor', max(DESCONTO) as 'Maior', avg(DESCONTO) as 'Media' 
  from venda
 group by COD_PROD;
 
 -- 12) Quais as NF que possuem mais de 3 itens vendidos. As colunas presentes no resultado da consulta são: ID_NF, QTD_ITENS. 
 -- OBS: NÃO ESTÁ RELACIONADO A QUANTIDADE VENDIDA DO ITEM E SIM A QUANTIDADE DE ITENS POR NOTA FISCAL.
select ID_NF, count(COD_PROD) as QTD_ITENS from venda
group by ID_NF
having count(COD_PROD) > 3;


-- parte 2
use universidade;

-- a) Encontre o codigo dos alunos com nota em BD em 2015 menor que 5 (obs: BD = código da disciplinas). 
select codigo_aluno, n1, n2 
from historico
where (n1 < 5) or (n2 < 5) and sigla_disciplina = 'BD';

-- b) Encontre o codigo_aluno e calcule a média das notas dos alunos na disciplina de POO em 2015.
select codigo_aluno,
	   ((n1 + n2)/2) as 'Media POO'
from historico
where sigla_disciplina = 'POO';

-- c) Encontre a MAT e calcule a média das notas dos alunos na disciplina de POO em 2015 e que esta média seja superior a 6. 
select codigo_aluno,
	   ((n1 + n2)/2) as Media_POO
from historico
where sigla_disciplina = 'POO' 
having Media_POO > 6;

-- d) Encontre quantos alunos não são de Natal. 
select * 
from aluno
where cidade not like 'NATAL';
 
