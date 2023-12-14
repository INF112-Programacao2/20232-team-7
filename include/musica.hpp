#ifndef MUSICA_HPP_
#define MUSICA_HPP_

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Artista;

class Musica{
    private:
        //DADOS
        static std::vector<Musica*> musicas_cadastradas; //COMPOSIÇÃO
        std::string _titulo;
        Artista* _artista;
        int _segundos;
        bool _explicito;
        std::string _generos;
        std::string _caminho;
    public:
        //CONSTRUTOR
        Musica(std::string titulo, int segundos, bool explicito, std::string generos, Artista* artista, std::string caminho);

        //SETTER
        void set_titulo(std::string titulo);

        //GETTERS
        std::string get_titulo();
        int get_segundos();
        Artista* get_artista();
        bool get_explicito();
        std::string get_caminho();
        static void get_musicas_cadastradas();
        static Musica* get_musica_cadastrada(int indice);

        //MÉTODOS
        static Musica* encontrar_musica(std::string nome);
        void tocar_musica();

};

#endif