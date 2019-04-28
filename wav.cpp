
#include <iostream>
#include <fstream>
#include <stdint.h>

#include "wav.h"

using namespace std;

#define WAV_HEADER_SIZE (44)

wav::wav() {
    isParsed = false;
}

wav::wav(string name) {
    wav();
    open(name);
}

wav::~wav() {
    infile.close();
}

bool wav::open(string name) {

    char header[44] = {0};
    short AudioFormat;
    uint64_t data_size;

    try {
        file_name = name;

        infile.open(name, ios::binary);
        infile.read(header, sizeof(header));

        AudioFormat = *((short*)(&header[20]));

        if (AudioFormat != 1 ) {
            throw "The WAV is not PCM format";
        }

        channel = *((short*)(&header[22]));
        sample_rate = *((int*)(&header[24]));
        sample_bit = *((int*)(&header[34]));
        sample_byte = sample_bit / 8;

        data_size = *((int*)(&header[40]));
        sample_num = data_size / channel / sample_byte;

    } catch (exception e){
        cout << e.what();
        infile.close();
        return false;
    }

    isParsed = true;

    return true;
}

void wav::show() {

    if (isParsed) {
        cout << "File = " << file_name << endl;
        cout << "Channel = " << channel << endl;
        cout << "Sample Rate = " << sample_rate << endl;
        cout << "Sample Bits = " << sample_bit << endl;
        cout << "Sameple Num = " << sample_num << endl;
    }
}

int wav::get_sample(int index, vector<uint8_t> &sample) {
    int num = 0;
    int sample_size = sample_byte * channel;
    uint8_t data[8] = {0};

    try {
        infile.seekg(WAV_HEADER_SIZE + index*sample_size, ifstream::beg);
        infile.read((char*)data, sample_size);

        sample.clear();
        sample.assign(data, data + sample_size);

    } catch (exception e){
        cout << e.what();
        return -1;
    }

    return sample_size;
}