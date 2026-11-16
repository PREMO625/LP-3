# Assignment 1: MetaMask and Ether Transaction Fees

## Viva Questions and Answers

### 1. What is MetaMask?
MetaMask is a browser extension and wallet that lets users manage Ethereum accounts
and interact with decentralized applications (dApps).

### 2. Why is MetaMask used in this practical?
It provides an Ethereum wallet and allows us to approve, sign, and view blockchain
transactions from a browser.

### 3. What is a blockchain?
A blockchain is a distributed digital ledger that records transactions in blocks
linked together using cryptography. Copies of the ledger are maintained by multiple
network participants, making the recorded history difficult to alter.

### 4. What is a cryptocurrency?
A cryptocurrency is a digital asset that uses cryptography and a blockchain or
distributed ledger to record ownership and transactions. It can be transferred
electronically without relying on a traditional central bank.

### 5. What is Bitcoin?
Bitcoin is the first widely adopted decentralized cryptocurrency. It runs on its
own public blockchain and is primarily used for peer-to-peer value transfer. Its
native currency is called bitcoin and is represented by `BTC`.

### 6. What is Ethereum?
Ethereum is a public blockchain platform that supports cryptocurrency transfers,
smart contracts, and decentralized applications. Its native cryptocurrency is
Ether (`ETH`).

### 7. What is a cryptocurrency wallet?
A wallet is an application that manages blockchain accounts and their cryptographic
keys. It does not store coins physically; it signs transactions for an account.

### 8. What is a public address?
A public address identifies an account on the blockchain. It may be shared to receive
funds, but it does not reveal the account's private key.

### 9. What is a private key or Secret Recovery Phrase?
It is the secret used to control and recover an account. It must never be shared or
entered into an untrusted website.

### 10. What is Ether (ETH)?
Ether (ETH) is Ethereum's native cryptocurrency. It is used to transfer value and pay
transaction fees.

### 11. What is the difference between Ether and Ethereum?
Ethereum is the blockchain platform and network. Ether (`ETH`) is the native
cryptocurrency used on that network to transfer value and pay transaction fees.

### 12. What is a gas fee?
Gas is the computational work required to execute an Ethereum transaction. The gas fee
is paid in ETH and generally depends on the work required and network demand.

### 13. Why are transaction fees required?
Fees compensate validators for processing and securing transactions and help prevent
network abuse.

### 14. What is a test network?
A test network, or testnet, is a blockchain network used for development, learning,
and testing before deploying to a production network. Testnet tokens are supplied
for testing and are intended to have no real monetary value.

### 15. What is Sepolia?
Sepolia is a currently supported Ethereum test network used to deploy and test smart
contracts without spending real ETH. Test ETH can be obtained from a Sepolia faucet.

### 16. What was Rinkeby?
Rinkeby was an Ethereum test network, but it has been deprecated. Use a currently
supported test network such as Sepolia when performing this practical.

### 17. Does Hyperledger Fabric have a built-in currency?
No. Hyperledger Fabric is a permissioned enterprise blockchain and does not have a
built-in native cryptocurrency, Ether, Bitcoin, or gas fee. Organizations pay the
operational costs of running the network, such as servers and Docker containers.
Fabric chaincode can implement a business asset or token if the application requires
one, but that token is defined by the application rather than by Fabric itself.

### 18. What is the difference between Ethereum and Hyperledger Fabric?
Ethereum is generally a public blockchain that uses accounts, validators, and ETH
for gas. Hyperledger Fabric is a permissioned network with known organizations,
peers, channels, ordering, and endorsement policies. Fabric does not require a
native cryptocurrency for transactions.

### 19. What is Remix IDE?
Remix is a browser-based IDE used to write, compile, deploy, and interact with Solidity
smart contracts.

### 20. What is Solidity?
Solidity is a programming language for writing smart contracts that run on
Ethereum-compatible blockchains.

### 21. What is a smart contract?
A smart contract is a program deployed on a blockchain. Its functions execute according
to its code when a transaction or call invokes them.

### 22. What happens when a contract is deployed?
The contract code is compiled into bytecode and submitted in a blockchain transaction.
After confirmation, the contract receives an address and can be called.

### 23. What is the difference between a transaction and a read-only call?
A transaction changes blockchain state and usually requires a signature and gas fee. A
read-only call only reads state and normally does not require gas.

### 24. What is the role of MetaMask during deployment?
MetaMask connects Remix to the selected network, shows the estimated fee, and asks the
user to approve and sign the deployment transaction.

### 25. How can the transaction cost be studied?
Record the ETH balance before and after the transaction. The difference is the amount
spent, subject to any balance changes from other transactions.

### 26. What is the conclusion of this practical?
MetaMask was installed and used with a test network to study an Ethereum account,
Ether, smart-contract interaction, and transaction fees.

## Smart Contract Code Explanation

The following `SimpleStorage` contract is written in Solidity:

```solidity
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract SimpleStorage {
    uint256 private storedValue;

    function setValue(uint256 value) public {
        storedValue = value;
    }

    function getValue() public view returns (uint256) {
        return storedValue;
    }
}
```

### 1. License declaration

```solidity
// SPDX-License-Identifier: MIT
```

This identifies the license under which the contract code is released. It also removes
the license warning shown by Remix.

### 2. Solidity version

```solidity
pragma solidity ^0.8.20;
```

This tells the compiler to use Solidity version `0.8.20` or a compatible later `0.8.x`
version. The caret (`^`) allows compatible compiler updates within the 0.8 release
series.

### 3. Contract declaration

```solidity
contract SimpleStorage {
```

This creates a smart contract named `SimpleStorage`. A contract is similar to a class
that contains data and functions, but it is deployed and executed on the blockchain.

### 4. Stored variable

```solidity
uint256 private storedValue;
```

This declares an unsigned 256-bit integer named `storedValue`.

- `uint256` stores a non-negative whole number.
- `private` means the variable is accessed directly only inside this contract.
- The default value is `0`.

### 5. Updating the value

```solidity
function setValue(uint256 value) public {
    storedValue = value;
}
```

The `setValue` function accepts a number and stores it in `storedValue`.

- `function` declares a function.
- `setValue` is the function name.
- `uint256 value` is the input parameter.
- `public` allows external users and applications to call the function.

Calling `setValue(25)` changes blockchain state. Therefore, MetaMask asks for approval
and a transaction fee is charged.

### 6. Reading the value

```solidity
function getValue() public view returns (uint256) {
    return storedValue;
}
```

The `getValue` function returns the current value of `storedValue`.

- `view` means the function only reads blockchain data.
- `returns (uint256)` specifies that the function returns an unsigned integer.
- `return storedValue` sends the stored value back to the caller.

Calling `getValue` does not change blockchain state, so it normally does not require a
MetaMask approval or gas fee when called from Remix.

### 7. Gas behavior in this practical

- Deploying `SimpleStorage` stores the contract on Sepolia and costs gas.
- Calling `setValue(25)` changes the stored value and costs gas.
- Calling `getValue()` only reads the value and normally costs no gas.
- The transaction fee can be checked in MetaMask or on a Sepolia block explorer.
