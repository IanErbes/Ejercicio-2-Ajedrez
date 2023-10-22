#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

// Variables
Texture texture_cn;
Texture texture_cb;
Sprite sprite_cn;
Sprite sprite_cb;

// Punto de entrada a la aplicación ///
int main() {
    // Cargamos las texturas de los archivos
    texture_cn.loadFromFile("chessb.png");
    texture_cb.loadFromFile("chessw.png");

    // Cargamos el material de los sprites
    sprite_cb.setTexture(texture_cb);
    sprite_cn.setTexture(texture_cn);

    // Tamaño de cada casilla en el tablero
    const int tileSize = 100;

    // Creamos la ventana
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ejercicio 2 ajedrez");

    // Loop principal
    while (App.isOpen()) {
        // Limpiamos la ventana
        App.clear();

        // Dibujamos la escena (el tablero de ajedrez)
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                // Calculamos la posición de la casilla
                float x = i * tileSize;
                float y = j * tileSize;

                // Dibujamos la casilla en blanco o negra según la posición
                if ((i + j) % 2 == 0) {
                    sprite_cn.setPosition(x, y);
                    App.draw(sprite_cn);
                }
                else {
                    sprite_cb.setPosition(x, y);
                    App.draw(sprite_cb);
                }
            }
        }

        // Mostramos la ventana
        App.display();
    }

    return 0;
}
