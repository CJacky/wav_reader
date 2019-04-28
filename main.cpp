
#include <iostream>
#include <vector>

#include "wav.h"


using namespace std;

int main(int argc, char* argv[]) {

    int num;
    vector<uint8_t> sample;

    //wav *mywav = new wav(string(argv[1]));
    wav *mywav = new wav("test.wav");

    mywav->show();

    for (int i=0; i<mywav->get_sampleNum(); ++i) {
        mywav->get_sample(i, sample);
        printf("Sample[%d] = ", i);
        for (auto &it : sample) {
            printf("%02X ", it);
        }
        printf("\n");
    }

    delete mywav;

    return 0;
}