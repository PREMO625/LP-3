# BT and DAA commands

These commands download one file at a time. They do not require Git, GitHub
Desktop, or a GitHub account.

Run download commands from the folder where you want the `BT` and `DAA` folders
created.

## Common command templates

Only the filename and path change between programs.

### Download a file on Windows CMD

```bat
curl.exe -fL "RAW_GITHUB_URL" -o "LOCAL_FOLDER\FILE_NAME"
```

Example:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/fibonacci.cpp" -o "DAA\fibonacci.cpp"
```

### Download a file on Windows PowerShell

```powershell
Invoke-WebRequest -Uri "RAW_GITHUB_URL" -OutFile "LOCAL_FOLDER\FILE_NAME"
```

### Download a file on Ubuntu/Linux

```bash
curl -fL "RAW_GITHUB_URL" -o "LOCAL_FOLDER/FILE_NAME"
```

### Compile a C++ file on Windows

```bat
g++ FOLDER\FILE_NAME.cpp -std=c++17 -O2 -o FOLDER\FILE_NAME.exe
```

### Run a C++ program on Windows CMD

```bat
FOLDER\FILE_NAME.exe
```

### Run a C++ program on Windows PowerShell

```powershell
.\FOLDER\FILE_NAME.exe
```

### Compile a C++ file on Ubuntu/Linux

```bash
g++ FOLDER/FILE_NAME.cpp -std=c++17 -O2 -o FOLDER/FILE_NAME
```

### Run a C++ program on Ubuntu/Linux

```bash
./FOLDER/FILE_NAME
```

### Run a Python file on Windows

```bat
py "FOLDER\FILE_NAME.py"
```

### Run a Python file on Ubuntu/Linux

```bash
python3 "FOLDER/FILE_NAME.py"
```

### Run a shell script on Ubuntu/Linux

```bash
chmod +x FOLDER/FILE_NAME.sh
./FOLDER/FILE_NAME.sh
```

## Download files on Windows Command Prompt

Create the BT folder:

```bat
mkdir BT
```

Download `SimpleStorage.sol`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/SimpleStorage.sol" -o "BT\SimpleStorage.sol"
```

Download `Bank.sol`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/Bank.sol" -o "BT\Bank.sol"
```

Download `StudentRegistry.sol`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/StudentRegistry.sol" -o "BT\StudentRegistry.sol"
```

Download the Fabric setup script:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/setup-fabric.sh" -o "BT\setup-fabric.sh"
```

Create the DAA folder:

```bat
mkdir DAA
```

Download `fibonacci.cpp`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/fibonacci.cpp" -o "DAA\fibonacci.cpp"
```

Download `huffman.cpp`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/huffman.cpp" -o "DAA\huffman.cpp"
```

Download `knapsack.cpp`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/knapsack.cpp" -o "DAA\knapsack.cpp"
```

Download `nqueens.cpp`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/nqueens.cpp" -o "DAA\nqueens.cpp"
```

Download `quicksort.cpp`:

```bat
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/quicksort.cpp" -o "DAA\quicksort.cpp"
```

## Download files on Windows PowerShell

Create the folders:

```powershell
New-Item -ItemType Directory -Force BT, DAA
```

Download `SimpleStorage.sol`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/SimpleStorage.sol" -OutFile "BT\SimpleStorage.sol"
```

Download `Bank.sol`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/Bank.sol" -OutFile "BT\Bank.sol"
```

Download `StudentRegistry.sol`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/StudentRegistry.sol" -OutFile "BT\StudentRegistry.sol"
```

Download the Fabric setup script:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/setup-fabric.sh" -OutFile "BT\setup-fabric.sh"
```

Download `fibonacci.cpp`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/fibonacci.cpp" -OutFile "DAA\fibonacci.cpp"
```

Download `huffman.cpp`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/huffman.cpp" -OutFile "DAA\huffman.cpp"
```

Download `knapsack.cpp`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/knapsack.cpp" -OutFile "DAA\knapsack.cpp"
```

Download `nqueens.cpp`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/nqueens.cpp" -OutFile "DAA\nqueens.cpp"
```

Download `quicksort.cpp`:

```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/quicksort.cpp" -OutFile "DAA\quicksort.cpp"
```

## Download files on Ubuntu/Linux

Create the BT folder:

```bash
mkdir -p BT
```

Download `SimpleStorage.sol`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/SimpleStorage.sol" -o "BT/SimpleStorage.sol"
```

Download `Bank.sol`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/Bank.sol" -o "BT/Bank.sol"
```

Download `StudentRegistry.sol`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/StudentRegistry.sol" -o "BT/StudentRegistry.sol"
```

Download the Fabric setup script:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/BT/setup-fabric.sh" -o "BT/setup-fabric.sh"
```

Create the DAA folder:

```bash
mkdir -p DAA
```

Download `fibonacci.cpp`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/fibonacci.cpp" -o "DAA/fibonacci.cpp"
```

Download `huffman.cpp`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/huffman.cpp" -o "DAA/huffman.cpp"
```

Download `knapsack.cpp`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/knapsack.cpp" -o "DAA/knapsack.cpp"
```

Download `nqueens.cpp`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/nqueens.cpp" -o "DAA/nqueens.cpp"
```

Download `quicksort.cpp`:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/DAA/quicksort.cpp" -o "DAA/quicksort.cpp"
```

## Run C++ programs on Windows

Install MinGW-w64 and ensure `g++` is available in `PATH`.

Compile `fibonacci.cpp`:

```bat
g++ DAA\fibonacci.cpp -std=c++17 -O2 -o DAA\fibonacci.exe
```

Run Fibonacci:

```bat
DAA\fibonacci.exe
```

Compile and run the other programs by replacing `fibonacci` with `huffman`,
`knapsack`, `nqueens`, or `quicksort`:

```bat
g++ DAA\huffman.cpp -std=c++17 -O2 -o DAA\huffman.exe
DAA\huffman.exe
```

```bat
g++ DAA\knapsack.cpp -std=c++17 -O2 -o DAA\knapsack.exe
DAA\knapsack.exe
```

```bat
g++ DAA\nqueens.cpp -std=c++17 -O2 -o DAA\nqueens.exe
DAA\nqueens.exe
```

```bat
g++ DAA\quicksort.cpp -std=c++17 -O2 -o DAA\quicksort.exe
DAA\quicksort.exe
```

In PowerShell, run an executable with `.\DAA\fibonacci.exe`.

## Run C++ programs on Ubuntu/Linux

Install the compiler:

```bash
sudo apt update
```

```bash
sudo apt install g++
```

Compile `fibonacci.cpp`:

```bash
g++ DAA/fibonacci.cpp -std=c++17 -O2 -o DAA/fibonacci
```

Run Fibonacci:

```bash
./DAA/fibonacci
```

Compile and run the other programs:

```bash
g++ DAA/huffman.cpp -std=c++17 -O2 -o DAA/huffman
```

```bash
./DAA/huffman
```

```bash
g++ DAA/knapsack.cpp -std=c++17 -O2 -o DAA/knapsack
```

```bash
./DAA/knapsack
```

```bash
g++ DAA/nqueens.cpp -std=c++17 -O2 -o DAA/nqueens
```

```bash
./DAA/nqueens
```

```bash
g++ DAA/quicksort.cpp -std=c++17 -O2 -o DAA/quicksort
```

```bash
./DAA/quicksort
```

## Run Python programs

The Python files remain in their original DAA practical folders.

### Windows

```bat
py "DAA\1_Fibonacci Series\non_recursive.py"
```

```bat
py "DAA\1_Fibonacci Series\recursive.py"
```

```bat
py "DAA\5_nqueens\nqueens.py"
```

```bat
py "DAA\6_quick sort analysis\quicksort.py"
```

If `py` is unavailable, use `python` instead.

### Ubuntu/Linux

Install Python:

```bash
sudo apt update
```

```bash
sudo apt install python3
```

Run each file:

```bash
python3 "DAA/1_Fibonacci Series/non_recursive.py"
```

```bash
python3 "DAA/1_Fibonacci Series/recursive.py"
```

```bash
python3 "DAA/5_nqueens/nqueens.py"
```

```bash
python3 "DAA/6_quick sort analysis/quicksort.py"
```

## BT Solidity programs

Open each `.sol` file in [Remix IDE](https://remix.ethereum.org/), choose a
compatible Solidity `0.8.x` compiler, compile it, and deploy it using the
Practical 1-4 instructions. Solidity programs are not run from Command Prompt
or the Linux terminal.

## Run BT Practical 5

The Fabric script is intended for Ubuntu/Linux with Docker and `sudo`.

Make it executable:

```bash
chmod +x BT/setup-fabric.sh
```

Run the setup:

```bash
./BT/setup-fabric.sh
```

Show status:

```bash
./BT/setup-fabric.sh status
```

Stop the network:

```bash
./BT/setup-fabric.sh down
```

Clean generated data:

```bash
./BT/setup-fabric.sh clean
```

Show help:

```bash
./BT/setup-fabric.sh help
```
