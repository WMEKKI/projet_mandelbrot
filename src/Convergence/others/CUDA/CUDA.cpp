#include "CUDA.hpp"
//#include "cuda_runtime.h"
//#include "kernel.cuh"

CUDA::CUDA() : Convergence("CUDA")
{
    fractal     = "mandelbrot";
    dataFormat  = "float";
    modeSIMD    = "none";
    modeOPENMP  = "disable";
    OTHER       = "cuda";

    device_ptr = nullptr;
}


CUDA::CUDA(ColorMap* _colors, int _max_iters) : Convergence("CUDA")
{
    colors      = _colors;
    max_iters   = _max_iters;

    fractal     = "mandelbrot";
    dataFormat  = "float";
    modeSIMD    = "none";
    modeOPENMP  = "disable";
    OTHER       = "cuda";

    device_ptr = nullptr;
}


CUDA::~CUDA()
{

}


void CUDA::updateImage(const long double _zoom, const long double _offsetX, const long double _offsetY, const int IMAGE_WIDTH, const int IMAGE_HEIGHT, float* ptr)
{
    // allocate device mem
    // cudaMalloc(&device_ptr, IMAGE_HEIGHT*IMAGE_WIDTH);

    // send memory to graphic card (only dinamicly allocated mem)
    // cudaMemcpy(device_ptr, ptr, IMAGE_HEIGHT*IMAGE_WIDTH, cudaMemcpyHostToDevice);

    // run kernal
    // compute_cuda_s   (threads,  _zoom, _offsetX, _offsetY, max_iters, IMAGE_WIDTH, IMAGE_HEIGHT, device_ptr)  ;

    // receive memory
    // cudaMemcpy(ptr, device_ptr, IMAGE_HEIGHT*IMAGE_WIDTH, cudaMemcpyDeviceToHost);

    // free device mem
    // cudaFree(&device_ptr)
}


bool CUDA::is_valid()
{
    // detect if cuda exists !!
    return true;
}
