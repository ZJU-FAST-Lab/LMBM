# LMBM
Nonsmooth Unconstrained Optimization via [Limited Memory Bundle Method](https://link.springer.com/article/10.1007/s10107-006-0728-2)

# Feature

1. The solver is a __C++11__ wrapper for the __FORTRAN__ solver [LMBM](http://napsu.karmitsa.fi/lmbm/), which suits __Large-Scale Nonsmooth Unconstrained Nonlinear Optimization__.

2. It is a substitution to [L-BFGS](https://github.com/ZJU-FAST-Lab/LBFGS-Lite) when nonsmooth optimization is inevitable. For example, nonsmoothness is quite common in various robotics applications where spatially discretized data is often incorporated into optimization problem.

# Building

  To build the lib, first make sure you have __gfortran__, __g++__, __make__, and __CMake__ installed. This toolchain is often installed by default in many Linux environments. Then, clone this repository and rename it LMBM. Now cd into this directory to build the shared lib for LMBM solver.

      cd LMBM/lmbm/
      make

  Then a shared lib for LMBM is generated. Two files __lmbm.so__ and __lmbm.h__ are all you need for conducting nonsmooth optimization in any C++ application. The header file contains sufficient information about how the lib should be called and tuned.
  
  A simple example is also provided where a nonsmooth function is minimized by LMBM. The CMakeList.txt shows how the lib should be linked by your own projects. Run the following commands to build and execute the example.
  
      cd ..
      mkdir build
      cd build
      cmake ..
      make
      ./lmbm_example

# Reference

1. Haarala, N., Miettinen, K. and Mäkelä, M.M., 2007. Globally convergent limited memory bundle method for large-scale nonsmooth optimization. Mathematical Programming, 109(1), pp.181-205.
2. Karmitsa, N., 2007. LMBM–FORTRAN subroutines for Large-Scale nonsmooth minimization: User’s manual’. TUCS Technical Report, (856).
3. Bagirov, A., Karmitsa, N. and Mäkelä, M.M., 2014. Introduction to Nonsmooth Optimization: theory, practice and software. Springer.