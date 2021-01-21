#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <math.h>
#include <utility>
#include <chrono>
#include <iomanip>
using namespace std;

void calc_distancia_euclidiana(vector<vector<double>> n_dim){
    for(int i=0;i<n_dim.size();i++){
        for(int j=i+1;j<n_dim.size();j++){
            double dist=0;
            for(int h=0;h<n_dim[i].size();h++){
                dist += pow(n_dim[i][h]-n_dim[j][h],2);
            }
            dist = sqrt(dist);
        }
    }
}
int main(){
    vector<vector<double>> dimensiones;
    const int kSize = 20;
    int num_vectores = 25000;
    for(int i=0;i<num_vectores;i++){
        std::vector<double> array(kSize);
        generate(array.begin(), array.end(),rand);  // generamos 10 numeros aleatorios
        sort(array.begin(), array.end(), std::greater<double>());  // de mayor a menor
        //copy(array.begin(), array.end(), std::ostream_iterator<double>(std::cout, "\n"));
        dimensiones.push_back(array);
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    calc_distancia_euclidiana(dimensiones);
    end = std::chrono::high_resolution_clock::now();
    int64_t duration =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout <<endl<< std::setw(10) << duration << std::setw(30)<<endl;
    return 0;
}