-- 1) Os dados de todos os pilotos de companhias brasileiras.
select p.cod_piloto, p.cod_companhia, p.nome, p.salario, p.gratificacao from piloto p
inner join companhia c on c.cod_companhia = p.cod_companhia
where p.pais = 'BRASIL';

-- 2) Nome de todos os pilotos da TAM
select  p.nome from piloto p
inner join companhia c on c.cod_companhia = p.cod_companhia
where c.nome = 'TAM';

-- 3) Nome de todos os pilotos, junto com seu salário e gratificação.
select nome, salario, gratificacao from piloto;

-- 4) Nome da cidade e país de destino do vôo de código ‘TAM30’.

-- 5) Os dados de todos os vôos juntamente com os nomes dos aeroportos de origem e destino e também o nome da companhia
select 
    v.cod_voo AS "Código do Voo",
    a_origem.nome AS "Aeroporto de Origem",
    a_destino.nome AS "Aeroporto de Destino",
    c.nome AS "Nome da Companhia"
from 
    voo v
join 
    aeroporto a_origem ON v.cod_aeroporto_origem = a_origem.cod_aeroporto
join 
    aeroporto a_destino ON v.cod_aeroporto_destino = a_destino.cod_aeroporto
join 
    companhia c ON v.cod_companhia = c.cod_companhia;

-- 6) Os dados de todas as partidas juntamente com os nomes dos pilotos e o nome da companhia.
SELECT 
    p.cod_partida, p.data, p.hora, p.aviao, pil.nome as 'nome piloto', c.nome as 'nome companhia'
FROM 
    partida p
JOIN 
    piloto pil ON p.cod_piloto = pil.cod_piloto
JOIN 
    companhia c ON pil.cod_companhia = c.cod_companhia
JOIN 
    voo v ON p.cod_voo = v.cod_voo;

-- 7) As companhias dos vôos com partidas no dia 01/05/2010.
SELECT DISTINCT
    c.nome  as 'Nome da Companhia'
FROM 
    partida p
JOIN 
    voo v ON p.cod_voo = v.cod_voo
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
WHERE 
    p.data = '2010-05-01';
    
-- 8) As companhias dos vôos com partidas no mês de maio de 2010.

SELECT DISTINCT
    c.nome AS "Nome da Companhia"
FROM 
    partida p
JOIN 
    voo v ON p.cod_voo = v.cod_voo
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
WHERE 
    MONTH(p.data) = 5 AND YEAR(p.data) = 2010;


-- 9) As companhias dos vôos com partidas no mês de junho de 2010.

SELECT DISTINCT
    c.nome AS "Nome da Companhia"
FROM 
    partida p
JOIN 
    voo v ON p.cod_voo = v.cod_voo
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
WHERE 
    MONTH(p.data) = 6 AND YEAR(p.data) = 2010;


-- 10) Os nomes dos pilotos que voaram no mês de maio de 2010.
SELECT DISTINCT
    pil.nome AS "Nome do Piloto"
FROM 
    partida p
JOIN 
    piloto pil ON p.cod_piloto = pil.cod_piloto
WHERE 
    MONTH(p.data) = 5 AND YEAR(p.data) = 2010;

-- 11) Os nomes dos pilotos que voaram entre os dias 25/05/2010 e 15/06/2010.
SELECT DISTINCT
    pil.nome AS "Nome do Piloto"
FROM 
    partida p
JOIN 
    piloto pil ON p.cod_piloto = pil.cod_piloto
WHERE 
    p.data BETWEEN '2010-05-25' AND '2010-06-15';

-- 12) Os vôos disponíveis para a Alemanha ou Itália, juntamente com o nome da companhia.
SELECT 
    v.cod_voo AS "Código do Voo",
    c.nome AS "Nome da Companhia"
FROM 
    voo v
JOIN 
    aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
WHERE 
    a.pais IN ('ALEMANHA', 'ITÁLIA', 'ITALIA');
    
-- 13) O código, data, hora e piloto de todas as partidas que saem do Brasil.
SELECT 
    p.cod_partida AS "Código da Partida",
    p.data AS "Data",
    p.hora AS "Hora",
    pil.nome AS "Nome do Piloto"
FROM 
    partida p
JOIN 
    voo v ON p.cod_voo = v.cod_voo
JOIN 
    aeroporto a ON v.cod_aeroporto_origem = a.cod_aeroporto
JOIN 
    piloto pil ON p.cod_piloto = pil.cod_piloto
WHERE 
    a.pais = 'BRASIL';

-- 14) O código, data, hora, código do vôo, companhia e piloto de todas as partidas que chegam ao Brasil.
SELECT 
    p.cod_partida AS "Código da Partida",
    p.data AS "Data",
    p.hora AS "Hora",
    v.cod_voo AS "Código do Voo",
    c.nome AS "Nome da Companhia",
    pil.nome AS "Nome do Piloto"
FROM 
    partida p
JOIN 
    voo v ON p.cod_voo = v.cod_voo
JOIN 
    aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
JOIN 
    piloto pil ON p.cod_piloto = pil.cod_piloto
WHERE 
    a.pais = 'BRASIL';

-- 15) O nome dos pilotos das companhias que voam para a Itália.
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
JOIN 
    voo v ON pil.cod_piloto = v.cod_voo
JOIN 
    companhia c ON pil.cod_companhia = c.cod_companhia
JOIN 
    aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
WHERE 
    a.pais in ('ITÁLIA', 'ITALIA');
    
-- 16) Os aeroportos de destino (nome, cidade e país) de todos os vôos da Gol.

SELECT 
    a.nome AS "Nome do Aeroporto",
    a.cidade AS "Cidade",
    a.pais AS "País"
FROM 
    voo v
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
JOIN 
    aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
WHERE 
    c.nome = 'GOL';

-- 17) Os aeroportos de origem (nome, cidade e país) para todos os vôos da German Air
SELECT 
    a.nome AS "Nome do Aeroporto",
    a.cidade AS "Cidade",
    a.pais AS "País"
FROM 
    voo v
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
JOIN 
    aeroporto a ON v.cod_aeroporto_origem = a.cod_aeroporto
WHERE 
    c.nome = 'GERMAN AIR';

-- 18) O nome de todos os aeroportos onde a Gol opera.
SELECT 
    a.nome AS "Nome do Aeroporto"
FROM 
    voo v
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
JOIN 
    aeroporto a ON v.cod_aeroporto_origem = a.cod_aeroporto
WHERE 
    c.nome = 'GOL'
UNION
SELECT 
    a.nome AS "Nome do Aeroporto"
FROM 
    voo v
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
JOIN 
    aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
WHERE 
    c.nome = 'GOL';

-- 19) O código de todos os vôos da companhia Tam que saem do Brasil com destino a outros países.
SELECT 
    v.cod_voo AS "Código do Vôo"
FROM 
    voo v
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
JOIN 
    aeroporto a_origem ON v.cod_aeroporto_origem = a_origem.cod_aeroporto
JOIN 
    aeroporto a_destino ON v.cod_aeroporto_destino = a_destino.cod_aeroporto
WHERE 
    c.nome = 'TAM' 
    AND a_origem.pais = 'BRASIL'
    AND a_destino.pais <> 'BRASIL';

-- 20) Os pilotos cujos nomes começam pela letra M
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
WHERE 
    pil.nome LIKE 'M%';

-- 21) Os pilotos cujos nomes não começam pela letra M.
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
WHERE 
    pil.nome NOT LIKE 'M%';

-- 22) Os nomes dos pilotos que sejam parentes da família ‘Silva’, ou seja, contenham Silva no nome
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
WHERE 
    pil.nome LIKE '%Silva%';

-- 23) Os nomes dos pilotos que terminam O ou A.
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
WHERE 
    pil.nome LIKE '%O' OR pil.nome LIKE '%A';

-- 24) Os nomes dos pilotos que tenham a 2ª letra igual a A.
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
WHERE 
    pil.nome LIKE '_A%';

-- 25) Os nomes dos pilotos que não tem ‘Silva’ no nome
SELECT 
    pil.nome AS "Nome do Piloto"
FROM 
    piloto pil
WHERE 
    pil.nome NOT LIKE '%Silva%';

-- 26) Os Aeroportos cujo nome do país tenha 'IT' ou 'AL'
SELECT 
    a.nome AS "Nome do Aeroporto", 
    a.cidade AS "Cidade", 
    a.pais AS "País"
FROM 
    aeroporto a
WHERE 
    a.pais LIKE '%IT%' OR a.pais LIKE '%AL%';

-- 27) Os nomes dos Aeroportos onde a penúltima letra seja R ou U.
SELECT 
    a.nome AS "Nome do Aeroporto"
FROM 
    aeroporto a
WHERE 
    SUBSTRING(a.nome, LENGTH(a.nome)-1, 1) IN ('R', 'U');

-- 28) Os vôos cujos códigos iniciam por ‘TA’ ou ‘GO’, exibindo também o nome da companhia.
SELECT 
    v.cod_voo AS "Código do Vôo", 
    c.nome AS "Nome da Companhia"
FROM 
    voo v
JOIN 
    companhia c ON v.cod_companhia = c.cod_companhia
WHERE 
    v.cod_voo LIKE 'TA%' OR v.cod_voo LIKE 'GO%';

-- 29) Listar os nomes dos pilotos ordenados pelo salário.
SELECT 
    pil.nome AS "Nome do Piloto", 
    pil.salario AS "Salário"
FROM 
    piloto pil
ORDER BY 
    pil.salario DESC;

-- 30) Listar os nomes dos pilotos que possuem partidas para o Brasil, ordenados pelo Nome.
SELECT DISTINCT p.nome
FROM piloto p
JOIN partida pa ON p.cod_piloto = pa.cod_piloto
JOIN voo v ON pa.cod_voo = v.cod_voo
JOIN aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
WHERE a.pais = 'BRASIL'
ORDER BY p.nome;


-- 31) Listar os nomes dos Aeroportos ordenados pelo país e pela cidade.
SELECT nome, cidade, pais
FROM aeroporto
ORDER BY pais, cidade;


-- 32) Listar a companhia, data, hora e aeroporto de origem de todas as partidas ordenadas por: nome da companhia, nome do aeroporto de origem, data da partida e hora da partida.
SELECT c.nome AS companhia, pa.data, pa.hora, a.nome AS 'aeroporto origem'
FROM partida pa
JOIN voo v ON pa.cod_voo = v.cod_voo
JOIN companhia c ON v.cod_companhia = c.cod_companhia
JOIN aeroporto a ON v.cod_aeroporto_origem = a.cod_aeroporto
ORDER BY c.nome, a.nome, pa.data, pa.hora;

-- 33) O salário do piloto mais bem pago da Tam.
SELECT MAX(p.salario) AS salario_maximo
FROM piloto p
JOIN companhia c ON p.cod_companhia = c.cod_companhia
WHERE c.nome = 'TAM';

-- 34) O menor, o maior, e a média dos salários dos pilotos de companhias brasileiras.
SELECT MIN(p.salario) AS salario_minimo, MAX(p.salario) AS salario_maximo, AVG(p.salario) AS salario_medio
FROM piloto p
JOIN companhia c ON p.cod_companhia = c.cod_companhia
WHERE c.pais = 'BRASIL';

-- 35) O total da folha de pagamento da Gol.
SELECT SUM(p.salario) AS total_folha
FROM piloto p
JOIN companhia c ON p.cod_companhia = c.cod_companhia
WHERE c.nome = 'GOL';

-- 36) Os nomes dos 4 pilotos mais bem pagos.
SELECT p.nome
FROM piloto p
ORDER BY p.salario DESC
LIMIT 4;

-- 37) O número de aeroportos no Brasil.
SELECT COUNT(*) AS numero_aeroportos_brasil
FROM aeroporto
WHERE pais = 'BRASIL';

-- 38) A quantidade de vôos que partem do Brasil.
SELECT COUNT(*) AS quantidade_voos_brasil
FROM voo v
JOIN aeroporto a ON v.cod_aeroporto_origem = a.cod_aeroporto
WHERE a.pais = 'BRASIL';

-- 39) A quantidade de vôos que tem como destino a Itália.
SELECT COUNT(*) AS quantidade_voos_italia
FROM voo v
JOIN aeroporto a ON v.cod_aeroporto_destino = a.cod_aeroporto
WHERE a.pais IN ('ITÁLIA', 'ITALIA');


-- 40) Os nomes de todos os aviões utilizados pelas companhias. OBS: não deverão ser listados nomes repetidos
SELECT DISTINCT pa.aviao
FROM partida pa;

