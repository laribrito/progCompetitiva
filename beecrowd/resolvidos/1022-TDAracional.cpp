    #include <bits/stdc++.h>
    using namespace std;

    class Racional{
        private:
            long int numerador;
            long int denominador;

            long int mdc(long int a, long int b){
                if (a%b==0) return b;
                else mdc(b, a%b);
            }
        public:
            Racional(long int a, long int b): numerador(a), denominador(b) {}
            Racional(): numerador(1), denominador(1) {}

            Racional soma(Racional outro){
                long int novoNumerador = this->numerador*outro.denominador + outro.numerador * this->denominador;
                long int novoDenominador = this->denominador * outro.denominador;
                return Racional(novoNumerador, novoDenominador);
            }
            Racional subtracao(Racional outro){
                long int novoNumerador = this->numerador*outro.denominador - outro.numerador * this->denominador;
                long int novoDenominador = this->denominador * outro.denominador;
                return Racional(novoNumerador, novoDenominador);
            }
            Racional multiplicacao(Racional outro){
                long int novoNumerador = this->numerador*outro.numerador;
                long int novoDenominador = this->denominador * outro.denominador;
                return Racional(novoNumerador, novoDenominador);
            }
            Racional divisao(Racional outro){
                long int novoNumerador = this->numerador*outro.denominador;
                long int novoDenominador = this->denominador * outro.numerador;
                return Racional(novoNumerador, novoDenominador);
            }
            void simplificar(){
                long int m = mdc(this->numerador, this->denominador);
                m = abs(m);
                this->numerador /=m;
                this->denominador /=m;
            }
            void print(){
                cout<<this->numerador << "/" << this->denominador;
            }
    };

    int main(void){
        int N;
        long int numerador1, denominador1, numerador2, denominador2;
        char op;
        cin >> N;
        while (N--){
            scanf("\n%ld / %ld %c %ld / %ld", &numerador1, &denominador1, &op, &numerador2, &denominador2);
            Racional r1(numerador1, denominador1), r2(numerador2, denominador2), res;
            if(op=='+') res = r1.soma(r2);
            else if(op=='-') res = r1.subtracao(r2);
            else if(op=='/') res = r1.divisao(r2);
            else res = r1.multiplicacao(r2);

            res.print();
            cout << " = ";
            res.simplificar();
            res.print();
            cout << endl;
        }
        
    }