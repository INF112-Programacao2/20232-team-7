#include <string>
#include <vector>
#include "musica.hpp"

class Album{
    private:
        std::string _titulo;
        std::vector<Musica*>_musicas;
        // imagem do álbum
        int _duracao;
        std::string _generos;
    public:
        Album(std::string titulo, std::string _generos);

        void set_musica(Musica* musica);

        Musica* get_musica(int posicao);

        std::string get_titulo();

        int get_quantidade();

        // get_imagem

        int get_duracao();

        std::string get_generos();
};