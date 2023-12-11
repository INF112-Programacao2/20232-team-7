#ifndef ARTISTA_HPP_
#define ARTISTA_HPP_

#include <string>
#include <vector>

#include "usuario_premium.hpp"
#include "musica.hpp"
#include "playlist.hpp"
#include "album.hpp"

class Artista : public Usuario_Premium {
    private:
        static std::vector<Artista*> artistas_cadastrados;
        std::vector<Musica*> _musicas_publicadas;
        std::vector<Album*> _albuns_publicados;
    public:
        Artista(std::string email, std::string nome);
        ~Artista();
        
        int get_quant_musicas_publicadas();
        Musica* get_musica_publicada(int posicao);
        int get_quant_albuns_publicados();
        Album* get_album_publicado(int posicao);

        void publicar_musica(Artista* artista);
        void publicar_album(Artista* artista);
        void adicionar_musica_album();
        static Artista* encontrar_artista(std::string nome);
};

#endif