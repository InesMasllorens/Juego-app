//Incluir esta libreriￂﾭa para poder hacer las llamadas en shiva2.upc.es
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexi￳n: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexin
	conn = mysql_real_connect (conn, "localhost","root", "mysql", NULL,0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	
	mysql_query (conn, "DROP DATABASE IF EXISTS Campeonato;");
	mysql_query (conn, "CREATE DATABASE Campeonato;");
	mysql_query (conn, "USE Campeonato;");
	
	mysql_query (conn, "CREATE TABLE Jugadores ( Id INTEGER PRIMARY KEY NOT NULL, Nombre VARCHAR(50) NOT NULL, Usuario VARCHAR(50) NOT NULL, Contrasena VARCHAR(50) NOT NULL )ENGINE = InnoDB;");
	mysql_query (conn, "CREATE TABLE Partidas ( Id INTEGER PRIMARY KEY NOT NULL, IdGanador INTEGER NOT NULL, Fecha DATE NOT NULL )ENGINE = InnoDB;");
	
	mysql_query (conn, "INSERT INTO Jugadores VALUES(1,'Juan', 'Juan01', 'Juanito');");
	mysql_query (conn, "INSERT INTO Jugadores VALUES(2,'Maria', 'Maria01', 'Maria123');");
	mysql_query (conn, "INSERT INTO Jugadores VALUES(3,'Pedro', 'Pedro01', 'Pedro123');");
	mysql_query (conn, "INSERT INTO Jugadores VALUES(4,'Luis', 'Luis01', 'Luismi');");
	mysql_query (conn, "INSERT INTO Jugadores VALUES(5,'Julia', 'Julia01', 'Julia123');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(1,1,'2022-01-14');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(2,2,'2021-12-12');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(3,1,'2021-12-06');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(4,1,'2022-02-07');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(5,3,'2022-03-09');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(6,3,'2022-03-09');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(7,4,'2022-02-19');");
	mysql_query (conn, "INSERT INTO Partidas VALUES(8,1,'2022-01-25');");
	/*if (err!=0) {
	printf ("Error al consultar datos de la base %u %s\n",
	mysql_errno(conn), mysql_error(conn));
	exit (1);
	}*/
	
	
	
	/*char nombre[50];
	// Pregunto los nombre de los dos jugadores
	printf ("Dame el nombre de una ciudad\n"); 
	scanf ("%s", nombre);*/
	
	char consulta [300];
	strcpy (consulta,"SELECT Jugadores.id, Jugadores.Nombre, COUNT(*) partidas_ganadas FROM Jugadores, Partidas WHERE Jugadores.id = Partidas.idGanador GROUP BY idGanador ORDER BY partidas_ganadas DESC LIMIT 1;");
	
	//strcat (consulta,"'AND Partidas.id = Jugadores.id");
	
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de una persona.
	
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW
	row = mysql_fetch_row (resultado);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			// la columna 0 contiene el nombre del jugador
			printf ("El jugador %s con id %s ha ganado %s partidas\n", row[1], row[0], row[2]);
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
	}
		
		mysql_close (conn);
		exit(0);
}


