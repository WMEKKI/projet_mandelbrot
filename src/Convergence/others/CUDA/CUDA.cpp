#include "CUDA.hpp"
#include "kernel.cuh"

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
    
    // setup device
    cudaStatus = cudaSetDevice(0);
	if ( cudaStatus != cudaSuccess ) {
		printf( "error %d: unable to setup cuda device\n", cudaStatus);
	}

    // allocate device mem
    cudaStatus = cudaMalloc(&device_ptr, 3840*2160*sizeof(float));
    if ( cudaStatus != cudaSuccess ) {
		printf( "error %d: unable to allocate buffer\n", cudaStatus);
		return;
	}

    // send memory to graphic card (only dinamicly allocated mem)
    //cudaStatus = cudaMem(device_ptr, ptr, 1200*800*sizeof(float), cudaMemcpyHostToDevice);  // pointeur vide pas besoin  de copie
    //if ( cudaStatus != cudaSuccess ) {
	//	printf( "error %d: unable to copy input buffer\n", cudaStatus);
	//	return;
	//}
}


CUDA::~CUDA()
{
    // free device mem
    cudaStatus = cudaFree(device_ptr);
    if (cudaStatus != cudaSuccess) {
		printf( "error %d: unable to free memory\n", cudaStatus);
	}

    // free device
    cudaStatus = cudaDeviceReset();
	if (cudaStatus != cudaSuccess) {
		printf( "error %d: unable to reset device\n", cudaStatus);
	}
}

void CUDA::updateImage(const long double _zoom, const long double _offsetX, const long double _offsetY, const int IMAGE_WIDTH, const int IMAGE_HEIGHT, float* ptr)
{
    // run kernal
    compute_cuda_f(IMAGE_HEIGHT*IMAGE_WIDTH, _zoom, _offsetX, _offsetY, max_iters, IMAGE_WIDTH, IMAGE_HEIGHT, device_ptr);

    cudaStatus = cudaDeviceSynchronize();
	if ( cudaStatus != cudaSuccess ) {
		printf( "error %d: unable to synchronize threads\n", cudaStatus);
	}

    // receive memory
    cudaStatus = cudaMemcpy(ptr, device_ptr, IMAGE_HEIGHT*IMAGE_WIDTH*sizeof(float), cudaMemcpyDeviceToHost);
    if ( cudaStatus != cudaSuccess ) {
		printf( "error %d: unable to copy output buffer\n", cudaStatus);
		return;
	}
}


bool CUDA::is_valid()
{ 
//#ifdef __NVCC__
    // detect if cuda exists !!
    return true;
//#else
  //  return false;
//#endif
}
