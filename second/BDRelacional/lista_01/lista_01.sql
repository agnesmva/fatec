-- a) Exibir código, nome, salário e o salário com 30% de aumento para todos os funcionários.
select FUNCIONARIO_ID, NOME, SALARIO, 
SALARIO *1.3 as 'SALARIO 30%'
from FUNCIONARIO;

-- b) Exibir os nomes das distintas cidades e bairros dos funcionários da empresa.
select f.NOME, f.BAIRRO, c.NOME AS 'NOME CIDADE'
from FUNCIONARIO f
inner join CIDADE c on f.CIDADE = c.CIDADE_ID;

-- c) Exibir código, nome, preço de custo, preço de venda e a diferença entre estes dois preços para todos os produtos.
select PRODUTO_ID, NOME, CUSTO, VENDA, (VENDA - CUSTO) AS 'LUCRO' from PRODUTO;

-- d) Exibir os 3 primeiros clientes cadastrados.
select * from CLIENTE limit 3;

-- e) Exiba o nome do funcionário e o nome mês do seu aniversário.
select NOME, month(DATA_NASC) as 'Mês Niver' from FUNCIONARIO;

-- f) Mostre os 50% primeiros pedidos cadastrados.

-- g) Mostre a descrição, preço de custo e preço de venda arredondados para 1 casa decimal, de todos os produtos.
select DESCRICAO, round(CUSTO, 1) as 'Custo Arredondado', round(VENDA, 1) as 'Venda Arredondada'
from PRODUTO;

-- h) Mostre o primeiro caractere das siglas dos setores existentes na empresa, tudo em minúsculo.
select lower(substring(SIGLA, 1,1)) as 'Primeiro Caracter em Minúsculo' from SETOR;

-- i) Mostre o nome do dia de hoje.
select 
	case DAYNAME(CURDATE()) 
		when 'Monday' then 'Segunda'
        when 'Tuesday' then 'Terça'
        when 'Wednesday' then 'Quarta'
        when 'Thursday' then 'Quinta'
        when 'Friday' then 'Sexta'
        when 'Saturday' then 'Sábado'
        When 'Sunday' then 'Domingo'
	end
as 'Dia da Semana';

-- j) Mostre os pedidos realizados nos últimos 06 meses.
select * from PEDIDO
where DATA_PEDIDO > '2024-03-01';

-- k) Exibir a data do pedido mais recente.
select max(DATA_PEDIDO) as 'Data do Pedido Mais Recente' from PEDIDO;

-- j) Mostre os nomes dos funcionários, e uma coluna adicional contendo ‘premiado’ com o cabeçalho ‘Bônus’ para todos os funcionários.
select NOME, 'premiado' as 'Bônus' from FUNCIONARIO;

-- m) Qual será o dia da semana, de hoje a 10 dias ??
select 
	case DAYNAME(CURDATE()) 
		when 'Monday' then 'Segunda'
        when 'Tuesday' then 'Terça'
        when 'Wednesday' then 'Quarta'
        when 'Thursday' then 'Quinta'
        when 'Friday' then 'Sexta'
        when 'Saturday' then 'Sábado'
        When 'Sunday' then 'Domingo'
	end
as 'Dia da Semana Hoje',
	case DAYNAME(CURDATE()+10) 
		when 'Monday' then 'Segunda'
        when 'Tuesday' then 'Terça'
        when 'Wednesday' then 'Quarta'
        when 'Thursday' then 'Quinta'
        when 'Friday' then 'Sexta'
        when 'Saturday' then 'Sábado'
        When 'Sunday' then 'Domingo'
	end
as 'Daqui a dez dias';

-- n) Mostre o preço de todos os itens elevados a 3
select PRECO,power(PRECO, 3) as 'Preço Elevado ao Cubo' from ITENS;
