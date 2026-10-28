# WEEK 3 PROGRESS REPORT
## C++ Affinity Propagation Clustering Project


Programming Language: C++  
Build System: CMake  
C++ Standard: C++17

---

## 1. Introduction

During this week, the project team worked on preparing the files and configurations required for the Affinity Propagation Clustering project. The main activities included preparing a sample dataset, adding the MIT License, configuring CMake, and creating a .gitignore file.

## 2. Activities Undertaken

### 2.1 Dataset Preparation

Kasozi Baihaki and Muwambi Wilson prepared a sample dataset containing six data points, each represented by two features, x and y.

| x | y |
|---:|---:|
| 1.0 | 2.0 |
| 1.2 | 1.8 |
| 0.8 | 2.1 |
| 8.0 | 8.0 |
| 8.2 | 8.1 |
| 7.9 | 7.8 |

The dataset contains two visibly separated groups. The first three points are located around (1, 2), while the last three are located around (8, 8). It will be used to test whether the clustering algorithm can identify groups of similar data points.

### 2.2 MIT License

Kasagga Francis and Nakirandha Martha added an MIT License to the project. This license permits users to use, copy, modify, distribute, and share the software, subject to the license conditions.

It requires the copyright and permission notices to be included in copies or substantial portions of the software. It also includes a disclaimer of warranties and limits the liability of the authors and copyright holders.

The copyright notice included in the license is:

*Copyright (c) 2026 GROUP 20*

Adding the license establishes the terms under which the software may be used and distributed.

### 2.3 CMake Configuration

Nakazibwe Shifrah and Matsiko Aron created a CMakeLists.txt file to manage the project's build process.

The configuration specifies CMake version 3.14 as the minimum required version and identifies the project as AffinityPropagationClustering, version 1.0.0.

The project is configured to use the C++17 standard, with compliance required and compiler-specific extensions disabled.

A core library named ap_core was defined using the following source files:

- src/dataset.cpp
- src/similarity.cpp
- src/affinity_propagation.cpp
- src/evaluation.cpp

The include directory was specified as the public include directory.

An executable named app was also defined using main.cpp and linked to the ap_core library. This organization separates the main application from the core implementation and supports modular development.

### 2.4 Git Ignore Configuration

Nandera Dorothy created a .gitignore file to prevent unnecessary files from being tracked by Git.

The file excludes:

- Build directories, including build/, bin/, and out/.
- Compiled object files such as .o and .obj files.
- Executable files such as .exe and .out files.
- The generated application binary named app.
- IDE-specific files and folders, including .vscode/, .idea/, and Visual Studio project files.

This helps keep the repository clean and prevents generated build files and local development settings from being unnecessarily committed.

## 3. Challenges and Considerations

The main consideration during this stage was organizing the project files and establishing a consistent build configuration.

Our team needed to ensure that the source files, include directory, C++ standard, and executable were correctly specified. The .gitignore file was also configured to prevent unnecessary files from entering the repository.

The small sample dataset provides a manageable starting point for testing the clustering algorithm.

## 4. Outcomes Achieved

The following activities were completed during the week:

1. Prepared a sample dataset containing six two-dimensional data points.
2. Added an MIT License to the project.
3. Configured CMake to use C++17.
4. Defined the ap_core library and its four source files.
5. Configured the app executable and linked it to the core library.
6. Created a .gitignore file to exclude build artifacts and IDE-specific files.

These activities established the basic project structure and configuration needed for continued development.

## 5. Work Planned for the Following Week

The team plans to:


 - Running and Testing the project code
 - Generating the README
- Build and test the application using CMake.


## 6. Conclusion

This week's work focused on establishing the foundation of the C++ Affinity Propagation Clustering project. Preparing the sample dataset, adding the MIT License, configuring CMake, and creating the .gitignore file helped organize the project and prepare it for further development.

The team can now proceed with implementing, integrating, and testing the core clustering components.
