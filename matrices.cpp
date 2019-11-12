#include <iostream>
#include <string>

using namespace std;

//Hace una matriz de tipo T con valores que se ingresan en la consola.
template <class T>
T** matriz(T** m, int filas, int columnas) {
    m = new T*[filas];
    for(int i = 0; i < filas; i++){
        m[i] = new T[columnas];
        for(int j = 0; j<columnas; j++){
            float valor;
            cout << "Ingrese el numero de la posicion "<< i+1 << "," << j+1 << endl;
            cin >> valor;
            m[i][j]=valor;
        }
    }
    return m;   
}

//Hace la matriz de tipo T, del tamaño filas1 y columnas 2. 
template <class T>
T** matrizResultado(T** resultado, int filas, int columnas) {
    resultado = new T*[filas];
    for(int i = 0; i < filas; i++){
        resultado[i] = new T[columnas];
    }
    return resultado;
}

//Multiplica cualquieras dos matrices de tipo T que cumplan que las columnas de m1 y las filas de m2 son iguales.
template <class T>
void multi(T** m1, T** m2, T** multip, int filas1, int iguales, int columnas2){

    for(int i =0; i<filas1; i++){
        for(int j=0; j<columnas2;j++){
            T suma=0;
            for(int k=0; k<iguales; k++){
                suma += m1[i][k]*m2[k][j];
            }
            multip[i][j]=suma;
            cout<< suma << "\t";
        }
        cout<<endl;
    }
}

//Funcion que hace la matriz de cauchy 
float** fcauchy(float**, int);

int main() {
    float** m1;
    float** m2;
    float** multiplicacion;

    // En el caso que se quisiera agregar las filas y columnas por parametro. 
    // if(argc != 5) {
    //     cout << "Numero de argumentos incorrecto" << endl;
    //     return 1;
    // }
    // Transforma los numeros de los argumentos en ints
    // int filas1 = stoi(argv[1]);
    // int columnas1 = stoi(argv[2]);
    // int filas2 = stoi(argv[3]);
    // int columnas2 = stoi(argv[4]);

    int filas1;
    int columnas1;
    int filas2;
    int columnas2;

    int cauchy;

    cout << "Ingrese 1 para matrices Cauchy o 0 para ingresar los valores de la matriz dependiendo de la multiplicacion que desee hacer:"<<endl;
    cin >> cauchy;

    if (cauchy==1)
    {
        cout << endl << "Ingrese el valor n de las filas y columnas de la matriz"<<endl;
        cin >> filas1;
        columnas1 = filas1;
        filas2 = filas1;
        columnas2 = filas1;

        m1 = fcauchy(m1, filas1);
        m2 = m1;
    }
    else if (cauchy == 0){
        int cuantas =0;
        do
        {
            if(cuantas>0) cout << "No ingreso los valores correctos. Ingreselos nuevamente" << endl;
            cout << "****** MATRIZ 1 ******" << endl;
            cout << "Ingrese el numero de filas" << endl;
            cin >> filas1;
            cout << "Ingrese el numero de columnas" << endl;
            cin >> columnas1;

            cout << "****** MATRIZ 2 ******" << endl;
            cout << "Ingrese el numero de filas" << endl;
            cin >> filas2;
            cout << "Ingrese el numero de columnas" << endl;
            cin >> columnas2;
            cuantas ++;
        } while (columnas1 != filas2 || filas1 < 1 || columnas1 < 1 || filas2 < 1 || columnas2 < 1);
       
        // Inicializa cada una de las matrices y reasigna la referencia aqui
        cout << "****** MATRIZ 1 ******" << endl;
        m1 = matriz(m1, filas1, columnas1);
        cout << "****** MATRIZ 2 ******" << endl;
        m2 = matriz(m2, filas2, columnas2);
        
    }

    else{
        cout << "No ingreso un valor disponible"<< endl;
        return 1;
    }
    

    cout << endl << "El resultado de la multiplicacion es la siguiente: " << endl;
    multiplicacion = matrizResultado(multiplicacion, filas1, columnas2);

    // Realizo las operaciones con las matrices
    multi(m1, m2, multiplicacion, filas1, columnas1, columnas2);
    
    if(cauchy == 1){
        int valor;
        cout << endl << "¿Desea probar que la matriz es nilpotent? Ingrese 1 para si, 0 para no." << endl;
        cin >> valor;
        if(valor == 1){
            int expo = 3;
            while(multiplicacion[0][0]!=0){
                float** mul;
                mul = matrizResultado(mul, filas1, columnas2);
                cout << endl << "Multiplicando nuevamente por la inicial ..." << endl;
                cout << "Matriz resultante (N^"<<expo << ")"<< endl;
                multi(multiplicacion, m1, mul, filas1, columnas1, columnas2);
                multiplicacion = mul;
                expo ++;
            }
            cout <<endl<< "Como la matriz esta llena con solo 0s despues de la(s) multiplicacion(es), se demuestra que es una nilpotent." << endl;
        }
    }

    delete *multiplicacion;
    delete multiplicacion;
    delete *m1;
    delete m1;
    if(cauchy != 1){
    delete *m2;
    delete m2;}

    return 0;
}

float** fcauchy(float** m, int n){
    cout << endl << "La matriz incial es:" << endl;
    m = new float*[n];
    for(int i = 0; i < n; i++){
        m[i] = new float[n];
        for(int j = 0; j<n; j++){
            float valor;
            if(i==0) {
                valor = 2;
                if(j==n-1) valor = 1-n;
            }
            else if(j==n-1) valor = -n;
            else if(i-1 == j) valor = n+2;
            else valor = 1;
            m[i][j]=valor;
            cout << valor << "\t";
        }
        cout << endl;
    }
    return m;
}

