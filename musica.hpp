#ifndef MUSICA_HPP_
#define MUSICA_HPP_

#include <string>
#include <vector>

class Musica{
    private:
        static std::vector<Musica*> musicas_cadastradas;
        std::string _titulo;
        int _segundos;
        bool _explicito;
        std::string _generos;
    public:
        Musica(std::string titulo, int segundos, bool explicito, std::string generos);

        void set_titulo(std::string titulo);

        std::string get_titulo();

        int get_segundos();

        bool get_explicito();

        static Musica* encontrar_musica(std::string nome);
};

#endif