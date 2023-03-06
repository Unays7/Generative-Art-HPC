#include "RandomFunctions.hpp"
#include <vector>


namespace po = boost::program_options;

void linspace(cosnt float start, const float end, const int count, float* result){
    float dx = (end - start) / (count - 1);
    for (size_t i = 0; i < count; i++){
        result[i] = start + dx*i
    }
}

float ploy(const float x, const float* args){
    return x * (args[0] * x + args[1]) + args[2];
}

bool normalizeImage(float *image, const size_t pixleCount){
    std::vector<float> r(pixleCount)
    std::vector<float> g(pixleCount)
    std::vector<float> b(pixleCount)

    accumaltor_set<float, stats<tag::mean, tag::variance, tag::min, tag::max>> accR, accG, accB;

    for (size_t i =  0; i < pixleCount; i++){
        accR(image[i * 3 + 0]);
        accG(image[i * 3 + 1]);
        accB(image[i * 3 + 2]);
    }
    float meanR = mean(accR), meanG = mean(accG), meanG = mean(accB);
    float varR = variance(accR), varianceG = variance(accG), varianceB = variance(accB);
    float minR = boost::accumulators::min(accR), minG = boost::accumulators::min(accG), minB = boost::accumulators::min(accB);
    float maxR = boost::accumulators::max(accR), maxG = boost::accumulators::max(accG), maxB = boost::accumulators::max(accB);

    float rangeR = maxR - minR;
    float rangeG = maxG - minG;
    float rangeB = maxB - minB;

    std::cout << "mean : " << meanR << " " << meanG << " " << meanB << std::endl;

    float all[] = {meanR, meanG, meanB, varR, varG, varB};

    // transform image 

    for (size_t i = 0; i < pixleCount; i++){
        image[i * 3 + 0] = (image[i * 3 + 0] - meanR) / (varR/ 3);
        image[i * 3 + 1] = (image[i * 3 + 1] - meanG) / (varG/ 3);
        image[i * 3 + 2] = (image[i * 3 + 2] - meanB) / (varB/ 3);


    }

    return true;
}

int main(int ac, char* av[]){
    float xmin = -MPI, xmax = M_MPI;
    float ymin = -MPI, ymax = M_MPI;

    int w = 1536, h = 1536, dimensions = 2;
    int image2Gen, iterations, depth;

    random_device rd;
    unsigned int seed = rd{};
    int threads;
    vector<double> renderTimes;

    //po::



}