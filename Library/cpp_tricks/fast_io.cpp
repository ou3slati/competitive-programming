/*
 * Fast I/O Techniques for Competitive Programming
 * Optimized input/output for large datasets
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class FastIO {
public:
    // Method 1: Standard optimization
    static void optimize_io() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    // Method 2: Custom fast input using getchar_unlocked (Unix/Linux only)
    static int read_int() {
        int x = 0;
        bool negative = false;
        char c = getchar_unlocked();
        
        // Skip non-digit characters
        while (c < '0' || c > '9') {
            if (c == '-') negative = true;
            c = getchar_unlocked();
        }
        
        // Read digits
        while (c >= '0' && c <= '9') {
            x = (x << 3) + (x << 1) + c - '0'; // x = x * 10 + (c - '0')
            c = getchar_unlocked();
        }
        
        return negative ? -x : x;
    }
    
    // Custom fast output
    static void write_int(int x) {
        if (x < 0) {
            putchar_unlocked('-');
            x = -x;
        }
        
        if (x >= 10) {
            write_int(x / 10);
        }
        
        putchar_unlocked('0' + x % 10);
    }
    
    // Method 3: Using scanf/printf (often faster than cin/cout)
    static void use_c_io() {
        // Just use scanf and printf instead of cin/cout
        // scanf("%lld", &x);
        // printf("%lld\n", x);
    }
    
    // Method 4: Buffer-based I/O
    static constexpr int BUFFER_SIZE = 1 << 16;
    static char input_buffer[BUFFER_SIZE];
    static char output_buffer[BUFFER_SIZE];
    static int input_pos = 0, input_len = 0;
    static int output_pos = 0;
    
    static char get_char() {
        if (input_pos == input_len) {
            input_len = fread(input_buffer, 1, BUFFER_SIZE, stdin);
            input_pos = 0;
        }
        return input_buffer[input_pos++];
    }
    
    static void put_char(char c) {
        if (output_pos == BUFFER_SIZE) {
            fwrite(output_buffer, 1, BUFFER_SIZE, stdout);
            output_pos = 0;
        }
        output_buffer[output_pos++] = c;
    }
    
    static void flush_output() {
        fwrite(output_buffer, 1, output_pos, stdout);
        output_pos = 0;
    }
    
    static int read_int_buffered() {
        int x = 0;
        bool negative = false;
        char c = get_char();
        
        while (c < '0' || c > '9') {
            if (c == '-') negative = true;
            c = get_char();
        }
        
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = get_char();
        }
        
        return negative ? -x : x;
    }
    
    static void write_int_buffered(int x) {
        if (x < 0) {
            put_char('-');
            x = -x;
        }
        
        if (x >= 10) {
            write_int_buffered(x / 10);
        }
        
        put_char('0' + x % 10);
    }
};

// Static member definitions
char FastIO::input_buffer[FastIO::BUFFER_SIZE];
char FastIO::output_buffer[FastIO::BUFFER_SIZE];
int FastIO::input_pos = 0;
int FastIO::input_len = 0;
int FastIO::output_pos = 0;

int32_t main() {
    // Method 1: Standard optimization (most commonly used)
    FastIO::optimize_io();
    
    int n;
    cin >> n;
    
    // Example: Reading large array efficiently
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Process data...
    
    // Output
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
Performance Tips:
1. Use '\n' instead of endl (endl flushes buffer)
2. Avoid mixing cin/cout with scanf/printf
3. For very large inputs, consider custom I/O methods
4. Use reserve() for vectors when size is known
5. Use emplace_back() instead of push_back() when constructing objects
*/
