/**
 * 1052. Grumpy Bookstore Owner - LeetCode Problem
 * 
 * Problem Description:
 * There is a bookstore owner that has a store open for n minutes. You are given two arrays:
 * - customers[i]: number of customers at minute i
 * - grumpy[i]: 0 if owner is not grumpy, 1 if owner is grumpy at minute i
 * 
 * When the owner is grumpy, customers are not satisfied. However, the owner has a secret technique
 * to keep themselves not grumpy for minutes minutes (not necessarily consecutive).
 * 
 * Goal:
 * Maximize the number of satisfied customers using the secret technique optimally.
 * A customer is satisfied if they arrive when the owner is not grumpy.
 * 
 * Constraints:
 * - 1 <= n <= 10^5
 * - 0 <= customers[i] <= 10^3
 * - grumpy[i] is either 0 or 1
 * - 0 <= minutes <= n
 * 
 * Approach:
 * - Use a sliding window of size 'minutes' to find the best window where we apply the technique
 * - Calculate baseline satisfied customers (when owner is not grumpy)
 * - For each window, track additional satisfied customers we can gain
 * - Return baseline + maximum gain from any window
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();

        // -----------------------------------------
        // STEP 1: Count customers who are ALWAYS satisfied
        // -----------------------------------------
        // If grumpy[i] == 0, the owner is happy,
        // so customers at that minute are satisfied no matter what.
        int baseSatisfied = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i];
            }
        }

        // -----------------------------------------
        // STEP 2: Build the FIRST window of size = minutes
        // -----------------------------------------
        // This window assumes we use the secret technique starting at minute 0.
        // We ONLY count customers where grumpy[i] == 1,
        // because these are the ones the technique can "fix".
        int currentExtra = 0;

        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                currentExtra += customers[i];
            }
        }

        // This is the best extra satisfaction seen so far
        int maxExtra = currentExtra;

        // -----------------------------------------
        // STEP 3: Slide the window across the array
        // -----------------------------------------
        // l = left index of window
        int l = 0;

        // r = new index entering the window
        for (int r = minutes; r < n; r++) {

            // ---- ADD STEP ----
            // A new minute enters from the right
            // If owner was grumpy, those customers now become satisfied
            if (grumpy[r] == 1) {
                currentExtra += customers[r];
            }

            // ---- REMOVE STEP ----
            // A minute leaves from the left
            // If owner was grumpy then, we must remove those customers
            if (grumpy[l] == 1) {
                currentExtra -= customers[l];
            }

            // Move the left boundary of the window
            l++;

            // Update the best window seen so far
            maxExtra = max(maxExtra, currentExtra);
        }

        // -----------------------------------------
        // STEP 4: Final Answer
        // -----------------------------------------
        // Total satisfied customers =
        // customers always satisfied + customers fixed by best window
        return baseSatisfied + maxExtra;
    }
};
