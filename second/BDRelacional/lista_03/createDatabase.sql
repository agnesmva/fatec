CREATE DATABASE estacionamento;

USE estacionamento;

CREATE TABLE cliente (
	cpf 			VARCHAR(255),
	nome			VARCHAR(255),
	data_nascimento DATE,
	
	PRIMARY KEY(cpf)
);

CREATE TABLE modelo (
	cod_modelo	INTEGER,
	descricao	VARCHAR(40),
	
	PRIMARY KEY(cod_modelo)
);

CREATE TABLE veiculo (
	placa			VARCHAR(8),
	cor				VARCHAR(20),
	cod_modelo		INTEGER,
	cpf_cliente			VARCHAR(255),
	
	PRIMARY KEY(placa),
	FOREIGN KEY (cod_modelo) REFERENCES modelo(cod_modelo),
	FOREIGN KEY (cpf_cliente) REFERENCES cliente(cpf)
);

CREATE TABLE patio (
	numero 		INTEGER,
	endereco 	VARCHAR(40),
	capacidade	INTEGER,
	
	PRIMARY KEY(numero)
);

CREATE TABLE estaciona (
	codigo			INTEGER,
	numero_patio	INTEGER,
	veiculo_placa	VARCHAR(8),
	data_entrada	DATE,
	data_saida		DATE,
	hora_entrada	TIME,
	hora_saida		TIME,
	
	PRIMARY KEY(codigo),
	FOREIGN KEY (numero_patio) REFERENCES patio(numero),
	FOREIGN KEY (veiculo_placa) REFERENCES veiculo(placa)
);
