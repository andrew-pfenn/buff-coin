# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

Team Members: Andrew Pfennigwerth, Ben HorlBeck

Our program can best be tested and observed by running ./run_app_1 in the build folder. In this file we have left some of the fuction calls that were there originally to get the blockchain started, and then our text-based interface starts running. There you have the option to 1. Add a transation 2. Verify Blockchain 3. Mine Pending Transactions and 4. Print blockhain 5. Quit. It is also important to note that we made hash, previousHash, and the vector of transactions public so our code could run properly. Our print function displays the current blocks hash, previousHash, and the transactions within that block.
