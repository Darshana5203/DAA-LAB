#include<iostream>
using namespace std;

// Function to solve the knapsack problem
void knapsack(int n, float weight[], float profit[], float capacity);

int main() {
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    // Input the number of objects
    cout << "Enter the number of objects: ";
    cin >> num;

    // Input the weights and profits of each object
    cout << "Enter the weights and profits of each object:" << endl;
    for (i = 0; i < num; i++) {
        cin >> weight[i] >> profit[i];
    }

    // Input the capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Calculate the profit-to-weight ratio for each object
    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort the objects based on their profit-to-weight ratio in non-increasing order
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Call the knapsack function to find the optimal solution
    knapsack(num, weight, profit, capacity);
    return 0;
}

// Function to solve the knapsack problem
void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    // Initialize the solution vector x to all zeros
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Greedily fill the knapsack
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    // Fill the knapsack partially with the next object if there is remaining capacity
    if (i < n) {
        x[i] = u / weight[i];
    }

    // Calculate the total profit and print the solution vector
    tp = tp + (x[i] * profit[i]);
    cout << "The result vector is = ";
    for (i = 0; i < n; i++)
        cout << x[i] << "  ,  ";
    cout << endl << "Maximum profit is = " << tp << endl;
}
/*
Output:
svkm@svkm-VirtualBox:~$ cd Documents
svkm@svkm-VirtualBox:~/Docment$ cd SY_IT_54
svkm@svkm-VirtualBox:~/Documents/SY_IT_54$ g++ knapsack.cpp 
svkm@svkm-VirtualBox:culents/SY_IT_54$ ./a.out
Enter no of object 7
Enter weights and profit for each object
2 10
3 5
5 15
7 7
1 6
4 18
1 3
Enter capacity of knapsack 15
the result vector is 111110.6666670
Maximum profit is= 55.3333
svkm@svkm-VirtualBox: Docaments/SY_IT_54*/
























