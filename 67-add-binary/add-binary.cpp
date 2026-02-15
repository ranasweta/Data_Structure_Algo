class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length();
        int n = b.length();

        // Pad shorter string with leading zeros
        if (m < n) {
            a = string(n - m, '0') + a;
        } else if (n < m) {
            b = string(m - n, '0') + b;
        }

        string ans;
        int carry = 0;

        // Traverse from right to left
        for (int i = a.length() - 1; i >= 0; i--) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        // Handle leftover carry
        if (carry) ans.push_back('1');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};