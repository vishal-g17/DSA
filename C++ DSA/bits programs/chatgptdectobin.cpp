int n;
cin>> n;
int ans =0;
int power = 1; // Tracks the current power of 10

    while (n > 0) {
        int bit = n & 1; // Extract the least significant bit

        ans = (10* ans) + bit;//for reversen order

        // ans += bit * power; // Add the bit to the answer
        // power *= 10; // Update the power for the next bit
        n >>= 1; // Shift n to the right by 1 bit
    }

    cout << "Binary representation: " << ans << endl;

