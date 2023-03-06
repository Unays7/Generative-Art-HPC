#pragma once
#include <boost/math/tools/rational.hpp>
#include "ColouringAlgo.h"


struct PloyColuring : ColouringAlgo{
    unit8_t terms;
    float *r, *g, *b;

    explicit PloyColuring(cosnt uint8_t terms) : terms(terms){
        r = new float[terms];
        b = new float[terms];
        g = new float[terms];

        for (size_t i = 0; i < terms; i++){
            r[i] = randfloat;
            g[i] = randfloat;
            b[i] = randfloat;

        }
    }

    virtual void Value(float input, float &r, float &g, float &b) override{
        r += tools::eval_poly(this->r, input, terms);
        g += tools::eval_poly(this->g, input, terms);
        b += tools::eval_poly(this->b, input, terms);

    }

    virtual ~PloyColuring(){
        delete[] r;
        delete[] g;
        delete[] b;
    }
}