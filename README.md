# Competitive Programming Repository

A comprehensive collection of competitive programming solutions, algorithms, and resources spanning multiple years of contests and practice.

## 👨‍💻 Author
**Amine Oueslati** ([@ou3slati](https://github.com/ou3slati))

## 🗂️ Repository Structure

```
competitive-programming/
├── 📁 Implementations/          # 5,776 problem solutions
│   ├── AtCoder/                 # Educational DP, rated contests
│   ├── Codeforces/              # Contest solutions and practice
│   ├── UVa/                     # 350+ classic problems
│   ├── IOI/                     # International Olympiad prep
│   ├── USACO/                   # Training and contests
│   ├── DMOJ/                    # Canadian contest platform
│   ├── EGOI/                    # European Girls' Olympiad
│   ├── CodeChef/                # Indian programming contests
│   ├── Camps/                   # Training camp problems
│   ├── MyChecklist/             # Personal problem tracking
│   └── [10+ more platforms]
├── 📁 Library/                  # Algorithm implementations
│   ├── data_structures/         # 8 optimized data structures
│   ├── graph_theory/            # 2 advanced algorithms
│   ├── math/                    # 3 mathematical utilities
│   └── cpp_tricks/              # 6 modern C++ techniques
├── 📁 Nice Problems/            # Contest analyses
│   └── ISIJ/                    # 33 problem solutions with analysis
├── 📁 Notes & Resources/        # Educational materials
│   ├── Topics/                  # IOI preparation materials
│   ├── cp handbook.pdf          # Competitive programming guide
│   └── Reference materials
└── 📁 Codeforces/               # Organized CF solutions
    └── Educational Rounds/      # Rounds 89-92
```

## 🏗️ Algorithm Library

### Data Structures
- **Fenwick Tree** - Point updates, prefix sums (3 variants)
- **Disjoint Set Union** - Path compression + union by rank
- **Ordered Set** - GNU PBDS for order statistics
- **Centroid Decomposition** - Tree divide-and-conquer
- **Longest Increasing Subsequence** - O(n log n) with reconstruction
- **Boyer-Moore Majority** - O(n) time, O(1) space voting algorithm

### Graph Theory
- **Edmonds-Karp Max Flow** - Maximum flow with BFS
- **Bipartite Matching** - Hungarian algorithm implementation

### Mathematics
- **Extended Euclidean** - GCD with Bézout coefficients
- **Modular Arithmetic** - Fast exponentiation, inverse, combinations
- **Prime Sieve** - Smallest prime factor for efficient factorization

### C++ Techniques
- **Fast I/O** - Multiple optimization methods
- **Modern C++** - Auto, lambdas, structured bindings
- **Advanced Tricks** - Emplace, containers, shortcuts
- **Competition Template** - Ready-to-use contest template

## 🏆 Contest Platforms

| Platform | Problems | Notable Achievements |
|----------|----------|---------------------|
| **UVa** | 350+ | Classic problem collection |
| **AtCoder** | 100+ | Educational DP series |
| **Codeforces** | 200+ | Div1/Div2 contests |
| **IOI** | 50+ | International Olympiad prep |
| **USACO** | 80+ | Training progression |
| **DMOJ** | 100+ | Canadian contests |
| **EGOI** | 40+ | European Girls' Olympiad |
| **CodeChef** | 60+ | Long/short contests |

## 🚀 Usage

### Compilation
All solutions are compatible with standard competitive programming environments:
```bash
g++ -std=c++17 -O2 solution.cpp -o solution
```

### Template Usage
Use the provided template for contests:
```cpp
#include "Library/cpp_tricks/template.cpp"
// Ready-to-use competitive programming template
```

### Algorithm Integration
```cpp
#include "Library/data_structures/fenwick_tree.cpp"
FenwickTree ft(n);
ft.update(i, val);
int sum = ft.range_sum(l, r);
```

## 📈 Statistics
- **Total Files**: 5,800+
- **Lines of Code**: 200,000+
- **Platforms Covered**: 15+
- **Years Active**: 2021-2024
- **Contest Participation**: IOI, EGOI, USACO, AtCoder, Codeforces

## 🤝 Contributing

This repository represents years of competitive programming journey. While primarily personal, contributions are welcome for:
- Bug fixes in algorithm implementations
- Additional test cases or optimizations
- Documentation improvements

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🔗 Connect

- **GitHub**: [@ou3slati](https://github.com/ou3slati)
- **Email**: amineoueslati139@gmail.com

---
*"The only way to learn a new programming language is by writing programs in it."* - Dennis Ritchie
