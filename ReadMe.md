# Blockchain for Peer-to-Peer Transactions

## System Overview
- Each block will store multiple transactions.
- Transactions contain:
  - **Sender** (A–E)
  - **Receiver** (A–E)
  - **Amount transferred**
  - **Timestamp**
- Blocks will be linked using **SHA-256 hashing** for immutability.
- A **genesis block** (first block) will initialize the blockchain.
- The system will allow **new transactions to be added** and form blocks after a certain threshold.

## Implementation Plan

### Step 1: Block Structure
- Define a `Block` class with:
  - **Index**
  - **Timestamp**
  - **Transactions**
  - **Previous block’s hash**
  - **Current block’s hash**

### Step 2: Blockchain Class
- Manage a **chain of blocks**.
- Ensure proper **linking** between blocks.
- Implement **hash verification**.

### Step 3: Transaction Processing
- Store **transactions in a queue**.
- Once a **threshold is reached** (e.g., 5 transactions), create a new block.

### Step 4: Display Blockchain
- Print the **entire blockchain** with transaction history.