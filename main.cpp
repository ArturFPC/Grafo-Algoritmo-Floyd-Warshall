#include <iostream>
#include <vector>
using namespace std;
const int INF =999;
void floydWarshall(vector<vector<int>> &mA, vector<vector<int>> &mP){
    for (unsigned int k = 0; k < mA.size(); k++){
        for (unsigned int i = 0; i < mA.size(); i++){
            for (unsigned int j = 0; j < mA.size(); j++){
                if (mA[i][j] > (mA[i][k] + mA[k][j])){
                    mA[i][j] = mA[i][k] + mA[k][j];
                    mP[i][j] = mP[k][j];
                }
            }
        }
    }
}
vector<vector<int>> preencherMPredecessor(vector<vector<int>> m){
    vector<vector<int>> aux;
    for (unsigned int i =0; i<m.size();i++){
        vector<int> vetAux;
        for (unsigned int i2 = 0; i2<m.size();i2++){
            if (m[i][i2]!= 999 && m[i][i2]!=0){
                vetAux.push_back(i);
            }else{
                vetAux.push_back(-1);
            }
        }
        aux.push_back(vetAux);
    }
    return aux;
}
void mostrarMatriz(vector<vector<int>> m){
    for (unsigned int i =0; i<m.size();i++){
        cout<<"{";
        for (unsigned int i2 = 0; i2<m.size();i2++){
            cout<<" "<<m[i][i2]<<" ";
        }
        cout<<"}"<<endl;
    }
}
int main()
{
    //matriz adjacencia inicial
    vector<vector<int>> mAdjacencia = {{0,3,8,INF,-4}, {INF,0,INF,1,7}, {INF,4,0,INF,INF},{2,INF,-5,0,INF},{INF,INF,INF,6,0}};
    //matriz predecessora inicial
    vector<vector<int>> mPredecessor;
    mPredecessor = preencherMPredecessor(mAdjacencia);
    floydWarshall(mAdjacencia,mPredecessor);
    cout<<"Matriz Adjacencia final: "<<endl;
    mostrarMatriz(mAdjacencia);
    cout<<"Matriz Predecessor final: "<<endl;
    mostrarMatriz(mPredecessor);
    return 0;
}
