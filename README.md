<div align="center">

# LP-3 Lab Hub

### BT · DAA · ML · Practical Programs

<img src="https://media.giphy.com/media/13HBDT4QSTpveU/giphy.gif" width="420" alt="Anime character waving">

**One repository. One downloader. Zero Git required.**

[![Programs](https://img.shields.io/badge/programs-BT%20%7C%20DAA%20%7C%20ML-ff69b4?style=for-the-badge)](./Programs)
[![Main tool](https://img.shields.io/badge/main%20tool-lp3--programs.sh-8A2BE2?style=for-the-badge)](./Programs/lp3-programs.sh)
![Educational](https://img.shields.io/badge/license-educational-blue?style=for-the-badge)

<img src="https://media.giphy.com/media/3oKIPtjElfqwMOTbH2/giphy.gif" width="260" alt="Anime character celebrating">

</div>

> A straightforward laboratory collection for Learning Program 3. The
> `lp3-programs.sh` menu is the main entry point for downloading only the
> programs you need.

## What is inside?

| Area | Contents | Where to start |
|---|---|---|
| **BT** | Solidity contracts and Hyperledger Fabric Practical 5 | [BT programs](./Programs/BT) |
| **DAA** | C++ implementations of classic algorithms | [DAA programs](./Programs/DAA) |
| **ML** | Jupyter notebooks for five machine-learning practicals | [ML notebooks](./Programs/ML) |
| **Commands** | Individual Windows/Linux commands and templates | [cmd.md](./Programs/cmd.md) |
| **Menu** | Selective downloader and help menu | [lp3-programs.sh](./Programs/lp3-programs.sh) |

The original practical folders are still preserved in [`BT/`](./BT) and
[`DAA/`](./DAA). The [`Programs/`](./Programs) folder is a clean copy area;
nothing is moved by the downloader.

## Quick start: the main menu

### Ubuntu/Linux

The Bash menu downloads files directly from GitHub. Git, GitHub Desktop, and a
GitHub account are not required.

Download the menu:

```bash
curl -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/lp3-programs.sh" -o lp3-programs.sh
```

Make it executable:

```bash
chmod +x lp3-programs.sh
```

Show help:

```bash
./lp3-programs.sh help
```

List programs:

```bash
./lp3-programs.sh list
```

Download selected programs:

```bash
./lp3-programs.sh download bt bank
```

```bash
./lp3-programs.sh download daa quicksort
```

```bash
./lp3-programs.sh download ml diabetes
```

Download everything:

```bash
./lp3-programs.sh download all
```

Downloaded files go to `./LP-3-Programs/` by default.

Choose another output folder:

```bash
LP3_OUTPUT_DIR=./my-programs ./lp3-programs.sh download ml sales
```

### Windows PowerShell or CMD

The native PowerShell menu does not require Bash, WSL, Git, or Git Bash.

Download the menu from PowerShell:

```powershell
curl.exe -fL "https://raw.githubusercontent.com/PREMO625/LP-3/main/Programs/lp3-programs.ps1" -o "lp3-programs.ps1"
```

Show help:

```powershell
powershell -ExecutionPolicy Bypass -File .\lp3-programs.ps1 help
```

List programs:

```powershell
powershell -ExecutionPolicy Bypass -File .\lp3-programs.ps1 list
```

Download selected programs:

```powershell
powershell -ExecutionPolicy Bypass -File .\lp3-programs.ps1 download bt bank
```

```powershell
powershell -ExecutionPolicy Bypass -File .\lp3-programs.ps1 download daa quicksort
```

```powershell
powershell -ExecutionPolicy Bypass -File .\lp3-programs.ps1 download ml diabetes
```

Download everything:

```powershell
powershell -ExecutionPolicy Bypass -File .\lp3-programs.ps1 download all
```

### Windows WSL or Git Bash

Use this only if you specifically want to run the Bash menu on Windows.
Install/open Ubuntu through WSL or open Git Bash, then follow the Ubuntu/Linux
section above. Normal Windows CMD and PowerShell should use the PowerShell menu.

## How `lp3-programs.sh` works

The script is intentionally small and predictable:

1. It checks that `curl` is installed.
2. It receives a category and a short program name.
3. It maps that name to one approved file path.
4. It creates the required local folder.
5. It downloads the selected raw file from this repository.
6. It prints the saved location.

The supported command shape is:

```text
./lp3-programs.sh download CATEGORY NAME
```

Supported categories:

```text
bt    Solidity contracts and the Fabric script
daa   C++ algorithm programs
ml    Jupyter notebooks
```

The script does not silently download unrelated files. Invalid names show the
help menu and stop with an error.

## Menu names

### BT

```text
simplestorage       SimpleStorage.sol
bank                Bank.sol
studentregistry     StudentRegistry.sol
setup-fabric        setup-fabric.sh
```

Example:

```bash
./lp3-programs.sh download bt studentregistry
```

### DAA

```text
fibonacci           fibonacci.cpp
huffman             huffman.cpp
knapsack            knapsack.cpp
nqueens             nqueens.cpp
quicksort           quicksort.cpp
```

Example:

```bash
./lp3-programs.sh download daa fibonacci
```

### ML

```text
uber                ML_1_UBER.ipynb
email-spam          ML_2_EMAIL_SPAM.ipynb
bank-churn          ML_3_BANK_CHURN.ipynb
diabetes            ML_5_DIABETES.ipynb
sales               ML_6_SALES.ipynb
```

Example:

```bash
./lp3-programs.sh download ml email-spam
```

## Running the downloaded programs

### DAA C++ on Windows

Install MinGW-w64 and ensure `g++` is available in `PATH`.

```bat
g++ DAA\fibonacci.cpp -std=c++17 -O2 -o DAA\fibonacci.exe
```

```bat
DAA\fibonacci.exe
```

Replace `fibonacci` with `huffman`, `knapsack`, `nqueens`, or `quicksort`.
PowerShell uses the same commands with `.\DAA\program.exe` when starting an
executable.

### DAA C++ on Ubuntu/Linux

```bash
sudo apt update
sudo apt install g++
```

```bash
g++ DAA/fibonacci.cpp -std=c++17 -O2 -o DAA/fibonacci
./DAA/fibonacci
```

### ML notebooks on Windows

```bat
py -m pip install notebook
py -m notebook "ML\ML_1_UBER.ipynb"
```

Replace the notebook filename with the ML practical you want to open.

### ML notebooks on Ubuntu/Linux

```bash
sudo apt update
sudo apt install python3 python3-pip python3-venv
python3 -m venv .venv
source .venv/bin/activate
python -m pip install notebook
python -m notebook "ML/ML_1_UBER.ipynb"
```

The complete one-by-one command reference is in
[`Programs/cmd.md`](./Programs/cmd.md).

### Windows download choices

For Windows, choose one of these:

1. Use the native `lp3-programs.ps1` menu.
2. Use the individual `curl.exe` or PowerShell commands in
   [`Programs/cmd.md`](./Programs/cmd.md).
3. Use `lp3-programs.sh` through WSL or Git Bash.

Windows CMD and PowerShell can download every file, but they do not execute the
Bash menu script natively. The PowerShell menu works without Bash.

## Windows WSL setup

WSL is the easiest way to run the Bash menu from Windows CMD.

Check whether WSL is installed:

```bat
wsl --status
```

List installed Linux distributions:

```bat
wsl -l -v
```

If Ubuntu is not installed, open **PowerShell as Administrator** and run:

```bat
wsl --install -d Ubuntu
```

Restart Windows if requested. On the first Ubuntu launch, create a Linux
username and password.

From Windows CMD, run the downloaded menu script with:

```bat
wsl bash lp3-programs.sh help
```

Download a selected program:

```bat
wsl bash lp3-programs.sh download ml diabetes
```

For the Fabric script, run it inside Ubuntu/WSL because it needs Linux and
Docker:

```bat
wsl bash BT/setup-fabric.sh
```

### BT Solidity

Open the selected `.sol` file in
[Remix IDE](https://remix.ethereum.org/), choose a compatible Solidity `0.8.x`
compiler, compile, and deploy using the relevant practical instructions.

Solidity contracts are not executed directly in Command Prompt or a Linux
terminal.

### BT Practical 5: Fabric

Practical 5 is a Linux/Docker workflow:

```bash
chmod +x BT/setup-fabric.sh
./BT/setup-fabric.sh
```

Useful actions:

```bash
./BT/setup-fabric.sh status
./BT/setup-fabric.sh down
./BT/setup-fabric.sh clean
./BT/setup-fabric.sh help
```

It uses Hyperledger Fabric rather than Ethereum or MetaMask.

## Direct file downloads

If you do not want to use the menu, use the individual commands in
[`Programs/cmd.md`](./Programs/cmd.md). They are provided separately for:

- Windows Command Prompt
- Windows PowerShell
- Ubuntu/Linux
- C++ compilation and execution
- Python execution
- Jupyter Notebook launch
- Fabric script actions

## Safety and reproducibility

- Inspect scripts before running them.
- Use test wallets and test ETH only for BT Ethereum practicals.
- Never share a Secret Recovery Phrase or private key.
- Use a supported Ubuntu/Linux machine for Fabric Practical 5.
- The downloader saves copies; it does not move or delete the original practical files.

## Troubleshooting

### `curl: command not found`

```bash
sudo apt update
sudo apt install curl
```

### `Permission denied` for the menu

```bash
chmod +x lp3-programs.sh
```

### `g++ is not recognized`

Install MinGW-w64 on Windows and add its `bin` folder to `PATH`.

### `jupyter` or `notebook` is not available

Install Notebook using the Windows or Ubuntu/Linux commands above, then reopen
the terminal or activate the virtual environment again.

## Repository map

```text
LP-3/
├── BT/                         Original BT practical material
├── DAA/                        Original DAA practical material
├── Programs/
│   ├── BT/                     Standalone Solidity and Fabric files
│   ├── DAA/                    Standalone C++ files
│   ├── ML/                     Jupyter notebooks
│   ├── cmd.md                  One-by-one command reference
│   └── lp3-programs.sh         Main selective downloader
└── README.md                   This guide
```

<div align="center">

### Happy coding, have fun, and may your practicals compile on the first try ✨

<img src="https://media.giphy.com/media/11KzOet1ElBDz2/giphy.gif" width="300" alt="Anime character cheering">

</div>
