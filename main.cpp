#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.hpp"

using std::string, std::vector, std::find, std::cout, std::endl, std::cin;

class marca{    
    string brand;
public:
    marca(const string& b) : brand(b){}

    void set_brand(const string& b){
        brand = b;
    }

    string get_brand() const{
        return brand;
    }

    ~marca(){}
};

class roupa{
    string tipo, tamanho;
    vector<marca*> marcas; // o vetor das marcas
public:
    roupa(const string& tp, const string& tam, marca* b)
    : tipo(tp), tamanho(tam){}

    virtual void set_tipo(const string& tp){
        tipo = tp;
    }
    virtual string get_tipo() const{
        return tipo;
    }

    virtual void get_tamanho(const string& tam){
        tamanho = tam;
    }
    virtual string get_tamanho(){
        return tamanho;
    }
    
    void add_marca(marca* b){ // as funções para adicionar e remover vetores para serem usados nos overrides logo abaixo.
        marcas.push_back(b);
    }

    void remove_marca(marca* b){
        auto it = find(marcas.begin(), marcas.end(), b);
        if (it != marcas.end())
            marcas.erase(it);
    }

    const vector<marca*>& get_marcas() const { // uma função para retornar os vetores
        return marcas;
    }
    
    roupa& operator+(marca* b){ // e os overrides
        add_marca(b);
        return *this;
    }

    roupa& operator-(marca* b){
        remove_marca(b);
        return *this;
    }

    ~roupa(){}
};

class roupa_adulto : public roupa{
    string tecido;
public:
    roupa_adulto(const string& tp, const string& tam, marca* b, const string tc)
    : roupa(tp, tam, b), tecido(tc){}

    void set_tecido(const string& tc){
        tecido = tc;
    }
    string get_tecido(){
        return tecido;
    }
};

class roupa_kids : public roupa{
    string faixa_etaria;
public:
    roupa_kids(const string& tp, const string& tam, marca* b, const string& fe)
    : roupa(tp, tam, b), faixa_etaria(fe){}

    void set_faixa_etaria(const string& fe){
        faixa_etaria = fe;
    }

    string get_faixa_etaria(){
        return faixa_etaria;
    }
};

class loja{
    vector<roupa*> roupas;
public:
    void add_roupa(roupa* r){
       roupas.push_back(r);
    }

    void remove_roupa(roupa* r){
        auto it = find(roupas.begin(), roupas.end(), r);
        if (it != roupas.end())
            roupas.erase(it);
            delete r;
    }

    const vector<roupa*>& get_roupas() const {
        return roupas;
    }

    void print_vector(const vector<roupa*>& roupas){ // o print ficou meio ruim, não deu tempo de colocar uma numeração para listar bonitinho as roupas.
        for (const auto& r : roupas){
            cout << "Tipo: " << r->get_tipo() << ", Tamanho: " << r->get_tamanho(); // um problema que não consegui resolver, o programa não printa as marcas aqui,
            cout << ", Marca: ";                                                    // tentei várias formas diferentes e não saiu de forma alguma.
            const vector<marca*>& marcas = r->get_marcas();
            for (const auto& m : marcas) {
                cout << m->get_brand() << " ";
            }
            cout << endl << endl; 
        }
               
    }
};

int main(void){

    loja loja1;
    cout << "Bem vindo ao Sistema da Loja de Roupas POO." << endl;
    cout << "Felizmente como o mundo é belo, não temos preços por aqui.\nTudo é de graça!!\n" << endl;
    cout << "Você pode adicionar roupas no catálogo, podemos dividir entre modelos para adultos e para crianças." << endl;
    
    cout << "\t\tSe você quiser adicionar roupas, digite 1" << endl;
    cout << "\t\tSe quiser remover alguma roupa, digite 2" << endl;
    cout << "\t\tSe quiser encerrar o programa, digite -1" << endl;

    int op, tp, tam, tc, fe, rm; // opções, tipo, tamanho, tecido, faixa etária e remover.
    string marca_input;

    cin >> op;
    while(op > 0){
        
        if (op == 1){
            cout << "Okay, você deseja adicionar roupas.\n";
            cout << "Mas vai ser roupas para criança ou para adultos?\n";
            cout << "Para adultos digite 1, para crianças digite 2." << endl;

            cin >> op;
            if (op == 1){

                cout << "Roupa para adultos então...\n";
                cout << "Qual tipo de roupa você vai adicionar?" << endl;
                cout << "Digite 1 para camisas, 2 para camisetas, 3 para calças, 4 para bermudas e 5 para um macacão industrial\n";
                cin >> tp;

                cout << "Agora o tamanho.\n";
                cout << "Digite 1 para PP, 2 para P, 3 para M, 4 para G e 5 para GG\n";
                cin >> tam;

                cout << "Agora para finalizar, o tipo do tecido dessa roupa.\n";
                cout << "1 para Algodão, 2 para Seda, 3 para Poliester e 4 para Nylon\n";
                cin >> tc;

                cout << "E qual a marca dessa sua roupa?" << endl;
                cin.ignore();
                std::getline(cin, marca_input);
                marca *new_brand = new marca(marca_input); // criando a marca para ser adicionada à roupa.
                roupa_adulto* new_adulto = new roupa_adulto(tipo(tp), tamanho(tam), new_brand, tecido(tc));
                loja1.add_roupa(new_adulto);
            }else{
                cout << "Roupa para crianças!\n";
                cout << "Qual tipo de roupa você vai adicionar?" << endl;
                cout << "Digite 1 para camisas, 2 para camisetas, 3 para calças, 4 para bermudas e 5 para um macacão industrial\n";
                cin >> tp;

                cout << "Agora o tamanho.\n";
                cout << "Digite 1 para PP, 2 para P, 3 para M, 4 para G e 5 para GG\n";
                cin >> tam;

                cout << "Qual faixa etária essa roupa se adequa?" << endl;
                cout << "Digite 1 para 0-2 anos, 2 para 3-5 anos, 3 para 6-9 anos e 4 para 10-12 anos" << endl;
                cin >> fe;

                cout << "E qual a marca dessa sua roupa?" << endl;
                cin.ignore();
                std::getline(cin, marca_input);
                marca *new_brand = new marca(marca_input);
                roupa_kids* new_kid = new roupa_kids(tipo(tp), tamanho(tam), new_brand, faixa_etaria(fe));
                
            }
        }
        else if (op == 2){
            cout << "Então vamos remover alguma roupa." << endl;
            cout << "\t\tAqui está a lista de roupas que temos no sistema: " << endl;
            loja1.print_vector(loja1.get_roupas());
            cout << "\n\n\tQual você gostaria de remover?" << endl;
            cout << "Digite a numeração de cima para baixo começando do 0" << endl;
            cin >> rm;
            loja1.remove_roupa(loja1.get_roupas()[rm]);

            }
        
        cout << "Deseja adicionar ou remover mais alguma roupa?" << endl;
        cout << "Se sim, digite 1 ou 2, caso queira encerrar o programa, digite -1" << endl;
        cin >> op;
    }   

    return 0;
}