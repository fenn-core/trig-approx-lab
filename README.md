# Trig Approximation Lab

A numerical methods project exploring different approaches to computing trigonometric functions.

The objective is to understand the mathematics, numerical behavior, and engineering tradeoffs behind function approximation.

The project combines modern C++, Python, and LaTeX into a reproducible workflow capable of generating numerical experiments, publication-quality figures, and paper-style documentation.

Every figure and result in the repository is generated directly from the C++ implementations through an automated experiment pipeline.


## Methods

Current planned implementations:

- Taylor Series
- Minimax (Chebyshev / Remez-generated polynomial)
- CORDIC

Each method will be implemented independently and evaluated under identical experimental conditions.


## Objectives

This project investigates:

- Approximation theory
- Numerical error
- Floating-point behavior
- Range reduction
- Polynomial evaluation
- CORDIC iteration behavior
- Runtime performance
- Hardware considerations
- Modern trigonometric computation techniques


## Workflow

```
C++ Numerical Engine
        │
        ▼
Generated CSV Data
        │
        ▼
Python Visualization
        │
        ▼
Publication-quality Figures
        │
        ▼
   LaTeX Papers
```

The C++ code performs all numerical computation.

Python is responsible only for visualization.

LaTeX integrates generated figures into paper-style documentation.



## Repository Structure

```
trig-approx-lab/

src/        C++ implementations
include/    Public headers
tests/      Correctness tests

data/       Generated experimental data
plots/      Generated figures

tools/      Python plotting utilities
scripts/    Build / automation scripts

papers/     LaTeX papers
docs/       Programming documentation
```


## Planned Experiments

- Approximation curves
- Absolute error
- Relative error
- Maximum error
- Runtime comparison
- Polynomial degree comparison
- CORDIC convergence
- Range reduction behavior
- Generated assembly inspection


## Documentation

The repository contains two different styles of documentation.

### Programming Documentation

Markdown documents describe

- project architecture
- implementation details
- build instructions
- benchmarking methodology
- limitations

### Mathematical Documentation

Each approximation method receives its own paper-style PDF discussing

- mathematical background
- historical motivation
- derivation
- implementation
- experimental methodology
- error analysis
- modern applications
- engineering tradeoffs

A final comparative paper summarizes and contrasts every method.


## Current Status

Current proof-of-concept pipeline:

```
C++
 ↓
CSV generation
 ↓
Python plotting
 ↓
PDF figures
```

Future milestones include implementing the approximation methods and generating comparative error analyses.


## Roadmap

### Infrastructure

- [x] Project structure
- [x] Data generation pipeline
- [x] Plot generation
- [ ] Benchmark framework
- [ ] Automation scripts

### Numerical Methods

- [ ] Taylor series
- [ ] Minimax approximation
- [ ] CORDIC
- [ ] Error analysis
- [ ] Comparative study

### Documentation

- [ ] Taylor paper
- [ ] Minimax paper
- [ ] CORDIC paper
- [ ] Comparative paper


## Technologies

- C++20
- CMake
- Python
- Matplotlib
- LaTeX



## Purpose

This repository is intended as a small numerical computing laboratory exploring how mathematics is transformed into efficient software.

Rather than treating trigonometric functions as black boxes, the project investigates the algorithms, numerical approximations, and implementation techniques that underpin modern scientific computing, embedded systems, and mathematical software.