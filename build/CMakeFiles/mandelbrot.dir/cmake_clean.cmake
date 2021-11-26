file(REMOVE_RECURSE
  "mandelbrot"
  "mandelbrot.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CUDA CXX)
  include(CMakeFiles/mandelbrot.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
