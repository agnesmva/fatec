-- prof ao final da lista estão os inserts e o script de criação do banco 

-- a) Listar os nomes dos assinantes, seguido dos dados do endereço e os telefones correspondentes.
SELECT a.nm_assinante, e.endereco, e.complemento, e.bairro, e.cep, m.ds_municipio, t.ddd, t.numero
FROM Assinante a
JOIN Endereco e ON a.cd_assinante = e.cd_assinante
JOIN Municipio m ON e.cd_municipio = m.cd_municipio
JOIN Telefone t ON a.cd_assinante = t.cd_assinante;

-- b)Listar os nomes dos assinantes, seguido do seu ramo, ordenados por ramo e posteriormente por nome

SELECT a.nm_assinante, r.ds_ramo
FROM Assinante a
JOIN Ramo_Atividade r ON a.cd_ramo = r.cd_ramo
ORDER BY r.ds_ramo, a.nm_assinante;


-- c) Listar os assinantes do município de Pelotas que são do tipo residencial. 
SELECT a.nm_assinante
FROM Assinante a
JOIN Endereco e ON a.cd_assinante = e.cd_assinante
JOIN Municipio m ON e.cd_municipio = m.cd_municipio
JOIN Tipo_Assinante ta ON a.cd_tipo = ta.cd_tipo
WHERE m.ds_municipio = 'Pelotas' AND ta.ds_tipo = 'Residencial';

-- d) Listar os nomes dos assinantes que possuem mais de um telefone.
SELECT a.nm_assinante
FROM Assinante a
JOIN Telefone t ON a.cd_assinante = t.cd_assinante
GROUP BY a.cd_assinante
HAVING COUNT(t.cd_fone) > 1;

-- e) Listar os nomes dos assinantes seguido do número do telefone, tipo de assinante comercial com endereço em Natal ou João Câmara.

SELECT a.nm_assinante, t.numero, ta.ds_tipo
FROM Assinante a
JOIN Telefone t ON a.cd_assinante = t.cd_assinante
JOIN Tipo_Assinante ta ON a.cd_tipo = ta.cd_tipo
JOIN Endereco e ON a.cd_assinante = e.cd_assinante
JOIN Municipio m ON e.cd_municipio = m.cd_municipio
WHERE ta.ds_tipo = 'Comercial' AND (m.ds_municipio = 'Natal' OR m.ds_municipio = 'João Câmara');

-- script para criação da base de dados
CREATE DATABASE AssinantesDB;
USE AssinantesDB;


CREATE TABLE Municipio (
    cd_municipio INT PRIMARY KEY,
    ds_municipio VARCHAR(100)
);

CREATE TABLE Tipo_Assinante (
    cd_tipo INT PRIMARY KEY,
    ds_tipo VARCHAR(50)
);

CREATE TABLE Ramo_Atividade (
    cd_ramo INT PRIMARY KEY,
    ds_ramo VARCHAR(100)
);

CREATE TABLE Assinante (
    cd_assinante INT PRIMARY KEY,
    nm_assinante VARCHAR(100),
    cd_ramo INT,
    cd_tipo INT,
    FOREIGN KEY (cd_ramo) REFERENCES Ramo_Atividade(cd_ramo),
    FOREIGN KEY (cd_tipo) REFERENCES Tipo_Assinante(cd_tipo)
);

CREATE TABLE Endereco (
    cd_endereco INT PRIMARY KEY,
    cd_assinante INT,
    endereco VARCHAR(255),
    complemento VARCHAR(100),
    bairro VARCHAR(100),
    cep VARCHAR(20),
    cd_municipio INT,
    FOREIGN KEY (cd_assinante) REFERENCES Assinante(cd_assinante),
    FOREIGN KEY (cd_municipio) REFERENCES Municipio(cd_municipio)
);

CREATE TABLE Telefone (
    cd_fone INT PRIMARY KEY,
    cd_assinante INT,
    ddd VARCHAR(5),
    numero VARCHAR(20),
    FOREIGN KEY (cd_assinante) REFERENCES Assinante(cd_assinante)
);


-- todos os inserts aqui prof
INSERT INTO Municipio VALUES (1, 'Pelotas');
INSERT INTO Municipio VALUES (2, 'Natal');
INSERT INTO Municipio VALUES (3, 'João Câmara');

INSERT INTO Tipo_Assinante VALUES (1, 'Residencial');
INSERT INTO Tipo_Assinante VALUES (2, 'Comercial');

INSERT INTO Ramo_Atividade VALUES (1, 'Comércio');
INSERT INTO Ramo_Atividade VALUES (2, 'Indústria');

INSERT INTO Assinante VALUES (1, 'João Silva', 1, 1);
INSERT INTO Assinante VALUES (2, 'Maria Oliveira', 1, 2);
INSERT INTO Assinante VALUES (3, 'Carlos Santos', 2, 1);

INSERT INTO Endereco VALUES (1, 1, 'Rua 1', 'Apto 101', 'Centro', '96000-000', 1);
INSERT INTO Endereco VALUES (2, 2, 'Rua 2', 'Casa', 'Bairro A', '59000-000', 2);
INSERT INTO Endereco VALUES (3, 3, 'Rua 3', 'Apto 202', 'Bairro B', '59000-000', 3);

INSERT INTO Telefone VALUES (1, 1, '53', '123456789');
INSERT INTO Telefone VALUES (2, 1, '53', '987654321');
INSERT INTO Telefone VALUES (3, 2, '84', '555555555');
INSERT INTO Telefone VALUES (4, 3, '84', '444444444');

