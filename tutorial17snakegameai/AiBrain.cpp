#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "AiBrain.h"
using namespace std;

AiBrain::AiBrain()
{
    ifstream brain("brain.txt");
    ofstream log("log.txt");
    if (brain.is_open())
    {
        log << "brain.txt opened!" << endl;
        int count = 0;
        float val;
        while (brain >> val && count < sizeof(neuronConnections)/sizeof(neuronConnections[0]))
        {
            log << "loading value into neuronConnections[" << count << "]:" << val << endl;
            neuronConnections[count++] = val;
        }
    }
    else
    {
        for (int i=0; i < sizeof(neuronConnections)/sizeof(neuronConnections[0]); i++)
        {
            double val = (rand())/100;
            neuronConnections[i] = val;
            log << "generating value for neuronConnections:" << val << endl;
        }
    }

    for (int i=0; i < sizeof(sensorNeurons)/sizeof(sensorNeurons[0]); i++)
    {
        sensorNeurons[i] = rand() % 10 - 5;
    }
    log.close();
    brain.close();
}


AiBrain::~AiBrain()
{
    //the brain should be persisted through a file
    ofstream brain("brain.txt");
    ofstream log("log2.txt");
    for (int i=0; i < sizeof(neuronConnections)/sizeof(neuronConnections[0]); i++)
    {
        brain << neuronConnections[i] << endl;
        cout << endl << neuronConnections[i];
        log << "saving value into brain.txt: " << neuronConnections[i] << endl;
    }
    brain.close();
    log.close();
}
