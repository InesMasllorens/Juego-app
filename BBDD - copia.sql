DROP DATABASE IF EXISTS Campeonato;
WHERE Jugadores.Id = Participacion.IdJ AND Participacion.Posicion = 1 
GROUP BY Jugadores.Id