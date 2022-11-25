#include <iostream>

using namespace std;

class Ponto{
    int x; // abcissa
    int y; // ordenada
public:
    Ponto( int x0 = -1, int y0 = -1):x(x0), y(y0){
        cout << "Construindo: (" << x << ", " << y << ")" << endl;
    }
    ~Ponto(){
        cout << "Destruindo: (" << x << ", " << y << ")" << endl;
    }

    void imprime() const{
        cout << "X = " << x << "; Y = " << y << endl;
    }

};



int memdinamica() {
//int main() {
    cout << "--- memória dinâmica::arrays de objetos---" << endl;

    Ponto *p = new Ponto{5, 7};
    p->imprime();
    delete p;


    // p->imprime(); // posso fazer isto??

    //Ponto *p1_ = new Ponto[3](); // inicializa com valor 0
    Ponto *p1 = new Ponto[3];
    Ponto *p2 = new Ponto[3] {Ponto{1,3}, Ponto{4, 8}};
    Ponto *p3 = new Ponto[3] {{2, 4}, {5, 6}};

    for(int i=0; i<3; ++i)
        p3[i].imprime();

    delete[] p1;
    delete[] p3;
    delete[] p2;

    return 0;
}

