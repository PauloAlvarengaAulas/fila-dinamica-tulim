/* URI Online Judge | 1069 */
#include <iostream>
using namespace std;
template <class T> class Fila {
  protected:  
    template <class TT> class Celula {
      public:
        Celula<TT> *prox;
        TT valor;
        Celula(TT v) {
          this->valor = v;
          prox = nullptr;
        }
    };
    int tamanho;
    Celula<T> *primeiro;
    Celula<T> *ultimo;
  public:
    Fila() {
      ultimo = primeiro = nullptr;
      tamanho = 0;
    }
    ~Fila() {
      Celula<T> *Mina_Sem_Areia;
      while(primeiro!=nullptr) {
        Mina_Sem_Areia=primeiro;
        primeiro = primeiro->prox;
        delete Mina_Sem_Areia;
      }
    }
    int getTamanho() {
    return tamanho;
    }
    bool inserir(const T &valor) {
      if(this->primeiro == nullptr) {
        this->ultimo = this->primeiro = new Celula<T>(valor);
      } else {
        this->ultimo->prox = new Celula<T>(valor);
        this->ultimo = this->ultimo->prox;
      }
      ++tamanho;
      return true;
    }
    bool excluir(void) {
      if(this->primeiro==nullptr) {
        return false;
      } else {
        Celula<T> *Mina_Sem_Areia;
        Mina_Sem_Areia = primeiro;
        this->primeiro = this->primeiro->prox;
        delete Mina_Sem_Areia;
        --tamanho;
      }
      return true;
    }
    void mostrar() {
      if(this->primeiro== nullptr) {
        cout << "<<nada>>";
      } else {
        cout << this->primeiro->valor;
      }
        cout << endl;
    }
    char Retorna_Primeiro()
    {
      if(this->primeiro== nullptr)
      {
        return '0';
      } else
      {
        return this->primeiro->valor;
      }     
    }
};

int main()
{
    int n, Comeco_Diamante = 0, Fim_Diamante = 0, Diamante;

    Fila<char> Mina;
    Fila<char> Mina_Sem_Areia;
    char aux[1001];
    cin>>n;
    do
    {
        cin.getline(aux, 1001);
        for(int i = 0; aux[i]; i++)
        {
            Mina.inserir(aux[i]);
        }
        for(int i = Mina.getTamanho(); i >= 1; i--)
        {
            switch (Mina.Retorna_Primeiro())
            {
            case '>':
                Mina_Sem_Areia.inserir(Mina.Retorna_Primeiro());
                Mina.excluir();
                break;
            case '<':
                Mina_Sem_Areia.inserir(Mina.Retorna_Primeiro());
                Mina.excluir();
            default:
                Mina.excluir();
                break;
            }
        }
        for(int i = Mina_Sem_Areia.getTamanho(); i >= 1; i--)
        {
            switch (Mina_Sem_Areia.Retorna_Primeiro())
            {
            case '<':
                Comeco_Diamante++;
                Mina_Sem_Areia.excluir();
                break;
            case '>':
                if(Comeco_Diamante > 0)
                {
                    Fim_Diamante ++;
                    Comeco_Diamante--;
                    Mina_Sem_Areia.excluir();
                }
            default:
                break;
            }
            Diamante = Fim_Diamante;
        }
        cout<<Diamante<<endl;
        Comeco_Diamante = Fim_Diamante = 0;
        n--;
    }while(n+1 > 0);
  return 0;
}