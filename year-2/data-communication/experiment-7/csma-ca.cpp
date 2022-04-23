#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int deviceDemand[10], maxBandwidth = 9, numOfDevice = 3; 
    float avgBandwidth = maxBandwidth / numOfDevice, bandwidthProvide[10];

    for (int i = 0; i < numOfDevice; i++) {
        deviceDemand[i] = rand() % 5 + 1;
    }
    
    printf("Bandwidth limit of the channel: %d\n", maxBandwidth);
    
    for (int i = 0; i < numOfDevice; i++) {
        printf("Bandwidth demand for device %d: %d mbps\n", i+1, deviceDemand[i]);
    }

    float excessBandwidth = 0, condition[10], count = 0;

    for (int i = 0; i < numOfDevice; i++) {
        if(deviceDemand[i] <= avgBandwidth) {
            bandwidthProvide[i] = deviceDemand[i];
            excessBandwidth += avgBandwidth - deviceDemand[i];
            condition[i] = 1;
        } else {
            bandwidthProvide[i] = avgBandwidth;
            condition[i] = 0;
            count++;
        }
    }

    printf("Excess Bandwidth after providing average bandwidth = %f\n", excessBandwidth);
    
    float BonusBandwidth = excessBandwidth/count;
    
    for (int i = 0; i < numOfDevice; i++) {
        if(condition[i] == 0) {
            bandwidthProvide[i] += BonusBandwidth;
        }
    }

    for (int i = 0; i < numOfDevice; i++) {
        if(deviceDemand[i] == bandwidthProvide[i]) {
            printf("Device %d: (%f mbps provided) Demand Satisfied\n", i+1, bandwidthProvide[i]);
        } else {
            printf("Device %d: (%f mbps provided) Demand Not Satisfied\n", i+1, bandwidthProvide[i]);
        }
    }
}