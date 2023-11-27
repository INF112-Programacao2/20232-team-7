#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>
#include <vector>

#include "usuario_premium.hpp"
#include "musica.h"
#include "album.h"

class Artista : public Usuario_Premium {
    private:
        std::vector<Musica*> _musicas_publicadas;
        std::vector<Album*> _albuns_publicados;
    public:
        Artista(std::string email, std::string nome);
        ~Artista();

        void publicar_musica();
        void publicar_album();
};

#endif