# GROUP 20 PROJECT FINAL REPORT
## OBJECT-ORIENTED AFFINITY PROPAGATION CLUSTERING ALGORITHM IN C++17
**Project repository:** https://github.com/muwambiwilson/GROUP-20\
**Project title:** Affinity Propagation Clustering Algorithm\
**Programming language:** C++17\
**Build system:** CMake\
**Group:** 20\
**Academic year:** 2026
------------------------------------------------------------------------
##  Executive Summary
This project presents an object-oriented implementation of the Affinity
Propagation (AP) clustering algorithm using C++17. Affinity Propagation
is an unsupervised machine-learning technique that groups data points
according to their similarities. Instead of requiring the user to
specify the number of clusters in advance, the algorithm considers every
data point as a possible cluster centre, known as an *exemplar*.

The implementation is organised into separate components for dataset
management, similarity calculation, the Affinity Propagation algorithm
and cluster evaluation. The system supports dataset validation, feature
standardisation using z-score normalisation, negative squared Euclidean
similarity, configurable self-preferences, iterative responsibility and
availability updates, damping, iteration limits and convergence
checking.

The project demonstrates how mathematical concepts in clustering can be
translated into a modular C++ application. It also provides example
programs and a unit-test location to support demonstration and
verification.

## Introduction
Data clustering is an important technique in data analysis and machine
learning. It is used to discover natural groupings in data without
requiring previously assigned class labels. Clustering can help identify
patterns, similarities and relationships within datasets.

Traditional algorithms such as K-Means require the number of clusters to
be selected before execution. This can be difficult when the natural
number of groups in a dataset is unknown.

Affinity Propagation addresses this challenge by exchanging numerical
messages between data points. These messages help each point determine
whether it should become an exemplar and which exemplar it should belong
to.

Group 20 developed a C++17 implementation of this algorithm using an
object-oriented and modular design. The project separates the major
responsibilities into independent classes and source files, making the
implementation easier to understand, test, maintain and extend.

##  Problem Statement
Many clustering methods require the number of clusters to be specified
before the clustering process begins. In practical situations, the
correct number may not be known. Selecting an unsuitable number can lead
to groups that do not represent the natural structure of the data.

The project addresses this problem by implementing Affinity Propagation,
which identifies representative data points through iterative message
passing. The implementation provides a configurable approach to
similarity measurement, preference selection and convergence.

##  Project Objectives
## Main Objective
To design and implement an object-oriented Affinity Propagation
clustering system in C++17 that identifies representative data points
and groups similar observations without requiring the number of clusters
to be specified in advance.

## Specific Objectives
1.  To understand the mathematical principles behind Affinity Propagation.
2.  To implement dataset storage, validation and feature standardisation.
3.  To calculate similarities between data points using negative squared Euclidean distance.
4.  To implement responsibility and availability message updates.
5.  To provide configurable damping, preference and convergence settings.
6.  To identify exemplars and assign data points to clusters.
7.  To evaluate the resulting cluster labels.
8.  To organise the program using object-oriented programming principles.
9.  To provide example programs and unit tests for verification.

##  Scope of the Project
The project focuses on implementing Affinity Propagation for numerical datasets using C++17.
The implemented project components cover:
-   Dataset storage and structural validation.
-   Checking dataset dimensions.
-   Feature standardisation using z-score normalisation.
-   Similarity matrix calculation.
-   Self-preference initialisation.
-   Responsibility and availability message passing.
-   Configurable damping and maximum iteration limits.
-   Convergence checking.
-   Cluster-label evaluation.
-   Example execution and CSV-based execution targets.

The project is an algorithmic implementation. It does not claim to
provide a graphical user interface or a production-scale distributed
clustering service.

##  Theoretical Background
## What Is Clustering?
Clustering is an unsupervised learning process in which observations are
grouped according to their similarities. Points within the same cluster
should generally be more similar to one another than to points in other
clusters.

## What Is Affinity Propagation?
Affinity Propagation is a clustering algorithm introduced by Brendan J.
Frey and Delbert Dueck. It identifies exemplars by exchanging two types
of messages between data points:
-   **Responsibility:** Indicates how suitable a candidate exemplar is
    for a particular data point compared with other possible exemplars.
-   **Availability:** Indicates how appropriate a candidate exemplar is
    for accepting a particular data point, based on support from other
    points.

The algorithm repeatedly updates these messages until the exemplar
assignments become stable or the configured iteration limit is reached.

## Similarity Calculation
A larger similarity value represents a closer pair of observations. The
diagonal value (s(k,k)) represents the preference of point (k) to become
an exemplar.

## Feature Standardisation
Features may have different measurement scales. Standardisation helps
prevent features with large numerical ranges from dominating the
distance calculation.

A feature with zero standard deviation requires special handling to
avoid division by zero.

## Responsibility Update
Responsibility (r(i,k)) measures how strongly data point (i) supports
candidate exemplar (k).
This update compares the suitability of candidate (k) against the best
alternative candidate.

## Availability Update
Availability (a(i,k)) measures the accumulated support for point (k) to
serve as an exemplar for point (i).

For the diagonal:

The diagonal availability indicates the accumulated evidence that point
(k) should become an exemplar.

## Damping
Damping reduces oscillations that may occur during iterative message
updates. A damped update combines the new message with the previous
message.

A higher damping factor gives more weight to the previous message and
can make updates more stable, although convergence may take longer.

## Exemplar Selection and Cluster Assignment
After message updates, the algorithm uses the diagonal evidence
as the standard exemplar-selection criterion.

The selected exemplars represent the cluster centres. Each non-exemplar
data point is assigned to an appropriate exemplar based on the
algorithm's similarity and assignment procedure.

The exact number of clusters is therefore determined by the algorithm's
message-passing process and preference settings.

## System Design and Architecture
The implementation follows a modular object-oriented design. Each
component has a specific responsibility.

## Dataset Module
**Files:** - `include/dataset.hpp` - `src/dataset.cpp`

Responsibilities:

-   Store the numerical dataset.
-   Validate the structure of the input data.
-   Check dataset dimensions.
-   Standardise features using z-score normalisation.
-   Provide data in a form suitable for similarity calculation.

## Similarity Calculator Module
**Files:** - `include/similarity.hpp` - `src/similarity.cpp`
Responsibilities:
-   Calculate the similarity matrix.
-   Use negative squared Euclidean distance.
-   Initialise self-preferences.
-   Support a user-specified preference or a median off-diagonal
    similarity preference.
The preference influences how readily data points become exemplars and
therefore affects the number of clusters produced.

## Affinity Propagation Module
**Files:** - `include/affinity_propagation.hpp` -
`src/affinity_propagation.cpp`
Responsibilities:
-   Manage the main Affinity Propagation procedure.
-   Initialise and update responsibility messages.
-   Initialise and update availability messages.
-   Apply damping.
-   Enforce maximum iteration limits.
-   Check convergence.
-   Determine exemplar and cluster assignments.

## Cluster Evaluation Module
**Files:** - `include/evaluation.hpp` - `src/evaluation.cpp`
Responsibilities:
-   Analyse the resulting cluster labels.
-   Count the number of unique clusters identified.
-   Provide basic information for evaluating the clustering output.

## Main Program and Examples
The main program and example files demonstrate how to configure the
algorithm, provide sample data, execute the clustering workflow and
display execution information.

The repository also contains an advanced example and a CSV execution
target.

##  Project Directory Structure
The repository is organised into the following main directories and
files:
``` text
GROUP-20/
│
├── CMakeLists.txt
├── main.cpp
│
├── Data/
│   └── (dataset files)
│
├── examples/
│   └── advanced_example.cpp
│
├── include/
│   ├── dataset.hpp
│   ├── similarity.hpp
│   ├── affinity_propagation.hpp
│   └── evaluation.hpp
│
├── src/
│   ├── dataset.cpp
│   ├── similarity.cpp
│   ├── affinity_propagation.cpp
│   └── evaluation.cpp
│
├── reports/
│
├── tests/
│   └── unit_tests.cpp
│
├── README.md
├── README_GUIDE.md
└── LICENSE
```

The exact contents of the data and reports directories may change as the
project develops.

##  System Workflow
The general execution process follows these stages:
1.  Load or prepare the input dataset.
2.  Validate the dataset structure and dimensions.
3.  Standardise features where required.
4.  Calculate pairwise similarities.
5.  Initialise self-preferences.
6.  Initialise responsibility and availability matrices.
7.  Update responsibility messages.
8.  Update availability messages.
9.  Apply damping to message updates.
10. Check convergence or the maximum iteration limit.
11. Identify exemplars and assign cluster labels.
12. Evaluate and display the clustering results.

## Workflow Diagram
``` mermaid
flowchart TD
    A([Start]) --> B[Load Dataset]
    B --> C[Validate Dataset]
    C --> D[Standardise Features]
    D --> E[Calculate Similarity Matrix]
    E --> F[Initialise Preferences and Messages]
    F --> G[Update Responsibilities]
    G --> H[Update Availabilities]
    H --> I[Apply Damping]
    I --> J{Converged or Maximum Iterations?}
    J -- No --> G
    J -- Yes --> K[Identify Exemplars]
    K --> L[Assign Cluster Labels]
    L --> M[Evaluate Clusters]
    M --> N[Display Results]
    N --> O([End])
```

##  Implementation Technologies
  -----------------------------------------------------------------------
  Technology                          Purpose
  ----------------------------------- -----------------------------------
  C++17                               Main programming language

  Object-oriented programming         Separation of responsibilities into
                                      modules

  CMake                               Project configuration and build
                                      management

  CSV data                            Input of tabular numerical
                                      observations

  Unit testing                        Verification of individual program
                                      components

  Git and GitHub                      Version control and collaborative
                                      development
  -----------------------------------------------------------------------

## Building and Running the Project
## Requirements
The development environment requires:
-   A C++ compiler with C++17 support.
-   CMake.
-   A compatible build tool, such as MinGW Makefiles or another
    supported generator.
-   Git, if cloning the repository.

## Clone the Repository
``` bash
git clone https://github.com/muwambiwilson/GROUP-20.git
cd GROUP-20
```
## Configure the Project
For a MinGW environment on Windows:
``` powershell
cmake -S . -B build -G "MinGW Makefiles"
```
Alternatively, use the default generator configured for the installed
environment:

``` bash
cmake -S . -B build
```

## Build the Project
``` bash
cmake --build build
```
## Run the Tests

``` bash
ctest --test-dir build --output-on-failure
```
## Build and Run the Examples
The repository README documents the following example targets:

``` bash
cmake --build build --target run_example run_csv
```
On Windows PowerShell, the example executable can be run using:
``` powershell
.\build\run_example.exe
```
The CSV target is documented with the following invocation:
``` powershell
.\build\run_csv.exe .\Data\data 1
```
The actual input path and command-line arguments should be checked
against the available dataset files and program usage before execution.

## Testing and Verification
Testing is important to establish that each component behaves as
expected and that the complete clustering workflow operates correctly.

The repository includes a unit-test source file:

`tests/unit_tests.cpp`

The project documentation provides a CTest command for running the
configured tests.

The following areas should be checked during verification:

  -----------------------------------------------------------------------
  Test area                           What should be verified
  ----------------------------------- -----------------------------------
  Dataset validation                  Invalid or inconsistent data
                                      structures are handled
                                      appropriately

  Dataset dimensions                  The number of features is
                                      consistent across observations

  Standardisation                     Features are transformed correctly
                                      and zero-variance features are
                                      handled

  Similarity calculation              Similarity values agree with
                                      negative squared Euclidean distance

  Preference initialisation           Custom and median-based preferences
                                      are handled

  Responsibility update               Responsibility values follow the
                                      update equation

  Availability update                 Availability values follow the
                                      update equations

  Damping                             Previous and newly calculated
                                      messages are combined correctly

  Convergence                         The algorithm stops when its
                                      configured convergence condition is
                                      met

  Cluster evaluation                  Unique cluster labels are counted
                                      correctly
  -----------------------------------------------------------------------

**Testing evidence note:** The repository documentation identifies the
unit-test file and gives the CTest command. This report does not claim a
particular test pass count or numerical clustering result because no
execution log or test output has been supplied. Actual results should be
inserted after running the tests and example programs.

## Expected Outputs and Results

When supplied with a valid numerical dataset, the program is designed to
produce clustering information through the Affinity Propagation
workflow.
The expected categories of output include:

-   Identified exemplar data points.
-   Cluster assignments or labels.
-   Number of unique clusters.
-   Execution information or metrics demonstrated by the example
    programs.
The final number of clusters depends on the dataset, similarity values,
preference settings, damping factor and convergence configuration.

For the final practical demonstration, record the following from an
actual program run:

  Result item              Observed value
  ------------------------ ----------------
  Input dataset            To be recorded
  Number of observations   To be recorded
  Number of features       To be recorded
  Preference setting       To be recorded
  Damping factor           To be recorded
  Number of iterations     To be recorded
  Number of clusters       To be recorded
  Identified exemplars     To be recorded
  Test summary             To be recorded

These fields should be completed using actual program output rather than
estimated values.

## Advantages of the Implemented Approach
1.  **No need to specify the number of clusters in advance:** The
    algorithm determines exemplars through message passing.
2.  **Representative data points:** Each cluster is represented by an
    actual observation from the dataset.
3.  **Modular structure:** Dataset handling, similarity calculation,
    clustering and evaluation are separated.
4.  **Configurable operation:** Preference, damping and iteration
    settings provide control over the clustering process.
5.  **Data validation:** Dataset checks help identify unsuitable input
    structures.
6.  **Feature standardisation:** Z-score normalisation helps manage
    differences in feature scales.
7.  **Maintainability:** Separate header and implementation files make
    the project easier to modify.
8.  **Test support:** A unit-test source file and CTest workflow are
    provided.

# Challenges and Limitations
## Computational Complexity
Affinity Propagation calculates and stores pairwise similarities and
message matrices. For (n) observations, these matrices require memory
proportional to:

\[ O(n\^2) \]

The repeated message updates also become computationally demanding as
the number of observations increases.

## Preference Selection
The preference value affects the number of exemplars and clusters. An
unsuitable preference may produce too many or too few clusters.

## Convergence
Message updates can oscillate or take many iterations. Damping and
suitable convergence settings help control this behaviour.

## Feature Scaling
Features with very different numerical ranges can distort distance
calculations if they are not appropriately standardised.

## Dataset Quality
Missing values, non-numeric entries, inconsistent dimensions and extreme
outliers can affect the quality of the results. Input data should
therefore be checked before clustering.

## Large Datasets
The quadratic memory requirement makes the conventional implementation
less suitable for very large datasets without additional optimisation.

## Recommendations for Future Improvement
The following improvements could make the project more useful and
efficient:
1.  Add more comprehensive input handling for missing and invalid
    values.
2.  Improve performance for large datasets through memory and
    computational optimisation.
3.  Provide graphical visualisation of clusters and exemplars.
4.  Support additional similarity measures where appropriate.
5.  Add more evaluation metrics, such as silhouette score where
    applicable.
6.  Compare results with K-Means and other clustering algorithms.
7.  Test the algorithm with more real-world datasets.
8.  Provide clearer output summaries, including cluster membership and
    exemplar information.
9.  Add automated test coverage for edge cases and convergence
    behaviour.
10. Document the effect of preference and damping settings using
    experimental results.

## Applications of Affinity Propagation
Affinity Propagation can be applied in several areas, including:
-   Customer segmentation.
-   Image and pattern recognition.
-   Document and text grouping.
-   Biological data analysis.
-   Identification of representative samples.
-   Grouping similar measurements in scientific datasets.
-   Exploratory analysis of engineering and experimental data.

These are potential application areas of the algorithm; they are not
claims that the project has been tested in each field.

## Conclusion
Our project demonstrates the design and implementation of the
Affinity Propagation clustering algorithm using C++17 and
object-oriented programming principles.

The implementation divides the clustering process into four major
components: dataset management, similarity calculation, Affinity
Propagation message passing and cluster evaluation. It uses negative
squared Euclidean distance to measure similarity and applies
responsibility and availability updates to identify representative data
points.

The project also provides configurable preferences, damping, iteration
limits and convergence checking. Its modular structure supports
understanding, maintenance, testing and future development.

Overall, the project provides a practical demonstration of how an
unsupervised machine-learning algorithm can be implemented using C++17.
Further testing with real datasets, performance evaluation and
visualisation would strengthen the system and provide additional
evidence of its effectiveness.

## Group Members
    No. Name                      Registration Number   Programme
  ----- ------------------------- --------------------- -----------
      1 NAKIRANDHA MARTHA TENDO   25/U/08763/PS         BCCE
      2 NANDERA DOROTHY           25/U/0850             BELE
      3 KASAGGA FRANCIS           25/U/0833             BELE
      4 MUWAMBI WILSON            25/U/0842             BELE
      5 NAKAZIBWE SHIFRAH         25/U/05326/PS         BCCE
      6 MATISKO ARON              25/U/25056            BELE
      7 KASOZI BAIHAKI            25/U/0834             BELE

##  References
1.  Frey, B. J., & Dueck, D. (2007). *Clustering by passing messages
    between data points*. Science, 315(5814), 972--976.
    https://doi.org/10.1126/science.1136800
2.  Group 20. *Object-Oriented Affinity Propagation Clustering in C++*.
    Project repository: https://github.com/muwambiwilson/GROUP-20
3.  Group 20. *README.md and README_GUIDE.md*. Project documentation in
    the repository.
4.  C++ documentation: https://en.cppreference.com/
5.  CMake documentation: https://cmake.org/documentation/

