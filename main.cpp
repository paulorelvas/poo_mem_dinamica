#include <iostream>

using namespace std;

class Poema {
    string titulo;
    string * pVersos; // ponteiro para um array dinamico de strings
    int nVersos ; // numero de elementos do array dinamico
public:
    Poema(const string & t): titulo(t), pVersos(nullptr), nVersos(0){
        cout <<  "A construir poema com o titulo: " << titulo << endl;
    }

    // construtor por cópia
    Poema(const Poema & obj):titulo(obj.titulo), nVersos(obj.nVersos){
        cout <<  "A construir poema por cópia com o titulo: " << titulo << endl;
        // titulo e nVersos são inicializado com os mesmos valores de obj
        // verifica se a origem da cópia é um poema sem versos
        if(obj.pVersos == nullptr || obj.nVersos == 0){
            pVersos = nullptr;
            return;
        }

        // reservar memória dinâmica para onde vai copiar os versos de obj
        pVersos = new string[obj.nVersos];
        for(int i = 0; i < obj.nVersos; ++i){
            pVersos[i] = obj.pVersos[i];
        }
    }
    ~Poema(){
        // destrutor
        cout <<  "A destruir poema com o titulo: " << titulo << endl;
        delete[] pVersos;
    }

    Poema & operator=(const Poema & obj){ // operador de atribuição
        cout <<  "Operador de atribuição overload para o poema com o titulo: " << titulo << endl;
        // teste de auto-atribuição - para evitar libertar obj quando o mesmo é a origem e o destino obj = obj
        if(this == &obj)
           return *this;
        // faz a atribuição quando os dois objetos são diferentes
        // faz a atribuição do obj ao primeiro membro
        titulo = obj.titulo;
        nVersos = obj.nVersos;

        // libertar a memória dinâmica exclusivamente pelo primeiro membro
        delete[] pVersos;
        pVersos = nullptr;

        // verifica se a origem da cópia é um poema sem versos
        if(obj.pVersos == nullptr || obj.nVersos == 0)
            return *this;

        // reservar memória dinâmica para criar uma cópia exclusiva dos versos do segundo membro
        pVersos = new string[obj.nVersos];
        // cópia os elementos
        for(int i = 0; i < obj.nVersos; ++i){
            pVersos[i] = obj.pVersos[i];
        }
        return *this;

    }
    void acrescentaVerso(const string & verso){
        // reserva espaço para mais um elemento
        string * aux = new string[nVersos + 1];
        // copia os elementos existentes
        for(int i = 0; i < nVersos; ++i){
            aux[i] = pVersos[i];
        }
        // coloca o novo elemento no final
        aux[nVersos] = verso;
        ++nVersos; // incrementa o número de elementos (versos)
        delete[] pVersos; // liberta o array dinâmico anterior

        //coloca pVersos apontar para o novo array dinâmico
        pVersos = aux;
    }
    void eliminaVerso (int ordem){
        if(ordem < 0 || ordem >= nVersos)
            return;
        if(nVersos == 1){ // quando apenas tem um elemento
            delete[] pVersos;
            pVersos = nullptr;
            nVersos = 0;
            return;
        }

        // reserva espaço ajustado a menos um elemento
        string * aux = new string[nVersos -1];

        // copia os elementos(versos) anteriores ao elemento (verso) a eliminar
        for(int i = 0; i < ordem; ++i){
            aux[i] = pVersos[i];
        }
        // copia os elementos(versos) posteriores ao elemento (verso) a eliminar
        for(int i = ordem; i < nVersos-1; ++i){
            aux[i] = pVersos[i+1];
        }

        // decrementa o número de elementos (nVersos)
        --nVersos;
        //liberta a memória ocupada pelo array dinâmico anterior
        delete[] pVersos;
        // coloca pVersos a apontar para o novo array dinâmico
        pVersos = aux;
    }

    string getAsString () const;
};


//int main() {
int main_() {
    cout << "--- memória dinâmica::composição---" << endl;

    Poema a {"Poema 1"};

    Poema b{"Poema 2"};

    Poema c = b; // construtor por cópia

    c=a;    // operador de atribuição

    return 0;
}
