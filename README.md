# GROUP-20
AFFINITY PROPAGATION CLUSTERING ALGORITHM
# Object-Oriented Affinity Propagation Clustering in C++

## Project Structure
```text
project/
├── CMakeLists.txt
├── main.cpp
├── data/
│   └── sample.csv
├── docs/
├── examples/
│   └── advanced_example.cpp
├── include/
│   ├── dataset.hpp
│   ├── similarity.hpp
│   ├── affinity_propagation.hpp
│   └── evaluation.hpp
├── reports/
├── src/
│   ├── dataset.cpp
│   ├── similarity.cpp
│   ├── affinity_propagation.cpp
│   └── evaluation.cpp
└── tests/
    └── unit_tests.cpp
    
### GROUP MEMBERS
    
NAKIRANDHA MARTHA TENDO   25/U/08763/PS   BCCE
NANDERA DOROTHY           25/U/0850       BELE 
KASAGGA FRANCIS           25/U/0833       BELE 
MUWAMBI WILSON            25/U/0842       BELE
NAKAZIBWE SHIFRAH         25/U/05326/PS   BCCE
MATISKO ARON              25/U/25056      BELE
KASOZI BAIHAKI            25/U/0834       BELE
### What the Code Does
​This project implements the Affinity Propagation clustering algorithm using a modular, object-oriented design in C++17. Unlike traditional partitioning algorithms (like K-Means) that require you to pre-specify the number of clusters, Affinity Propagation evaluates all data points as potential cluster centers (exemplars) simultaneously and passes messages between them until stable clusters emerge.
​The architecture is divided into clear, single-responsibility components:
​Dataset (dataset.hpp / dataset.cpp): Handles raw data matrix storage, structural validation, dimensions checking, and feature standardization (z-score normalization).
​SimilarityCalculator (similarity.hpp / similarity.cpp): Computes the negative squared Euclidean distance matrix between all data points and initializes self-preferences (using either a custom user value or the median off-diagonal similarity).
​AffinityPropagation (affinity_propagation.hpp / affinity_propagation.cpp): Manages the core iterative message-passing loop. It updates responsiveness and availability matrices using configurable damping factors, maximum iteration caps, and convergence checks.
​ClusterEvaluator (evaluation.hpp / evaluation.cpp): Provides utility functions to analyze the resulting cluster labels, such as counting the total number of unique clusters identified.
​main.cpp / examples/: Demonstrates how to configure the algorithm (APConfig), pass sample datasets, run the optimization workflow, and print out execution metrics.
## Build and Run the Example

From the project root, configure and build the example target:

powershell
cmake -S . -B build
cmake --build build --target run_example
.\build\run_example.exe

The existing `app` target remains available for `main.cpp`.
Build and Run Tests
Build the test executables and run them through CTest:
powershell
cmake --build build --target test_dataset test_similarity test_affinity_propagation test_evaluation
ctest --test-dir build --output-on-failure

