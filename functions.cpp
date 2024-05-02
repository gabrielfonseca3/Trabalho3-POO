#include <iostream>
#include "functions.hpp"

std::string tecido(int x){
    switch(x){
        case 1:
            return "Algodao";
        case 2:
            return "Seda";
        case 3:
            return "Poliester";
        case 4:
            return "Nylon";
        default:
            return "Material não existente";
    }
}

std::string tamanho(int x){
    switch(x){
        case 1:
            return "PP";
        case 2:
            return "P";
        case 3:
            return "M";
        case 4:
            return "G";
        case 5:
            return "GG";
        default:
            return "Tamanho não existente";
    }
}

std::string tipo(int x){
    switch(x){
        case 1:
            return "Camisa";
        case 2:
            return "Camiseta";
        case 3:
            return "Calça";
        case 4:
            return "Bermuda";
        case 5:
            return "Macacão Industrial";
        default:
            return "Tipo não existente";
    }
}

std::string faixa_etaria(int x){
    switch(x){
        case 1:
            return "0-2 anos";
        case 2:
            return "3-5 anos";
        case 3:
            return "6-9 anos";
        case 4:
            return "10-12 anos";
        default:
            return "Fora do range";
    }
}
