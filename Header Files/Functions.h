#pragma once

//typedef function<float(float)> unaryFunction;
//typedef function<float(float)> binaryFunction;


inline std::vector<unaryFunction> initUnaryFucntion(){

        std::vector<unaryFunction> result {sinf, cosf, expf, logf, sinhf, coshf, tanhf};
        
}

 