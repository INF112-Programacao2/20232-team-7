#ifndef ARTISTA_HPP_
#define ARTISTA_HPP_

#include <string>
#include <vector>

#include "usuario_premium.hpp"
#include "musica.hpp"
#include "playlist.hpp"
#include "album.hpp"

//A classe artista recebe herança de usuário premium
class Artista : public Usuario_Premium {
    private:
        //DADOS
        static std::vector<Artista*> artistas_cadastrados;
        std::vector<Musica*> _musicas_publicadas;
        std::vector<Album*> _albuns_publicados;

    public:
        //CONSTRUTOR E DESTRUTOR
        Artista(std::string email, std::string nome);
        ~Artista();
        
        //GETTERS
        int get_quant_musicas_publicadas();
        Musica* get_musica_publicada(int posicao);
        int get_quant_albuns_publicados();
        Album* get_album_publicado(int posicao);

        //MÉTODOS
        void publicar_musica(std::string titulo, int duracao_segundos, bool explicito, std::string genero, Artista* artista, std::string caminho);
        void publicar_album(std::string titulo, std::string genero);
        static Artista* encontrar_artista(std::string nome);
};

#endif