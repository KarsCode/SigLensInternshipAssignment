# Contact Tracing Simulation

## Problem Statement
The goal of this project is to simulate the spread of an infection based on interaction logs. Given a list of interactions between individuals and a set of initially infected individuals, the program identifies all individuals who may have been infected within a specified contagious period.

### Key Requirements:
1. **Input**:
   - A list of interactions in the format `<person1>,<person2>,<timestamp>`.
   - A list of initially infected individuals.
   - A contagious period (in hours).

2. **Output**:
   - A list of all individuals who may have been infected.

3. **Functions**:
   - `parseLog`: Parses the interaction logs and stores them in a suitable data structure.
   - `traceInfection`: Traces the spread of infection and returns a list of infected individuals.
   - `findContacts`: Finds all individuals a given person interacted with within a specific time window.

## Project Structure
The project is organized as follows:

```
KARTIK_SUBBARAM_220905298/
├── src/
│   ├── main.cpp           # Entry point of the program
│   ├── Logger.h           # Header file for log parsing
│   ├── Logger.cpp         # Implementation of log parsing
│   ├── ContactTracer.h    # Header file for contact tracing
│   ├── ContactTracer.cpp  # Implementation of contact tracing
│   └── test_cases.txt     # Test cases for the program
├── bin/                   # Optional: Compiled binaries
├── resume.pdf             # Updated resume
└── README.md              # This file
```

## Why C++?
C++ was chosen for this project due to its:
- **Performance**: Efficient handling of large datasets.
- **Standard Library**: Rich data structures like `unordered_map` and `vector` for storing and processing interaction logs.
- **Object-Oriented Design**: Encapsulation of functionality into classes like `Logger` and `ContactTracer`.

## How It Works
1. **Input Parsing**:
   - The `Logger::parseLog` function reads the interaction logs and stores them in an `unordered_map` where each person maps to a list of their interactions.

2. **Infection Tracing**:
   - The `ContactTracer::traceInfection` function uses a breadth-first search (BFS) approach to trace the spread of infection. It processes each infected individual and checks their interactions within the contagious period.

3. **Contact Finding**:
   - The `ContactTracer::findContacts` function identifies all individuals a given person interacted with within a specific time window.

## Compilation and Execution

### Prerequisites
- A C++ compiler (e.g., `g++`).
- Basic knowledge of the command line.

### Steps to Compile and Run
1. Navigate to the `src` folder:
   ```bash
   cd src
   ```

2. Compile the program:
   ```bash
   g++ -std=c++17 -Wall -Wextra -o ./../bin/contact_tracer main.cpp Logger.cpp ContactTracer.cpp
   ```

3. Run the program:
   ```bash
   ./contact_tracer
   ```

### Running Test Cases
1. Open the `test_cases.txt` file in the `src` folder.
2. Copy the desired test case (logs, initially infected, and contagious period) into the `main.cpp` file, replacing the existing test case that is hardcoded due to lack of time.
3. Recompile and run the program to see the results.

## Example Test Case
### Input:
```cpp
vector<string> logs = {
    "A1,B1,00",
    "B1,C1,20",
    "C1,A1,40"
};

vector<string> initiallyInfected = {
    "A1"
};

int contagiousPeriod = 48;
```

### Output:
```
Infected individuals: A1 B1 C1
```

## Limitations
- The program assumes that all log entries are valid and formatted correctly.
- It does not handle cases where the same interaction is logged multiple times.
- The contagious period is assumed to be a fixed duration for all individuals.

## Included Test Cases
The `test_cases.txt` file contains the following test cases:
1. Simple Transmission
2. No Transmission (Isolated Case)
3. Infection Dies Out (Short Period)
4. Large-Scale Infection
5. Infection Loops Back
6. Multiple Initial Infections
7. Delayed Infection (Long Timestamp)
8. Chain Broken (Gap in Transmission)
9. Rapid Infection (Short Time Gaps)
10. No Infections Recorded

## Resume
An updated copy of my resume is included in the root folder as `resume.pdf`.
