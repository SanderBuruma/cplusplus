#ifndef AIBRAIN_H
#define AIBRAIN_H


class AiBrain
{
    public:
        AiBrain();
        virtual ~AiBrain();
    protected:

    private:
        /*
            neurons only contain their static values which get added to the sum of the weights of previous neurons.
            neuron connections contain the weights which get applied to their values and passed on to the relevant neuron.
        */
        float sensorNeurons[5];         //North South East West distance to tail piece and tail length
        float decisionNeurons[3][6];
        float outputNeurons[4];
        float neuronConnections[108];
};

#endif // AIBRAIN_H
