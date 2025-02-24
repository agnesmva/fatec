create schema atividade;
use atividade;
 
create table setor(
	id int not null auto_increment primary key,
	nome varchar(30) not null,
    sala varchar(30) not null,
    bloco varchar(30) not null
     
);
create table funcionario(
	id int not null auto_increment primary key,
    nome varchar(30) not null,
    cpf varchar(30) not null,
    data_nasc varchar(30) not null,
    cidade varchar(30) not null,
    estado varchar(30) not null,
    logradouro varchar(30) not null,
    foreign key (id_setor) references setor (id)
);

insert into setor (nome, sala, bloco) values 
('Centro de Filosofia e Ciência Humanas', '004', 'Bloco - 1'),
('Centro de Artes e Comunicação', '876', 'Bloco - 9'),
('Centro de Ciências Biológicas', '45', 'Bloco - 10'),
('Centro de Educação', '789', 'Bloco - 1'),
('Centro de Ciências da Saúde', '566', 'Bloco - 69'),
('Centro de Informática', '666', 'Bloco - 0101');


insert into funcionario(nome, cpf, data_nasc, cidade, estado, logradouro, id_setor) values
('Karl Marx', '12345678901', '1818-05-05', 'Trier', 'Alemanha', 'Brückenstraße, 10', 1),
('Max Weber', '12345678902', '1864-04-21', 'Erfurt', 'Alemanha', 'Michaelisstraße, 36', 1),
('Durkheim', '12345678903', '1858-04-15', 'Épinal', 'França', 'Rue du Petit-Pot-de-Terre, 3', 1),
('Sigmund Freud', '12345678904', '1856-05-06', 'Freiberg', 'Áustria', 'Schlossergasse, 117', 5),
('Charles Darwin', '12345678905', '1809-02-12', 'The Mount', 'Reino Unido', 'Shrewsbury, Inglaterra', 3),
('Gregor Mendel', '12345678906', '1822-07-20', 'Hynčice', 'Áustria', 'Mendel Square, 1', 3),
('Alan Turing', '12345678907', '1912-06-23', 'Paddington', 'Reino Unido', 'Maida Vale, Londres', 6),
('Ada Lovelace', '12345678908', '1815-12-10', 'Londres', 'Reino Unido', 'Piccadilly Terrace, Londres', 6),
('Oscar Niemeyer', '12345678909', '1907-12-15', 'Rio de Janeiro', 'Brasil', 'Ladeira de Nossa Senhora, 98', 2),
('Dennis Ritchie', '12345678911', '1941-09-09', 'Bronxville', 'Nova Iorque', 'White Plains, Nova Iorque', 6),
('Linus Torvalds', '12345678912', '1969-12-28', 'Helsínquia', 'Uusimaa', 'Helsínquia, Finlândia', 6);



