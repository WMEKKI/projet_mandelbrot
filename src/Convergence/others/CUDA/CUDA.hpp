#ifndef _CUDA_
#define _CUDA_

#include "cuda_runtime.h"
#include "Convergence/Convergence.hpp"

class CUDA : public Convergence {
private:

    float* device_ptr;

    cudaError_t cudaStatus;    

public:

    CUDA(ColorMap* _colors, int _max_iters);

    ~CUDA();

    virtual void updateImage(const long double _zoom, const long double _offsetX, const long double _offsetY, const int IMAGE_WIDTH, const int IMAGE_HEIGHT, float* ptr);

    virtual bool is_valid();
};

#endif
