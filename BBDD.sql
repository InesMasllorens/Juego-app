DROP DATABASE IF EXISTS Campeonato;
CREATE DATABASE Campeonato;
USE Campeonato;
CREATE TABLE Jugadores (
  Id INTEGER PRIMARY KEY NOT NULL,
  Nombre VARCHAR(50) NOT NULL,
  Usuario VARCHAR(50) NOT NULL,
  Contraseña VARCHAR(50) NOT NULL
 
)ENGINE = InnoDB;

CREATE TABLE Partidas (
 Id INTEGER PRIMARY KEY NOT NULL,
 IdGanador INTEGER NOT NULL,
 Fecha DATE NOT NULL
)ENGINE = InnoDB;


INSERT INTO Jugadores VALUES(1,'Juan', 'Juan01', 'Juanito');
INSERT INTO Jugadores VALUES(2,'Maria', 'Maria01', 'Maria123');
INSERT INTO Jugadores VALUES(3,'Pedro', 'Pedro01', 'Pedro123');
INSERT INTO Jugadores VALUES(4,'Luis', 'Luis01', 'Luismi');
INSERT INTO Jugadores VALUES(5,'Julia', 'Julia01', 'Julia123');

INSERT INTO Partidas VALUES(1,1,'2022-01-14');
INSERT INTO Partidas VALUES(2,2,'2021-12-12');
INSERT INTO Partidas VALUES(3,1,'2021-12-06');
INSERT INTO Partidas VALUES(4,1,'2022-02-07');
INSERT INTO Partidas VALUES(5,3,'2022-03-09');
INSERT INTO Partidas VALUES(6,3,'2022-03-09');
INSERT INTO Partidas VALUES(7,4,'2022-02-19');
INSERT INTO Partidas VALUES(8,1,'2022-01-25');

SELECT Jugadores.id, Jugadores.Nombre, COUNT(*) partidas_ganadas
FROM Jugadores, Partidas
WHERE Jugadores.id = Partidas.idGanador
GROUP BY idGanador
ORDER BY partidas_ganadas DESC
LIMIT 1;




