#include <QCoreApplication>
#include <iostream>
#include <string>
#include "jugador.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Creamos objetos de la clase Jugador
    Jugador jugador1( 50, 20 , "Juan");
    Jugador jugador2( 5, 45 , "Pedro");
    Jugador jugador3( 15, 98 , "Santi");
    Jugador jugador4( 92, 20 , "Damian");
    Jugador jugador5( 22, 8 , "Jorge");
    Jugador jugador6( 31, 76 , "Pablo");
    Jugador jugador7( 55, 16 , "Julia");
    Jugador jugador8( 84, 27 , "Hernan");
    Jugador jugador9( 91, 71 , "Julian");
    Jugador jugador10( 72, 48 , "Ricardo");

    // Almacenar los objetos en un vector
    std::vector<Jugador> jugadores;
    jugadores.push_back(jugador1);
    jugadores.push_back(jugador2);
    jugadores.push_back(jugador3);
    jugadores.push_back(jugador4);
    jugadores.push_back(jugador5);
    jugadores.push_back(jugador6);
    jugadores.push_back(jugador7);
    jugadores.push_back(jugador8);
    jugadores.push_back(jugador9);
    jugadores.push_back(jugador10);

    // Mostrar la información de los jugadores
    std::cout << "Datos de los jugadores:" << std::endl << std::endl;
    for (const Jugador& jugador : jugadores) {
        std::cout << "Nombre: " <<  jugador.getNombre() << " - Velocidad: " << jugador.getVelocidad() << " - Fuerza: " << jugador.getFuerza() << std::endl;
    }

    return a.exec();
}
