-- prof devido a alguns problemas ao rodar os scripts de criação das tabelas precisei fazer algumas modificações:

-- mudei o nome da coluna CPF da tabela Veículo para cpf_cliente
-- tb mudei o cpf pra varchar não tava pegando como inteiro
-- para fazer o exercício 4 adicionei o ano do veiculo



-- 1. Exiba a placa e o nome dos donos de todos os veículos

SELECT 
	cliente.nome,
    veiculo.placa
FROM 
    veiculo
INNER JOIN cliente ON veiculo.cpf_cliente = cliente.cpf; 

-- 2. Exiba o CPF e o nome do cliente que possui o veiculo de placa “JJJ-2020”
SELECT 
	cliente.nome,
    veiculo.placa
FROM 
    veiculo
INNER JOIN cliente ON veiculo.cpf_cliente = cliente.cpf
WHERE veiculo.placa = 'JJJ-2020';

-- 3. Exiba a placa e a cor do veículo que possui o código de estacionamento 1
SELECT 
	veiculo.placa,
    veiculo.cor
FROM veiculo
INNER JOIN estaciona ON estaciona.veiculo_placa = veiculo.placa
WHERE estaciona.codigo = 1;

-- 4. Exiba a placa e o ano do veículo que possui o código de estacionamento 1
SELECT 
	veiculo.placa,
    veiculo.cor
FROM veiculo
INNER JOIN estaciona ON estaciona.veiculo_placa = veiculo.placa
WHERE estaciona.codigo = 1;
-- 5. Exiba a placa, o ano do veículo e a descrição de seu modelo, se ele possuir ano a partir de 2000
SELECT 
	veiculo.placa,
    veiculo.ano
FROM veiculo
INNER JOIN modelo ON veiculo.cod_modelo = modelo.cod_modelo
WHERE year(ano) > 2000;

-- 6. Exiba o endereço, a data de entrada e de saída dos estacionamentos do veículo de placa “JEG-1010”
SELECT 
	patio.endereco,
    estaciona.data_entrada,
    estaciona.data_saida
FROM estaciona
INNER JOIN patio ON estaciona.numero_patio = patio.numero
INNER JOIN veiculo ON veiculo.placa = estaciona.veiculo_placa
WHERE veiculo.placa = 'JEG-1010';


-- 7. Exiba a quantidade de vezes os veículos de cor verde estacionaram.
SELECT
	count(estaciona.codigo) AS 'Quantidade de Vezes Cor Verde'
FROM estaciona
INNER JOIN veiculo ON veiculo.placa = estaciona.veiculo_placa
WHERE veiculo.cor = 'VERDE';

-- 8. Liste todos os clientes que possuem carro de modelo 1
SELECT
	cliente.nome
FROM cliente
INNER JOIN veiculo ON veiculo.cpf_cliente = cliente.cpf
WHERE veiculo.cod_modelo = 1;

-- 9. Liste as placas, os horários de entrada e saída dos veículos de cor verde
SELECT
	estaciona.veiculo_placa,
    estaciona.data_entrada,
    estaciona.data_saida
FROM estaciona
INNER JOIN veiculo ON veiculo.placa = estaciona.veiculo_placa
WHERE veiculo.cor = 'VERDE';

-- 10. Liste todos os estacionamentos do veículo de placa “JJJ-2020”
SELECT 
    patio.numero,
    estaciona.data_entrada,
    estaciona.data_saida
FROM estaciona
INNER JOIN patio ON estaciona.numero_patio = patio.numero
INNER JOIN veiculo ON veiculo.placa = estaciona.veiculo_placa
WHERE veiculo.placa = 'JJJ-2020';

-- 11. Exiba o nome do cliente que possui o veículo cujo código do estacionamento é 2
SELECT
	 cliente.nome
FROM cliente
INNER JOIN veiculo ON veiculo.cpf_cliente = cliente.cpf
INNER JOIN estaciona ON estaciona.veiculo_placa = veiculo.placa
WHERE estaciona.codigo = 2;

-- 12. Exiba o CPF do cliente que possui o veículo cujo código do estacionamento é 3
SELECT
	 cliente.cpf
FROM cliente
INNER JOIN veiculo ON veiculo.cpf_cliente = cliente.cpf
INNER JOIN estaciona ON estaciona.veiculo_placa = veiculo.placa
WHERE estaciona.codigo = 3;


-- 13. Exiba a descrição do modelo do veículo cujo código do estacionamento é 2.
SELECT
	modelo.descricao
FROM modelo
INNER JOIN veiculo ON veiculo.cod_modelo = modelo.cod_modelo
INNER JOIN estaciona ON estaciona.veiculo_placa = veiculo.placa
WHERE estaciona.codigo = 2;


-- 14. Exiba a placa, o nome dos donos e a descrição dos modelos de todos os veículos.
SELECT
	veiculo.placa,
    cliente.nome,
    modelo.descricao
FROM veiculo
INNER JOIN cliente ON cliente.cpf = veiculo.cpf_cliente
INNER JOIN modelo ON modelo.cod_modelo = veiculo.cod_modelo;