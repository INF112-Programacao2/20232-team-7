#ifndef ARTISTA_HPP
#define ARTISTA_HPP

#include <string>
#include <vector>

#include "usuario_premium.hpp"
#include "musica.hpp"
#include "playlist.hpp"
#include "album.hpp"

class Artista : public Usuario_Premium {
    private:
        std::vector<Musica*> _musicas_publicadas;
        std::vector<Album*> _albuns_publicados;
    public:
        Artista(std::string email, std::string nome);
        ~Artista();

        void publicar_musica();
        void publicar_album();
        void adicionar_musica_album();
};

#endif