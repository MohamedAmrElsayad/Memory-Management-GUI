#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <cstring>
#include <cmath>
#include <QInputDialog>
#include "ui_mainwindow.h"



using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

  int m = ui->memoryBlocksSpinBox->value();
        int n = ui->processesSpinBox->value();

        int blockSize[m];
        int processSize[n];

        // Prompt the user to enter the block size for each block
        for (int i = 0; i < m; i++) {
            bool ok;
            QString input = QInputDialog::getText(this, "Enter Block Size", "Block " + QString::number(i + 1), QLineEdit::Normal, "", &ok);
            if (ok) {
                blockSize[i] = input.toInt();
            } else {
                // User canceled input, handle it appropriately
                return;
            }
        }

        // Prompt the user to enter the process size for each process
        for (int i = 0; i < n; i++) {
            bool ok;
            QString input = QInputDialog::getText(this, "Enter Process Size", "Process " + QString::number(i + 1), QLineEdit::Normal, "", &ok);
            if (ok) {
                processSize[i] = input.toInt();
            } else {
                // User canceled input, handle it appropriately
                return;
            }
        }


        int allocation[n]; // Declare the allocation array here
        nextFit(blockSize, m, processSize, n);
        buddySystem(blockSize, m, processSize, n);

            // Store the allocation results in a string
            QString allocationResults = "Next Fit Allocation:\n";
            allocationResults += "Process No.\tProcess Size\tBlock no.\n";
            for (int i = 0; i < n; i++) {
                allocationResults += " " + QString::number(i + 1) + "\t\t" + QString::number(processSize[i]) + "\t\t";
                if (allocation[i] != -1)
                    allocationResults += QString::number(allocation[i] + 1);
                else
                    allocationResults += "Not Allocated";
                allocationResults += "\n";
            }
            allocationResults += "\n";

            // Append the Buddy System allocation results
            allocationResults += "Buddy System Allocation:\n";
            allocationResults += "Process No.\tProcess Size\tBlock no.\n";
            for (int i = 0; i < n; i++) {
                allocationResults += " " + QString::number(i + 1) + "\t\t" + QString::number(processSize[i]) + "\t\t";
                if (allocation[i] != -1)
                    allocationResults += QString::number(allocation[i] + 1);
                else
                    allocationResults += "Not Allocated";
                allocationResults += "\n";
            }
            allocationResults += "\n";

            // Display the allocation results using QMessageBox
            QMessageBox::information(this, "Allocation Results", allocationResults);
        }


void MainWindow::nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int j = 0; // Represents the index of the memory block assigned to the current process

    // Initially, no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // Traverse each process and find a suitable block according to its size
    for (int i = 0; i < n; i++) {
        // Start from the current index and search for a block that can accommodate the process
        int startBlock = j; // Keep track of the starting block index for each process
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;

                // Reduce the available memory in this block
                blockSize[j] -= processSize[i];

                // Move to the next block
                j = (j + 1) % m;
                break;
            }
            j = (j + 1) % m;

            // If we have traversed all blocks and not found a suitable one, wrap around and search from the beginning
            if (j == startBlock) {
                j = (j + 1) % m;
                break;
            }
        }
    }

    // Store the allocation results in a string
    QString allocationResults = "Next Fit Allocation:\n";
    allocationResults += "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        allocationResults += " " + QString::number(i + 1) + "\t\t" + QString::number(processSize[i]) + "\t\t";
        if (allocation[i] != -1)
            allocationResults += QString::number(allocation[i] + 1);
        else
            allocationResults += "Not Allocated";
        allocationResults += "\n";
    }
    allocationResults += "\n";

    // Append the Buddy System allocation results
    allocationResults += "Buddy System Allocation:\n";
    allocationResults += "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        allocationResults += " " + QString::number(i + 1) + "\t\t" + QString::number(processSize[i]) + "\t\t";
        if (allocation[i] != -1)
            allocationResults += QString::number(allocation[i] + 1);
        else
            allocationResults += "Not Allocated";
        allocationResults += "\n";
    }
    allocationResults += "\n";

    // Display the allocation results using QMessageBox
    QMessageBox::information(this, "Allocation Results", allocationResults);
}

void MainWindow::buddySystem(int* blockSize, int m, int* processSize, int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    // Calculate the total number of blocks in the memory
    int totalBlocks = pow(2, ceil(log2(m)));

    // Create a binary tree to represent the buddy system
    int tree[2 * totalBlocks - 1];
    memset(tree, 0, sizeof(tree));

    for (int i = 0; i < n; i++) {
        int blockSizeIndex = 0;
        int currBlock = 0;
        int currSize = totalBlocks;

        // Search for a suitable block to allocate the process
        while (currBlock < totalBlocks - 1) {
            // If the current block is already allocated or smaller than the process size, move to the right child
            if (tree[currBlock] == 1 || currSize < processSize[i]) {
                currBlock = 2 * currBlock + 2;
                currSize /= 2;
            }
            // If the current block is not allocated and large enough to split, split it and move to the left child
            else {
                tree[currBlock] = 1;
                currBlock = 2 * currBlock + 1;
                currSize /= 2;
            }
        }

        // Allocate the process to the selected block
        int blockNo = currBlock - totalBlocks + 2; // Adjust the block number by adding 1
        allocation[i] = blockNo;
        while (blockNo > 1 && tree[(blockNo - 2) / 2] == 0) {
            blockNo = (blockNo - 2) / 2 + 1;
            allocation[i] = blockNo;
        }
    }

    // Store the allocation results in a string
    QString allocationResults = "Buddy System Allocation:\n";
    allocationResults += "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        allocationResults += " " + QString::number(i + 1) + "\t\t" + QString::number(processSize[i]) + "\t\t";
        if (allocation[i] != -1)
            allocationResults += QString::number(allocation[i]);
        else
            allocationResults += "Not Allocated";
        allocationResults += "\n";
    }
    allocationResults += "\n";

    // Display the allocation results using QMessageBox
    QMessageBox::information(this, "Allocation Results", allocationResults);
}
