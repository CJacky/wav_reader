
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#ifndef __WAV_H__
#define __WAV_H__

using namespace std;

class wav{
public:
    wav();
    wav(string name);

    ~wav();

    bool open(string name);

    int get_channel(){ return (isParsed)? channel:-1; }
    int get_sampleRate(){ return (isParsed)? sample_rate:-1; }
    int get_sampleBit(){ return (isParsed)? sample_bit:-1; }
    int get_sampleNum(){ return (isParsed)? sample_num:-1; }

    int get_sample(int index, vector<uint8_t> &sample);
    //int get_sample(int start, int length, char* buffer, );

    void show();

private:
    bool isParsed;
    string file_name;
    ifstream infile;

    short channel;
    int sample_rate;
    int sample_bit;
    int sample_byte;
    int sample_num;
};

#endif
