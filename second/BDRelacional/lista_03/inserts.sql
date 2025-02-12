-- Incluindo valores na tabela cliente
INSERT INTO cliente (cpf, nome, data_nascimento) VALUES
('12345678901', 'João Silva', '1985-07-15'),
('23456789012', 'Maria Oliveira', '1990-02-20'),
('34567890123', 'Carlos Souza', '1978-11-03'),
('45678901234', 'Ana Costa', '1995-05-10'),
('56789012345', 'Pedro Lima', '1988-08-25'),
('67890123456', 'Beatriz Ramos', '2000-01-15'),
('78901234567', 'Lucas Alves', '1982-03-12'),
('89012345678', 'Fernanda Melo', '1993-09-18');

-- Incluindo valores na tabela modelo
INSERT INTO modelo (cod_modelo, descricao) VALUES
(1, 'Sedan'),
(2, 'SUV'),
(3, 'Hatchback'),
(4, 'Pick-up'),
(5, 'Esportivo'),
(6, 'Conversível'),
(7, 'Van'),
(8, 'Minivan');

-- Incluindo valores na tabela veiculo
INSERT INTO veiculo (placa, cor, cod_modelo, cpf_cliente) VALUES
('ABC1234', 'Preto', 1, '12345678901'),
('DEF5678', 'Branco', 2, '23456789012'),
('GHI9012', 'Vermelho', 3, '34567890123'),
('JKL3456', 'Azul', 4, '45678901234'),
('MNO7890', 'Prata', 5, '56789012345'),
('PQR1122', 'Cinza', 6, '67890123456'),
('STU3344', 'Verde', 7, '78901234567'),
('VWX5566', 'Amarelo', 8, '89012345678');

-- Incluindo valores na tabela patio
INSERT INTO patio (numero, endereco, capacidade) VALUES
(1, 'Rua A, 123', 50),
(2, 'Avenida B, 456', 30),
(3, 'Praça C, 789', 20),
(4, 'Travessa D, 101', 40),
(5, 'Alameda E, 202', 25),
(6, 'Estrada F, 303', 60),
(7, 'Rodovia G, 404', 35),
(8, 'Via H, 505', 45);

-- Incluindo valores na tabela estaciona
INSERT INTO estaciona (codigo, numero_patio, veiculo_placa, data_entrada, data_saida, hora_entrada, hora_saida) VALUES
(1, 1, 'ABC1234', '2024-11-01', '2024-11-01', '08:00:00', '12:00:00'),
(2, 2, 'DEF5678', '2024-11-01', '2024-11-01', '09:30:00', '11:00:00'),
(3, 3, 'GHI9012', '2024-11-01', '2024-11-01', '07:45:00', '13:15:00'),
(4, 4, 'JKL3456', '2024-11-02', '2024-11-02', '10:00:00', '14:00:00'),
(5, 5, 'MNO7890', '2024-11-02', '2024-11-02', '11:00:00', '15:30:00'),
(6, 6, 'PQR1122', '2024-11-02', '2024-11-02', '12:30:00', '16:45:00'),
(7, 7, 'STU3344', '2024-11-03', '2024-11-03', '08:15:00', '11:45:00'),
(8, 8, 'VWX5566', '2024-11-03', '2024-11-03', '09:00:00', '12:30:00');
