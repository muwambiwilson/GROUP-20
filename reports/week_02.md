THE CLASSES WE CREATED
Dataset Class
SimilarityCalculator Class
AffinityPropagation Class
ClusterEvaluator Class

Why we created the classes , what data does it store and the function?
The Dataset class; is used to keep the numerical data that the program works with. It brings the data and the operations needed to manage it together in one place. This makes it easier to check that the data is arranged correctly and to prepare it before clustering.
It stores two main things: a matrix of numerical values, called values_, and a list of column names, called column_names_. The matrix is represented using a vector of vectors of double values, while the column names are stored as strings.
The class has constructors for creating a Dataset, rows() and cols() for checking its size, get_values() and set_values() for accessing or changing the values, and get_column_names() for retrieving the column labels. It also has validate() to check that the data is consistent and standardize() to put numerical features on a common scale.

The SimilarityCalculator class;It handles the calculations used to compare data points. For this project, it includes a negative squared Euclidean distance measure and a function for initializing preference values used by the clustering algorithm.
It does not store its own data. Instead, it acts as a utility class with static functions, which can be called without creating a SimilarityCalculator object.
The public function negative_squared_euclidean() calculates similarities from a Dataset, while initialize_preferences() sets the preference values in the similarity matrix. The private helper median_off_diagonal() finds the median of the off-diagonal similarity values and is used internally when initializing preferences.

The ClusterEvaluator class;It provides a small utility for checking the clustering results. In this project, it counts how many different clusters appear in the assigned labels.
It does not store its own data. Instead, it acts as a utility class with static functions, which can be called without creating a SimilarityCalculator object.
The public function negative_squared_euclidean() calculates similarities from a Dataset, while initialize_preferences() sets the preference values in the similarity matrix. The private helper median_off_diagonal() finds the median of the off-diagonal similarity values and is used internally when initializing preferences.

The AffinityPropagation class;It contains the main logic for the Affinity Propagation clustering algorithm. It repeatedly updates messages between data points to identify representative points, called exemplars, and then uses them to form clusters.
It stores an APConfig object named config_. This configuration contains the settings that control the algorithm, such as the damping factor, maximum number of iterations, convergence requirements, and preference settings.
The constructor, AffinityPropagation(APConfig config), sets up the algorithm using the supplied configuration. The public run() function accepts a Dataset and returns an APResult containing the clustering results. The private helper functions find_exemplars() and same_vector() support the internal process of identifying exemplars and checking whether results have stopped changing.

Why some members are public and others pravite?
Dataset class:
The data members are private so other parts of the program cannot change them directly without going through the class. This helps protect the data and keeps it consistent. The public functions provide controlled ways to access, check, and process the data. Other classes, including SimilarityCalculator and AffinityPropagation, can therefore use the Dataset safely.

SimilarityCalcultor class:
The median_off_diagonal() function is private because it is only a supporting step in the internal calculation. The other two functions are public so that the clustering code can request similarity calculations and preference initialization when needed. Keeping these tasks separate also makes the program easier to maintain.

AffinityPropagation class:
The configuration and helper operations are kept private so the internal steps of the algorithm are managed by the class itself. The run() function is public because main.cpp needs to call it to start clustering. This gives the rest of the program a simple way to use the algorithm without needing to manage every calculation.

 ClusterEvaluator class:
 The function is public because main.cpp can call it directly when it needs to summarize the results. Since the class only performs a simple calculation and does not need to protect internal data, there is no need for private helper functions in the described design.

 How the classes are used by the rest of the  program?
 The classes work together as parts of one process. First, Dataset stores and checks the input data. Next, SimilarityCalculator calculates how closely the data points relate to one another and prepares the preference values. AffinityPropagation then uses this information to perform clustering and produce the results. Finally, ClusterEvaluator counts the distinct clusters so the program can report a simple summary. Each class focuses on one job, which keeps the overall program organized.
 
 














