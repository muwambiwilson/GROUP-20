# Week 1 Progress Report

## Completed
- In Week 1,  we set up the basic project structure and files for our C++ machine learning project. The main goal of this project is to build a grouping algorithm called Affinity Propagation from scratch without using extra complex libraries.To make the program run fast and avoid computer memory slowdowns, we decided to store all data grid numbers in simple continuous lists (1D arrays) instead of nested lists (2D vectors).

## In Progress
- Created Project Folders: Set up all required folders (include, src, tests, examples,data, and gitingore) to keep the code clean and organized.
- Designed Main Code Blueprint: Created the main header file (affinity_propagation.hpp) which defines how the user will pass data into our algorithm.
- Created the logic to read numbers from standard CSV spreadsheet files.
## Project Structure
- Here is how the project files are organized:
affinity-propagation-cpp/
├── CMakeLists.txt              # Build configuration file
├── include/                    # Header files (public code)
│   └── affinity_propagation/
│       └── affinity_propagation.hpp
├── src/                        # Main C++ source code
│   └── affinity_propagation.cpp
├── tests/                      # Automated test files
│   └── test_affinity_propagation.cpp
├── examples/                   # Example program to test the code
│   └── basic_clustering.cpp
└── data/                       # CSV files containing test data

###  Challenges/Blockers
- Using normal 2D lists (vector<vector<double>>) makes the computer slow down when doing thousands of repeated calculations.
- : I used a single 1D list (vector<double>) and calculated the position using simple math (row * total_columns + column). This keeps the computer running fast.
### Next Week plan 
- Getting simple codes from members
1.Muwambi Wilson-  Dataset Loading & Preprocessing
2.Nakirandha Martha Tendo - Similarity Matrix
3.Nandera Dorothy- Preference Initialization
4.Kasozi Baihaki- Responsibility Update
5.Kasagga Francis- Availability Update
6.Nakazibwe Shifrah- Convergence + Exemplar Selection
7.Matsiko Aron- Cluster Assignment + Evaluation + Integration
#### AI Use
- We used AI to get the solution for the challenge we got
