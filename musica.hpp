#ifndef MUSICA_HPP_
#define MUSICA_HPP_

#include <string>
#include <vector>

class Artista;

class Musica{
    private:
        static std::vector<Musica*> musicas_cadastradas;
        std::string _titulo;
        Artista* _artista;
        int _segundos;
        bool _explicito;
        std::string _generos;
    public:
        Musica(std::string titulo, int segundos, bool explicito, std::string generos, Artista* artista);

        void set_titulo(std::string titulo);

        std::string get_titulo();

        int get_segundos();

        Artista* get_artista();

        bool get_explicito();

        static Musica* encontrar_musica(std::string nome);

        static void get_musicas_cadastradas();

        static Musica* get_musica_cadastrada(int indice);
};

#endif