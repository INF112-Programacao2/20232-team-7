#ifndef CONTROLE_HPP_
#define CONTROLE_HPP_
#include "usuario.hpp"

class Controle{
    public:
        Controle();
        void comptify(Artista *artista);
        void comptify(Usuario_Premium *premium);
        void comptify(Usuario *usuario);
};

#endif