/*
    Exercício 4 - Semana 12 -> (MENOR NÚMERO DE PARADAS EM VIAGEM) Suponha que você esteja dirigindo de São
    Paulo para Curitiba e que, com o tanque cheio, seu carro consegue andar m quilômetros.
    Suponha também que você sabe que existem n postos de combustível na estrada e que a
    distância deles para a saída de São Paulo seja d1 < d2 < · · · < dn. Finalmente, assuma
    que a distância entre dois postos vizinhos seja de, no máximo, m quilômetros e que você
    esteja saindo da cidade de tanque cheio. Dadas essas suposições, escreva um algoritmo
    para determinar o menor número de paradas nos postos de combustível que te permitam
    chegar ao destino final.

*/

#include <stdio.h>

int minimum_fuel_stops(int stations[], int numStations, int maxRange, int totalDistance) {
    int stops = 0;
    int currentPosition = 0; 
    int lastStop = 0;
    
    int allStations[numStations+1];
    for (int j = 0; j < numStations; j++) {
        allStations[j] = stations[j];
    }
    allStations[numStations] = totalDistance;
    
    for (int i = 0; i <= numStations; ) {
        int reachableStation = lastStop;
        for (int j = i; j <= numStations && allStations[j] - currentPosition <= maxRange; j++) {
            reachableStation = j;
        }
        
        if (reachableStation == lastStop) {
            return -1;
        }
        
        currentPosition = allStations[reachableStation];
        
        if (currentPosition != totalDistance) {
            stops++;
        }
        
        lastStop = reachableStation;
        i = reachableStation + 1;
    }
    
    return stops;
}

int main() {
    int maxRange = 400; 
    int totalDistance = 408;
    
    int stations[] = {100, 200, 300, 350, 400};
    int numStations = sizeof(stations) / sizeof(stations[0]);
    
    int result = minimum_fuel_stops(stations, numStations, maxRange, totalDistance);
    
    if (result == -1) {
        printf("A viagem é impossível com os postos disponíveis.\n");
    } else {
        printf("Número mínimo de paradas de combustível necessárias: %d\n", result);
    }
    
    return 0;
}